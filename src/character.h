#ifndef Character_H
#define Character_H

#include <iostream>
#include <string>
#include "Types.h"
#include "qneed.h"
#include "unit.h"

using namespace std;

#define MAXNUM_BOMB 8
#define MAXPOW_BOMB 8
#define MAX_SPEED 8
class Character : public Unit
{
private:
	enum CharacterType::Type character_type;
	enum Team::Type team;
	int numbomb;
	int powbomb;
	int speed;
	int position;
public:
	Character(Qneed* parent, enum CharacterType::Type, int _numbomb, int _powbomb, int _speed, enum Team::Type);
	void setupCharacter();
	void setNumBomb(int);
	void setPowBomb(int);
	void setSpeed(int);
	void setPosition(int);
	int getPosition();
	enum CharacterType::Type getType();
	enum Team::Type getTeam() const;
	int getNumBomb() const;
	int getPowBomb() const;
	int getSpeed() const;
	Qneed* image;
};
#endif
