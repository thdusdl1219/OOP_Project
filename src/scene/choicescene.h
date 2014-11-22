#ifndef CHOICESCENE_H
#define CHOICESCENE_H

#include "scene.h"
#include "../qneed.h"

class GoButton;
class PlayerButton;

class ChoiceScene : public Scene
{
    Q_OBJECT
public:
    ChoiceScene(QObject *parent = 0);
    virtual void action();
    void setupChoice();
    ~ChoiceScene();
    int player1_cnt;
    int player2_cnt;
signals:

public slots:

private:
    GoButton* go_button;
    PlayerButton* player_button[4];
};

class GoButton : public Qneed
{
public :
    GoButton(QGraphicsScene*, MainWindow*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

class PlayerButton : public Qneed
{
public :
    PlayerButton(QGraphicsScene*, MainWindow*, int);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
private :
    int character_id;
    ChoiceScene* scene;
};

#endif // CHOICESCENE_H
