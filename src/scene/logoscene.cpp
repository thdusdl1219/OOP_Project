#include "logoscene.h"
#include <QDebug>
#include "endgamescene.h"
#include "../map.h"
#include "../character.h"
#include "../mainwindow.h"
#include "initscene.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

LogoScene::LogoScene(QObject* parent) : Scene(parent)
{
    qDebug() << "LogoScene call";
    setupLogo();
}

LogoScene::~LogoScene()
{
    delete logo;
}

void LogoScene::action()
{

}

void LogoScene::setupLogo()
{
    Qneed* background = new Qneed(this, get_window());
    background->loadImage(":images/logo/logo_background.png");
    set_background(background);

    logo = new Qneed(this, get_window());
    logo->loadImage(":images/logo/logo.png");
    logo->setPos(256, 192);

    OnemoreButton* one = new OnemoreButton(this,get_window());
    one->setPos(400, 553);
    one->hide();
    InitButton* init = new InitButton(this, get_window());
    init->setPos(400, 649);
    init->hide();

    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect();
    opacityEffect->setOpacity(0.0);

    logo->setGraphicsEffect(opacityEffect);

    QPropertyAnimation * animation = new QPropertyAnimation();
    animation->setTargetObject(opacityEffect);
    animation->setPropertyName("opacity");
    animation->setDuration(2000);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setEasingCurve(QEasingCurve::OutQuad);

    connect(animation, SIGNAL(finished()), init, SLOT(showbutton()));
    connect(animation, SIGNAL(finished()), one, SLOT(showbutton()));
    animation->start();


}


InitButton::InitButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene, window)
{
    loadImage(":images/logo/init_button.png");
}

void InitButton::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    loadImage(":images/logo/init_button_press.png");
}

void InitButton::mouseReleaseEvent(QGraphicsSceneMouseEvent* e)
{
    loadImage(":images/logo/init_button.png");
    get_window()->changeScene(SceneType::INIT);
}

void InitButton::showbutton(){
    this->show();
}




