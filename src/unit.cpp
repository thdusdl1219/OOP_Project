#include "unit.h"
#include <QTimer>
#include "map.h"

Unit::Unit(Qneed* need, int x, int y) : Qneed(need)
{
    this->need = need;
    cell_x = x;
    cell_y = y;
    position = x *(13*3-2)*3 + 3 * y;
    setPos(cell_xy[position]);
    Null = true;
}

Unit::~Unit()
{

}


void Unit::setPosition(int x, int y)
{
    cell_x = x;
    cell_y = y;
    position = x*(13*3 - 2)*3 + 3 * y;
}

bool Unit::bombObject()
{
    loadImage(":images/ingame/map/map_bomb.png");
    setOpacity(1);
    QTimer::singleShot(50,this, SLOT(bombrecover()));
    return true;
}

void Unit::bombrecover()
{
    setOpacity(0);
   // loadImage(":images/ingame/map/map_unit.png");
}

int Unit::getPosition()
{
    return position;
}

Item::Item(Qneed* need, int x, int y, ItemType::Type type): Unit(need, x, y)
{
    Null = false;
    for(int i=0; i<4; i++)  stat[i]=0;
    this->type = type;
    switch(type)
    {
    case ItemType::BOMB_NUM:
        loadImage(":images/ingame/map/map_bn.png");
        type=ItemType::BOMB_NUM;
        stat[0]=1;
        break;
    case ItemType::BOMB_POWER:
        loadImage(":images/ingame/map/map_bp.png");
        type=ItemType::BOMB_POWER;
        stat[1]=1;
        break;
    case ItemType::LIFE:
        loadImage(":images/ingame/map/map_life.png");
        type=ItemType::LIFE;
        stat[2]=1;
        break;
    case ItemType::SPEED:
        type=ItemType::SPEED;
        loadImage(":images/ingame/map/map_speed.png");
        stat[3]=1;
        break;
    }

    //  setPos(cell_xy[getPosition()]);
}

void Item::setItemStat(int s, int quantity){
    stat[s] = quantity;
}

ItemType::Type Item::getItemStat(){
    return type;
}


bool Item::bombObject(){
    if(Null == false)
    {
        Null = true;
    }
        loadImage(":images/ingame/map/map_bomb.png");
        setOpacity(1);
        QTimer::singleShot(50,this, SLOT(bombrecover()));
    return true;
}

Soju::Soju(Qneed* need, int x, int y, int p, Character* _player): Unit(need, x, y)
{
//    Map::get_map()->cell[x][y]->Null = false;
    loadImage(":images/ingame/map/map_soju.png");
    time=2;
    Null = false;
    power=p;
    player = _player;
    player->use_soju++;
    QTimer::singleShot(time*1000, this, SLOT(bombObject()));
}

int Soju::getTime(){
    return time;
}

int Soju::getPower(){
    return power;
}

bool Soju::bombObject(){
    bomb();
    Map::get_map()->cell[cell_x][cell_y]->Null = true;
    Map::get_map()->soju[cell_x][cell_y] = NULL;
    player->use_soju--;
    delete this;
    return true;
}

void Soju::bomb()
{
    Map* map = Map::get_map();
    int pos = getPosition();
    int num = 1;
    Character* player1 = Map::get_map()->player1;
    Character* player2 = Map::get_map()->player2;

    for(int i = cell_y; i <= cell_y + power; i++ )
    {
        if(i < 13)
        {

            QTimer::singleShot(num*50,map->cell[cell_x][i], SLOT(bombObject()));
            if(map->cell[cell_x][i]->Null == false)
                break;
            if(map->soju[cell_x][i] != NULL)
                QTimer::singleShot(0, map->soju[cell_x][i], SLOT(bombObject()));
            if(player1->cell_x == cell_x && player1->cell_y == i)
                QTimer::singleShot(num*50, player1, SLOT(bombObject()));
            if(player2->cell_x == cell_x && player2->cell_y == i)
                QTimer::singleShot(num*50, player2, SLOT(bombObject()));
            num++;

        }
    }
    num = 1;
    for(int i = cell_y - 1; i >= cell_y - power; i--)
    {
        if(i >= 0)
        {
            QTimer::singleShot(num*50,map->cell[cell_x][i], SLOT(bombObject()));
            if(map->cell[cell_x][i]->Null == false)
                break;
            if(map->soju[cell_x][i] != NULL)
                QTimer::singleShot(0, map->soju[cell_x][i], SLOT(bombObject()));
            if(player1->cell_x == cell_x && player1->cell_y == i)
                QTimer::singleShot(num*50, player1, SLOT(bombObject()));
            if(player2->cell_x == cell_x && player2->cell_y == i)
                QTimer::singleShot(num*50, player2, SLOT(bombObject()));
            num++;
        }
    }
    num = 1;
    for(int i = cell_x + 1; i <= cell_x + power; i++)
    {
        if(i < 10)
        {
            QTimer::singleShot(num*50,map->cell[i][cell_y], SLOT(bombObject()));
            if(map->cell[i][cell_y]->Null == false)
                break;
            if(map->soju[i][cell_y] != NULL)
                QTimer::singleShot(0, map->soju[i][cell_y], SLOT(bombObject()));
            if(player1->cell_x == i && player1->cell_y == cell_y)
                QTimer::singleShot(num*50, player1, SLOT(bombObject()));
            if(player2->cell_x == i && player2->cell_y == cell_y)
                QTimer::singleShot(num*50, player2, SLOT(bombObject()));
            num++;
        }
    }
    num = 1;
    for(int i = cell_x - 1; i >= cell_x - power; i--)
    {
        if(i >= 0)
        {
            QTimer::singleShot(num*50,map->cell[i][cell_y], SLOT(bombObject()));
            if(map->cell[i][cell_y]->Null == false)
                break;
            if(map->soju[i][cell_y] != NULL)
                QTimer::singleShot(0, map->soju[i][cell_y], SLOT(bombObject()));
            if(player1->cell_x == i && player1->cell_y == cell_y)
                QTimer::singleShot(num*50, player1, SLOT(bombObject()));
            if(player2->cell_x == i && player2->cell_y == cell_y)
                QTimer::singleShot(num*50, player2, SLOT(bombObject()));
            num++;
        }
    }

}

Block::Block(Qneed* need, int x, int y, bool bre, bool it): Unit(need, x, y)
{
    Null = false;
    if(bre){
        loadImage(":images/ingame/map/map_block.png");
    }
    else{
        loadImage(":images/ingame/map/map_breakable.png");
    }
  setPosition(x,y);
  breakable=bre;
  item = it;
}

bool Block::getItem(){
  return item;
}

bool Block::isBreakable(){
  return breakable;
}


bool Block::bombObject(){
  if(isBreakable())
  {
  srand((cell_x + cell_y)*time(0));
  if(Null == false)
  {
      Null = true;
    if(item == true)
    {
        int rand_num = rand()%4;
      dynamic_cast<Map *>(need)->cell[cell_x][cell_y] = new Item(need, cell_x, cell_y, (ItemType::Type)rand_num);
      //  dynamic_cast<Item*>(cell[cell_x][cell_y])->setItemStat((IteamType::Type)rand_num);
      delete this;
      return true;
    }
    else
    {
       loadImage(":images/ingame/map/map_bomb.png");
       setOpacity(1);
       QTimer::singleShot(50,this, SLOT(bombrecover()));
       return false;
    }
   }
  else
  {
       loadImage(":images/ingame/map/map_bomb.png");
       setOpacity(1);
       QTimer::singleShot(50,this, SLOT(bombrecover()));
       return false;

  }
  }
}
