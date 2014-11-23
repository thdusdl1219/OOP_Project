#ifndef MAP_H
#define MAP_H

#include "qneed.h"
#include <QPoint>
#include "unit.h"
#include "scene/choicescene.h"
#include "character.h"
class Unit;
class Block;
class Map : public Qneed
{
public:
  Map(QGraphicsScene*, MainWindow *, int);
  Unit* cell[130];

  static Map* get_map();
public slots:
private:
  void map_xyInit();
  void mapInit1();
  void mapInit2();
  void mapInit3();
  QGraphicsScene* scene;
  MainWindow* window;
  static Map* map;
};

namespace Map_xy
{
  extern const int map_w;
  extern const int map_h;
  extern const int cell_s;
}


#endif // MAP_H
