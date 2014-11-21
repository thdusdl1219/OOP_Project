#include "initscene.h"
#include <QDebug>
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
}
