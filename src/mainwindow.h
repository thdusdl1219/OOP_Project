#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "scene/scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void changeScene(int scenetype);
    ~MainWindow();
    void replay();
private:
    Ui::MainWindow *ui;
    Scene* scene1;
    Scene* scene2;
    Scene* scene3;
    Scene* scene4;
    Scene* scene5;

};

#endif // MAINWINDOW_H
