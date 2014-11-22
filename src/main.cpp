#include "mainwindow.h"
#include <QApplication>
#include <QSize>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSize s = QSize(1030,770);
    w.setFixedSize(s);
    w.show();
    return a.exec();
}
