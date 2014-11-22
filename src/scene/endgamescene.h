#ifndef ENDGAMESCENE_H
#define ENDGAMESCENE_H

#include "scene.h"

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

};

#endif // ENDGAMESCENE_H
