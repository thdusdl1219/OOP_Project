#ifndef INITSCENE_H
#define INITSCENE_H

#include <QObject>
#include "scene.h"
#include "../qneed.h"

class PlayButton;
class CreatorButton;
class InitScene : public Scene
{
public:
    InitScene(QObject* parent = 0);
    virtual void action();
    void setupInit();
    ~InitScene();
private:
    PlayButton* play_button;
    CreatorButton* creator_button;
};

class PlayButton : public Qneed
{
public:
    PlayButton(QGraphicsScene*, MainWindow *);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

class CreatorButton : public Qneed
{
public:
    CreatorButton(QGraphicsScene*, MainWindow *);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};


#endif // INITSCENE_H
