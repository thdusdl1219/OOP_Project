#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Types.h"
#include "scene/initscene.h"
#include "scene/choicescene.h"
#include "scene/logoscene.h"
#include "scene/ingamescene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = NULL;
    changeScene(SceneType::INIT);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::changeScene(int scenetype)
{
    using namespace SceneType;
    switch(scenetype)
    {
        case INIT :
            scene = new InitScene(this);
            break;
        case CHOICECHARACTER :
            scene = new ChoiceScene(this);
            break;
        case INGAME :
            scene = new InGameScene(this);
            break;
        case ENDGAME :
//            scene = new EndgameScene(this);
            break;
        case LOGO :
            scene = new LogoScene(this);
            break;
    }
    ui->graphicsView->setScene(scene);
    actionScene();
}

void MainWindow::actionScene()
{
    scene->action();
}
