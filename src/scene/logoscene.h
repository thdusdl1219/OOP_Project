#ifndef LOGOSCENE_H
#define LOGOSCENE_H

#include <QObject>
#include "scene.h"
#include "../qneed.h"

class LogoScene : public Scene
{
    Q_OBJECT
public:
    LogoScene(QObject* parent = 0);
    virtual void action();
    void setupLogo();
    ~LogoScene();
private:
    Qneed* logo;
};


class InitButton : public Qneed
{
    Q_OBJECT
public:
    InitButton(QGraphicsScene*, MainWindow*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
public slots:
    void showbutton();
};

#endif // LOGOSCENE_H
