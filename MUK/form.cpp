#include "form.h"
#include "ui_form.h"
#include <QLabel>
#include <QSize>

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
        Muk->setPos(0, 540);
        Muk->setvida(15);
        ui->label_2->setNum(15);
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
        l5=new QGraphicsLineItem(1300,0,1300,100);
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
        r.last()->setPos(10, 130);
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(205,305);
        scene->addItem(ene.last());
        ene.last()->setpx(205);
        ene.last()->setpx1(90);
        ene.last()->setpx2(300);
        ene.last()->sett(0);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(135,85);
        scene->addItem(ene.last());
        ene.last()->setpx(135);
        ene.last()->setpx1(20);
        ene.last()->setpx2(233);
        ene.last()->sett(1);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(625,155);
        scene->addItem(ene.last());
        ene.last()->setpx(625);
        ene.last()->setpx1(520);
        ene.last()->setpx2(730);
        ene.last()->sett(1);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(625,455);
        scene->addItem(ene.last());
        ene.last()->setpx(1075);
        ene.last()->setpx1(970);
        ene.last()->setpx2(1150);
        ene.last()->sett(0);
        ene.last()->setvida(4);
    }
}
void Form::getnivel(int n)
{
    nivel = n;
}
void Form::animar()
{
    coliciones();
    teclas();
    moverbalas();
    moverenemigos();
}
void Form::coliciones()
{
    if(!Muk->collidingItems().empty())
    {
        if(Muk->collidingItems().size() < 2)
        {
            if(Muk->collidesWithItem(l2) || Muk->collidesWithItem(l4)) b2 = 1, con2 = 22;
            else b2 = 0;
        }
        else b2 = 0;
        if(b2 == 0)
        {
            for(int i = 0; i < r.length(); i++)
            {
                if(r.at(i)->collidesWithItem(Muk))
                {
                    if(Muk->y() > r.at(i)->y()-40) bt3 = 0, bt4 = 0, b2 = 1, con2 = 22;
                    else b2 = 0;
                    break;
                }
                else if(con2 > 20) b2 = 1;
            }
        }
        if(Muk->collidesWithItem(l3)) b2 = 0;
        if(Muk->collidesWithItem(l1)) b2 = 1, con2 = 22;

    }
}
void Form::teclas()
{
    if(bt1 == 1 && b == 0)
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(1);//tiro rectilineo
        bala.last()->setact(1);
    }
    if(bt2 == 1 && b == 0)
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(0);//tiro parabolico
        bala.last()->setact(1);
    }
    if(bt3 == 1 && !Muk->collidesWithItem(l4)) Muk->setPos(Muk->x()-8, Muk->y());
    if(bt4 == 1 && !Muk->collidesWithItem(l2)) Muk->setPos(Muk->x()+8, Muk->y());
    if(con2 < 20 && b2 == 0)
    {
        Muk->setPos(Muk->x(), Muk->y()-8);
        for(int i = 0; i < r.length(); i++)
        {
            if(Muk->collidesWithItem(r.at(i))) con2 = 22;
        }
        con2 ++;
    }
    else if(Muk->collidingItems().empty() || b2 == 1) Muk->setPos(Muk->x(), Muk->y()+8);
    else
    {
        if(con2 > 100) con2 = 20;
        con2++;
    }
    if(ene.length() < 1 &&  Muk->collidesWithItem(l5)) timer->stop();
}
void Form::moverenemigos()
{
    con3++;
    for(int i = 0; i<ene.length(); i++)
    {
        if(ene.at(i)->getpx() < ene.at(i)->getpx1() || ene.at(i)->getpx() > ene.at(i)->getpx2()) ene.at(i)->setd(-1);
        ene.at(i)->mover();
        ene.at(i)->setPos(ene.at(i)->getpx(), ene.at(i)->y());
        if(con3 > 15)
        {
            if(ene.at(i)->getpx() < Muk->x()) agregarbala(ene.at(i), 1);
            else agregarbala(ene.at(i), -1);
            bala.last()->getbaf()->seta(ene.at(i)->gett());
        }
    }
    if(con3 > 15) con3 = 0;
}
void Form::moverbalas()
{
    for(int i = 0;i < bala.length(); i++)
    {
        bala.at(i)->getbaf()->mover();
        bala.at(i)->setPos(bala[i]->getbaf()->getx(), bala[i]->getbaf()->gety());
        if(!bala.at(i)->collidingItems().empty())
        {
            if(Muk->collidesWithItem(bala.at(i))) Muk->setvida(Muk->getvida()-1), ui->label_2->setNum(Muk->getvida());
            if(Muk->getvida() < 1) timer->stop();
            if(bala.at(i)->getact() == 1)
            {
                for(int j = 0; j < ene.size(); j++)
                {
                    if(ene.at(j)->collidesWithItem(bala.at(i)))
                    {
                        ene.at(j)->setvida(ene.at(j)->getvida()-1);
                        if(ene.at(j)->getvida() < 1) scene->removeItem(ene.at(j)), ene.removeAt(j);
                    }
                }
            }
            scene->removeItem(bala.at(i));
            bala.removeAt(i);
        }
    }
    if (b == 1) con++;
    if(con > 12) con = 0, b = 0;
}
void Form::agregarbala(muk *m, int di)
{
    bala.append(new balas());
    bala.last()->getbaf()->setx(m->x()+(di*20));
    bala.last()->getbaf()->sety(m->y()-(20));
    bala.last()->getbaf()->setd(di);
    bala.last()->setPos(bala.last()->getbaf()->getx(), bala.last()->getbaf()->gety());
    scene->addItem(bala.last());
}
void Form::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space) bt1 = 1;
    else if(event->key()==Qt::Key_M) bt2 = 1;
    if(event->key()==Qt::Key_A) d = -1, bt3 = 1;
    if(event->key()==Qt::Key_D) d = 1, bt4 = 1;
    if(event->key()==Qt::Key_W && con2 > 22) con2 = 0;
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
    bala.clear();
    r.clear();
    ene.clear();
}
