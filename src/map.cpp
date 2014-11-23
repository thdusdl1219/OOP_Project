#include "map.h"
QPoint cell_xy[130];

Map::Map(QGraphicsScene* scene, MainWindow* window, int map_kind) : Qneed(scene, window)
{
  loadImage(":images/ingame/map/map_background.png");
  map_xyInit();
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

void Map::mapInit1()
{
  b = new Block(this, 0, true, NULL);

}

void Map::mapInit2()
{

}

void Map::mapInit3()
{

}

void Map::map_xyInit()
{
  using namespace Map_xy;
   for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 13; j++)

    {
      cell_xy[i*13 + j] = QPoint(j*cell_s, i*cell_s);
    }
  }
}

namespace Map_xy
{
  const int map_w = 57;
  const int map_h = 34;
  const int cell_s = 70;
}
