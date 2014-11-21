#include "logoscene.h"
#include <QDebug>
LogoScene::LogoScene(QObject* parent) : Scene(parent)
{
    qDebug() << "LogoScene call";
    setupLogo();
}

LogoScene::~LogoScene()
{
    if(get_background() != NULL)
        delete get_background();
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
    logo->setPos(200, 200);
}
