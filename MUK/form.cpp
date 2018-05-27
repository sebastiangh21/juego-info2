#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
void Form::inicializacion()
{
    if(nivel == 1)
    {
        Muk = new muk();
        Muk->setPos(700, 540);
        timer =new QTimer();
        timer->start(40);
        connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1300,600);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(1300,600);
        l1=new QGraphicsLineItem(0,0,1300,0);
        l2=new QGraphicsLineItem(1300,0,1300,600);
        l3=new QGraphicsLineItem(0,600,1300,600);
        l4=new QGraphicsLineItem(0,0,0,600);
        scene->addItem(l1);
        scene->addItem(l2);
        scene->addItem(l3);
        scene->addItem(l4);
        scene->addItem(Muk);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(80, 350);
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 450);
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(950, 500);
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 200);
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,350,20));
        r.last()->setPos(950, 100);
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(10, 100);
        scene->addItem(r.last());
    }
}
void Form::getnivel(int n)
{
    nivel = n;
}
void Form::animar()
{

    if(!Muk->collidingItems().empty())
    {
        if((Muk->collidesWithItem(l2) || Muk->collidesWithItem(l4)) && !Muk->collidesWithItem(l3)) b2 = 1, con2 = 22;
        if(Muk->collidesWithItem(l1)) b2 = 1, con2 = 22;
        else b2 = 0;
    }
    for(int i = 0; i < r.length(); i++)
    {
        if(r.at(i)->collidesWithItem(Muk))
        {
            if(Muk->y() > r.at(i)->y()-40) bt3 = 0, bt4 = 0, b2 = 1, con2 = 22;
        }
    }
    teclas();
    moverbalas();
}
void Form::teclas()
{
    if(bt1 == 1 && b == 0)
    {
        b = 1;
        agregarbala();
        bala.last()->getbaf()->seta(1);//tiro rectilineo
    }
    if(bt2 == 1 && b == 0)
    {
        b = 1;
        agregarbala();
        bala.last()->getbaf()->seta(0);//tiro parabolico
    }
    if(bt3 == 1 && !Muk->collidesWithItem(l4)) Muk->setPos(Muk->x()-8, Muk->y());
    if(bt4 == 1 && !Muk->collidesWithItem(l2)) Muk->setPos(Muk->x()+8, Muk->y());
    if(con2 < 20 && b2 == 0)
    {
        Muk->setPos(Muk->x(), Muk->y()-8);
        for(int i = 0; i < r.length(); i++)
        {
            if(Muk->collidesWithItem(r.at(i)))
            {
                con2 = 22;
            }
        }
        con2 ++;
    }
    else if(Muk->collidingItems().empty() || b2 == 1)
    {
        Muk->setPos(Muk->x(), Muk->y()+8);
    }
    else
    {
        if(con2 > 100) con2 = 20;
        con2++;
    }
}
void Form::moverbalas()
{
    for(int i = 0;i < bala.length(); i++)
    {
        bala[i]->getbaf()->mover();
        bala[i]->setPos(bala[i]->getbaf()->getx(), bala[i]->getbaf()->gety());
        if(!bala[i]->collidingItems().empty() && !bala[i]->collidesWithItem(Muk))
        {
            scene->removeItem(bala[i]);
            bala.removeAt(i);
        }
    }
    if (b == 1) con++;
    if(con > 6)
    {
        con = 0;
        b = 0;
    }
}
void Form::agregarbala()
{
    bala.append(new balas());
    bala.last()->getbaf()->setx(Muk->x()+(d*10));
    bala.last()->getbaf()->sety(Muk->y()-(10));
    bala.last()->getbaf()->setd(d);
    bala.last()->setPos(bala.last()->getbaf()->getx(), bala.last()->getbaf()->gety());
    scene->addItem(bala.last());
}
void Form::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space)
    {
        bt1 = 1;
    }
    else if(event->key()==Qt::Key_M)
    {
        bt2 = 1;
    }
    if(event->key()==Qt::Key_A)
    {
        d = -1;
        bt3 = 1;
    }
    if(event->key()==Qt::Key_D)
    {
        d = 1;
        bt4 = 1;
    }
    if(event->key()==Qt::Key_W && con2 > 22)
    {
        con2 = 0;
    }
}
void Form::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space) bt1 = 0;
    if(event->key()==Qt::Key_M) bt2 = 0;
    if(event->key()==Qt::Key_A) bt3 = 0;
    if(event->key()==Qt::Key_D) bt4 = 0;
}

Form::~Form()
{
    delete ui;
    delete timer;
    delete Muk;
    delete l1;
    delete l2;
    delete l3;
    delete l4;
}
