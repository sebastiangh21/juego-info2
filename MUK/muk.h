#ifndef MUK_H
#define MUK_H

#include <QKeyEvent>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

class muk:public QObject,
          public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int vida, px, px1, px2, d;
public:
    muk(QGraphicsItem *carr = 0);
    void setvida(int v);
    int getvida();
    void setpx(int a);
    int getpx();
    void setpx1(int a);
    void setpx2(int a);
    int getpx1();
    int getpx2();
    void setd(int a);
    int getd();
    void mover();
};

#endif // MUK_H
