#include "unit.h"

Unit::Unit(QGraphicsScene* scene, MainWindow* window, int pos) : Qneed(scene, window)
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

Item::Item(QGraphicsScene* scene, MainWindow* window, int pos): Unit(scene, window, pos)
{
  for(int i=0; i<4; i++)  stat[i]=0;
}

void Item::setItemStat(int s, int quantity){
  stat[s] = quantity;
}

bool Item::bombObject(){
  delete this;
  return true;
}

Soju::Soju(QGraphicsScene* scene, MainWindow* window, int pos, int t, int p): Unit(scene, window, pos)
{
  time=t;
  power=p;
}

int Soju::getTime(){
  return time;
}

int Soju::getPower(){
  return power;
}

bool Soju::bombObject(){
  time=0;
  delete this;
  return true;
}


Block::Block(QGraphicsScene* scene, MainWindow* window, int pos, bool bre, Item* it): Unit(scene, window, pos)
{
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
