#include "searchevista.h"
#include "ui_searchervista.h"

SearcherVista::SearcherVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearcherVista)
{
    ui->setupUi(this);
}

SearcherVista::~SearcherVista()
{
    delete ui;
}

void SearcherVista::on_clasificarpB_clicked()
{

}

void SearcherVista::on_buscarpB_clicked()
{

}
