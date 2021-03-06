#include "muk.h"

muk::muk(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/"));
    vida = 0, d = 1, px = 0, px1 = 0, px2 = 0, vx = 17, cont = 0;
    t = 0;
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

void muk::sett(int a)
{
    t = a;
}

int muk::gett()
{
    return t;
}
void muk::mover(int a)
{
    if(a == 1) px += (d*8);
}

void muk::setvx(int a)
{
    vx = a;
}

int muk::getvx()
{
    return vx;
}
void muk::movsapo(int b) // aqui se le ponen las imagenes al sapo en cada movimiento
{
    if(b == 1)
    {
        if (cont<5)
        {

            setPixmap(QPixmap(":/sapo1.png"));
        }
        else if (cont >5)
        {
            setPixmap(QPixmap(":/sapo2.png"));
        }
        if (cont==10)cont=0;
    }
    else
    {
        if (cont<5)
        {
            setPixmap(QPixmap(":/sapo3.png"));
        }
        else if (cont >5)
        {
            setPixmap(QPixmap(":/sapo4.png"));
        }
        if (cont==10)cont=0;
    }
    cont++;
}
void muk::movsapoj(int b)// imagenes del sapo gefe en movimiento
{
    if(b == 1)
    {
        if (cont<5)
        {

            setPixmap(QPixmap(":/sapoj1.png"));
        }
        else if (cont >5)
        {
            setPixmap(QPixmap(":/sapoj2.png"));
        }
        if (cont==10)cont=0;
    }
    else
    {
        if (cont<5)
        {
            setPixmap(QPixmap(":/sapoj3.png"));
        }
        else if (cont >5)
        {
            setPixmap(QPixmap(":/sapoj4.png"));
        }
        if (cont==10)cont=0;
    }
    cont++;
}
void muk::imagen(QString s)
{
    setPixmap(QPixmap(s));
}
void muk::movMuk(int b)// imagenes de muk(jugador) movimiento
{
    if(b == 1)
    {
        if (cont<5 && cont > -1)
        {
            setPixmap(QPixmap(":/Muk3.png"));
        }
        else if (cont >= 5)
        {
            setPixmap(QPixmap(":/Muk4.png"));
        }
    }
    else
    {
        if (cont<5)
        {
            setPixmap(QPixmap(":/Muk1.png"));
        }
        else if (cont >= 5)
        {
            setPixmap(QPixmap(":/Muk2.png"));
        }
    }
    cont++;
    if (cont==10)cont=0;
}
void muk::movara(int b)// imagenes de la araña en movimiento
{
    if(b == 1)
    {
        if (cont<5 && cont > -1)
        {
            setPixmap(QPixmap(":/araña1.png"));
        }
        else if (cont >= 5)
        {
            setPixmap(QPixmap(":/araña2.png"));
        }
    }
    else
    {
        if (cont<5)
        {
            setPixmap(QPixmap(":/araña3.png"));
        }
        else if (cont >= 5)
        {
            setPixmap(QPixmap(":/araña4.png"));
        }
    }
    cont++;
    if (cont==10)cont=0;
}
void muk::disMuk(int e)// imagen de muk cuando dispara
{
    if(e == 1) setPixmap(QPixmap(":/MukDD.png"));
    else setPixmap(QPixmap(":/MukDI.png"));
    cont = -5;
}
