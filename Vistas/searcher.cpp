#include "searcher.h"
#include "ui_searcher.h"

Searcher::Searcher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Searcher)
{
    ui->setupUi(this);
}

Searcher::~Searcher()
{
    delete ui;
}

void Searcher::on_clasificarpB_clicked()
{

}

void Searcher::on_buscarpB_clicked()
{

}
