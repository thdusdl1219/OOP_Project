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
#define MAX_SPEED 6
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
    bool mujuk;
    void setCharPos(int);
public:
    Character(Qneed* parent, enum CharacterType::Type, int _numbomb, int _powbomb, int _speed, enum Team::Type);
    void setupCharacter();
    void setUnitDir(enum Direction::Type);
    void setPosition(int);
    void setNeed(Map* map);
    int getPosition();
    void consumeItem(Item*);
    enum CharacterType::Type getType();
    enum Team::Type getTeam() const;
    int getNumBomb() const;
    int getPowBomb() const;
    int getSpeed() const;
    int getLife();
    Qneed* image;
    int use_soju;
    bool getMujuk();
    void setMujuk(bool);
public slots:
    virtual void bombrecover2();
    virtual void resetMujuk();
    virtual bool bombObject();
    virtual void bombrecover();
    void animateImage(int);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

//signals:
//    void Aya(){}

};
#endif
