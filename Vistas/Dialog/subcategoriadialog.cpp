#include "subcategoriadialog.h"
#include "ui_subcategoriadialog.h"

SubcategoriaDialog::SubcategoriaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubcategoriaDialog)
{
    ui->setupUi(this);
}

SubcategoriaDialog::~SubcategoriaDialog()
{
    delete ui;
}

QString SubcategoriaDialog::getNombre()
{
    return ui->nombrele->text();
}

void SubcategoriaDialog::setNombre(QString nombre)
{
    ui->nombrele->setText(nombre);
}

void SubcategoriaDialog::on_buttonBox_accepted()
{
    accept();
}

void SubcategoriaDialog::on_buttonBox_rejected()
{
    reject();
}
