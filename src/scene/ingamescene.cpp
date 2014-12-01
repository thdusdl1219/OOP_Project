#include "ingamescene.h"
#include "choicescene.h"
#include "../map.h"
#include <QTimer>
#include <QSize>
#include <QObject>
#include <QWidget>
#include <QThread>
#include "../unit.h"
#include "../character.h"
#include "../mainwindow.h"
InGameScene::InGameScene(QObject *parent) :
	Scene(parent)
{
	player1 = ChoiceScene :: get_ChoiceScene()->player1;
	player2 = ChoiceScene :: get_ChoiceScene()->player2;
	keyUp = keyDown = keyLeft = keyRight = false;
<<<<<<< HEAD
    keyT = keyF = keyG = keyH = false;
=======
    keyW = keyA = keyS = keyD = false;
>>>>>>> 노의미
    bomb1 = bomb2 = false;
	setupIngame();
    scene = this;
//    setFocusPolicy(Qt::StrongFocus);
    timerid = QObject::startTimer(1000/80);


    animation = new QTimeLine(500);
    animation->setFrameRange(1,4);
    connect(animation, SIGNAL(finished()), animation, SLOT(start()));
    animation->start();

    connect(animation, SIGNAL(frameChanged(int)), player1, SLOT(animateImage(int)));
    connect(animation, SIGNAL(frameChanged(int)), player2, SLOT(animateImage(int)));

}

InGameScene* InGameScene::scene = NULL;
InGameScene* InGameScene::get_InGameScene()
{
    return scene;
}

InGameScene::~InGameScene()
{
    killTimer(timerid);
    delete map;
    delete animation;
}

void InGameScene::keyPressEvent(QKeyEvent *e)
{
	if(e->isAutoRepeat() == false)
		{
			if(e->key()==Qt::Key_Left)
				{
                    player2->setUnitDir(Direction::LEFT);
					keyLeft=true;
				}
			else if(e->key()==Qt::Key_Right)
				{
                player2->setUnitDir(Direction::RIGHT);
					keyRight=true;
				}
			else if(e->key()==Qt::Key_Up)
				{
                player2->setUnitDir(Direction::UP);
					keyUp=true;
				}
			else if(e->key()==Qt::Key_Down)
                {
                player2->setUnitDir(Direction::DOWN);
					keyDown=true;
				}
            if(e->key()==Qt::Key_F)
				{
                player1->setUnitDir(Direction::LEFT);
                    keyF=true;
				}
            else if(e->key()==Qt::Key_H)
				{
                player1->setUnitDir(Direction::RIGHT);
                    keyH=true;
				}
            else if(e->key()==Qt::Key_T)
				{
                player1->setUnitDir(Direction::UP);
                    keyT=true;
				}
            else if(e->key()==Qt::Key_G)
				{
                player1->setUnitDir(Direction::DOWN);
                    keyG=true;
				}
            if(e->key()==Qt::Key_A)
            {
                player1->setUnitDir(Direction::STAY);
                bomb1 = true;
            }
            if(e->key()==Qt::Key_Slash)
            {
                player2->setUnitDir(Direction::STAY);
                bomb2 = true;
            }
			QGraphicsScene::keyPressEvent(e);
		}
}

void InGameScene::keyReleaseEvent(QKeyEvent *e)
{
	if(e->isAutoRepeat()==false)
		{
			if(e->key()==Qt::Key_Left)
				{
                player2->setUnitDir(Direction::STAY);
					keyLeft=false;
				}
			else if(e->key()==Qt::Key_Right)
				{
                player2->setUnitDir(Direction::STAY);
					keyRight=false;
				}
			else if(e->key()==Qt::Key_Up)
                {
                player2->setUnitDir(Direction::STAY);
					keyUp=false;
				}
			else if(e->key()==Qt::Key_Down)
				{
                player2->setUnitDir(Direction::STAY);
					keyDown=false;
				}
            if(e->key()==Qt::Key_F)
				{
                player1->setUnitDir(Direction::STAY);
                    keyF=false;
				}
            else if(e->key()==Qt::Key_H)
				{
                player1->setUnitDir(Direction::STAY);
                    keyH=false;
				}
            else if(e->key()==Qt::Key_T)
				{
                player1->setUnitDir(Direction::STAY);
                    keyT=false;
				}
            else if(e->key()==Qt::Key_G)
				{
                player1->setUnitDir(Direction::STAY);
                    keyG=false;
				}
            if(e->key()==Qt::Key_A)
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
     static int delay1 = 0, delay2 = 0;
     int x1 = player1->cell_x;
     int y1 = player1->cell_y;
     int x2 = player2->cell_x;
     int y2 = player2->cell_y;
    delay1 ++;
    delay2 ++;
    if(delay1 >= (9-player1->getSpeed()))
        delay1 = 0;
    if(delay2 >= (9-player2->getSpeed()))
        delay2 = 0;
    if(bomb1)
    {
      if((map->soju[x1][y1]) == NULL)
        if(player1->use_soju < player1->getNumBomb())
        map->soju[x1][y1] = new Soju(map, x1, y1, player1->getPowBomb(), player1);
    }
    if(bomb2)
    {
      if((map->soju[x2][y2]) == NULL)
        if(player2->use_soju < player2->getNumBomb())
        map->soju[x2][y2] = new Soju(map, x2, y2, player2->getPowBomb(), player2);
    }
    if(delay2 == 0)
    {
    if(keyUp && cur_position2 >= 13*3-2)
    {
        //qDebug() << "Up";
        player2->moveUp();
        //player2->setPos(cell_xy[cur_position2-13*3+2]);
    }
    if(keyDown && cur_position2 < (13*3-2)*9*3)
    {
        //qDebug() << "Down";
        player2->moveDown();
        //player2->setPos(cell_xy[cur_position2+13*3-2]);
    }
    if(keyLeft && cur_position2 % (13*3-2) != 0)
    {
        //qDebug() << "Left";
        player2->moveLeft();
        //player2->setPos(cell_xy[cur_position2-1]);
    }
    if(keyRight && (cur_position2+1) % (13*3 - 2) != 0)
    {
        //qDebug() << "Right";
        player2->moveRight();
        //player2->setPos(cell_xy[cur_position2+1]);
    }
    }
    if(delay1 == 0)
    {
    if(keyT && cur_position1 >= 13*3-2)
    {
        //qDebug() << "W";
        player1->moveUp();
        //player1->setPos(cell_xy[cur_position1-13*3+2]);
    }
    if(keyG && cur_position1 < (13*3-2)*9*3)
    {
        //qDebug() << "S";
        player1->moveDown();
        //player1->setPos(cell_xy[cur_position1+13*3-2]);
    }
    if(keyF && cur_position1 % (13*3-2) != 0)
    {
        //qDebug() << "A";
        player1->moveLeft();
        //player1->setPos(cell_xy[cur_position1-1]);
    }
    if(keyH && cur_position1 % (13*3 - 2) != (13*3-3))
    {
        //qDebug() << "D";
        player1->moveRight();
        //player1->setPos(cell_xy[cur_position1+1]);
    }
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

    HeartNum* num1 = new HeartNum(this, get_window(), Team::POSTECH);
    num1->setPos(0, 76);
    QObject::connect(player1,SIGNAL(Aya()),num1,SLOT(bombLife()));
    this->num1 = num1;
    HeartNum* num2 = new HeartNum(this, get_window(), Team::KAIST);
    num2->setPos(980, 76);
    QObject::connect(player2, SIGNAL(Aya()), num2, SLOT(bombLife()));
    this->num2 = num2;

//	ChoiceScene* scene = ChoiceScene::get_ChoiceScene(); // just test. you can call ChoiceScene!
}

void InGameScene::zero()
{
    get_window()->changeScene(SceneType::ENDGAME);
}



HeartNum::HeartNum(QGraphicsScene *scene, MainWindow *window, Team::Type team) :Qneed(scene, window)
{
    this->team = team;
    loadImage(":images/ingame/ingame_3.png");
}

void HeartNum::bombLife()
{
    qDebug() << "bomb!";
    Character* player;
    if(team == Team::POSTECH)
        player = Map::get_map()->player1;
    else
        player = Map::get_map()->player2;
    switch(player->getLife())
    {
    case 0:
        loadImage(":images/ingame/ingame_0.png");
        break;
    case 1:
        loadImage(":images/ingame/ingame_1.png");
        break;
    case 2:
        loadImage(":images/ingame/ingame_2.png");
        break;
    case 3:
        loadImage(":images/ingame/ingame_3.png");
        break;
    }
}
