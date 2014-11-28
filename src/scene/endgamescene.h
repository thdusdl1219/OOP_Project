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
	virtual void action();
	~EndgameScene();
signals:

public slots:
private:
    Qneed* win;
};

class OnemoreButton : public Qneed
{
public:
    OnemoreButton(QGraphicsScene*, MainWindow*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent*);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
};

#endif // ENDGAMESCENE_H
