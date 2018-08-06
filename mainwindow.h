#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Vistas/reglasvista.h>
#include <Vistas/searchervista.h>

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
    SearcherVista *searcher;
};

#endif // MAINWINDOW_H
