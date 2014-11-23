#include "unit.h"

Unit::Unit(Qneed* need, int pos) : Qneed(need)
{
  position = pos;
}

Unit::~Unit()
{

}

int Unit::getPostion()
{
  return position;
}

Item::Item(Qneed* need, int pos, ItemType::Type type): Unit(need, pos)
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

Soju::Soju(Qneed* need, int pos, int p): Unit(need, pos)
{
  loadImage(":images/ingame/map/map_soju.png");
  setPos(cell_xy[pos]);
  time=10;
  power=p;
}

int Soju::getTime(){
  return time;
}

int Soju::getPower(){
  return power;
}

bool Soju::bombObject(){
  delete this;
  return true;
}


Block::Block(Qneed* need, int pos, bool bre, Item* it): Unit(need, pos)
{
  loadImage(":images/ingame/map/map_block.png");
  setPos(cell_xy[pos]);
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
