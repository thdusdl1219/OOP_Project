#include "endgamescene.h"
#include "../map.h"
#include "../character.h"
#include "../mainwindow.h"
#include "initscene.h"
#include <QPropertyAnimation>

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
    //background->loadImage(":images/endgame/endgame_background.png");
    //set_background(background);

   // win = new Qneed(this, get_window());
   // win->setZValue(10);
    Character* player1 = Map::get_map()->player1;
    Character* player2 = Map::get_map()->player2;
    if(player1->getLife() == 0 && player2->getLife() == 0)
        background->loadImage(":images/endgame/endgame_draw.png");
    else if(player1->getLife() == 0)
        background->loadImage(":images/endgame/endgame_kaist.png");
    else
        background->loadImage(":images/endgame/endgame_postech.png");
    set_background(background);
   // win->setPos(0,0);
    OnemoreButton* one = new OnemoreButton(this,get_window());
    one->setPos(824, 553);
    CreatorButton* cre = new CreatorButton(this,get_window());
    cre->setPos(824, 649);
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
    get_window()->replay();
	get_window()->changeScene(SceneType::CHOICECHARACTER);
}

void OnemoreButton::showbutton(){
    this->show();
}
