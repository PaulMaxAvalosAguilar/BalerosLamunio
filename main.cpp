#include "mainwindow.h"
#include <QApplication>

void configureScreenPosition();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    configureScreenPosition();

    return a.exec();
}

void configureScreenPosition(){

}
