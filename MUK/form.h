#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QFile>
#include "balas.h"
#include "muk.h"
#include <QKeyEvent>
#include <QFileDialog>
#include <QGraphicsView>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
public slots:
    void animar();
public:
    explicit Form(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void moverbalas();
    void agregarbala(muk *m, int di);
    void inicializacion();
    void getnivel(int n);
    void moverenemigos();
    void moverjefe();
    void teclas();
    void coliciones();
    ~Form();

private:
    Ui::Form *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<balas*> bala;
    muk* Muk;
    muk* Jefe;
    QList<QGraphicsRectItem*> r;
    QList<muk*> ene;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    QGraphicsLineItem* l5;
    bool a = 0;
    bool b = 0;
    bool b2 = 1;
    bool b3 = 0;
    bool b4 = 0;
    bool bt1 = 0;
    bool bt2 = 0;
    bool bt3 = 0;
    bool bt4 = 0;
    bool bt5 = 0;
    short int nivel = 1;
    short int d = 1;
    short int con = 0;
    short int con2 = 22;
    short int con3 = 0;
    short int con4 = 0;
    short int jefe = 0;
};

#endif // FORM_H
