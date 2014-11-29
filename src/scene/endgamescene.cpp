#include "endgamescene.h"
#include "../map.h"
#include "../character.h"
#include "../mainwindow.h"
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
    win->setPos(10,10);
    OnemoreButton* one = new OnemoreButton(this,get_window());
    one->setPos(425, 600);
}

void EndgameScene::action()
{

}

OnemoreButton::OnemoreButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
	loadImage(":images/endgame/endgame_button_replay.png");
}

void OnemoreButton::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
	loadImage(":images/endgame/endgame_button_replay_press.png");
}

void OnemoreButton::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{
	loadImage(":images/endgame/endgame_button_replay.png");
	get_window()->changeScene(SceneType::CHOICECHARACTER);
}
