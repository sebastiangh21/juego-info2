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
    int act;
public:
    balas(QGraphicsItem *carr = 0);
    balafisica* getbaf();
    void setact(int a);
    int getact();
    ~balas();
};

#endif // BALAS_H
