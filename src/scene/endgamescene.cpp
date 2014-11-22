#include "endgamescene.h"

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
}

void EndgameScene::action()
{

}
