#include "choicescene.h"
#include "../Types.h"
#include "../mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "../character.h"
ChoiceScene::ChoiceScene(QObject *parent) :
	Scene(parent)
{
    go_button = NULL;
    for(int i = 0; i < 6; i++)
    {
        player_button[i] = NULL;
    }
    for(int i = 0; i < 3; i++)
    {
        map_button[i] = NULL;
    }
    player1_cnt = 0;
    player2_cnt = 0;
    player1 = NULL;
    player2 = NULL;
    map_cnt = 0;
    map_kind = 0;
    scene = this;
    setupChoice();
}
ChoiceScene::~ChoiceScene()
{
	qDebug() << "choiceScene deleted";
	player1_cnt = 0;
    player2_cnt = 0;
    delete player1;
    delete player2;
    for(int i = 0; i < 6; i++)
        delete player_button[i];
    for(int i = 0; i < 3; i++)
        delete map_button[i];
	delete go_button;
}

ChoiceScene* ChoiceScene::scene = NULL;

ChoiceScene* ChoiceScene::get_ChoiceScene()
{
	return scene;
}


void ChoiceScene::setupChoice()
{
	Qneed* background = new Qneed(this, get_window());
	background->loadImage(":images/choice/choice_background.png");
	set_background(background);

	go_button = new GoButton(this, get_window());
    go_button->setPos(365,200);

	player_button[0] = new PlayerButton(this, get_window(), 0);
    player_button[0]->setPos(50, 100);
	player_button[1] = new PlayerButton(this, get_window(), 1);
    player_button[1]->setPos(50, 250);
	player_button[2] = new PlayerButton(this, get_window(), 2);
    player_button[2] ->setPos(50, 400);
	player_button[3] = new PlayerButton(this, get_window(), 3);
    player_button[3]->setPos(784, 100);
	player_button[4] = new PlayerButton(this, get_window(), 4);
    player_button[4]->setPos(784, 250);
	player_button[5] = new PlayerButton(this, get_window(), 5);
    player_button[5]->setPos(784, 400);

	map_button[0] = new MapButton(this, get_window(), 0);
    map_button[0] ->setPos(215, 550);
	map_button[1] = new MapButton(this, get_window(), 1);
    map_button[1] ->setPos(415, 550);
	map_button[2] = new MapButton(this, get_window(), 2);
    map_button[2] ->setPos(615, 550);


}

GoButton::GoButton(QGraphicsScene *scene, MainWindow *window) : Qneed(scene,window)
{
	qDebug() << "Go Button created";
    loadImage(":images/choice/choice_button_go.png");
	this->scene = dynamic_cast<ChoiceScene* >(scene);
}

void GoButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Go Button pressed";
    loadImage(":images/choice/choice_button_go_press.png");
}

void GoButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    loadImage(":images/choice/choice_button_go.png");
	QMessageBox message_box;
	if(scene->player1_cnt == 1 && scene->player2_cnt == 1)
		{
			if(scene->map_cnt == 1)
				get_window()->changeScene(SceneType::INGAME);
			else
				{
					message_box.setStandardButtons(QMessageBox::Ok);
					message_box.setDefaultButton(QMessageBox::Ok);
					message_box.setText("You must choose map!");
					message_box.exec();
					return;
				}

		}
	else
		{
			message_box.setStandardButtons(QMessageBox::Ok);
			message_box.setDefaultButton(QMessageBox::Ok);
			message_box.setText("You must choose character!");
			message_box.exec();
			return;
		}
}

PlayerButton::PlayerButton(QGraphicsScene *scene, MainWindow *window, int player_num) : Qneed(scene, window)
{
	qDebug() << "Player button created";
	character_id = player_num;
	play = false;
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
		case 4:
			loadImage(":images/choice/choice_character4.png");
			break;
		case 5:
			loadImage(":images/choice/choice_character5.png");
			break;
		}
}

void PlayerButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Player" << character_id << "pressed";

}

void PlayerButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Player" << character_id << "Released";
	if(!play)
		{
			QMessageBox message_box;
			if(character_id < 3)
				{
					if(scene->player1_cnt > 0)
						{
							message_box.setStandardButtons(QMessageBox::Ok);
							message_box.setDefaultButton(QMessageBox::Ok);
							message_box.setText("You can choose just 1 character");
							message_box.exec();
							return;
						}
				}
			else
				{
					if(scene->player2_cnt > 0)
						{
							message_box.setStandardButtons(QMessageBox::Ok);
							message_box.setDefaultButton(QMessageBox::Ok);
							message_box.setText("You can choose just 1 character");
							message_box.exec();
							return;
						}
				}
			play = true;
			switch(character_id)
				{
				case 0:
				case 1:
				case 2:
					scene->player1_cnt++;
					break;
				case 3:
				case 4:
				case 5:
					scene->player2_cnt++;
					break;
				}



			switch(character_id)
				{
				case 0:
					loadImage(":images/choice/choice_character_clicked0.png");
                    scene->player1 = new Character(NULL, CharacterType::LIAR, 1, 1, 2, Team::POSTECH);
					break;
				case 1:
					loadImage(":images/choice/choice_character_clicked1.png");
					scene->player1 = new Character(NULL, CharacterType::RICH, 1, 2, 1, Team::POSTECH);
					break;
				case 2:
					loadImage(":images/choice/choice_character_clicked2.png");
					scene->player1 = new Character(NULL, CharacterType::ALCHOHOLIC, 2, 1, 1, Team::POSTECH);
					break;
				case 3:
					loadImage(":images/choice/choice_character_clicked3.png");
					scene->player2 = new Character(NULL, CharacterType::LIAR, 1, 1, 2, Team::KAIST);
					break;
				case 4:
					loadImage(":images/choice/choice_character_clicked4.png");
					scene->player2 = new Character(NULL, CharacterType::RICH, 1, 2, 1, Team::KAIST);
					break;
				case 5:
					loadImage(":images/choice/choice_character_clicked5.png");
					scene->player2 = new Character(NULL, CharacterType::ALCHOHOLIC, 2, 1, 1, Team::KAIST);
					break;
				}
		}
	else
		{
			play = false;
			switch(character_id)
				{
				case 0:
				case 1:
				case 2:
					delete scene->player1;
					scene->player1 = NULL;
					scene->player1_cnt--;
					break;
				case 3:
				case 4:
				case 5:
					delete scene->player2;
					scene->player2 = NULL;
					scene->player2_cnt--;
					break;
				}
			switch(character_id)
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
				case 4:
					loadImage(":images/choice/choice_character4.png");
					break;
				case 5:
					loadImage(":images/choice/choice_character5.png");
					break;
				}

		}
}

MapButton::MapButton(QGraphicsScene *scene, MainWindow *window, int map_num) : Qneed(scene, window)
{
	map_id = map_num;
	choice = false;
	this->scene = dynamic_cast<ChoiceScene*>(scene);
	switch(map_num)
		{
		case 0:
			loadImage(":images/choice/choice_map0.png");
			break;
		case 1:
			loadImage(":images/choice/choice_map1.png");
			break;
		case 2:
			loadImage(":images/choice/choice_map2.png");
			break;
		}
}

void MapButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Map" << map_id << "pressed";
}

void MapButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Map" << map_id << "Released";
	if(!choice)
		{
			if(scene->map_cnt > 0)
				{
					QMessageBox message_box;
					message_box.setStandardButtons(QMessageBox::Ok);
					message_box.setDefaultButton(QMessageBox::Ok);
					message_box.setText("You can choose just 1 map");
					message_box.exec();
					return;
				}
			else
				{
					scene->map_cnt++;
					choice = true;
					switch(map_id)
						{
						case 0:
							loadImage(":images/choice/choice_map_clicked0.png");
							scene->map_kind = 1;
							break;
						case 1:
							loadImage(":images/choice/choice_map_clicked1.png");
							scene->map_kind = 2;
							break;
						case 2:
							loadImage(":images/choice/choice_map_clicked2.png");
							scene->map_kind = 3;
							break;
						}
				}
		}
	else
		{
			choice = false;
			scene->map_cnt--;
			switch(map_id)
				{
				case 0:
					loadImage(":images/choice/choice_map0.png");
					break;
				case 1:
					loadImage(":images/choice/choice_map1.png");
					break;
				case 2:
					loadImage(":images/choice/choice_map2.png");
					break;
				}
		}
}

