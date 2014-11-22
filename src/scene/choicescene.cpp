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
	player1_cnt = 0;
	player2_cnt = 0;
	map_cnt = 0;
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

	map_button[0] = new MapButton(this, get_window(), 0);
	map_button[0] ->setPos(70, 500);
	map_button[1] = new MapButton(this, get_window(), 1);
	map_button[1] ->setPos(300, 500);
	map_button[2] = new MapButton(this, get_window(), 2);
	map_button[2] ->setPos(570, 500);


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
}

void GoButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
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
			if(character_id < 2)
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
					scene->player1_cnt++;
					break;
				case 2:
				case 3:
					scene->player2_cnt++;
					break;
				}



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
	else
		{
			play = false;
			switch(character_id)
				{
				case 0:
				case 1:
					scene->player1_cnt--;
					break;
				case 2:
				case 3:
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
							break;
						case 1:
							loadImage(":images/choice/choice_map_clicked1.png");
							break;
						case 2:
							loadImage(":images/choice/choice_map_clicked2.png");
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

