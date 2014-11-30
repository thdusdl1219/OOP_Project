#ifndef CHOICESCENE_H
#define CHOICESCENE_H

#include "scene.h"
#include "../qneed.h"
class Character;
class GoButton;
class PlayerButton;
class MapButton;

class ChoiceScene : public Scene
{
    Q_OBJECT
public:
    ChoiceScene(QObject *parent = 0);
    void setupChoice();
    ~ChoiceScene();
    int player1_cnt;
    int player2_cnt;
    Character* player1;
    Character* player2;
    int map_cnt;
    int map_kind;
    static ChoiceScene* get_ChoiceScene();
signals:

public slots:

private:
    static ChoiceScene* scene;
    GoButton* go_button;
    PlayerButton* player_button[6];
    MapButton* map_button[3];
};

class GoButton : public Qneed
{
public :
    GoButton(QGraphicsScene*, MainWindow*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
private:
    ChoiceScene* scene;
};

class PlayerButton : public Qneed
{
public :
    PlayerButton(QGraphicsScene*, MainWindow*, int);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
private :
    bool play;
    int character_id;
    ChoiceScene* scene;
};

class MapButton :public Qneed
{
public :
  MapButton(QGraphicsScene*, MainWindow*, int);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
private:
  int map_id;
  bool choice;
  ChoiceScene* scene;
};

#endif // CHOICESCENE_H
