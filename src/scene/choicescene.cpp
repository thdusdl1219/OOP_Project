#include "choicescene.h"
#include "Types.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
ChoiceScene::ChoiceScene(QObject *parent) :
    Scene(parent)
{
    go_button = NULL;
    for(int i = 0; i < 4; i++)
    {
        player_button[i] = NULL;
    }
    setupChoice();
}
ChoiceScene::~ChoiceScene()
{
    if(get_background() == NULL)
        delete get_background();
    delete go_button;
}

void ChoiceScene::action()
{

}

void ChoiceScene::setupChoice()
{
    Qneed* background = new Qneed(this, get_window());
    background->loadImage(":images/choice/choice_background.png");
    set_background(background);

    go_button = new GoButton(this, get_window());
    go_button->setPos(285,150);

    player_button[0] = new PlayerButton(this, get_window(), 0);
    player_button[0]->setPos(70, 100);
    player_button[1] = new PlayerButton(this, get_window(), 1);
    player_button[1]->setPos(70, 300);
    player_button[2] = new PlayerButton(this, get_window(), 2);
    player_button[2] ->setPos(800, 100);
    player_button[3] = new PlayerButton(this, get_window(), 3);
    player_button[3]->setPos(800, 300);


}

GoButton::GoButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene,window)
{
    qDebug() << "Go Button created";
    loadImage(":images/choice/choice_button_go.png");
}

void GoButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Go Button pressed";
}

void GoButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    get_window()->changeScene(SceneType::INGAME);
}

PlayerButton::PlayerButton(QGraphicsScene *scene, MainWindow *window, int player_num) : Qneed(scene, window)
{
    qDebug() << "Player button created";
    character_id = player_num;
    this->scene = dynamic_cast<ChoiceScene *>(scene);
    switch(player_num)
    {
        case 0:
            loadImage(":images/choice/choice_character0.png");
            break;
        case 1:
            loadImage(":images/choice/choice_character1.png");
            break;
        case 2:
            loadImage(":images/choice/choice_character2.png");
            break;
        case 3:
            loadImage(":images/choice/choice_character3.png");
            break;
    }
}

void PlayerButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Player" << character_id << "pressed";
    if(scene->player1_cnt > 1)
    {
                QMessageBox message_box;
        message_box.setStandardButtons(QMessageBox::Ok);
        message_box.setDefaultButton(QMessageBox::Ok);
        message_box.setText("");
        message_box.exec();
        return;
    }

}

void PlayerButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch(character_id)
    {
    case 0:
        loadImage(":images/choice/choice_character_clicked0.png");
        break;
    case 1:
        loadImage(":images/choice/choice_character_clicked1.png");
        break;
    case 2:
        loadImage(":images/choice/choice_character_clicked2.png");
        break;
    case 3:
        loadImage(":images/choice/choice_character_clicked3.png");
        break;

    }
}
