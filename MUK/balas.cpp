#include "balas.h"

balas::balas(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/balamuk.png"));
    bala = new balafisica;
    act = 0;
}

balafisica *balas::getbaf()
{
    return bala;
}

void balas::balasapo()
{
    setPixmap(QPixmap(":/balasapo.png"));
}

void balas::setact(int a)
{
    act = a;
}

int balas::getact()
{
    return act;
}
balas::~balas()
{
    delete  bala;
}
