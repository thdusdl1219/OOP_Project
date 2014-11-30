#include "character.h"
#include "map.h"
#include <QDebug>
#include <QTimer>
#include "scene/ingamescene.h"
#include "mainwindow.h"
Character::Character(Qneed* parent, enum CharacterType::Type _character_type, int _numbomb, int _powbomb, int _speed, enum Team::Type _team)
        : Unit(parent, 0, 0)
{
    Null = false;
    character_type = _character_type;
    character_dir = Direction::STAY;
    numbomb = _numbomb;
    powbomb = _powbomb;
    speed = _speed;
    team = _team;
    position = 0;
    setupCharacter();
    setZValue(10);
    use_soju = 0;
    life = 3;
}

bool Character::bombObject()
{
    qDebug() << "AYA";
    if(life == 0)
        life = 1;
    life--;
    if(life == 0)
    {
        emit Aya();

        QTimer::singleShot(1000,InGameScene::get_InGameScene(), SLOT(zero()));
    }
    else
    {
        setOpacity(0);
        QTimer::singleShot(75, this, SLOT(bombrecover()));
        emit Aya();
    }
    return true;
}

void Character::bombrecover()
{
    setOpacity(1);
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


void Character::setUnitDir(enum Direction::Type d){
    character_dir=d;
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


void Character::consumeItem(Item* i){
    int pos=i->getPosition();
    switch(i->getItemStat()){
    case ItemType::BOMB_NUM:
        numbomb++;
        break;
    case ItemType::BOMB_POWER:
        powbomb++;
        break;
    case ItemType::LIFE:
        life++;
        break;
    case ItemType::SPEED:
        speed++;
        break;
    }

    map->cell[pos/37/3][(pos%37)/3]=new Unit(need, pos/37/3, (pos%37)/3);
    delete i;
}



void Character::moveUp(){
    int temp_pos=position-37;
    if(temp_pos < 0){
        return;
    }   // Upper bound
    if((position/37)%3 == 1)
    {
        setPosition(temp_pos);
        return;
    }
    if(map->cell[(temp_pos/37)/3][(temp_pos%37)/3]->Null == false || map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]->Null == false){
        //qDebug() << (temp_pos/37)/3 << "  " << (temp_pos%37)/3;
            setPosition((cell_x*3)*37+cell_y*3);
        return;
    }

    if(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][(temp_pos%37)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][(temp_pos%37)/3]));
        setPosition(temp_pos);
    }
    else if(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]));
        setPosition(temp_pos);
    }
    if(map->soju[(temp_pos/37)/3][(temp_pos%37)/3] != NULL ||
                    map->soju[(temp_pos/37)/3][((temp_pos%37)+2)/3] != NULL)
        return;
    setPosition(temp_pos);
}


void Character::moveDown(){
    int temp_pos=position+37;
    if(temp_pos >= 37*3*10){
        return;
    }   // Bottom bound
    if((position/37)%3 == 2)
    {
        setPosition(temp_pos);
        return;
    }
    if(map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]->Null == false || map->cell[((temp_pos/37)+2)/3][((temp_pos%37))/3]->Null == false){
        //qDebug() << ((temp_pos/37)+2)/3 << "  " << (temp_pos%37)/3;
            setPosition((cell_x*3)*37+cell_y*3);

        return;
    }
    if(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]));
        setPosition(temp_pos);
    }
    else if(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37))/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37))/3]));
        setPosition(temp_pos);
    }

    if(map->soju[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3] != NULL ||
                    map->soju[((temp_pos/37)+2)/3][(temp_pos%37)/3] != NULL)
        return;

    setPosition(temp_pos);
}

void Character::moveLeft(){
    int temp_pos=position-1;
    if((temp_pos+1)%37 == 0){
        return;
    }   // Leftward bound
    if((position%37)%3 == 1)
    {
        setPosition(temp_pos);
        return;
    }
    if(map->cell[((temp_pos/37)+2)/3][(temp_pos%37)/3]->Null == false || map->cell[((temp_pos/37))/3][(temp_pos%37)/3]->Null == false){
        //qDebug() << (temp_pos/37)/3 << "  " << (temp_pos%37)/3;
            setPosition((cell_x*3)*37+cell_y*3);

        return;
    }
    if(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][(temp_pos%37)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][(temp_pos%37)/3]));
        setPosition(temp_pos);
    }
    else if(dynamic_cast<Item*>(map->cell[((temp_pos/37))/3][(temp_pos%37)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[((temp_pos/37))/3][(temp_pos%37)/3]));
        setPosition(temp_pos);
    }

    if(map->soju[((temp_pos/37)+2)/3][(temp_pos%37)/3] != NULL ||
                    map->soju[(temp_pos/37)/3][(temp_pos%37)/3] != NULL)
        return;

    setPosition(temp_pos);
}

void Character::moveRight(){
    int temp_pos=position+1;
    if(temp_pos%37 == 0){
        return;
    }   // Rightward bound
    if((position%37)%3 == 2)
    {
        setPosition(temp_pos);
        return;
    }
    if(map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]->Null == false || map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]->Null == false){
        //qDebug() << (temp_pos/37)/3 << "  " << ((temp_pos%37)+2)/3;
            setPosition((cell_x*3)*37+cell_y*3);

        return;
    }
    if(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[(temp_pos/37)/3][((temp_pos%37)+2)/3]));
        setPosition(temp_pos);
    }
    else if(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]) != NULL){
        consumeItem(dynamic_cast<Item*>(map->cell[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3]));
        setPosition(temp_pos);
    }

    if(map->soju[(temp_pos/37)/3][((temp_pos%37)+2)/3] != NULL ||
                    map->soju[((temp_pos/37)+2)/3][((temp_pos%37)+2)/3] != NULL)
        return;

    setPosition(temp_pos);

}

void Character::setNeed(Map* map)
{
    need = map;
    this->map=map;
}

int Character::getPosition()
{
	return position;
}

int Character::getLife()
{
    return life;
}


void Character::setLife(int l)
{
    if(numbomb <= MAX_LIFE)
        life += l;
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


void Character::animateImage(int frame){
    QString filename = QString(":images/ingame/character/");

    using namespace CharacterType;
    switch(character_type){
    case LIAR:
        filename += QString("liar_");
        break;
    case RICH:
        filename += QString("rich_");
        break;
    case ALCHOHOLIC:
        filename += QString("alchoholic_");
        break;
    }
    switch(team){
    case Team::POSTECH:
        filename += QString("postech_");
        break;
    case Team::KAIST:
        filename += QString("kaist_");
        break;
    }

    using namespace Direction;
    switch(character_dir){
    case UP:
        filename += QString("up_");
        break;
    case DOWN:
        filename += QString("down_");
        break;
    case LEFT:
        filename += QString("left_");
        break;
    case RIGHT:
        filename += QString("right_");
        break;
    case STAY:
        filename += QString("stay_");
        break;
    }

    filename += QString::number(frame) + QString(".png");

    Qneed::loadImage(filename);
}
