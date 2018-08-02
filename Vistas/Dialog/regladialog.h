#ifndef ANIADIRREGLADIALOG_H
#define ANIADIRREGLADIALOG_H

#include <QDialog>

namespace Ui {
class ReglaDialog;
}

class ReglaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReglaDialog(QWidget *parent = 0);
    ~ReglaDialog();
    QString getNombre();
    void setNombre(QString nombre);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ReglaDialog *ui;
};

#endif // ANIADIRREGLADIALOG_H
