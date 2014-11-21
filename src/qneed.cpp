#include "qneed.h"
#include <QString>

Qneed::Qneed(QGraphicsScene *scene, MainWindow *window)
{
    scene->addItem(this);
    image = NULL;
    this->window = window;
}

Qneed::Qneed(QObject *parent) :
    QObject(parent)
{
    image = NULL;
}

void Qneed::loadImage(const char* filename)
{
    if(image != NULL)
        delete image;
    image = new QPixmap(QString(filename));
    setPixmap(*image);
}

MainWindow* Qneed::get_window()
{
    return window;
}
