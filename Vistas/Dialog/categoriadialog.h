#ifndef ANIADIRCATEGORIADIALOG_H
#define ANIADIRCATEGORIADIALOG_H

#include <QDialog>

namespace Ui {
class CategoriaDialog;
}

class CategoriaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CategoriaDialog(QWidget *parent = 0);
    ~CategoriaDialog();
    QString getNombre();
    void setNombre(QString nombre);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CategoriaDialog *ui;
};

#endif // ANIADIRCATEGORIADIALOG_H
