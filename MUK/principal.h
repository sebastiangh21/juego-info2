#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include "form.h"


namespace Ui {
class principal;
}

class principal : public QWidget
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_volver_clicked();

    void on_nivel1_clicked();

    void on_nivel2_clicked();

    void on_nivel3_clicked();

    void on_nivel4_clicked();

    void on_nivel5_clicked();

    void on_nivel6_clicked();

    void on_jugar_clicked();

private:
    Ui::principal *ui;
    Form *a;
    int nivel = 0;
};

#endif // PRINCIPAL_H
