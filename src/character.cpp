#include "character.h"

Character::Character(int _character_type, int _numbomb, int _powbomb, int _speed, int _team) {
	character_type = _character_type;
	numbomb = _numbomb;
	powbomb = _powbomb;
	speed = _speed;
	team = _team;
}

void Character::setNumBomb(int cnumbomb) {
	if(numbomb <= MAXNUM_BOMB)
		numbomb += cnumbomb;
}

void Character::setPowBomb(int cpowbomb) {
	if(numbomb <= MAXPOW_BOMB)
		numbomb += cpowbomb;
}

void Character::setSpeed(int cspeed) {
	if(numbomb <= MAX_SPEED)
		numbomb += cspeed;
}

int Character::getType() {
	return character_type;
}

int Character::getTeam() const {
	return team;
}

int Character::getNumBomb() const {
	return numbomb;
}

int Character::getPowBomb() const {
	return powbomb;
}

int Character::getSpeed() const {
	return speed;
}
