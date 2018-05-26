#include "balas.h"

balas::balas(QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/playmove.png"));
    bala = new balafisica;
}

balafisica *balas::getbaf()
{
    return bala;
}
balas::~balas()
{
    delete  bala;
}
