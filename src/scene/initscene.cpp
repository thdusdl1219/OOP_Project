#include "initscene.h"
#include <QDebug>
#include "Types.h"
#include "mainwindow.h"

InitScene::InitScene(QObject* parent) : Scene(parent)
{
    qDebug() << "InitScene call";
    setupInit();
}

InitScene::~InitScene()
{
   qDebug() << "InitScene Die";
   if(get_background() != NULL)
       delete get_background();
}

void InitScene::action()
{

}

void InitScene::setupInit()
{
    Qneed* background = new Qneed(this, get_window());
    background->loadImage(":/images/init/init_background.png");
    set_background(background);

    play_button = new PlayButton(this, get_window());
    play_button->setPos(380, 350);

    creator_button = new CreatorButton(this, get_window());
    creator_button->setPos(380, 500);
}

PlayButton::PlayButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
    this->loadImage(":images/init/button_init_play.png");
}

void PlayButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Play Button pressed";
}

void PlayButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    get_window()->changeScene(SceneType::CHOICECHARACTER);
}


CreatorButton::CreatorButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
    this->loadImage(":images/init/button_init_creator.png");
}

void CreatorButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "creator Button pressed";
}

void CreatorButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    get_window()->changeScene(SceneType::LOGO);
}
