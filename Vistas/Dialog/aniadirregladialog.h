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

private:
    Ui::AniadirReglaDialog *ui;
};

#endif // ANIADIRREGLADIALOG_H
