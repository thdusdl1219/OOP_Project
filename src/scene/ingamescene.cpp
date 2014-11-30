#include "ingamescene.h"
#include "choicescene.h"
#include "../map.h"
#include <QTimer>
#include <QSize>
#include <QObject>
#include <QWidget>
#include "../unit.h"
#include "../character.h"
#include "../mainwindow.h"
InGameScene::InGameScene(QObject *parent) :
	Scene(parent)
{
	player1 = ChoiceScene :: get_ChoiceScene()->player1;
	player2 = ChoiceScene :: get_ChoiceScene()->player2;
	keyUp = keyDown = keyLeft = keyRight = false;
	keyW = keyA = keyS = keyD = false;
    bomb1 = bomb2 = false;
	setupIngame();
    scene = this;
//    setFocusPolicy(Qt::StrongFocus);
	QObject::startTimer(1000/20);


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
			if(e->key()==Qt::Key_A)
				{
                player1->setUnitDir(Direction::LEFT);
					keyA=true;
				}
			else if(e->key()==Qt::Key_D)
				{
                player1->setUnitDir(Direction::RIGHT);
					keyD=true;
				}
			else if(e->key()==Qt::Key_W)
				{
                player1->setUnitDir(Direction::UP);
					keyW=true;
				}
			else if(e->key()==Qt::Key_S)
				{
                player1->setUnitDir(Direction::DOWN);
					keyS=true;
				}
            if(e->key()==Qt::Key_Shift)
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
			if(e->key()==Qt::Key_A)
				{
                player1->setUnitDir(Direction::STAY);
					keyA=false;
				}
			else if(e->key()==Qt::Key_D)
				{
                player1->setUnitDir(Direction::STAY);
					keyD=false;
				}
			else if(e->key()==Qt::Key_W)
				{
                player1->setUnitDir(Direction::STAY);
					keyW=false;
				}
			else if(e->key()==Qt::Key_S)
				{
                player1->setUnitDir(Direction::STAY);
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
      if((map->cell[x1][y1])->Null)
        if(player1->use_soju < player1->getNumBomb())
        map->soju[x1][y1] = new Soju(map, x1, y1, player1->getPowBomb(), player1);
    }
    if(bomb2)
    {
      if((map->cell[x2][y2])->Null)
        if(player2->use_soju < player2->getNumBomb())
        map->soju[x2][y2] = new Soju(map, x2, y2, player2->getPowBomb(), player2);
    }
    if(keyUp && cur_position2 >= 13*3-2)
    {
        qDebug() << "Up";
        player2->moveUp();
        //player2->setPos(cell_xy[cur_position2-13*3+2]);
    }
    if(keyDown && cur_position2 < (13*3-2)*9*3)
    {
        qDebug() << "Down";
        player2->moveDown();
        //player2->setPos(cell_xy[cur_position2+13*3-2]);
    }
    if(keyLeft && cur_position2 % (13*3-2) != 0)
    {
        qDebug() << "Left";
        player2->moveLeft();
        //player2->setPos(cell_xy[cur_position2-1]);
    }
    if(keyRight && (cur_position2+1) % (13*3 - 2) != 0)
    {
        qDebug() << "Right";
        player2->moveRight();
        //player2->setPos(cell_xy[cur_position2+1]);
    }

    if(keyW && cur_position1 >= 13*3-2)
    {
        qDebug() << "W";
        player1->setPosition(cur_position1-13*3+2);
        //player1->setPos(cell_xy[cur_position1-13*3+2]);
    }
    if(keyS && cur_position1 < (13*3-2)*9*3)
    {
        qDebug() << "S";
        player1->setPosition(cur_position1+13*3-2);
        //player1->setPos(cell_xy[cur_position1+13*3-2]);
    }
    if(keyA && cur_position1 % (13*3-2) != 0)
    {
        qDebug() << "A";
        player1->setPosition(cur_position1-1);
        //player1->setPos(cell_xy[cur_position1-1]);
    }
    if(keyD && cur_position1 % (13*3 - 2) != (13*3-3))
    {
        qDebug() << "D";
        player1->setPosition(cur_position1+1);
        //player1->setPos(cell_xy[cur_position1+1]);
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
//    delete num1;
//    delete num2;
//    delete map;
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
