#include "endgamescene.h"
#include "../map.h"
#include "../character.h"
EndgameScene::EndgameScene(QObject *parent) :
  Scene(parent)
{
  setupEndgame();
}

EndgameScene::~EndgameScene()
{

}

void EndgameScene::setupEndgame()
{
	Qneed* background = new Qneed(this, get_window());
	background->loadImage(":images/endgame/endgame_background.png");
    set_background(background);

    win = new Qneed(this, get_window());
    win->setZValue(10);
    Character* player1 = Map::get_map()->player1;
    Character* player2 = Map::get_map()->player2;
    if(player1->getLife() == 0 && player2->getLife() == 0)
        win->loadImage(":images/endgame/endgame_draw.png");
    else if(player1->getLife() == 0)
        win->loadImage(":images/endgame/endgame_kaist.png");
    else
        win->loadImage(":images/endgame/endgame_postech.png");
}

void EndgameScene::action()
{

}

OnemoreButton::OnemoreButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{

}

void OnemoreButton::mousePressEvent(QGraphicsSceneMouseEvent *e)
{

}

void OnemoreButton::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{

}
