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

private:
    Ui::MainWindow *ui;
    Scene* scene;

    void actionScene();
};

#endif // MAINWINDOW_H
