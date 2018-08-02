#ifndef ANIADIRREGLADIALOG_H
#define ANIADIRREGLADIALOG_H

#include <QDialog>

namespace Ui {
class AniadirReglaDialog;
}

class AniadirReglaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AniadirReglaDialog(QWidget *parent = 0);
    ~AniadirReglaDialog();
    QString getNombre();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AniadirReglaDialog *ui;
};

#endif // ANIADIRREGLADIALOG_H
