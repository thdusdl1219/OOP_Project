#ifndef CHOICESCENE_H
#define CHOICESCENE_H

#include "scene.h"
#include "../qneed.h"

class GoButton;

class ChoiceScene : public Scene
{
    Q_OBJECT
public:
    ChoiceScene(QObject *parent = 0);
    virtual void action();
    void setupChoice();
    ~ChoiceScene();

signals:

public slots:

private:
    GoButton* go_button;
};

class GoButton : public Qneed
{
public :
    GoButton(QGraphicsScene*, MainWindow*);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};


#endif // CHOICESCENE_H
