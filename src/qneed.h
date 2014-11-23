#ifndef QNEED_H
#define QNEED_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
class MainWindow;

class Qneed : public QWidget, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Qneed(QGraphicsScene*, MainWindow*);
    Qneed(Qneed *parent = 0);
    void loadImage(const char* filename);
    MainWindow* get_window();
    void additem(QGraphicsScene*);
    void setParent(Qneed* parent);
signals:

public slots:

private:
    QPixmap* image;
    MainWindow* window;
};

#endif // QNEED_H
