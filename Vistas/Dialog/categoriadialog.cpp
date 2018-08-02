#include "categoriadialog.h"
#include "ui_categoriadialog.h"

CategoriaDialog::CategoriaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoriaDialog)
{
    ui->setupUi(this);
}

CategoriaDialog::~CategoriaDialog()
{
    delete ui;
}

QString CategoriaDialog::getNombre()
{
    return ui->nombrele->text();
}

void CategoriaDialog::setNombre(QString nombre)
{
    ui->nombrele->setText(nombre);
}

void CategoriaDialog::on_buttonBox_accepted()
{
    accept();
}

void CategoriaDialog::on_buttonBox_rejected()
{
    reject();
}
