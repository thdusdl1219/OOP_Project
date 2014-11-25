#include "unit.h"
#include <QTimer>
#include "map.h"

Unit::Unit(Qneed* need, int x, int y) : Qneed(need)
{
  cell_x = x;
  cell_y = y;
  position = x *(13*3-2)*3 + 3 * y;
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

int Unit::getPosition()
{
  return position;
}

Item::Item(Qneed* need, int x, int y, ItemType::Type type): Unit(need, x, y)
{
  for(int i=0; i<4; i++)  stat[i]=0;
  switch(type)
    {
    case ItemType::BOMB_NUM:
      break;
    case ItemType::BOMB_POWER:
      break;
    case ItemType::LIFE:
      break;
    case ItemType::SPEED:
      break;
    }

}

void Item::setItemStat(int s, int quantity){
  stat[s] = quantity;
}

bool Item::bombObject(){
  delete this;
  return true;
}

Soju::Soju(Qneed* need, int x, int y, int p): Unit(need, x, y)
{
  setPosition(x, y);
  loadImage(":images/ingame/map/map_soju.png");
  setPos(cell_xy[getPosition()]);
  time=5;
  power=p;
  QTimer::singleShot(5*1000, this, SLOT(bombObject()));
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

	for(int i = 0; i <= power; i++ )
		{
			QTimer::singleShot(i*100,map->cell[0][i], SLOT(bombObject()));
		}

}

Block::Block(Qneed* need, int x, int y, bool bre, Item* it): Unit(need, x, y)
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
  if(it==NULL){
      hasItem=false;
      item=NULL;
    }
  else{
      hasItem=true;
      item=it;
    }
}

Item* Block::getItem(){
  return item;
}

bool Block::isBreakable(){
  return breakable;
}


bool Block::bombObject(){
  if(item != NULL)
  {
      return true;
  }
  else
  {
    delete this;
    return false;
  }
}
