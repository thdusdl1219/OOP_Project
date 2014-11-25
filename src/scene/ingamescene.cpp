#include "ingamescene.h"
#include "choicescene.h"
#include "../map.h"
#include <QTimer>
#include <Qsize>

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
    int x = player1->cell_x;
    int y = player1->cell_y;
    if(event->key() == 'W' )
    {
        qDebug() << "w pressed";
        if(cur_position >= 13*3-2)
        {
            player1->setPosition(cur_position-13*3+2);
        }
    }
    if(event->key() == 'A')
    {
        qDebug() << "a pressed";
        if(cur_position % (13*3-2) != 0)
        {
            player1->setPosition(cur_position-1);
        }
    }
    if(event->key() == 'S')
    {
        qDebug() << "s pressed";
        if(cur_position < (13*3-2)*9*3)
        {
            player1->setPosition(cur_position+13*3-2);
        }
    }
    if(event->key() == 'D')
    {
        qDebug() << "d pressed";
        if(cur_position % (13*3 - 2) != (13*3-3))
        {
            player1->setPosition(cur_position+1);
        }
    }
    if(event->key() == 16777248)
      {
          new Soju(map, x, y, 2);
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
	map = newMap;
//	ChoiceScene* scene = ChoiceScene::get_ChoiceScene(); // just test. you can call ChoiceScene!
}

void InGameScene::action()
{

}
