#include "balas.h"

balas::balas(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/playmove.png"));
    bala = new balafisica;
    act = 0;
}

balafisica *balas::getbaf()
{
    return bala;
}

void balas::setact(bool a)
{
    act = a;
}

bool balas::getact()
{
    return act;
}
balas::~balas()
{
    delete  bala;
}
