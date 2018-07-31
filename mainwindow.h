#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BaseDatos/DatabaseManager/databasemanager.h"
#include <QTreeWidgetItem>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_treeWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
