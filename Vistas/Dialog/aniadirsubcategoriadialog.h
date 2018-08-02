#ifndef ANIADIRSUBCATEGORIADIALOG_H
#define ANIADIRSUBCATEGORIADIALOG_H

#include <QDialog>

namespace Ui {
class AniadirSubcategoriaDialog;
}

class AniadirSubcategoriaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AniadirSubcategoriaDialog(QWidget *parent = 0);
    ~AniadirSubcategoriaDialog();
    QString getNombre();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AniadirSubcategoriaDialog *ui;
};

#endif // ANIADIRSUBCATEGORIADIALOG_H
