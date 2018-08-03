#include "codigodialog.h"
#include "ui_codigodialog.h"

CodigoDialog::CodigoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodigoDialog)
{
    ui->setupUi(this);
}

CodigoDialog::~CodigoDialog()
{
    delete ui;
}

QString CodigoDialog::getCaracteres()
{
    return ui->nombrele->text();
}

void CodigoDialog::setCaracteres(QString nombre)
{
    ui->nombrele->setText(nombre);
}

void CodigoDialog::on_buttonBox_accepted()
{
    accept();
}

void CodigoDialog::on_buttonBox_rejected()
{
    reject();
}
