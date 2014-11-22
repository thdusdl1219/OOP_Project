#include "choicescene.h"
#include "Types.h"
#include "mainwindow.h"
#include <QDebug>
ChoiceScene::ChoiceScene(QObject *parent) :
    Scene(parent)
{
    setupChoice();
}
ChoiceScene::~ChoiceScene()
{
    if(get_background() == NULL)
        delete get_background();
    delete go_button;
}

void ChoiceScene::action()
{

}

void ChoiceScene::setupChoice()
{
    Qneed* background = new Qneed(this, get_window());
    background->loadImage(":images/choice/choice_background.png");
    set_background(background);

    go_button = new GoButton(this, get_window());
    go_button->setPos(285,150);

}

GoButton::GoButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene,window)
{
    qDebug() << "Go Button created";
    loadImage(":images/choice/choice_button_go.png");

}

void GoButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Go Button pressed";
}

void GoButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    get_window()->changeScene(SceneType::INGAME);
}
