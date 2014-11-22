#ifndef MAP_H
#define MAP_H

#include "qneed.h"
#include <QGraphicsScene>
#include <QPoint>

class Map : public Qneed
{
public:
  Map(QGraphicsScene*, MainWindow *);

public slots:
private:
  void map_xyInit();
};

namespace Map_xy
{
  extern const int map_w;
  extern const int map_h;
  extern const int cell_s;
  extern QPoint cell_xy[130];
}


#endif // MAP_H
