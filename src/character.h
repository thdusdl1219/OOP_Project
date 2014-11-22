#ifndef Character_H
#define Character_H

#include <iostream>
#include <string>

using namespace std;

#define MAXNUM_BOMB 8
#define MAXPOW_BOMB 8
#define MAX_SPEED 8

class Character {
private:
	string name;
	int team;
	int numbomb;
	int powbomb;
    int speed;
    Character();
public:
	Character(string, int, int, int, int);
	Character(char*, int, int, int, int);
	void setNumBomb(int);
	void setPowBomb(int);
	void setSpeed(int);
    string getName();
	int getTeam() const;
	int getNumBomb() const;
	int getPowBomb() const;
	int getSpeed() const;
};
#endif
