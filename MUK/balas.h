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
    bool act;
public:
    balas(QGraphicsItem *carr = 0);
    balafisica* getbaf();
    void setact(bool a);
    bool getact();
    ~balas();
};

#endif // BALAS_H
