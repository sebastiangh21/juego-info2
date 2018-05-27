#include "muk.h"

muk::muk(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/playmove.png"));
    vida = 0, d = 1, px = 0, px1 = 0, px2 = 0;
}

void muk::setvida(int v)
{
    vida = v;
}

int muk::getvida()
{
    return vida;
}
void muk::setpx(int a)
{
    px = a;
}
int muk::getpx()
{
    return px;
}
void muk::setpx1(int a)
{
    px1 = a;
}
void muk::setpx2(int a)
{
    px2 = a;
}
int muk::getpx1()
{
    return px1;
}
int muk::getpx2()
{
    return px2;
}

void muk::setd(int a)
{
    d *= a;
}

int muk::getd()
{
    return d;
}

void muk::mover()
{
    px += (d*8);
}
