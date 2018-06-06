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
    void setniveltotal(int n);
    void setusu(QString u);
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
    QString usu;
    int nivel = 0;
    int niveltotal = 0;
};

#endif // PRINCIPAL_H
