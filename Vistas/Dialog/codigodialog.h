#ifndef CODIGODIALOG_H
#define CODIGODIALOG_H

#include <QDialog>

namespace Ui {
class CodigoDialog;
}

class CodigoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CodigoDialog(QWidget *parent = 0);
    ~CodigoDialog();
    QString getCaracteres();
    void setCaracteres(QString nombre);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CodigoDialog *ui;
};

#endif // CODIGODIALOG_H
