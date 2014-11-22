#ifndef UNIT_H
#define UNIT_H

#include <QImage>
#include <QPixmap>


class Unit: public QObject{
    Q_OBJECT
public:
    Unit(int, int);		// row, col;
    bool bombObject();	// action for bombing Unit
    void getPostion(int&, int&);	// get row col of Unit;
private:
    int row, col;
};

class Item: public Unit{
public:
    Item(int, int, const char*);	// row, col, imageSrc
    void setItemStat(int, int);	// stat_type, increasement
    bool bombObject();	// true - Item destroyed, false - Nothing happened
private:
    QPixmap* imageSrc;
    // 0 - bombNum, 1 - bombPower, 2 - Speed, 3 - Life
    enum Stat_Type {BOMB_NUM, BOMB_POWER, SPEED, LIFE};
    int stat[4];
};

class Soju: public Unit{
public:
    Soju(int, int, const char*, int , int);	// row, col, imageSrc;
    // get private member function
    int getTime();
    int getPower();
    bool bombObject();
private:
    QPixmap* imageSrc;
    int time;			// zero for bomb
    int power;			// power of soju
};


class Block: public Unit{
public:
        Block(int, int, const char*, bool , Item*);	// row, col, imageSrc
        ~Block();
    // get private member fct
    Item* getItem();
    bool isBreakable();
    //////////////////////////
    bool bombObject();		// true : break block, false : nothing happened;
    void placeItem(Item*);		// item setting
private:
    bool breakable;

    QPixmap* imageSrc;
    bool hasItem;
    Item* item;
};

#endif
