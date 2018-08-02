#include "regladialog.h"
#include "ui_regladialog.h"

ReglaDialog::ReglaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReglaDialog)
{
    ui->setupUi(this);
}

ReglaDialog::~ReglaDialog()
{
    delete ui;
}

QString ReglaDialog::getNombre()
{
    return ui->nombrele->text();
}

void ReglaDialog::setNombre(QString nombre)
{
    ui->nombrele->setText(nombre);
}

void ReglaDialog::on_buttonBox_accepted()
{
    accept();
}

void ReglaDialog::on_buttonBox_rejected()
{
    reject();
}
