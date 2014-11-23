#ifndef UNIT_H
#define UNIT_H

#include <QImage>
#include <QPixmap>
#include "qneed.h"
#include "Types.h"

class Unit: public Qneed
{
	Q_OBJECT
public:
	Unit(Qneed*, int);		// row, col;
	virtual bool bombObject() {return true;}	// action for bombing Unit
	int getPostion();	// get row col of Unit;
	virtual ~Unit();
private:
	//
	//	image size = 70 * 70 pixel
	//
	Qneed* image;
	int position;
};

class Item: public Unit
{
	Q_OBJECT
public:
	Item(Qneed*, int, ItemType::Type);	// row, col, imageSrc
	void setItemStat(int, int);	// stat_type, increasement
	virtual bool bombObject();	// true - Item destroyed, false - Nothing happened
private:
	int type;
	// 0 - bombNum, 1 - bombPower, 2 - Speed, 3 - Life
	int stat[4];
};

class Soju: public Unit
{
	Q_OBJECT
public:
	Soju(Qneed*, int , int);	// row, col, imageSrc;
	// get private member function
	int getTime();
	int getPower();
	virtual bool bombObject();
private:
	int time;			// zero for bomb
	int power;			// power of soju
};


class Block: public Unit
{
	Q_OBJECT
public:
    Block(Qneed*, int, bool , Item*);
	// get private member fct
	//
	//
	Item* getItem();
	bool isBreakable();
	//////////////////////////
	virtual bool bombObject();		// true : break block, false : nothing happened;
	void placeItem(Item*);		// item setting
private:
	bool breakable;
	bool hasItem;
	Item* item;
};

#endif
