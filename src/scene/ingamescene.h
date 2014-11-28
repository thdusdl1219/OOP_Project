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
class Heart;
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

private:
  static InGameScene* scene;
  Character* player1;
  Character* player2;
  Map* map;
  Heart* heart;
  Heart* heart2;
  bool keyLeft, keyRight, keyUp, keyDown;
  bool keyW, keyA, keyS, keyD;
  bool bomb1, bomb2;
};

class Heart : public Qneed
{
private:
    enum Team::Type team;
public :
    Heart(QGraphicsScene*, MainWindow *, enum Team::Type);
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
