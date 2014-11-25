#include "ingamescene.h"
#include "choicescene.h"
#include "../map.h"
#include <QTimer>
#include <Qsize>
#include <QObject>
#include <QWidget>

InGameScene::InGameScene(QObject *parent) :
	Scene(parent)
{
	player1 = ChoiceScene :: get_ChoiceScene()->player1;
	player2 = ChoiceScene :: get_ChoiceScene()->player2;
	keyUp = keyDown = keyLeft = keyRight = false;
	keyW = keyA = keyS = keyD = false;
    bomb1 = bomb2 = false;
	setupIngame();
//    setFocusPolicy(Qt::StrongFocus);
	QObject::startTimer(1000/20);
}

InGameScene::~InGameScene()
{

}

void InGameScene::keyPressEvent(QKeyEvent *e)
{
	if(e->isAutoRepeat() == false)
		{
			if(e->key()==Qt::Key_Left)
				{
					keyLeft=true;
				}
			else if(e->key()==Qt::Key_Right)
				{
					keyRight=true;
				}
			else if(e->key()==Qt::Key_Up)
				{
					keyUp=true;
				}
			else if(e->key()==Qt::Key_Down)
				{
					keyDown=true;
				}
			if(e->key()==Qt::Key_A)
				{
					keyA=true;
				}
			else if(e->key()==Qt::Key_D)
				{
					keyD=true;
				}
			else if(e->key()==Qt::Key_W)
				{
					keyW=true;
				}
			else if(e->key()==Qt::Key_S)
				{
					keyS=true;
				}
            if(e->key()==Qt::Key_Shift)
            {
                bomb1 = true;
            }
            if(e->key()==Qt::Key_Slash)
            {
                bomb2 = true;
            }
			QGraphicsScene::keyPressEvent(e);
		}
	/*
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
			*/
}

void InGameScene::keyReleaseEvent(QKeyEvent *e)
{
	if(e->isAutoRepeat()==false)
		{
			if(e->key()==Qt::Key_Left)
				{
					keyLeft=false;
				}
			else if(e->key()==Qt::Key_Right)
				{
					keyRight=false;
				}
			else if(e->key()==Qt::Key_Up)
				{
					keyUp=false;
				}
			else if(e->key()==Qt::Key_Down)
				{
					keyDown=false;
				}
			if(e->key()==Qt::Key_A)
				{
					keyA=false;
				}
			else if(e->key()==Qt::Key_D)
				{
					keyD=false;
				}
			else if(e->key()==Qt::Key_W)
				{
					keyW=false;
				}
			else if(e->key()==Qt::Key_S)
				{
					keyS=false;
				}
            if(e->key()==Qt::Key_Shift)
            {
                bomb1 = false;
            }
            if(e->key()==Qt::Key_Slash)
            {
                bomb2 = false;
            }
			QGraphicsScene::keyReleaseEvent(e);
		}
	//	qDebug() << "RRR!" << event->key();
}


void InGameScene::timerEvent(QTimerEvent *)
 {
     int cur_position1 = player1->getPosition();
     int cur_position2 = player2->getPosition();
     int x1 = player1->cell_x;
     int y1 = player1->cell_y;
     int x2 = player2->cell_x;
     int y2 = player2->cell_y;
    if(bomb1)
    {
        new Soju(map, x1, y1, 2);
    }
    if(bomb2)
    {
        new Soju(map, x2, y2, 2);
    }
    if(keyUp && cur_position2 >= 13*3-2)
    {
        qDebug() << "Up";
        player2->setPosition(cur_position2-13*3+2);
        player2->setPos(cell_xy[cur_position2-13*3+2]);
    }
    if(keyDown && cur_position2 < (13*3-2)*9*3)
    {
        qDebug() << "Down";
        player2->setPosition(cur_position2+13*3-2);
        player2->setPos(cell_xy[cur_position2+13*3-2]);
    }
    if(keyLeft && cur_position2 % (13*3-2) != 0)
    {
        qDebug() << "Left";
        player2->setPosition(cur_position2-1);
        player2->setPos(cell_xy[cur_position2-1]);
    }
    if(keyRight && cur_position2 % (13*3 - 2) != (13*3-3))
    {
        qDebug() << "Right";
        player2->setPosition(cur_position2+1);
        player2->setPos(cell_xy[cur_position2+1]);
    }

    if(keyW && cur_position1 >= 13*3-2)
    {
        qDebug() << "W";
        player1->setPosition(cur_position1-13*3+2);
        player1->setPos(cell_xy[cur_position1-13*3+2]);
    }
    if(keyS && cur_position1 < (13*3-2)*9*3)
    {
        qDebug() << "S";
        player1->setPosition(cur_position1+13*3-2);
        player1->setPos(cell_xy[cur_position1+13*3-2]);
    }
    if(keyA && cur_position1 % (13*3-2) != 0)
    {
        qDebug() << "A";
        player1->setPosition(cur_position1-1);
        player1->setPos(cell_xy[cur_position1-1]);
    }
    if(keyD && cur_position1 % (13*3 - 2) != (13*3-3))
    {
        qDebug() << "D";
        player1->setPosition(cur_position1+1);
        player1->setPos(cell_xy[cur_position1+1]);
    }
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
