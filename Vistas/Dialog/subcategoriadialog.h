#ifndef ANIADIRSUBCATEGORIADIALOG_H
#define ANIADIRSUBCATEGORIADIALOG_H

#include <QDialog>

namespace Ui {
class SubcategoriaDialog;
}

class SubcategoriaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SubcategoriaDialog(QWidget *parent = 0);
    ~SubcategoriaDialog();
    QString getNombre();
    void setNombre(QString nombre);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SubcategoriaDialog *ui;
};

#endif // ANIADIRSUBCATEGORIADIALOG_H
