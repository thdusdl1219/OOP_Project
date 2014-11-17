#ifndef CHARACTORH
#define CHARACTORH

#define MAXNUM_BOMB = 8
#define MAXPOW_BOMB = 8
#define MAX_SPEED = 8

class Character {
public:
	Character(string _name, int, int, int, int);//character(name, team, numbomb, powbomb, speed)
	Character(char*, int, int, int, int);
	void setNumBomb(int); //
	void setPowBomb(int);
	void setSpeed(int);
    string getName();
	int getTeam() const;
	int getNumBomb() const;
	int getPowBomb() const;
	int getSpeed() const;
private:
	string name;
	int team;
	int numbomb;
	int powbomb;
	int speed;
	Character();
};

#endif
