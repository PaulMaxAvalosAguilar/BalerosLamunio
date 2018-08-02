#include "aniadircategoriadialog.h"
#include "ui_aniadircategoriadialog.h"

AniadirCategoriaDialog::AniadirCategoriaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirCategoriaDialog)
{
    ui->setupUi(this);
}

AniadirCategoriaDialog::~AniadirCategoriaDialog()
{
    delete ui;
}

QString AniadirCategoriaDialog::getNombre()
{
    return ui->nombrele->text();
}

void AniadirCategoriaDialog::on_buttonBox_accepted()
{
    accept();
}

void AniadirCategoriaDialog::on_buttonBox_rejected()
{
    reject();
}
