#include "muk.h"

muk::muk(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/playmove.png"));
}
