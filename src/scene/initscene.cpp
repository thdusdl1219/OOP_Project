#include "initscene.h"
#include <QDebug>
#include "../Types.h"
#include "../mainwindow.h"
#include <QKeyEvent>
InitScene::InitScene(QObject* parent) : Scene(parent)
{
    qDebug() << "InitScene call";
    setupInit();
}

InitScene::~InitScene()
{
   qDebug() << "InitScene Die";
}

void InitScene::setupInit()
{
    Qneed* background = new Qneed(this, get_window());
    background->loadImage(":/images/init/init_background.png");
    set_background(background);

    PlayButton* play_button = new PlayButton(this, get_window());
    play_button->setPos(425, 528);

    CreatorButton* creator_button = new CreatorButton(this, get_window());
    creator_button->setPos(425, 624);
}

PlayButton::PlayButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
    this->loadImage(":images/init/init_button_play.png");
}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Play Button pressed";
    this->loadImage(":images/init/init_button_play_press.png");
}

void PlayButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->loadImage(":images/init/init_button_play.png");
    get_window()->changeScene(SceneType::CHOICECHARACTER);
}


CreatorButton::CreatorButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
    this->loadImage(":images/init/init_button_creator.png");
}

void CreatorButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "creator Button pressed";
    this->loadImage(":images/init/init_button_creator_press.png");
}

void CreatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->loadImage(":images/init/init_button_creator.png");
    get_window()->replay();
    get_window()->changeScene(SceneType::LOGO);
}
