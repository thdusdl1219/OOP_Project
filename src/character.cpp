#include "character.h"
#include "map.h"
Character::Character(Qneed* parent, enum CharacterType::Type _character_type, int _numbomb, int _powbomb, int _speed, enum Team::Type _team)
	: Unit(parent, 0, 0)
{
    Null = false;
	character_type = _character_type;
	numbomb = _numbomb;
	powbomb = _powbomb;
	speed = _speed;
	team = _team;
	position = 0;
    setupCharacter();
    setZValue(10);
}

bool Character::bombObject()
{

}

void Character::setupCharacter()
{
	using namespace CharacterType;
	if(team == Team::POSTECH)
		{
		switch(character_type)
			{
			case LIAR:
				loadImage(":images/ingame/character/liar_postech.png");
				break;
			case RICH:
				loadImage(":images/ingame/character/rich_postech.png");
				break;
			case ALCHOHOLIC:
				loadImage(":images/ingame/character/alchoholic_postech.png");
				break;
			}
		}
	else
		{
		switch(character_type)
			{
			case LIAR:
				loadImage(":images/ingame/character/liar_kaist.png");
				break;
			case RICH:
				loadImage(":images/ingame/character/rich_kaist.png");
				break;
			case ALCHOHOLIC:
				loadImage(":images/ingame/character/alchoholic_kaist.png");
				break;
			}
		}
}

void Character::setCharPos(int pos)
{
	position = pos;
	cell_x = ((pos / 37) + 1) / 3;
	cell_y = ((pos % 37) + 1) / 3;
}

void Character::setPosition(int pos)
{
//	setupCharacter();
	setCharPos(pos);
    setPos(cell_xy[getPosition()]);
}

void Character::setNeed(Map* map)
{
	need = map;
}

int Character::getPosition()
{
	return position;
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

enum CharacterType::Type Character::getType() {
	return character_type;
}

enum Team::Type Character::getTeam() const {
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
