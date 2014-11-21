#ifndef INITSCENE_H
#define INITSCENE_H

#include <QObject>
#include "scene.h"
#include "../qneed.h"


class InitScene : public Scene
{
public:
    InitScene(QObject* parent = 0);
    virtual void action();
    void setupInit();
    ~InitScene();
};

/*class PlayButton : public Qneed
{
public:
    PlayButton(QGraphicsScene*, MainWindow *);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};*/

#endif // INITSCENE_H
