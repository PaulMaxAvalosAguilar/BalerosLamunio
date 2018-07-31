#include "reglasvista.h"
#include "ui_reglasvista.h"

ReglasVista::ReglasVista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReglasVista)
{
    ui->setupUi(this);
}

ReglasVista::~ReglasVista()
{
    delete ui;
}
