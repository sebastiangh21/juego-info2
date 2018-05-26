#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTimer>
#include <QFile>
#include "balas.h"
#include "muk.h"
#include <QKeyEvent>
#include <QFileDialog>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void animar();
public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void moverbalas();
    void agregarbala();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList<balas*> bala;
    muk* Muk;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    bool b = 0;
    bool b2 = 0;
    bool bt1 = 0;
    bool bt2 = 0;
    bool bt3 = 0;
    bool bt4 = 0;
    bool bt5 = 0;
    short int d = 1;
    short int con = 0;
    short int con2 = 21;
};

#endif // MAINWINDOW_H
