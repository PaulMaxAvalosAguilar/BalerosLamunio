#ifndef SEARCHER_H
#define SEARCHER_H

#include <QWidget>

namespace Ui {
class Searcher;
}

class Searcher : public QWidget
{
    Q_OBJECT

public:
    explicit Searcher(QWidget *parent = 0);
    ~Searcher();

private slots:
    void on_clasificarpB_clicked();

    void on_buscarpB_clicked();

private:
    Ui::Searcher *ui;
};

#endif // SEARCHER_H
