#ifndef REGLASVISTA_H
#define REGLASVISTA_H

#include <QWidget>

namespace Ui {
class ReglasVista;
}

class ReglasVista : public QWidget
{
    Q_OBJECT

public:
    explicit ReglasVista(QWidget *parent = 0);
    ~ReglasVista();

private:
    Ui::ReglasVista *ui;
};

#endif // REGLASVISTA_H
