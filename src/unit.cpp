#include "unit.h"

Unit::Unit(int r, int c){
  row=r;
  col=c;
}

void Unit::getPostion(int& r, int& c){
  r=row;
  c=col;
}

Item::Item(int r, int c, const char* filename): Unit(r, c){
  QPixmap* imgSrc = new QPixmap(filename);
  if(imgSrc != NULL)
    imageSrc=imgSrc;
  else
    imageSrc=NULL;
  for(int i=0; i<4; i++)  stat[i]=0;
}

void Item::setItemStat(int s, int qauntity){
  for(int i=0; i<qauntity; i++) stat[s]++;
}

bool Item::bombObject(){
  delete this;
  return true;
}

Soju::Soju(int r, int c, const char* filename, int t, int p): Unit(r, c){
  QPixmap* imgSrc = new QPixmap(filename);
  if(imgSrc != NULL)
    imageSrc=imgSrc;
  else
    imageSrc=NULL;
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

/*
Block::Block(int r, int c, const char* filename, bool b, Item* i): Unit(r, c){
  QPixmap* imgSrc = new QPixmap(filename);
  if(imgSrc != NULL)
    imageSrc=imgSrc;
  else
    imageSrc=NULL;
  breakable=b;
  if(i==NULL){
      hasItem=false;
      item=NULL;
    }
  else{
      hasItem=true;
      item=i;
    }
}
*/
Item* Block::getItem(){
  return item;
}

bool Block::isBreakable(){
  return breakable;
}


bool Block::bombObject(){
  delete this;
  return true;
}
