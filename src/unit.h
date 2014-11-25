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
	Unit(Qneed*, int, int);		// row, col;
	int getPosition();	// get row col of Unit;
	virtual ~Unit();
	void setPosition(int, int);
private:
	//
	//	image size = 70 * 70 pixel
	//
	Qneed* image;
	int cell_x, cell_y;
	int position;
public slots:
	virtual bool bombObject() {return true;}	// action for bombing Unit
};

class Item: public Unit
{
	Q_OBJECT
public:
	Item(Qneed*, int, int, ItemType::Type);	// row, col, imageSrc
	void setItemStat(int, int);	// stat_type, increasement
private:
	int type;
	// 0 - bombNum, 1 - bombPower, 2 - Speed, 3 - Life
	int stat[4];
public slots:
	virtual bool bombObject();	// action for bombing Unit

};

class Soju: public Unit
{
	Q_OBJECT
public:
	Soju(Qneed*, int, int , int);	// row, col, imageSrc;
	// get private member function
	int getTime();
	int getPower();
	void bomb();
private:
	int time;			// zero for bomb
	int power;			// power of soju
public slots:
	virtual bool bombObject();	// action for bombing Unit

};


class Block: public Unit
{
	Q_OBJECT
public:
		Block(Qneed*, int, int, bool , Item*);
	// get private member fct
	//
	//
	Item* getItem();
	bool isBreakable();
	//////////////////////////
	void placeItem(Item*);		// item setting
private:
	bool breakable;
	bool hasItem;
	Item* item;
public slots:
	virtual bool bombObject();	// action for bombing Unit
};

#endif
