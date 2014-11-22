#include "map.h"

Map::Map(QGraphicsScene* scene, MainWindow* window) : Qneed(scene, window)
{
  loadImage(":images/ingame/map/map_background.png");
  map_xyInit();
}

void Map::map_xyInit()
{
  using namespace Map_xy;
  QPoint cell_xy[130];
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
