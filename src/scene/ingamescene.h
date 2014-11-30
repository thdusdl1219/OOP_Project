#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include <QDebug>
#include <QKeyEvent>
#include <QWidget>
#include "scene.h"
#include "../qneed.h"
#include "../character.h"
#include "../Types.h"
class Map;

class HeartNum;
class Character;
class InGameScene : public Scene
{
  Q_OBJECT
public:
  InGameScene(QObject *parent = 0);
  void setupIngame();

  virtual void keyReleaseEvent(QKeyEvent* event);
  virtual void keyPressEvent(QKeyEvent* event);
  void timerEvent(QTimerEvent*);
  void Widget();
  HeartNum* num1;
  HeartNum* num2;
  //
  // a w d s
  //
  //
  ~InGameScene();
  static InGameScene* get_InGameScene();
signals:

public slots:

  virtual void zero();
private:
  int timerid;
  static InGameScene* scene;
  Character* player1;
  Character* player2;
  Map* map;
  bool keyLeft, keyRight, keyUp, keyDown;
  bool keyT, keyF, keyG, keyH;
  bool bomb1, bomb2;
  QTimeLine* animation;
};


class HeartNum : public Qneed
{
Q_OBJECT
private:
    enum Team::Type team;
public:
    HeartNum(QGraphicsScene*, MainWindow *, enum Team::Type);
public slots:
    virtual void bombLife();
};

#endif // INGAMESCENE_H
