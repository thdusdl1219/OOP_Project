#ifndef ENDGAMESCENE_H
#define ENDGAMESCENE_H

#include "scene.h"
#include "../qneed.h"
class EndgameScene : public Scene
{
  Q_OBJECT
public:
	EndgameScene(QObject *parent = 0);
	void setupEndgame();
	~EndgameScene();
signals:

public slots:
};

class OnemoreButton : public Qneed
{
    Q_OBJECT
public:
    OnemoreButton(QGraphicsScene*, MainWindow*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
public slots:
    void showbutton();
};

#endif // ENDGAMESCENE_H
