#ifndef UNIT_H
#define UNIT_H

#include <QImage>
#include <QPixmap>
#include "qneed.h"
#include "Types.h"
#include "ctime"

class Unit: public Qneed
{
	Q_OBJECT
public:
	Unit(Qneed*, int, int);		// row, col;
	int getPosition();	// get row col of Unit;
	virtual ~Unit();
	void setPosition(int, int);
	int cell_x, cell_y;
	bool Null;
	Qneed* need;
private:
	//
	//	image size = 70 * 70 pixel
	//
	Qneed* image;
	int position;
public slots:
	virtual bool bombObject();	// action for bombing Unit
	void bombrecover();
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
		Block(Qneed*, int, int, bool , bool);
	// get private member fct
	//
	//
	bool getItem();
	bool isBreakable();
	//////////////////////////
	void placeItem(Item*);		// item setting
private:
	bool breakable;
	bool item;
public slots:
	virtual bool bombObject();	// action for bombing Unit
};

#endif
