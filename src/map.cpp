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
    cell[0][0]=new Unit (this, 0, 0);
    cell[0][1]=new 	Unit	(this, 	0, 1	);
    cell[0][2]=new 	Block	(this, 	0, 2	, 	true,	true);
    cell[0][3]=new 	Block	(this, 	0, 3	, 	true,	false);
    cell[0][4]=new 	Block	(this, 	0, 4	, 	true,	true);
    cell[0][5]=new Block (this, 0, 5, false, false);
    for(int i = 6; i < 13; i++)
      cell[0][i] = new Unit(this, 0, i);
    for(int i = 1; i < 10; i++)
      {
        for(int j = 0; j < 13; j++)
          {
            cell[i][j] = new Unit(this, i, j);
          }
      }
/*    cell[	5	]=new 	Block	(this, 	0, 5  , 	true,	NULL);
    cell[	6	]=new 	Unit	(this, 	0, 6	);
    cell[	7	]=new 	Unit	(this, 	0, 7	);
    cell[	8	]=new 	Block	(this, 	0, 8	, 	true,	NULL);
    cell[	9	]=new 	Block	(this, 	0, 9, 	true,	NULL);
    cell[	10	]=new 	Block	(this, 	0*(13*3*3)+3*10	, 	true,	NULL);
    cell[	11	]=new 	Unit	(this, 	0*(13*3*3)+3*11	);
    cell[	12	]=new 	Unit	(this, 	0*(13*3*3)+3*12	);
    cell[	13	]=new 	Unit	(this, 	1*(13*3*3)+3*0	);
    cell[	14	]=new 	Block	(this, 	1*(13*3*3)+3*1	, 	false,	NULL);
    cell[	15	]=new 	Block	(this, 	1*(13*3*3)+3*2	, 	true,	NULL);
    cell[	16	]=new 	Block	(this, 	1*(13*3*3)+3*3	, 	false,	NULL);
    cell[	17	]=new 	Block	(this, 	1*(13*3*3)+3*4	, 	true,	NULL);
    cell[	18	]=new 	Block	(this, 	1*(13*3*3)+3*5	, 	false,	NULL);
    cell[	19	]=new 	Block	(this, 	1*(13*3*3)+3*6	, 	true,	NULL);
    cell[	20	]=new 	Unit	(this, 	1*(13*3*3)+3*7	);
    cell[	21	]=new 	Block	(this, 	1*(13*3*3)+3*8	, 	false,	NULL);
    cell[	22	]=new 	Block	(this, 	1*(13*3*3)+3*9	, 	true,	NULL);
    cell[	23	]=new 	Block	(this, 	1*(13*3*3)+3*10	, 	false,	NULL);
    cell[	24	]=new 	Block	(this, 	1*(13*3*3)+3*11	, 	true,	NULL);
    cell[	25	]=new 	Unit	(this, 	1*(13*3*3)+3*12	);
    cell[	26	]=new 	Block	(this, 	2*(13*3*3)+3*0	, 	true,	NULL);
    cell[	27	]=new 	Block	(this, 	2*(13*3*3)+3*1	, 	true,	NULL);
    cell[	28	]=new 	Block	(this, 	2*(13*3*3)+3*2	, 	true,	NULL);
    cell[	29	]=new 	Block	(this, 	2*(13*3*3)+3*3	, 	true,	NULL);
    cell[	30	]=new 	Block	(this, 	2*(13*3*3)+3*4	, 	true,	NULL);
    cell[	31	]=new 	Block	(this, 	2*(13*3*3)+3*5	, 	true,	NULL);
    cell[	32	]=new 	Block	(this, 	2*(13*3*3)+3*6	, 	true,	NULL);
    cell[	33	]=new 	Block	(this, 	2*(13*3*3)+3*7	, 	true,	NULL);
    cell[	34	]=new 	Block	(this, 	2*(13*3*3)+3*8	, 	true,	NULL);
    cell[	35	]=new 	Block	(this, 	2*(13*3*3)+3*9	, 	true,	NULL);
    cell[	36	]=new 	Block	(this, 	2*(13*3*3)+3*10	, 	true,	NULL);
    cell[	37	]=new 	Block	(this, 	2*(13*3*3)+3*11	, 	true,	NULL);
    cell[	38	]=new 	Block	(this, 	2*(13*3*3)+3*12	, 	true,	NULL);
    cell[	39	]=new 	Block	(this, 	3*(13*3*3)+3*0	, 	true,	NULL);
    cell[	40	]=new 	Block	(this, 	3*(13*3*3)+3*1	, 	false,	NULL);
    cell[	41	]=new 	Block	(this, 	3*(13*3*3)+3*2	, 	true,	NULL);
    cell[	42	]=new 	Block	(this, 	3*(13*3*3)+3*3	, 	false,	NULL);
    cell[	43	]=new 	Block	(this, 	3*(13*3*3)+3*4	, 	false,	NULL);
    cell[	44	]=new 	Unit	(this, 	3*(13*3*3)+3*5	);
    cell[	45	]=new 	Block	(this, 	3*(13*3*3)+3*6	, 	false,	NULL);
    cell[	46	]=new 	Block	(this, 	3*(13*3*3)+3*7	, 	false,	NULL);
    cell[	47	]=new 	Block	(this, 	3*(13*3*3)+3*8	, 	false,	NULL);
    cell[	48	]=new 	Block	(this, 	3*(13*3*3)+3*9	, 	false,	NULL);
    cell[	49	]=new 	Block	(this, 	3*(13*3*3)+3*10	, 	true,	NULL);
    cell[	50	]=new 	Block	(this, 	3*(13*3*3)+3*11	, 	false,	NULL);
    cell[	51	]=new 	Block	(this, 	3*(13*3*3)+3*12	, 	true,	NULL);
    cell[	52	]=new 	Unit	(this, 	4*(13*3*3)+3*0	);
    cell[	53	]=new 	Unit	(this, 	4*(13*3*3)+3*1	);
    cell[	54	]=new 	Block	(this, 	4*(13*3*3)+3*2	, 	true,	NULL);
    cell[	55	]=new 	Block	(this, 	4*(13*3*3)+3*3	, 	false,	NULL);
    cell[	56	]=new 	Block	(this, 	4*(13*3*3)+3*4	, 	true,	NULL);
    cell[	57	]=new 	Unit	(this, 	4*(13*3*3)+3*5	);
    cell[	58	]=new 	Unit	(this, 	4*(13*3*3)+3*6	);
    cell[	59	]=new 	Unit	(this, 	4*(13*3*3)+3*7	);
    cell[	60	]=new 	Unit	(this, 	4*(13*3*3)+3*8	);
    cell[	61	]=new 	Block	(this, 	4*(13*3*3)+3*9	, 	false,	NULL);
    cell[	62	]=new 	Block	(this, 	4*(13*3*3)+3*10	, 	true,	NULL);
    cell[	63	]=new 	Block	(this, 	4*(13*3*3)+3*11	, 	true,	NULL);
    cell[	64	]=new 	Unit	(this, 	4*(13*3*3)+3*12	);
    cell[	65	]=new 	Unit	(this, 	5*(13*3*3)+3*0	);
    cell[	66	]=new 	Block	(this, 	5*(13*3*3)+3*1	, 	true,	NULL);
    cell[	67	]=new 	Block	(this, 	5*(13*3*3)+3*2	, 	true,	NULL);
    cell[	68	]=new 	Block	(this, 	5*(13*3*3)+3*3	, 	false,	NULL);
    cell[	69	]=new 	Unit	(this, 	5*(13*3*3)+3*4	);
    cell[	70	]=new 	Unit	(this, 	5*(13*3*3)+3*5	);
    cell[	71	]=new 	Unit	(this, 	5*(13*3*3)+3*6	);
    cell[	72	]=new 	Unit	(this, 	5*(13*3*3)+3*7	);
    cell[	73	]=new 	Block	(this, 	5*(13*3*3)+3*8	, 	true,	NULL);
    cell[	74	]=new 	Block	(this, 	5*(13*3*3)+3*9	, 	false,	NULL);
    cell[	75	]=new 	Block	(this, 	5*(13*3*3)+3*10	, 	true,	NULL);
    cell[	76	]=new 	Unit	(this, 	5*(13*3*3)+3*11	);
    cell[	77	]=new 	Unit	(this, 	5*(13*3*3)+3*12	);
    cell[	78	]=new 	Block	(this, 	6*(13*3*3)+3*0	, 	true,	NULL);
    cell[	79	]=new 	Block	(this, 	6*(13*3*3)+3*1	, 	false,	NULL);
    cell[	80	]=new 	Block	(this, 	6*(13*3*3)+3*2	, 	true,	NULL);
    cell[	81	]=new 	Block	(this, 	6*(13*3*3)+3*3	, 	false,	NULL);
    cell[	82	]=new 	Block	(this, 	6*(13*3*3)+3*4	, 	false,	NULL);
    cell[	83	]=new 	Block	(this, 	6*(13*3*3)+3*5	, 	false,	NULL);
    cell[	84	]=new 	Block	(this, 	6*(13*3*3)+3*6	, 	false,	NULL);
    cell[	85	]=new 	Unit	(this, 	6*(13*3*3)+3*7	);
    cell[	86	]=new 	Block	(this, 	6*(13*3*3)+3*8	, 	false,	NULL);
    cell[	87	]=new 	Block	(this, 	6*(13*3*3)+3*9	, 	false,	NULL);
    cell[	88	]=new 	Block	(this, 	6*(13*3*3)+3*10	, 	true,	NULL);
    cell[	89	]=new 	Block	(this, 	6*(13*3*3)+3*11	, 	false,	NULL);
    cell[	90	]=new 	Block	(this, 	6*(13*3*3)+3*12	, 	true,	NULL);
    cell[	91	]=new 	Block	(this, 	7*(13*3*3)+3*0	, 	true,	NULL);
    cell[	92	]=new 	Block	(this, 	7*(13*3*3)+3*1	, 	true,	NULL);
    cell[	93	]=new 	Block	(this, 	7*(13*3*3)+3*2	, 	true,	NULL);
    cell[	94	]=new 	Block	(this, 	7*(13*3*3)+3*3	, 	true,	NULL);
    cell[	95	]=new 	Block	(this, 	7*(13*3*3)+3*4	, 	true,	NULL);
    cell[	96	]=new 	Block	(this, 	7*(13*3*3)+3*5	, 	true,	NULL);
    cell[	97	]=new 	Block	(this, 	7*(13*3*3)+3*6	, 	true,	NULL);
    cell[	98	]=new 	Block	(this, 	7*(13*3*3)+3*7	, 	true,	NULL);
    cell[	99	]=new 	Block	(this, 	7*(13*3*3)+3*8	, 	true,	NULL);
    cell[	100	]=new 	Block	(this, 	7*(13*3*3)+3*9	, 	true,	NULL);
    cell[	101	]=new 	Block	(this, 	7*(13*3*3)+3*10	, 	true,	NULL);
    cell[	102	]=new 	Block	(this, 	7*(13*3*3)+3*11	, 	true,	NULL);
    cell[	103	]=new 	Block	(this, 	7*(13*3*3)+3*12	, 	true,	NULL);
    cell[	104	]=new 	Unit	(this, 	8*(13*3*3)+3*0	);
    cell[	105	]=new 	Block	(this, 	8*(13*3*3)+3*1	, 	false,	NULL);
    cell[	106	]=new 	Block	(this, 	8*(13*3*3)+3*2	, 	true,	NULL);
    cell[	107	]=new 	Block	(this, 	8*(13*3*3)+3*3	, 	false,	NULL);
    cell[	108	]=new 	Block	(this, 	8*(13*3*3)+3*4	, 	true,	NULL);
    cell[	109	]=new 	Block	(this, 	8*(13*3*3)+3*5	, 	false,	NULL);
    cell[	110	]=new 	Unit	(this, 	8*(13*3*3)+3*6	);
    cell[	111	]=new 	Block	(this, 	8*(13*3*3)+3*7	, 	false,	NULL);
    cell[	112	]=new 	Block	(this, 	8*(13*3*3)+3*8	, 	true,	NULL);
    cell[	113	]=new 	Block	(this, 	8*(13*3*3)+3*9	, 	false,	NULL);
    cell[	114	]=new 	Block	(this, 	8*(13*3*3)+3*10	, 	true,	NULL);
    cell[	115	]=new 	Block	(this, 	8*(13*3*3)+3*11	, 	false,	NULL);
    cell[	116	]=new 	Unit	(this, 	8*(13*3*3)+3*12	);
    cell[	117	]=new 	Unit	(this, 	9*(13*3*3)+3*0	);
    cell[	118	]=new 	Unit	(this, 	9*(13*3*3)+3*1	);
    cell[	119	]=new 	Block	(this, 	9*(13*3*3)+3*2	, 	true,	NULL);
    cell[	120	]=new 	Block	(this, 	9*(13*3*3)+3*3	, 	true,	NULL);
    cell[	121	]=new 	Block	(this, 	9*(13*3*3)+3*4	, 	true,	NULL);
    cell[	122	]=new 	Block	(this, 	9*(13*3*3)+3*5	, 	true,	NULL);
    cell[	123	]=new 	Unit	(this, 	9*(13*3*3)+3*6	);
    cell[	124	]=new 	Unit	(this, 	9*(13*3*3)+3*7	);
    cell[	125	]=new 	Block	(this, 	9*(13*3*3)+3*8	, 	true,	NULL);
    cell[	126	]=new 	Block	(this, 	9*(13*3*3)+3*9	, 	true,	NULL);
    cell[	127	]=new 	Block	(this, 	9*(13*3*3)+3*10	, 	true,	NULL);
    cell[	128	]=new 	Unit	(this, 	9*(13*3*3)+3*11	);
*/
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
  /*
    cell[	1	]=new 	Unit	(this, 	0*(13*3*3)+3*1	);
    cell[	2	]=new 	Block	(this, 	0*(13*3*3)+3*2	, 	true,	NULL);
    cell[	3	]=new 	Block	(this, 	0*(13*3*3)+3*3	, 	true,	NULL);
    cell[	4	]=new 	Block	(this, 	0*(13*3*3)+3*4	, 	true,	NULL);
    cell[	5	]=new 	Block	(this, 	0*(13*3*3)+3*5	, 	true,	NULL);
    cell[	6	]=new 	Block	(this, 	0*(13*3*3)+3*6	, 	true,	NULL);
    cell[	7	]=new 	Block	(this, 	0*(13*3*3)+3*7	, 	true,	NULL);
    cell[	8	]=new 	Block	(this, 	0*(13*3*3)+3*8	, 	true,	NULL);
    cell[	9	]=new 	Block	(this, 	0*(13*3*3)+3*9	, 	true,	NULL);
    cell[	10	]=new 	Block	(this, 	0*(13*3*3)+3*10	, 	true,	NULL);
    cell[	11	]=new 	Unit	(this, 	0*(13*3*3)+3*11	);
    cell[	12	]=new 	Unit	(this, 	0*(13*3*3)+3*12	);
    cell[	13	]=new 	Unit	(this, 	1*(13*3*3)+3*0	);
    cell[	14	]=new 	Block	(this, 	1*(13*3*3)+3*1	, 	false,	NULL);
    cell[	15	]=new 	Block	(this, 	1*(13*3*3)+3*2	, 	false,	NULL);
    cell[	16	]=new 	Block	(this, 	1*(13*3*3)+3*3	, 	false,	NULL);
    cell[	17	]=new 	Block	(this, 	1*(13*3*3)+3*4	, 	true,	NULL);
    cell[	18	]=new 	Block	(this, 	1*(13*3*3)+3*5	, 	false,	NULL);
    cell[	19	]=new 	Block	(this, 	1*(13*3*3)+3*6  , 	false,	NULL);
    cell[	20	]=new 	Block	(this, 	1*(13*3*3)+3*7	, 	false,	NULL);
    cell[	21	]=new 	Block	(this, 	1*(13*3*3)+3*8	, 	true,	NULL);
    cell[	22	]=new 	Block	(this, 	1*(13*3*3)+3*9	, 	false,	NULL);
    cell[	23	]=new 	Block	(this, 	1*(13*3*3)+3*10 , 	false,	NULL);
    cell[	24	]=new 	Block	(this, 	1*(13*3*3)+3*11	, 	false,	NULL);
    cell[	25	]=new 	Unit	(this, 	1*(13*3*3)+3*12	);
    cell[	26	]=new 	Block	(this, 	2*(13*3*3)+3*0	, 	true,	NULL);
    cell[	27	]=new 	Block	(this, 	2*(13*3*3)+3*1	, 	false,	NULL);
    cell[	28	]=new 	Block	(this, 	2*(13*3*3)+3*2	, 	true,	NULL);
    cell[	29	]=new 	Block	(this, 	2*(13*3*3)+3*3	, 	false,	NULL);
    cell[	30	]=new 	Block	(this, 	2*(13*3*3)+3*4	, 	true,	NULL);
    cell[	31	]=new 	Block	(this, 	2*(13*3*3)+3*5	, 	false,	NULL);
    cell[	32	]=new 	Block	(this, 	2*(13*3*3)+3*6	, 	true,	NULL);
    cell[	33	]=new 	Block	(this, 	2*(13*3*3)+3*7	, 	false,	NULL);
    cell[	34	]=new 	Block	(this, 	2*(13*3*3)+3*8	, 	true,	NULL);
    cell[	35	]=new 	Block	(this, 	2*(13*3*3)+3*9	, 	false,	NULL);
    cell[	36	]=new 	Block	(this, 	2*(13*3*3)+3*10	, 	true,	NULL);
    cell[	37	]=new 	Block	(this, 	2*(13*3*3)+3*11	, 	false,	NULL);
    cell[	38	]=new 	Block	(this, 	2*(13*3*3)+3*12	, 	true,	NULL);
    cell[	39	]=new 	Block	(this, 	3*(13*3*3)+3*0	, 	true,	NULL);
    cell[	40	]=new 	Block	(this, 	3*(13*3*3)+3*1	, 	false,	NULL);
    cell[	41	]=new 	Block	(this, 	3*(13*3*3)+3*2	, 	true,	NULL);
    cell[	42	]=new 	Block	(this, 	3*(13*3*3)+3*3	, 	true,	NULL);
    cell[	43	]=new 	Block	(this, 	3*(13*3*3)+3*4	, 	true,	NULL);
    cell[	44	]=new 	Block	(this, 	3*(13*3*3)+3*5	, 	true,	NULL);
    cell[	45	]=new 	Block	(this, 	3*(13*3*3)+3*6	, 	true,	NULL);
    cell[	46	]=new 	Block	(this, 	3*(13*3*3)+3*7	, 	true,	NULL);
    cell[	47	]=new 	Block	(this, 	3*(13*3*3)+3*8	, 	true,	NULL);
    cell[	48	]=new 	Block	(this, 	3*(13*3*3)+3*9	, 	true,	NULL);
    cell[	49	]=new 	Block	(this, 	3*(13*3*3)+3*10	, 	true,	NULL);
    cell[	50	]=new 	Block	(this, 	3*(13*3*3)+3*11	, 	false,	NULL);
    cell[	51	]=new 	Block	(this, 	3*(13*3*3)+3*12	, 	true,	NULL);
    cell[	52	]=new 	Block	(this, 	4*(13*3*3)+3*0	, 	true,	NULL);
    cell[	53	]=new 	Block	(this, 	4*(13*3*3)+3*1	, 	true,	NULL);
    cell[	54	]=new 	Block	(this, 	4*(13*3*3)+3*2	, 	true,	NULL);
    cell[	55	]=new 	Block	(this, 	4*(13*3*3)+3*3	, 	false,	NULL);
    cell[	56	]=new 	Block	(this, 	4*(13*3*3)+3*4	, 	true,	NULL);
    cell[	57	]=new 	Block	(this, 	4*(13*3*3)+3*5	, 	true,	NULL);
    cell[	58	]=new 	Block	(this, 	4*(13*3*3)+3*6	, 	false,	NULL);
    cell[	59	]=new 	Block	(this, 	4*(13*3*3)+3*7	, 	true,	NULL);
    cell[	60	]=new 	Block	(this, 	4*(13*3*3)+3*8	, 	true,	NULL);
    cell[	61	]=new 	Block	(this, 	4*(13*3*3)+3*9	, 	false,	NULL);
    cell[	62	]=new 	Block	(this, 	4*(13*3*3)+3*10	, 	true,	NULL);
    cell[	63	]=new 	Block	(this, 	4*(13*3*3)+3*11 , 	true,	NULL);
    cell[	64	]=new 	Block	(this, 	4*(13*3*3)+3*12	, 	true,	NULL);
    cell[	65	]=new 	Block	(this, 	5*(13*3*3)+3*0	, 	true,	NULL);
    cell[	66	]=new 	Block	(this, 	5*(13*3*3)+3*1	, 	true,	NULL);
    cell[	67	]=new 	Block	(this, 	5*(13*3*3)+3*2	, 	true,	NULL);
    cell[	68	]=new 	Block	(this, 	5*(13*3*3)+3*3	, 	false,	NULL);
    cell[	69	]=new 	Block	(this, 	5*(13*3*3)+3*4	, 	true,	NULL);
    cell[	70	]=new 	Block	(this, 	5*(13*3*3)+3*5	, 	true,	NULL);
    cell[	71	]=new 	Block	(this, 	5*(13*3*3)+3*6	, 	false,	NULL);
    cell[	72	]=new 	Block	(this, 	5*(13*3*3)+3*7	, 	true,	NULL);
    cell[	73	]=new 	Block	(this, 	5*(13*3*3)+3*8	, 	true,	NULL);
    cell[	74	]=new 	Block	(this, 	5*(13*3*3)+3*9	, 	false,	NULL);
    cell[	75	]=new 	Block	(this, 	5*(13*3*3)+3*10	, 	true,	NULL);
    cell[	76	]=new 	Block	(this, 	5*(13*3*3)+3*11 , 	true,	NULL);
    cell[	77	]=new 	Block	(this, 	5*(13*3*3)+3*12	, 	true,	NULL);
    cell[	78	]=new 	Block	(this, 	6*(13*3*3)+3*0	, 	true,	NULL);
    cell[	79	]=new 	Block	(this, 	6*(13*3*3)+3*1	, 	false,	NULL);
    cell[	80	]=new 	Block	(this, 	6*(13*3*3)+3*2	, 	true,	NULL);
    cell[	81	]=new 	Block	(this, 	6*(13*3*3)+3*3	, 	true,	NULL);
    cell[	82	]=new 	Block	(this, 	6*(13*3*3)+3*4	, 	true,	NULL);
    cell[	83	]=new 	Block	(this, 	6*(13*3*3)+3*5	, 	true,	NULL);
    cell[	84	]=new 	Block	(this, 	6*(13*3*3)+3*6	, 	true,	NULL);
    cell[	85	]=new 	Block	(this, 	6*(13*3*3)+3*7	, 	true,	NULL);
    cell[	86	]=new 	Block	(this, 	6*(13*3*3)+3*8	, 	true,	NULL);
    cell[	87	]=new 	Block	(this, 	6*(13*3*3)+3*9	, 	true,	NULL);
    cell[	88	]=new 	Block	(this, 	6*(13*3*3)+3*10	, 	true,	NULL);
    cell[	89	]=new 	Block	(this, 	6*(13*3*3)+3*11	, 	false,	NULL);
    cell[	90	]=new 	Block	(this, 	6*(13*3*3)+3*12	, 	true,	NULL);
    cell[	91	]=new 	Block	(this, 	7*(13*3*3)+3*0	, 	true,	NULL);
    cell[	92	]=new 	Block	(this, 	7*(13*3*3)+3*1	, 	false,	NULL);
    cell[	93	]=new 	Block	(this, 	7*(13*3*3)+3*2	, 	true,	NULL);
    cell[	94	]=new 	Block	(this, 	7*(13*3*3)+3*3	, 	false,	NULL);
    cell[	95	]=new 	Block	(this, 	7*(13*3*3)+3*4	, 	true,	NULL);
    cell[	96	]=new 	Block	(this, 	7*(13*3*3)+3*5	, 	false,	NULL);
    cell[	97	]=new 	Block	(this, 	7*(13*3*3)+3*6	, 	true,	NULL);
    cell[	98	]=new 	Block	(this, 	7*(13*3*3)+3*7	, 	false,	NULL);
    cell[	99	]=new 	Block	(this, 	7*(13*3*3)+3*8	, 	true,	NULL);
    cell[	100	]=new 	Block	(this, 	7*(13*3*3)+3*9	, 	false,	NULL);
    cell[	101	]=new 	Block	(this, 	7*(13*3*3)+3*10	, 	true,	NULL);
    cell[	102	]=new 	Block	(this, 	7*(13*3*3)+3*11	, 	false,	NULL);
    cell[	103	]=new 	Block	(this, 	7*(13*3*3)+3*12	, 	true,	NULL);
    cell[	104	]=new 	Unit	(this, 	8*(13*3*3)+3*0	);
    cell[	105	]=new 	Block	(this, 	8*(13*3*3)+3*1	, 	false,	NULL);
    cell[	106	]=new 	Block	(this, 	8*(13*3*3)+3*2	, 	false,	NULL);
    cell[	107	]=new 	Block	(this, 	8*(13*3*3)+3*3	, 	false,	NULL);
    cell[	108	]=new 	Block	(this, 	8*(13*3*3)+3*4	, 	true,	NULL);
    cell[	109	]=new 	Block	(this, 	8*(13*3*3)+3*5	, 	false,	NULL);
    cell[	110	]=new 	Block	(this, 	8*(13*3*3)+3*6	, 	false,	NULL);
    cell[	111	]=new 	Block	(this, 	8*(13*3*3)+3*7	, 	false,	NULL);
    cell[	112	]=new 	Block	(this, 	8*(13*3*3)+3*8	, 	true,	NULL);
    cell[	113	]=new 	Block	(this, 	8*(13*3*3)+3*9	, 	false,	NULL);
    cell[	114	]=new 	Block	(this, 	8*(13*3*3)+3*10	, 	false,	NULL);
    cell[	115	]=new 	Block	(this, 	8*(13*3*3)+3*11	, 	false,	NULL);
    cell[	116	]=new 	Unit	(this, 	8*(13*3*3)+3*12	);
    cell[	117	]=new 	Unit	(this, 	9*(13*3*3)+3*0	);
    cell[	118	]=new 	Unit	(this, 	9*(13*3*3)+3*1	);
    cell[	119	]=new 	Block	(this, 	9*(13*3*3)+3*2	, 	true,	NULL);
    cell[	120	]=new 	Block	(this, 	9*(13*3*3)+3*3	, 	true,	NULL);
    cell[	121	]=new 	Block	(this, 	9*(13*3*3)+3*4	, 	true,	NULL);
    cell[	122	]=new 	Block	(this, 	9*(13*3*3)+3*5	, 	true,	NULL);
    cell[	123	]=new 	Block	(this, 	9*(13*3*3)+3*6	, 	true,	NULL);
    cell[	124	]=new 	Block	(this, 	9*(13*3*3)+3*7	, 	true,	NULL);
    cell[	125	]=new 	Block	(this, 	9*(13*3*3)+3*8	, 	true,	NULL);
    cell[	126	]=new 	Block	(this, 	9*(13*3*3)+3*9	, 	true,	NULL);
    cell[	127	]=new 	Block	(this,  9*(13*3*3)+3*10	, 	true,	NULL);
    cell[	128	]=new 	Unit	(this,  9*(13*3*3)+3*11 );

    cell[0] = ChoiceScene::get_ChoiceScene()->player1;
    cell[0] -> setParent(this);
    dynamic_cast<Character*>(cell[0])->setPosition(0);
    cell[129] = ChoiceScene::get_ChoiceScene()->player2;
    cell[129] -> setParent(this);
    dynamic_cast<Character*>(cell[129])->setPosition(9*(13*3*3)+3*12);
*/
}

void Map::mapInit3()
{
  /*
    cell[	1	]=new 	Unit	(this, 	1*3	);
    cell[	2	]=new 	Block	(this, 	2*3	, 	true,	NULL);
    cell[	3	]=new 	Block	(this, 	3*3	, 	true,	NULL);
    cell[	4	]=new 	Block	(this, 	4*3	, 	false,	NULL);
    cell[	5	]=new 	Block	(this, 	5*3	, 	true,	NULL);
    cell[	6	]=new 	Block	(this, 	6*3	, 	true,	NULL);
    cell[	7	]=new 	Block	(this, 	7*3	, 	true,	NULL);
    cell[	8	]=new 	Block	(this, 	8*3	, 	false,	NULL);
    cell[	9	]=new 	Block	(this, 	9*3	, 	true,	NULL);
    cell[	10	]=new 	Block	(this, 	10*3	, 	true,	NULL);
    cell[	11	]=new 	Unit	(this, 	11*3	);
    cell[	12	]=new 	Unit	(this, 	12*3	);
    cell[	13	]=new 	Unit	(this, 	0*3+13*3*3	);
    cell[	14	]=new 	Block	(this, 	1*3+13*3*3	, 	true,	NULL);
    cell[	15	]=new 	Block	(this, 	2*3+13*3*3	, 	false,	NULL);
    cell[	16	]=new 	Block	(this, 	3*3+13*3*3	, 	true,	NULL);
    cell[	17	]=new 	Block	(this, 	4*3+13*3*3	, 	false,	NULL);
    cell[	18	]=new 	Block	(this, 	5*3+13*3*3	, 	true,	NULL);
    cell[	19	]=new 	Block	(this, 	6*3+13*3*3	, 	true,	NULL);
    cell[	20	]=new 	Block	(this, 	7*3+13*3*3	, 	true,	NULL);
    cell[	21	]=new 	Block	(this, 	8*3+13*3*3	, 	false,	NULL);
    cell[	22	]=new 	Block	(this, 	9*3+13*3*3	, 	true,	NULL);
    cell[	23	]=new 	Block	(this, 	10*3+13*3*3	, 	false,	NULL);
    cell[	24	]=new 	Block	(this, 	11*3+13*3*3	, 	true,	NULL);
    cell[	25	]=new 	Block	(this, 	12*3+13*3*3	, 	true,	NULL);
    cell[	26	]=new 	Block	(this, 	0*3+13*3*3*2	, 	true,	NULL);
    cell[	27	]=new 	Block	(this, 	1*3+13*3*3*2	, 	true,	NULL);
    cell[	28	]=new 	Block	(this, 	2*3+13*3*3*2	, 	true,	NULL);
    cell[	29	]=new 	Block	(this, 	3*3+13*3*3*2	, 	true,	NULL);
    cell[	30	]=new 	Block	(this, 	4*3+13*3*3*2	, 	false,	NULL);
    cell[	31	]=new 	Block	(this, 	5*3+13*3*3*2	, 	true,	NULL);
    cell[	32	]=new 	Block	(this, 	6*3+13*3*3*2	, 	true,	NULL);
    cell[	33	]=new 	Block	(this, 	7*3+13*3*3*2	, 	true,	NULL);
    cell[	34	]=new 	Block	(this, 	8*3+13*3*3*2	, 	false,	NULL);
    cell[	35	]=new 	Block	(this, 	9*3+13*3*3*2	, 	true,	NULL);
    cell[	36	]=new 	Block	(this, 	10*3+13*3*3*2	, 	true,	NULL);
    cell[	37	]=new 	Block	(this, 	11*3+13*3*3*2	, 	true,	NULL);
    cell[	38	]=new 	Block	(this, 	12*3+13*3*3*2	, 	true,	NULL);
    cell[	39	]=new 	Block	(this, 	0*3+13*3*3*3	, 	false,	NULL);
    cell[	40	]=new 	Block	(this, 	1*3+13*3*3*3	, 	true,	NULL);
    cell[	41	]=new 	Block	(this, 	2*3+13*3*3*3	, 	false,	NULL);
    cell[	42	]=new 	Block	(this, 	3*3+13*3*3*3	, 	true,	NULL);
    cell[	43	]=new 	Block	(this, 	4*3+13*3*3*3	, 	true,	NULL);
    cell[	44	]=new 	Block	(this, 	5*3+13*3*3*3	, 	true,	NULL);
    cell[	45	]=new 	Block	(this, 	6*3+13*3*3*3	, 	true,	NULL);
    cell[	46	]=new 	Block	(this, 	7*3+13*3*3*3	, 	true,	NULL);
    cell[	47	]=new 	Block	(this, 	8*3+13*3*3*3	, 	true,	NULL);
    cell[	48	]=new 	Block	(this, 	9*3+13*3*3*3	, 	true,	NULL);
    cell[	49	]=new 	Block	(this, 	10*3+13*3*3*3	, 	false,	NULL);
    cell[	50	]=new 	Block	(this, 	11*3+13*3*3*3	, 	true,	NULL);
    cell[	51	]=new 	Block	(this, 	12*3+13*3*3*3	, 	false,	NULL);
    cell[	52	]=new 	Block	(this, 	0*3+13*3*3*4	, 	false,	NULL);
    cell[	53	]=new 	Block	(this, 	1*3+13*3*3*4	, 	false,	NULL);
    cell[	54	]=new 	Block	(this, 	2*3+13*3*3*4	, 	false,	NULL);
    cell[	55	]=new 	Block	(this, 	3*3+13*3*3*4	, 	false,	NULL);
    cell[	56	]=new 	Block	(this, 	4*3+13*3*3*4	, 	false,	NULL);
    cell[	57	]=new 	Block	(this, 	5*3+13*3*3*4	, 	true,	NULL);
    cell[	58	]=new 	Block	(this, 	6*3+13*3*3*4	, 	true,	NULL);
    cell[	59	]=new 	Block	(this, 	7*3+13*3*3*4	, 	true,	NULL);
    cell[	60	]=new 	Block	(this, 	8*3+13*3*3*4	, 	false,	NULL);
    cell[	61	]=new 	Block	(this, 	9*3+13*3*3*4	, 	false,	NULL);
    cell[	62	]=new 	Block	(this, 	10*3+13*3*3*4	, 	false,	NULL);
    cell[	63	]=new 	Block	(this, 	11*3+13*3*3*4	, 	false,	NULL);
    cell[	64	]=new 	Block	(this, 	12*3+13*3*3*4	, 	false,	NULL);
    cell[	65	]=new 	Block	(this, 	0*3+13*3*3*5	, 	false,	NULL);
    cell[	66	]=new 	Block	(this, 	1*3+13*3*3*5	, 	false,	NULL);
    cell[	67	]=new 	Block	(this, 	2*3+13*3*3*5	, 	false,	NULL);
    cell[	68	]=new 	Block	(this, 	3*3+13*3*3*5	, 	false,	NULL);
    cell[	69	]=new 	Block	(this, 	4*3+13*3*3*5	, 	false,	NULL);
    cell[	70	]=new 	Block	(this, 	5*3+13*3*3*5	, 	true,	NULL);
    cell[	71	]=new 	Block	(this, 	6*3+13*3*3*5	, 	true,	NULL);
    cell[	72	]=new 	Block	(this, 	7*3+13*3*3*5	, 	true,	NULL);
    cell[	73	]=new 	Block	(this, 	8*3+13*3*3*5	, 	false,	NULL);
    cell[	74	]=new 	Block	(this, 	9*3+13*3*3*5	, 	false,	NULL);
    cell[	75	]=new 	Block	(this, 	10*3+13*3*3*5	, 	false,	NULL);
    cell[	76	]=new 	Block	(this, 	11*3+13*3*3*5	, 	false,	NULL);
    cell[	77	]=new 	Block	(this, 	12*3+13*3*3*5	, 	false,	NULL);
    cell[	78	]=new 	Block	(this, 	0*3+13*3*3*6	, 	false,	NULL);
    cell[	79	]=new 	Block	(this, 	1*3+13*3*3*6	, 	true,	NULL);
    cell[	80	]=new 	Block	(this, 	2*3+13*3*3*6	, 	false,	NULL);
    cell[	81	]=new 	Block	(this, 	3*3+13*3*3*6	, 	true,	NULL);
    cell[	82	]=new 	Block	(this, 	4*3+13*3*3*6	, 	true,	NULL);
    cell[	83	]=new 	Block	(this, 	5*3+13*3*3*6	, 	true,	NULL);
    cell[	84	]=new 	Block	(this, 	6*3+13*3*3*6	, 	true,	NULL);
    cell[	85	]=new 	Block	(this, 	7*3+13*3*3*6	, 	true,	NULL);
    cell[	86	]=new 	Block	(this, 	8*3+13*3*3*6	, 	true,	NULL);
    cell[	87	]=new 	Block	(this, 	9*3+13*3*3*6	, 	true,	NULL);
    cell[	88	]=new 	Block	(this, 	10*3+13*3*3*6	, 	false,	NULL);
    cell[	89	]=new 	Block	(this, 	11*3+13*3*3*6	, 	true,	NULL);
    cell[	90	]=new 	Block	(this, 	12*3+13*3*3*6	, 	false,	NULL);
    cell[	91	]=new 	Block	(this, 	0*3+13*3*3*7	, 	true,	NULL);
    cell[	92	]=new 	Block	(this, 	1*3+13*3*3*7	, 	true,	NULL);
    cell[	93	]=new 	Block	(this, 	2*3+13*3*3*7	, 	true,	NULL);
    cell[	94	]=new 	Block	(this, 	3*3+13*3*3*7	, 	true,	NULL);
    cell[	95	]=new 	Block	(this, 	4*3+13*3*3*7	, 	false,	NULL);
    cell[	96	]=new 	Block	(this, 	5*3+13*3*3*7	, 	true,	NULL);
    cell[	97	]=new 	Block	(this, 	6*3+13*3*3*7	, 	true,	NULL);
    cell[	98	]=new 	Block	(this, 	7*3+13*3*3*7	, 	true,	NULL);
    cell[	99	]=new 	Block	(this, 	8*3+13*3*3*7	, 	false,	NULL);
    cell[	100	]=new 	Block	(this, 	9*3+13*3*3*7	, 	true,	NULL);
    cell[	101	]=new 	Block	(this, 	10*3+13*3*3*7	, 	true,	NULL);
    cell[	102	]=new 	Block	(this, 	11*3+13*3*3*7	, 	true,	NULL);
    cell[	103	]=new 	Block	(this, 	12*3+13*3*3*7	, 	true,	NULL);
    cell[	104	]=new 	Unit	(this, 	0*3+13*3*3*8	);
    cell[	105	]=new 	Block	(this, 	1*3+13*3*3*8	, 	true,	NULL);
    cell[	106	]=new 	Block	(this, 	2*3+13*3*3*8	, 	false,	NULL);
    cell[	107	]=new 	Block	(this, 	3*3+13*3*3*8	, 	true,	NULL);
    cell[	108	]=new 	Block	(this, 	4*3+13*3*3*8	, 	false,	NULL);
    cell[	109	]=new 	Block	(this, 	5*3+13*3*3*8	, 	true,	NULL);
    cell[	110	]=new 	Block	(this, 	6*3+13*3*3*8	, 	true,	NULL);
    cell[	111	]=new 	Block	(this, 	7*3+13*3*3*8	, 	true,	NULL);
    cell[	112	]=new 	Block	(this, 	8*3+13*3*3*8	, 	false,	NULL);
    cell[	113	]=new 	Block	(this, 	9*3+13*3*3*8	, 	true,	NULL);
    cell[	114	]=new 	Block	(this, 	10*3+13*3*3*8	, 	false,	NULL);
    cell[	115	]=new 	Block	(this, 	11*3+13*3*3*8	, 	true,	NULL);
    cell[	116	]=new 	Unit	(this, 	12*3+13*3*3*8	);
    cell[	117	]=new 	Unit	(this, 	0*3+13*3*3*9	);
    cell[	118	]=new 	Unit	(this, 	1*3+13*3*3*9	);
    cell[	119	]=new 	Block	(this, 	2*3+13*3*3*9	, 	true,	NULL);
    cell[	120	]=new 	Block	(this, 	3*3+13*3*3*9	, 	true,	NULL);
    cell[	121	]=new 	Block	(this, 	4*3+13*3*3*9	, 	false,	NULL);
    cell[	122	]=new 	Block	(this, 	5*3+13*3*3*9	, 	true,	NULL);
    cell[	123	]=new 	Block	(this, 	6*3+13*3*3*9	, 	true,	NULL);
    cell[	124	]=new 	Block	(this, 	7*3+13*3*3*9	, 	true,	NULL);
    cell[	125	]=new 	Block	(this, 	8*3+13*3*3*9	, 	false,	NULL);
    cell[	126	]=new 	Block	(this, 	9*3+13*3*3*9	, 	true,	NULL);
    cell[	127	]=new 	Block	(this, 	10*3+13*3*3*9	, 	true,	NULL);
    cell[	128	]=new 	Unit	(this, 	11*3+13*3*3*9	);

    cell[0] = ChoiceScene::get_ChoiceScene()->player1;
    cell[0] -> setParent(this);
    dynamic_cast<Character*>(cell[0])->setPosition(0);
    cell[129] = ChoiceScene::get_ChoiceScene()->player2;
    cell[129] -> setParent(this);
    dynamic_cast<Character*>(cell[129])->setPosition(9*(13*3*3)+3*12);
*/
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
