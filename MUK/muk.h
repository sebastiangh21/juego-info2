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
    int vida, px, px1, px2, d, vx;
    bool t;
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
    void sett(bool a);
    bool gett();
    void mover(int a);
    void setvx(int a);
    int getvx();
};

#endif // MUK_H
