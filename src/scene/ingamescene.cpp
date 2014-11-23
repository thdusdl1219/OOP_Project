#include "ingamescene.h"
#include "choicescene.h"
#include "../map.h"
#include <QTimer>
InGameScene::InGameScene(QObject *parent) :
  Scene(parent)
{

    player1 = ChoiceScene :: get_ChoiceScene()->player1;
    player2 = ChoiceScene :: get_ChoiceScene()->player2;
    setupIngame();
}

InGameScene::~InGameScene()
{

}

void InGameScene::keyPressEvent(QKeyEvent *event)
{
    int cur_position = player1->getPosition();
    if(event->key() == 'W')
    {
        qDebug() << "w pressed";
        if(cur_position >= 13*3)
        {
            player1->setPosition(cur_position-13*3);
            player1->setPos(cell_xy[cur_position-13*3]);
        }
    }
    if(event->key() == 'A')
    {
        qDebug() << "a pressed";
        if(cur_position % (13*3) != 0)
        {
            player1->setPosition(cur_position-1);
            player1->setPos(cell_xy[cur_position-1]);
        }
    }
    if(event->key() == 'S')
    {
        qDebug() << "s pressed";
        if(cur_position < 13*3*9*3)
        {
            player1->setPosition(cur_position+13*3);
            player1->setPos(cell_xy[cur_position+13*3]);
        }
    }
    if(event->key() == 'D')
    {
        qDebug() << "d pressed";
        if(cur_position % (13*3) != (13*3-1))
        {
            player1->setPosition(cur_position+1);
            player1->setPos(cell_xy[cur_position+1]);
        }
    }
}


void InGameScene::keyReleaseEvent(QKeyEvent *event)
{
	qDebug() << "RRR!" << event->key();
}




void InGameScene::setupIngame()
{
	Qneed* background = new Qneed(this, get_window());
	background->loadImage(":images/ingame/ingame_background.png");
	set_background(background);

	Map* newMap = new Map(this, get_window(), ChoiceScene::get_ChoiceScene()->map_kind);
	newMap->setPos(44,24);
	newMap->setFixedSize(936, 720);
	map = newMap;
//	ChoiceScene* scene = ChoiceScene::get_ChoiceScene(); // just test. you can call ChoiceScene!
}

void InGameScene::action()
{

}
