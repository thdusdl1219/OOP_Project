#include "map.h"
QPoint cell_xy[(13*3-2)*(10*3)];

Map::Map(QGraphicsScene* scene, MainWindow* window, int map_kind) : Qneed(scene, window)
{
  loadImage(":images/ingame/map/map_background.png");
  map_xyInit();
  map = this;
  this->scene = scene;
  this->window = window;

  switch(map_kind)
    {
      case 1:
        mapInit1();
        break;
      case 2:
        mapInit2();
        break;
      case 3:
        mapInit3();
        break;
    }
}

Map* Map::map = NULL;

Map* Map::get_map()
{
  return map;
}

void Map::mapInit1()
{
    cell[	0	][	0	]=new	Unit	(this,	0	,	0	);
    cell[	0	][	1	]=new	Unit	(this,	0	,	1	);
    cell[	0	][	2	]=new	Block	(this,	0	,	2	,	true,	true);
    cell[	0	][	3	]=new	Block	(this,	0	,	3	,	true,	false);
    cell[	0	][	4	]=new	Block	(this,	0	,	4	,	true,	false);
    cell[	0	][	5	]=new	Block	(this,	0	,	5	,	true,	true);
    cell[	0	][	6	]=new	Unit	(this,	0	,	6	);
    cell[	0	][	7	]=new	Unit	(this,	0	,	7	);
    cell[	0	][	8	]=new	Block	(this,	0	,	8	,	true,	false);
    cell[	0	][	9	]=new	Block	(this,	0	,	9	,	true,	true);
    cell[	0	][	10	]=new	Block	(this,	0	,	10	,	true,	false);
    cell[	0	][	11	]=new	Unit	(this,	0	,	11	);
    cell[	0	][	12	]=new	Unit	(this,	0	,	12	);
    cell[	1	][	0	]=new	Unit	(this,	1	,	0	);
    cell[	1	][	1	]=new	Block	(this,	1	,	1	,	false,	false);
    cell[	1	][	2	]=new	Block	(this,	1	,	2	,	true,	true);
    cell[	1	][	3	]=new	Block	(this,	1	,	3	,	false,	false);
    cell[	1	][	4	]=new	Block	(this,	1	,	4	,	true,	false);
    cell[	1	][	5	]=new	Block	(this,	1	,	5	,	false,	true);
    cell[	1	][	6	]=new	Block	(this,	1	,	6	,	true,	false);
    cell[	1	][	7	]=new	Unit	(this,	1	,	7	);
    cell[	1	][	8	]=new	Block	(this,	1	,	8	,	false,	false);
    cell[	1	][	9	]=new	Block	(this,	1	,	9	,	true,	true);
    cell[	1	][	10	]=new	Block	(this,	1	,	10	,	false,	false);
    cell[	1	][	11	]=new	Block	(this,	1	,	11	,	true,	true);
    cell[	1	][	12	]=new	Unit	(this,	1	,	12	);
    cell[	2	][	0	]=new	Block	(this,	2	,	0	,	true,	false);
    cell[	2	][	1	]=new	Block	(this,	2	,	1	,	true,	true);
    cell[	2	][	2	]=new	Block	(this,	2	,	2	,	true,	false);
    cell[	2	][	3	]=new	Block	(this,	2	,	3	,	true,	true);
    cell[	2	][	4	]=new	Block	(this,	2	,	4	,	true,	true);
    cell[	2	][	5	]=new	Block	(this,	2	,	5	,	true,	false);
    cell[	2	][	6	]=new	Block	(this,	2	,	6	,	true,	true);
    cell[	2	][	7	]=new	Block	(this,	2	,	7	,	true,	false);
    cell[	2	][	8	]=new	Block	(this,	2	,	8	,	true,	true);
    cell[	2	][	9	]=new	Block	(this,	2	,	9	,	true,	false);
    cell[	2	][	10	]=new	Block	(this,	2	,	10	,	true,	false);
    cell[	2	][	11	]=new	Block	(this,	2	,	11	,	true,	false);
    cell[	2	][	12	]=new	Block	(this,	2	,	12	,	true,	false);
    cell[	3	][	0	]=new	Block	(this,	3	,	0	,	true,	true);
    cell[	3	][	1	]=new	Block	(this,	3	,	1	,	false,	false);
    cell[	3	][	2	]=new	Block	(this,	3	,	2	,	true,	false);
    cell[	3	][	3	]=new	Block	(this,	3	,	3	,	false,	true);
    cell[	3	][	4	]=new	Block	(this,	3	,	4	,	false,	false);
    cell[	3	][	5	]=new	Unit	(this,	3	,	5	);
    cell[	3	][	6	]=new	Block	(this,	3	,	6	,	false,	false);
    cell[	3	][	7	]=new	Block	(this,	3	,	7	,	false,	false);
    cell[	3	][	8	]=new	Block	(this,	3	,	8	,	false,	true);
    cell[	3	][	9	]=new	Block	(this,	3	,	9	,	false,	false);
    cell[	3	][	10	]=new	Block	(this,	3	,	10	,	true,	true);
    cell[	3	][	11	]=new	Block	(this,	3	,	11	,	false,	false);
    cell[	3	][	12	]=new	Block	(this,	3	,	12	,	true,	false);
    cell[	4	][	0	]=new	Unit	(this,	4	,	0	);
    cell[	4	][	1	]=new	Unit	(this,	4	,	1	);
    cell[	4	][	2	]=new	Block	(this,	4	,	2	,	true,	true);
    cell[	4	][	3	]=new	Block	(this,	4	,	3	,	false,	true);
    cell[	4	][	4	]=new	Block	(this,	4	,	4	,	true,	false);
    cell[	4	][	5	]=new	Unit	(this,	4	,	5	);
    cell[	4	][	6	]=new	Unit	(this,	4	,	6	);
    cell[	4	][	7	]=new	Unit	(this,	4	,	7	);
    cell[	4	][	8	]=new	Unit	(this,	4	,	8	);
    cell[	4	][	9	]=new	Block	(this,	4	,	9	,	false,	false);
    cell[	4	][	10	]=new	Block	(this,	4	,	10	,	true,	false);
    cell[	4	][	11	]=new	Block	(this,	4	,	11	,	true,	true);
    cell[	4	][	12	]=new	Unit	(this,	4	,	12	);
    cell[	5	][	0	]=new	Unit	(this,	5	,	0	);
    cell[	5	][	1	]=new	Block	(this,	5	,	1	,	true,	false);
    cell[	5	][	2	]=new	Block	(this,	5	,	2	,	true,	true);
    cell[	5	][	3	]=new	Block	(this,	5	,	3	,	false,	false);
    cell[	5	][	4	]=new	Unit	(this,	5	,	4	);
    cell[	5	][	5	]=new	Unit	(this,	5	,	5	);
    cell[	5	][	6	]=new	Unit	(this,	5	,	6	);
    cell[	5	][	7	]=new	Unit	(this,	5	,	7	);
    cell[	5	][	8	]=new	Block	(this,	5	,	8	,	true,	false);
    cell[	5	][	9	]=new	Block	(this,	5	,	9	,	false,	false);
    cell[	5	][	10	]=new	Block	(this,	5	,	10	,	true,	false);
    cell[	5	][	11	]=new	Unit	(this,	5	,	11	);
    cell[	5	][	12	]=new	Unit	(this,	5	,	12	);
    cell[	6	][	0	]=new	Block	(this,	6	,	0	,	true,	false);
    cell[	6	][	1	]=new	Block	(this,	6	,	1	,	false,	false);
    cell[	6	][	2	]=new	Block	(this,	6	,	2	,	true,	true);
    cell[	6	][	3	]=new	Block	(this,	6	,	3	,	false,	false);
    cell[	6	][	4	]=new	Block	(this,	6	,	4	,	false,	true);
    cell[	6	][	5	]=new	Block	(this,	6	,	5	,	false,	false);
    cell[	6	][	6	]=new	Block	(this,	6	,	6	,	false,	true);
    cell[	6	][	7	]=new	Unit	(this,	6	,	7	);
    cell[	6	][	8	]=new	Block	(this,	6	,	8	,	false,	false);
    cell[	6	][	9	]=new	Block	(this,	6	,	9	,	false,	true);
    cell[	6	][	10	]=new	Block	(this,	6	,	10	,	true,	false);
    cell[	6	][	11	]=new	Block	(this,	6	,	11	,	false,	true);
    cell[	6	][	12	]=new	Block	(this,	6	,	12	,	true,	false);
    cell[	7	][	0	]=new	Block	(this,	7	,	0	,	true,	false);
    cell[	7	][	1	]=new	Block	(this,	7	,	1	,	true,	false);
    cell[	7	][	2	]=new	Block	(this,	7	,	2	,	true,	true);
    cell[	7	][	3	]=new	Block	(this,	7	,	3	,	true,	true);
    cell[	7	][	4	]=new	Block	(this,	7	,	4	,	true,	true);
    cell[	7	][	5	]=new	Block	(this,	7	,	5	,	true,	false);
    cell[	7	][	6	]=new	Block	(this,	7	,	6	,	true,	true);
    cell[	7	][	7	]=new	Block	(this,	7	,	7	,	true,	false);
    cell[	7	][	8	]=new	Block	(this,	7	,	8	,	true,	false);
    cell[	7	][	9	]=new	Block	(this,	7	,	9	,	true,	true);
    cell[	7	][	10	]=new	Block	(this,	7	,	10	,	true,	true);
    cell[	7	][	11	]=new	Block	(this,	7	,	11	,	true,	false);
    cell[	7	][	12	]=new	Block	(this,	7	,	12	,	true,	true);
    cell[	8	][	0	]=new	Unit	(this,	8	,	0	);
    cell[	8	][	1	]=new	Block	(this,	8	,	1	,	false,	false);
    cell[	8	][	2	]=new	Block	(this,	8	,	2	,	true,	false);
    cell[	8	][	3	]=new	Block	(this,	8	,	3	,	false,	true);
    cell[	8	][	4	]=new	Block	(this,	8	,	4	,	true,	false);
    cell[	8	][	5	]=new	Block	(this,	8	,	5	,	false,	true);
    cell[	8	][	6	]=new	Unit	(this,	8	,	6	);
    cell[	8	][	7	]=new	Block	(this,	8	,	7	,	false,	false);
    cell[	8	][	8	]=new	Block	(this,	8	,	8	,	true,	false);
    cell[	8	][	9	]=new	Block	(this,	8	,	9	,	false,	true);
    cell[	8	][	10	]=new	Block	(this,	8	,	10	,	true,	false);
    cell[	8	][	11	]=new	Block	(this,	8	,	11	,	false,	true);
    cell[	8	][	12	]=new	Unit	(this,	8	,	12	);
    cell[	9	][	0	]=new	Unit	(this,	9	,	0	);
    cell[	9	][	1	]=new	Unit	(this,	9	,	1	);
    cell[	9	][	2	]=new	Block	(this,	9	,	2	,	true,	true);
    cell[	9	][	3	]=new	Block	(this,	9	,	3	,	true,	true);
    cell[	9	][	4	]=new	Block	(this,	9	,	4	,	true,	false);
    cell[	9	][	5	]=new	Block	(this,	9	,	5	,	true,	true);
    cell[	9	][	6	]=new	Unit	(this,	9	,	6	);
    cell[	9	][	7	]=new	Unit	(this,	9	,	7	);
    cell[	9	][	8	]=new	Block	(this,	9	,	8	,	true,	false);
    cell[	9	][	9	]=new	Block	(this,	9	,	9	,	true,	true);
    cell[	9	][	10	]=new	Block	(this,	9	,	10	,	true,	false);
    cell[	9	][	11	]=new	Unit	(this,	9	,	11	);
    cell[	9	][	12	]=new	Unit	(this,	9	,	12	);


  player1 = ChoiceScene::get_ChoiceScene()->player1;
  player1 -> setParent(this);
  player1 -> setNeed(this);
  dynamic_cast<Character*>(player1)->setPosition(0);
  player2 = ChoiceScene::get_ChoiceScene()->player2;
  player2 -> setParent(this);
  player2	-> setNeed(this);
  dynamic_cast<Character*>(player2)->setPosition(9*(13*3-2)*3+3*12);

}

void Map::mapInit2()
{
    cell[	0	][	0	]=new	Unit	(this,	0	,	0	);
    cell[	0	][	1	]=new	Unit	(this,	0	,	1	);
    cell[	0	][	2	]=new	Block	(this,	0	,	2	,	true,	false);
    cell[	0	][	3	]=new	Block	(this,	0	,	3	,	true,	true);
    cell[	0	][	4	]=new	Block	(this,	0	,	4	,	true,	false);
    cell[	0	][	5	]=new	Block	(this,	0	,	5	,	true,	true);
    cell[	0	][	6	]=new	Block	(this,	0	,	6   ,	true,	true);
    cell[	0	][	7	]=new	Block	(this,	0	,	7   ,	true,	false);
    cell[	0	][	8	]=new	Block	(this,	0	,	8	,	true,	false);
    cell[	0	][	9	]=new	Block	(this,	0	,	9	,	true,	true);
    cell[	0	][	10	]=new	Block	(this,	0	,	10	,	true,	true);
    cell[	0	][	11	]=new	Unit	(this,	0	,	11	);
    cell[	0	][	12	]=new	Unit	(this,	0	,	12	);
    cell[	1	][	0	]=new	Unit	(this,	1	,	0	);
    cell[	1	][	1	]=new	Block	(this,	1	,	1	,	false,	true);
    cell[	1	][	2	]=new	Block	(this,	1	,	2	,	false,	false);
    cell[	1	][	3	]=new	Block	(this,	1	,	3	,	false,	true);
    cell[	1	][	4	]=new	Block	(this,	1	,	4	,	true,	false);
    cell[	1	][	5	]=new	Block	(this,	1	,	5	,	false,	true);
    cell[	1	][	6	]=new	Block	(this,	1	,	6	,	false,	false);
    cell[	1	][	7	]=new	Block	(this,	1	,	7	,	false,	false);
    cell[	1	][	8	]=new	Block	(this,	1	,	8	,	true,	true);
    cell[	1	][	9	]=new	Block	(this,	1	,	9	,	false,	true);
    cell[	1	][	10	]=new	Block	(this,	1	,	10	,	false,	false);
    cell[	1	][	11	]=new	Block	(this,	1	,	11	,	false,	true);
    cell[	1	][	12	]=new	Unit	(this,	1	,	12	);
    cell[	2	][	0	]=new	Block	(this,	2	,	0	,	true,	false);
    cell[	2	][	1	]=new	Block	(this,	2	,	1	,	false,	false);
    cell[	2	][	2	]=new	Block	(this,	2	,	2	,	true,	true);
    cell[	2	][	3	]=new	Block	(this,	2	,	3	,	false,	false);
    cell[	2	][	4	]=new	Block	(this,	2	,	4	,	true,	false);
    cell[	2	][	5	]=new	Block	(this,	2	,	5	,	false,	false);
    cell[	2	][	6	]=new	Block	(this,	2	,	6	,	true,	true);
    cell[	2	][	7	]=new	Block	(this,	2	,	7	,	false,	false);
    cell[	2	][	8	]=new	Block	(this,	2	,	8	,	true,	false);
    cell[	2	][	9	]=new	Block	(this,	2	,	9	,	false,	true);
    cell[	2	][	10	]=new	Block	(this,	2	,	10	,	true,	true);
    cell[	2	][	11	]=new	Block	(this,	2	,	11	,	false,	false);
    cell[	2	][	12	]=new	Block	(this,	2	,	12	,	true,	false);
    cell[	3	][	0	]=new	Block	(this,	3	,	0	,	true,	true);
    cell[	3	][	1	]=new	Block	(this,	3	,	1	,	false,	false);
    cell[	3	][	2	]=new	Block	(this,	3	,	2	,	true,	false);
    cell[	3	][	3	]=new	Block	(this,	3	,	3	,	true,	false);
    cell[	3	][	4	]=new	Block	(this,	3	,	4	,	true,	true);
    cell[	3	][	5	]=new	Block	(this,	3	,	5	,	true,	true);
    cell[	3	][	6	]=new	Block	(this,	3	,	6	,	true,	true);
    cell[	3	][	7	]=new	Block	(this,	3	,	7	,	true,	false);
    cell[	3	][	8	]=new	Block	(this,	3	,	8	,	true,	true);
    cell[	3	][	9	]=new	Block	(this,	3	,	9	,	true,	false);
    cell[	3	][	10	]=new	Block	(this,	3	,	10	,	true,	true);
    cell[	3	][	11	]=new	Block	(this,	3	,	11	,	false,	false);
    cell[	3	][	12	]=new	Block	(this,	3	,	12	,	true,	true);
    cell[	4	][	0	]=new	Block	(this,	4	,	0	,	true,	false);
    cell[	4	][	1	]=new	Block	(this,	4	,	1	,	true,	false);
    cell[	4	][	2	]=new	Block	(this,	4	,	2	,	true,	true);
    cell[	4	][	3	]=new	Block	(this,	4	,	3	,	false,	true);
    cell[	4	][	4	]=new	Block	(this,	4	,	4	,	true,	false);
    cell[	4	][	5	]=new	Block	(this,	4	,	5   ,	true,	false);
    cell[	4	][	6	]=new	Block	(this,	4	,	6	,	false,	false);
    cell[	4	][	7	]=new	Block	(this,	4	,	7	,	true,	true);
    cell[	4	][	8	]=new	Block	(this,	4	,	8	,	true,	true);
    cell[	4	][	9	]=new	Block	(this,	4	,	9	,	false,	false);
    cell[	4	][	10	]=new	Block	(this,	4	,	10	,	true,	false);
    cell[	4	][	11	]=new	Block	(this,	4	,	11	,	true,	false);
    cell[	4	][	12	]=new	Block	(this,	4	,	12	,	true,	true);
    cell[	5	][	0	]=new	Block	(this,	5	,	0	,	true,	true);
    cell[	5	][	1	]=new	Block	(this,	5	,	1	,	true,	false);
    cell[	5	][	2	]=new	Block	(this,	5	,	2	,	true,	true);
    cell[	5	][	3	]=new	Block	(this,	5	,	3	,	false,	true);
    cell[	5	][	4	]=new	Block	(this,	5	,	4	,	true,	false);
    cell[	5	][	5	]=new	Block	(this,	5	,	5	,	true,	false);
    cell[	5	][	6	]=new	Block	(this,	5	,	6	,	false,	false);
    cell[	5	][	7	]=new	Block	(this,	5	,	7	,	true,	false);
    cell[	5	][	8	]=new	Block	(this,	5	,	8	,	true,	false);
    cell[	5	][	9	]=new	Block	(this,	5	,	9	,	false,	true);
    cell[	5	][	10	]=new	Block	(this,	5	,	10	,	true,	true);
    cell[	5	][	11	]=new	Block	(this,	5	,	11	,	true,	false);
    cell[	5	][	12	]=new	Block	(this,	5	,	12	,	true,	true);
    cell[	6	][	0	]=new	Block	(this,	6	,	0	,	true,	false);
    cell[	6	][	1	]=new	Block	(this,	6	,	1	,	false,	false);
    cell[	6	][	2	]=new	Block	(this,	6	,	2	,	true,	true);
    cell[	6	][	3	]=new	Block	(this,	6	,	3	,	true,	false);
    cell[	6	][	4	]=new	Block	(this,	6	,	4	,	true,	false);
    cell[	6	][	5	]=new	Block	(this,	6	,	5	,	true,	false);
    cell[	6	][	6	]=new	Block	(this,	6	,	6	,	true,	true);
    cell[	6	][	7	]=new	Block	(this,	6	,	7	,	true,	true);
    cell[	6	][	8	]=new	Block	(this,	6	,	8	,	true,	false);
    cell[	6	][	9	]=new	Block	(this,	6	,	9	,	true,	true);
    cell[	6	][	10	]=new	Block	(this,	6	,	10	,	true,	false);
    cell[	6	][	11	]=new	Block	(this,	6	,	11	,	false,	false);
    cell[	6	][	12	]=new	Block	(this,	6	,	12	,	true,	false);
    cell[	7	][	0	]=new	Block	(this,	7	,	0	,	true,	false);
    cell[	7	][	1	]=new	Block	(this,	7	,	1	,	false,	true);
    cell[	7	][	2	]=new	Block	(this,	7	,	2	,	true,	false);
    cell[	7	][	3	]=new	Block	(this,	7	,	3	,	false,	true);
    cell[	7	][	4	]=new	Block	(this,	7	,	4	,	true,	false);
    cell[	7	][	5	]=new	Block	(this,	7	,	5	,	false,	false);
    cell[	7	][	6	]=new	Block	(this,	7	,	6	,	true,	false);
    cell[	7	][	7	]=new	Block	(this,	7	,	7	,	false,	true);
    cell[	7	][	8	]=new	Block	(this,	7	,	8	,	true,	false);
    cell[	7	][	9	]=new	Block	(this,	7	,	9	,	false,	true);
    cell[	7	][	10	]=new	Block	(this,	7	,	10	,	true,	true);
    cell[	7	][	11	]=new	Block	(this,	7	,	11	,	false,	false);
    cell[	7	][	12	]=new	Block	(this,	7	,	12	,	true,	false);
    cell[	8	][	0	]=new	Unit	(this,	8	,	0	);
    cell[	8	][	1	]=new	Block	(this,	8	,	1	,	false,	true);
    cell[	8	][	2	]=new	Block	(this,	8	,	2	,	false,	false);
    cell[	8	][	3	]=new	Block	(this,	8	,	3	,	false,	true);
    cell[	8	][	4	]=new	Block	(this,	8	,	4	,	true,	true);
    cell[	8	][	5	]=new	Block	(this,	8	,	5	,	false,	false);
    cell[	8	][	6	]=new	Block	(this,	8	,	6	,	false,	true);
    cell[	8	][	7	]=new	Block	(this,	8	,	7	,	false,	false);
    cell[	8	][	8	]=new	Block	(this,	8	,	8	,	true,	true);
    cell[	8	][	9	]=new	Block	(this,	8	,	9	,	false,	false);
    cell[	8	][	10	]=new	Block	(this,	8	,	10	,	false,	false);
    cell[	8	][	11	]=new	Block	(this,	8	,	11	,	false,	false);
    cell[	8	][	12	]=new	Unit	(this,	8	,	12	);
    cell[	9	][	0	]=new	Unit	(this,	9	,	0	);
    cell[	9	][	1	]=new	Unit	(this,	9	,	1	);
    cell[	9	][	2	]=new	Block	(this,	9	,	2	,	true,	false);
    cell[	9	][	3	]=new	Block	(this,	9	,	3	,	true,	true);
    cell[	9	][	4	]=new	Block	(this,	9	,	4	,	true,	true);
    cell[	9	][	5	]=new	Block	(this,	9	,	5	,	true,	false);
    cell[	9	][	6	]=new	Block	(this,	9	,	6	,	true,	false);
    cell[	9	][	7	]=new	Block	(this,	9	,	7	,	true,	false);
    cell[	9	][	8	]=new	Block	(this,	9	,	8	,	true,	true);
    cell[	9	][	9	]=new	Block	(this,	9	,	9	,	true,	false);
    cell[	9	][	10	]=new	Block	(this,	9	,	10	,	true,	true);
    cell[	9	][	11	]=new	Unit	(this,	9	,	11	);
    cell[	9	][	12	]=new	Unit	(this,	9	,	12	);


    player1 = ChoiceScene::get_ChoiceScene()->player1;
    player1 -> setParent(this);
    player1 -> setNeed(this);
    dynamic_cast<Character*>(player1)->setPosition(0);
    player2 = ChoiceScene::get_ChoiceScene()->player2;
    player2 -> setParent(this);
    player2	-> setNeed(this);
    dynamic_cast<Character*>(player2)->setPosition(9*(13*3-2)*3+3*12);

}

void Map::mapInit3()
{
    cell[	0	][	0	]=new	Unit	(this,	0	,	0	);
    cell[	0	][	1	]=new	Unit	(this,	0	,	1	);
    cell[	0	][	2	]=new	Block	(this,	0	,	2	,	true,	true);
    cell[	0	][	3	]=new	Block	(this,	0	,	3	,	true,	false);
    cell[	0	][	4	]=new	Block	(this,	0	,	4	,	false,	false);
    cell[	0	][	5	]=new	Block	(this,	0	,	5	,	true,	true);
    cell[	0	][	6	]=new	Block	(this,	0	,	6	,	true,	false);
    cell[	0	][	7	]=new	Block	(this,	0	,	7	,	true,	false);
    cell[	0	][	8	]=new	Block	(this,	0	,	8	,	false,	false);
    cell[	0	][	9	]=new	Block	(this,	0	,	9	,	true,	false);
    cell[	0	][	10	]=new	Block	(this,	0	,	10	,	true,	true);
    cell[	0	][	11	]=new	Unit	(this,	0	,	11	);
    cell[	0	][	12	]=new	Unit	(this,	0	,	12	);
    cell[	1	][	0	]=new	Unit	(this,	1	,	0	);
    cell[	1	][	1	]=new	Block	(this,	1	,	1	,	true,	true);
    cell[	1	][	2	]=new	Block	(this,	1	,	2	,	false,	false);
    cell[	1	][	3	]=new	Block	(this,	1	,	3	,	true,	true);
    cell[	1	][	4	]=new	Block	(this,	1	,	4	,	false,	false);
    cell[	1	][	5	]=new	Block	(this,	1	,	5	,	true,	false);
    cell[	1	][	6	]=new	Block	(this,	1	,	6	,	true,	false);
    cell[	1	][	7	]=new	Block	(this,	1	,	7	,	true,	false);
    cell[	1	][	8	]=new	Block	(this,	1	,	8	,	false,	true);
    cell[	1	][	9	]=new	Block	(this,	1	,	9	,	true,	false);
    cell[	1	][	10	]=new	Block	(this,	1	,	10	,	false,	true);
    cell[	1	][	11	]=new	Block	(this,	1	,	11	,	true,	true);
    cell[	1	][	12	]=new	Block	(this,	1	,	12	,	true,	false);
    cell[	2	][	0	]=new	Block	(this,	2	,	0	,	true,	true);
    cell[	2	][	1	]=new	Block	(this,	2	,	1	,	true,	false);
    cell[	2	][	2	]=new	Block	(this,	2	,	2	,	true,	false);
    cell[	2	][	3	]=new	Block	(this,	2	,	3	,	true,	false);
    cell[	2	][	4	]=new	Block	(this,	2	,	4	,	false,	true);
    cell[	2	][	5	]=new	Block	(this,	2	,	5	,	true,	true);
    cell[	2	][	6	]=new	Block	(this,	2	,	6	,	true,	false);
    cell[	2	][	7	]=new	Block	(this,	2	,	7	,	true,	false);
    cell[	2	][	8	]=new	Block	(this,	2	,	8	,	false,	false);
    cell[	2	][	9	]=new	Block	(this,	2	,	9	,	true,	true);
    cell[	2	][	10	]=new	Block	(this,	2	,	10	,	true,	false);
    cell[	2	][	11	]=new	Block	(this,	2	,	11	,	true,	false);
    cell[	2	][	12	]=new	Block	(this,	2	,	12	,	true,	true);
    cell[	3	][	0	]=new	Block	(this,	3	,	0	,	false,	false);
    cell[	3	][	1	]=new	Block	(this,	3	,	1	,	true,	false);
    cell[	3	][	2	]=new	Block	(this,	3	,	2	,	false,	true);
    cell[	3	][	3	]=new	Block	(this,	3	,	3	,	true,	false);
    cell[	3	][	4	]=new	Block	(this,	3	,	4	,	true,	true);
    cell[	3	][	5	]=new	Block	(this,	3	,	5	,	true,	false);
    cell[	3	][	6	]=new	Block	(this,	3	,	6	,	true,	false);
    cell[	3	][	7	]=new	Block	(this,	3	,	7	,	true,	true);
    cell[	3	][	8	]=new	Block	(this,	3	,	8	,	true,	false);
    cell[	3	][	9	]=new	Block	(this,	3	,	9	,	true,	true);
    cell[	3	][	10	]=new	Block	(this,	3	,	10	,	false,	false);
    cell[	3	][	11	]=new	Block	(this,	3	,	11	,	true,	false);
    cell[	3	][	12	]=new	Block	(this,	3	,	12	,	false,	true);
    cell[	4	][	0	]=new	Block	(this,	4	,	0	,	false,	false);
    cell[	4	][	1	]=new	Block	(this,	4	,	1	,	false,	false);
    cell[	4	][	2	]=new	Block	(this,	4	,	2	,	false,	false);
    cell[	4	][	3	]=new	Block	(this,	4	,	3	,	false,	true);
    cell[	4	][	4	]=new	Block	(this,	4	,	4	,	false,	true);
    cell[	4	][	5	]=new	Block	(this,	4	,	5	,	true,	true);
    cell[	4	][	6	]=new	Block	(this,	4	,	6	,	true,	false);
    cell[	4	][	7	]=new	Block	(this,	4	,	7	,	true,	false);
    cell[	4	][	8	]=new	Block	(this,	4	,	8	,	false,	false);
    cell[	4	][	9	]=new	Block	(this,	4	,	9	,	false,	true);
    cell[	4	][	10	]=new	Block	(this,	4	,	10	,	false,	false);
    cell[	4	][	11	]=new	Block	(this,	4	,	11	,	false,	false);
    cell[	4	][	12	]=new	Block	(this,	4	,	12	,	false,	true);
    cell[	5	][	0	]=new	Block	(this,	5	,	0	,	false,	true);
    cell[	5	][	1	]=new	Block	(this,	5	,	1	,	false,	false);
    cell[	5	][	2	]=new	Block	(this,	5	,	2	,	false,	true);
    cell[	5	][	3	]=new	Block	(this,	5	,	3	,	false,	true);
    cell[	5	][	4	]=new	Block	(this,	5	,	4	,	false,	false);
    cell[	5	][	5	]=new	Block	(this,	5	,	5	,	true,	false);
    cell[	5	][	6	]=new	Block	(this,	5	,	6	,	true,	true);
    cell[	5	][	7	]=new	Block	(this,	5	,	7	,	true,	false);
    cell[	5	][	8	]=new	Block	(this,	5	,	8	,	false,	true);
    cell[	5	][	9	]=new	Block	(this,	5	,	9	,	false,	false);
    cell[	5	][	10	]=new	Block	(this,	5	,	10	,	false,	false);
    cell[	5	][	11	]=new	Block	(this,	5	,	11	,	false,	false);
    cell[	5	][	12	]=new	Block	(this,	5	,	12	,	false,	true);
    cell[	6	][	0	]=new	Block	(this,	6	,	0	,	false,	true);
    cell[	6	][	1	]=new	Block	(this,	6	,	1	,	true,	false);
    cell[	6	][	2	]=new	Block	(this,	6	,	2	,	false,	false);
    cell[	6	][	3	]=new	Block	(this,	6	,	3	,	true,	true);
    cell[	6	][	4	]=new	Block	(this,	6	,	4	,	true,	true);
    cell[	6	][	5	]=new	Block	(this,	6	,	5	,	true,	true);
    cell[	6	][	6	]=new	Block	(this,	6	,	6	,	true,	false);
    cell[	6	][	7	]=new	Block	(this,	6	,	7	,	true,	false);
    cell[	6	][	8	]=new	Block	(this,	6	,	8	,	true,	true);
    cell[	6	][	9	]=new	Block	(this,	6	,	9	,	true,	false);
    cell[	6	][	10	]=new	Block	(this,	6	,	10	,	false,	false);
    cell[	6	][	11	]=new	Block	(this,	6	,	11	,	true,	false);
    cell[	6	][	12	]=new	Block	(this,	6	,	12	,	false,	true);
    cell[	7	][	0	]=new	Block	(this,	7	,	0	,	true,	true);
    cell[	7	][	1	]=new	Block	(this,	7	,	1	,	true,	false);
    cell[	7	][	2	]=new	Block	(this,	7	,	2	,	true,	false);
    cell[	7	][	3	]=new	Block	(this,	7	,	3	,	true,	true);
    cell[	7	][	4	]=new	Block	(this,	7	,	4	,	false,	false);
    cell[	7	][	5	]=new	Block	(this,	7	,	5	,	true,	false);
    cell[	7	][	6	]=new	Block	(this,	7	,	6	,	true,	false);
    cell[	7	][	7	]=new	Block	(this,	7	,	7	,	true,	true);
    cell[	7	][	8	]=new	Block	(this,	7	,	8	,	false,	false);
    cell[	7	][	9	]=new	Block	(this,	7	,	9	,	true,	true);
    cell[	7	][	10	]=new	Block	(this,	7	,	10	,	true,	false);
    cell[	7	][	11	]=new	Block	(this,	7	,	11	,	true,	true);
    cell[	7	][	12	]=new	Block	(this,	7	,	12	,	true,	false);
    cell[	8	][	0	]=new	Unit	(this,	8	,	0	);
    cell[	8	][	1	]=new	Block	(this,	8	,	1	,	true,	true);
    cell[	8	][	2	]=new	Block	(this,	8	,	2	,	false,	false);
    cell[	8	][	3	]=new	Block	(this,	8	,	3	,	true,	true);
    cell[	8	][	4	]=new	Block	(this,	8	,	4	,	false,	false);
    cell[	8	][	5	]=new	Block	(this,	8	,	5	,	true,	true);
    cell[	8	][	6	]=new	Block	(this,	8	,	6	,	true,	true);
    cell[	8	][	7	]=new	Block	(this,	8	,	7	,	true,	false);
    cell[	8	][	8	]=new	Block	(this,	8	,	8	,	false,	false);
    cell[	8	][	9	]=new	Block	(this,	8	,	9	,	true,	true);
    cell[	8	][	10	]=new	Block	(this,	8	,	10	,	false,	false);
    cell[	8	][	11	]=new	Block	(this,	8	,	11	,	true,	true);
    cell[	8	][	12	]=new	Unit	(this,	8	,	12	);
    cell[	9	][	0	]=new	Unit	(this,	9	,	0	);
    cell[	9	][	1	]=new	Unit	(this,	9	,	1	);
    cell[	9	][	2	]=new	Block	(this,	9	,	2	,	true,	false);
    cell[	9	][	3	]=new	Block	(this,	9	,	3	,	true,	true);
    cell[	9	][	4	]=new	Block	(this,	9	,	4	,	false,	false);
    cell[	9	][	5	]=new	Block	(this,	9	,	5	,	true,	true);
    cell[	9	][	6	]=new	Block	(this,	9	,	6	,	true,	false);
    cell[	9	][	7	]=new	Block	(this,	9	,	7	,	true,	true);
    cell[	9	][	8	]=new	Block	(this,	9	,	8	,	false,	true);
    cell[	9	][	9	]=new	Block	(this,	9	,	9	,	true,	false);
    cell[	9	][	10	]=new	Block	(this,	9	,	10	,	true,	true);
    cell[	9	][	11	]=new	Unit	(this,	9	,	11	);
    cell[	9	][	12	]=new	Unit	(this,	9	,	12	);


    player1 = ChoiceScene::get_ChoiceScene()->player1;
    player1 -> setParent(this);
    player1 -> setNeed(this);
    dynamic_cast<Character*>(player1)->setPosition(0);
    player2 = ChoiceScene::get_ChoiceScene()->player2;
    player2 -> setParent(this);
    player2	-> setNeed(this);
    dynamic_cast<Character*>(player2)->setPosition(9*(13*3-2)*3+3*12);

}

void Map::map_xyInit()
{
  using namespace Map_xy;
   for(int i = 0; i < 10*3; i++)
  {
    for(int j = 0; j < 13*3 - 2; j++)
    {
      cell_xy[i*(13*3 - 2) + j] = QPoint(j*cell_s, i*cell_s);
    }
  }
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 13; j++)
      {
        cell[i][j] = NULL;
        soju[i][j] = NULL;
      }
  }
}

namespace Map_xy
{
  const int map_w = 57;
  const int map_h = 34;
  const int cell_s = 72/3;
}
