#ifndef Character_H
#define Character_H

#include <iostream>
#include <string>
#include <QTimeLine>
#include <QString>
#include "Types.h"
#include "qneed.h"
#include "unit.h"
#include <QDir>
using namespace std;

#define MAXNUM_BOMB 8
#define MAXPOW_BOMB 8
#define MAX_SPEED 8
#define MAX_LIFE 3
class Map;
class Character : public Unit
{
    Q_OBJECT
private:
	enum CharacterType::Type character_type;
	enum Team::Type team;
    enum Direction::Type character_dir;
	int numbomb;
	int powbomb;
	int speed;
    int position;
    int life;
    Map* map;
    void setCharPos(int);
public:
	Character(Qneed* parent, enum CharacterType::Type, int _numbomb, int _powbomb, int _speed, enum Team::Type);
	void setupCharacter();
    void setUnitDir(enum Direction::Type);
	void setNumBomb(int);
	void setPowBomb(int);
	void setSpeed(int);
	void setPosition(int);
	void setNeed(Map* map);
	int getPosition();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
	enum CharacterType::Type getType();
	enum Team::Type getTeam() const;
	int getNumBomb() const;
	int getPowBomb() const;
    int getSpeed() const;
    int getLife();
    void setLife(int);
    Qneed* image;
    int use_soju;
public slots:
    virtual bool bombObject();
    virtual void bombrecover();
    void animateImage(int);
//signals:
//    void Aya(){}

};
#endif
