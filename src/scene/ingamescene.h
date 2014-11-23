#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include <QDebug>
#include <QKeyEvent>
#include "scene.h"
#include "../qneed.h"
class InGameScene : public Scene
{
  Q_OBJECT
public:
	InGameScene(QObject *parent = 0);
	void setupIngame();
	virtual void action();


	virtual void keyPressEvent(QKeyEvent* event);
	//
	// a w d s
	//
	//
	~InGameScene();
signals:

public slots:

};

#endif // INGAMESCENE_H
