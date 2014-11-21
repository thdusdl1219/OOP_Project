#include "mainwindow.h"
#include <QApplication>
#include <Qsize>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSize s = QSize(1024,768);
    w.setFixedSize(s);
    w.show();
    return a.exec();
}
