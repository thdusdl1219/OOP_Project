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
  Null = false;
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
  QTimer::singleShot(10,this, SLOT(bombrecover()));
  return true;
}

void Unit::bombrecover()
{
  loadImage(":images/ingame/map/map_unit.png");
}

int Unit::getPosition()
{
  return position;
}

Item::Item(Qneed* need, int x, int y, ItemType::Type type): Unit(need, x, y)
{
  for(int i=0; i<4; i++)  stat[i]=0;
  setPos(cell_xy[getPosition()]);
  switch(type)
    {
    case ItemType::BOMB_NUM:
      loadImage(":images/ingame/map/map_bn.png");
      break;
    case ItemType::BOMB_POWER:
      loadImage(":images/ingame/map/map_bp.png");
      break;
    case ItemType::LIFE:
      loadImage(":images/ingame/map/map_life.png");
      break;
    case ItemType::SPEED:
      loadImage(":images/ingame/map/map_speed.png");
      break;
    }

}

void Item::setItemStat(int s, int quantity){
  stat[s] = quantity;
}

bool Item::bombObject(){
	if(Null == false)
		{
			Null = true;
			loadImage(":images/ingame/map/map_bomb.png");
			QTimer::singleShot(10,this, SLOT(bombrecover()));
		}
	return true;
}

Soju::Soju(Qneed* need, int x, int y, int p): Unit(need, x, y)
{
  loadImage(":images/ingame/map/map_soju.png");
  setPos(cell_xy[getPosition()]);
  time=2;
  power=p;
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
  delete this;
  return true;
}

void Soju::bomb()
{
  Map* map = Map::get_map();
  int pos = getPosition();

	for(int i = cell_y + 1; i <= cell_y + power; i++ )
		{
			if(i < 13)
				QTimer::singleShot(i*10,map->cell[cell_x][i], SLOT(bombObject()));
		}
	for(int i = cell_y - 1; i >= cell_y - power; i--)
		{
			if(i >= 0)
				QTimer::singleShot(i*10,map->cell[cell_x][i], SLOT(bombObject()));
		}
	for(int i = cell_x + 1; i <= cell_x + power; i++)
		{
			if(i < 10)
				QTimer::singleShot(i*10,map->cell[i][cell_y], SLOT(bombObject()));
		}
	for(int i = cell_x - 1; i >= cell_x - power; i--)
		{
			if(i >= 0)
				QTimer::singleShot(i*10,map->cell[i][cell_y], SLOT(bombObject()));
		}

}

Block::Block(Qneed* need, int x, int y, bool bre, bool it): Unit(need, x, y)
{
    if(bre){
        loadImage(":images/ingame/map/map_block.png");
    }
    else{
        loadImage(":images/ingame/map/map_breakable.png");
    }
  setPosition(x,y);
  setPos(cell_xy[getPosition()]);
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
  srand(time(0));
  if(Null == false)
  {
      Null = true;
    if(item == true)
    {
      dynamic_cast<Map *>(need)->cell[cell_x][cell_y] = new Item(need, cell_x, cell_y, (ItemType::Type)(rand()%4));
      return true;
    }
    else
    {
       loadImage(":images/ingame/map/map_bomb.png");
       QTimer::singleShot(10,this, SLOT(bombrecover()));
       return false;
    }
   }
}
