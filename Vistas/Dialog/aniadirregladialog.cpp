#include "aniadirregladialog.h"
#include "ui_aniadirregladialog.h"

AniadirReglaDialog::AniadirReglaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AniadirReglaDialog)
{
    ui->setupUi(this);
}

AniadirReglaDialog::~AniadirReglaDialog()
{
    delete ui;
}

QString AniadirReglaDialog::getNombre()
{
    return ui->nombrele->text();
}

void AniadirReglaDialog::on_buttonBox_accepted()
{
    accept();
}

void AniadirReglaDialog::on_buttonBox_rejected()
{
    reject();
}
