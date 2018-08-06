#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Vistas/reglasvista.h>
#include <Vistas/searcher.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ReglasVista *reglasvista;
    Searcher *searcher;
};

#endif // MAINWINDOW_H
