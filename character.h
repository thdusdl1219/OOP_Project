#include <iostream>
#include <string>

class Character {
public:
	Character(string, int, int, int, int); //character »ý¼º(name, team, numbomb, powbomb, speed)
	void setNumBomb(int); //
	void setPowBomb(int);
	void setSpeed(int);
	string getName();
	int getTeam();
	int getNumBomb();
	int getPowBomb();
	int getSpeed();
private:
	enum {MAXNUM_BOMB = Max};
	enum {MAXNUM_BOMB = Max};
	enum {MAX_SPEED = Max};
	string name;
	int team;
	int numbomb;
	int powbomb;
	int speed;
	Character();
};