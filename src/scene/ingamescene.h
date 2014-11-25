#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include <QDebug>
#include <QKeyEvent>
#include "scene.h"
#include "../qneed.h"
#include "../character.h"
class Map;


class Character;
class InGameScene : public Scene
{
  Q_OBJECT
public:
  InGameScene(QObject *parent = 0);
  void setupIngame();
  virtual void action();

  virtual void keyReleaseEvent(QKeyEvent* event);
  virtual void keyPressEvent(QKeyEvent* event);
  void timerEvent(QTimerEvent*);
  void Widget();
  //
  // a w d s
  //
  //
  ~InGameScene();
signals:

public slots:

private:

  Character* player1;
  Character* player2;
  Map* map;
  bool keyLeft, keyRight, keyUp, keyDown;
  bool keyW, keyA, keyS, keyD;

};

#endif // INGAMESCENE_H
