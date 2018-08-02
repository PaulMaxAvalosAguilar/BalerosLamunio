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
