class Character {
public:
	Character(string _name, int, int, int, int);//character »ý¼º(name, team, numbomb, powbomb, speed)
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
	enum {MAXNUM_BOMB = 8};
	enum {MAXPOW_BOMB = 8};
	enum {MAX_SPEED = 8};
	string name;
	int team;
	int numbomb;
	int powbomb;
	int speed;
	Character();
};