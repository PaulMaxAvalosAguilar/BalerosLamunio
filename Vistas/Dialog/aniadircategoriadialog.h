#ifndef ANIADIRCATEGORIADIALOG_H
#define ANIADIRCATEGORIADIALOG_H

#include <QDialog>

namespace Ui {
class AniadirCategoriaDialog;
}

class AniadirCategoriaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AniadirCategoriaDialog(QWidget *parent = 0);
    ~AniadirCategoriaDialog();
    QString getNombre();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AniadirCategoriaDialog *ui;
};

#endif // ANIADIRCATEGORIADIALOG_H
