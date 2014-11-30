#include "qneed.h"
#include <QString>

Qneed::Qneed(QGraphicsScene *scene, MainWindow *window)
{
    scene->addItem(this);
    image = NULL;
    this->window = window;
}

Qneed::Qneed(Qneed *parent) :
    QObject(parent)
{
    image = NULL;
    if(parent != NULL)
       setParent(parent);

}

void Qneed::setParent(Qneed *parent)
{
  QObject::setParent(parent);
  QGraphicsPixmapItem::setParentItem(parent);
}

void Qneed::additem(QGraphicsScene *scene)
{
  scene->addItem(this);
}


void Qneed::loadImage(const char* filename)
{
    if(image != NULL)
        delete image;
    image = new QPixmap(QString(filename));
    setPixmap(*image);
}

void Qneed::loadImage(QString filename){
    if(image != NULL)
        delete image;
    image = new QPixmap(filename);
    setPixmap(*image);
}

MainWindow* Qneed::get_window()
{
    return window;
}
