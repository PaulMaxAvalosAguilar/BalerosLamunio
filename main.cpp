#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QRect>
#include <QGuiApplication>

void configureScreenPosition(MainWindow &w);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    configureScreenPosition(w);

    w.show();

    return a.exec();
}

void configureScreenPosition(MainWindow &w){
    //Set window in the center
    QRect screenGeometry = QGuiApplication::screens().at(0)->geometry();
    int x = (screenGeometry.width()- w.width()) / 2;
    int y = (screenGeometry.height()- w.height()) / 2;
    w.move(x, y);
}
