#include "scene.h"
#include "mainwindow.h"
Scene::Scene(QObject *parent) :
    QGraphicsScene(parent)
{
    window = dynamic_cast<MainWindow *>(parent);
    background = NULL;
}

Scene::~Scene()
{

}

MainWindow* Scene::get_window()
{
    return window;
}

Qneed* Scene::get_background()
{
    return background;
}

void Scene::set_background(Qneed *background)
{
    this->background = background;
}
