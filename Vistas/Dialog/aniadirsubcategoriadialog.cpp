#include "aniadirsubcategoriadialog.h"
#include "ui_aniadirsubcategoriadialog.h"

AniadirSubcategoriaDialog::AniadirSubcategoriaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirSubcategoriaDialog)
{
    ui->setupUi(this);
}

AniadirSubcategoriaDialog::~AniadirSubcategoriaDialog()
{
    delete ui;
}

QString AniadirSubcategoriaDialog::getNombre()
{
    return ui->nombrele->text();
}

void AniadirSubcategoriaDialog::on_buttonBox_accepted()
{
    accept();
}

void AniadirSubcategoriaDialog::on_buttonBox_rejected()
{
    reject();
}
