#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "../qneed.h"
class MainWindow;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    virtual void action(){}
    ~Scene();
    MainWindow* get_window();
    Qneed* get_background();
    void set_background(Qneed *);
signals:

public slots:

private:
    MainWindow* window;
    Qneed* background;
};

#endif // SCENE_H
