#include "ingamescene.h"

InGameScene::InGameScene(QObject *parent) :
  Scene(parent)
{
  setupIngame();
}

InGameScene::~InGameScene()
{

}

void InGameScene::setupIngame()
{
	Qneed* background = new Qneed(this, get_window());
	background->loadImage(":images/ingame/ingame_background.png");
	set_background(background);
}

void InGameScene::action()
{

}
