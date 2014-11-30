#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Types.h"
#include "scene/initscene.h"
#include "scene/choicescene.h"
#include "scene/logoscene.h"
#include "scene/ingamescene.h"
#include "scene/endgamescene.h"
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene1 = NULL;
    scene2 = NULL;
    scene3 = NULL;
    scene4 = NULL;
    scene5 = NULL;
    changeScene(SceneType::INIT);
}

MainWindow::~MainWindow()
{
    delete ui;
    replay();
}

void MainWindow::changeScene(int scenetype)
{
    using namespace SceneType;
    switch(scenetype)
    {
    case INIT :
        scene1 = new InitScene(this);
        ui->graphicsView->setScene(scene1);
        break;
    case CHOICECHARACTER :
        scene2 = new ChoiceScene(this);
        ui->graphicsView->setScene(scene2);
        break;
    case INGAME :
        scene3 = new InGameScene(this);
        ui->graphicsView->setScene(scene3);
        break;
    case ENDGAME :
        scene4 = new EndgameScene(this);
        ui->graphicsView->setScene(scene4);
        break;
    case LOGO :
        scene5 = new LogoScene(this);
        ui->graphicsView->setScene(scene5);
        break;
    }
}

void MainWindow::replay()
{
    if(scene2 != NULL)
    {
        delete scene2;
        scene2 = NULL;
    }
    if(scene3 != NULL)
    {
        delete scene3;
        scene3 = NULL;
    }
    if(scene5 != NULL)
    {
        delete scene5;
        scene5 = NULL;
    }
}

