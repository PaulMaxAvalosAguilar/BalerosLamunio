#ifndef SEARCHER_H
#define SEARCHER_H

#include <QWidget>
#include <memory>
#include "Controllers/searchervistacontroller.h"

namespace Ui {
class SearcherVista;
}

class SearcherVista : public QWidget
{
    Q_OBJECT

public:
    explicit SearcherVista(QWidget *parent = 0);
    ~SearcherVista();

private slots:
    void on_clasificarpB_clicked();

    void on_buscarpB_clicked();

private:
    Ui::SearcherVista *ui;


};

#endif // SEARCHER_H
