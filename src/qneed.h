#ifndef QNEED_H
#define QNEED_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
class MainWindow;

class Qneed : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Qneed(QGraphicsScene*, MainWindow*);
    Qneed(Qneed *parent = 0);
    void loadImage(const char* filename);
    MainWindow* get_window();
    void additem(QGraphicsScene*);
signals:

public slots:

private:
    void setParent(Qneed* parent);
    QPixmap* image;
    MainWindow* window;
};

#endif // QNEED_H
