#ifndef BALAS_H
#define BALAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "balafisica.h"

class balas:public QObject,
            public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    balafisica *bala;
public:
    balas(QGraphicsItem *carr = 0);
    balafisica* getbaf();
    ~balas();
};

#endif // BALAS_H
