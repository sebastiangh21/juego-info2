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
    int vida;
public:
    muk(QGraphicsItem *carr = 0);
};

#endif // MUK_H
