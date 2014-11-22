#include "ingamescene.h"
#include "choicescene.h"
#include <QDebug>
#include <QKeyEvent>
InGameScene::InGameScene(QObject *parent) :
  Scene(parent)
{
  setupIngame();
}

InGameScene::~InGameScene()
{

}

void InGameScene::keyPressEvent(QKeyEvent *event)
{
	qDebug() << "PPP!" << event->key();
}


void InGameScene::setupIngame()
{
	Qneed* background = new Qneed(this, get_window());
	background->loadImage(":images/ingame/ingame_background.png");
	set_background(background);

	ChoiceScene* scene = ChoiceScene::get_ChoiceScene(); // just test. you can call ChoiceScene!
}

void InGameScene::action()
{

}
