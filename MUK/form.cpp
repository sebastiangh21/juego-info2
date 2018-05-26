#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
void Form::inicializacion()
{
    if(nivel == 2)
    {
        Muk = new muk();
        Muk->setPos(700, 530);
        timer =new QTimer();
        timer->start(40);
        connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1300,600);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(1300,600);
        l.append(new QGraphicsLineItem(0,0,1300,0));
        scene->addItem(l.last());
        l.append(new QGraphicsLineItem(1300,0,1300,600));
        scene->addItem(l.last());
        l.append(new QGraphicsLineItem(0,600,1300,600));
        scene->addItem(l.last());
        l.append(new QGraphicsLineItem(0,0,0,600));
        scene->addItem(l.last());
        scene->addItem(Muk);
        Muk->setFlag(QGraphicsItem::ItemIsFocusable);
        Muk->setFocus();
    }
}

void Form::getnivel(int n)
{
    nivel = n;
}
void Form::animar()
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
    if(bt3 == 1) Muk->setPos(Muk->x()-8, Muk->y());
    if(bt4 == 1) Muk->setPos(Muk->x()+8, Muk->y());
    if(con2 < 20)
    {
        if(con2 < 10) Muk->setPos(Muk->x(), Muk->y()-8);
        else Muk->setPos(Muk->x(), Muk->y()+8);
        con2 ++;
    }
    moverbalas();
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
    bala.last()->getbaf()->sety(Muk->y());
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
    if(event->key()==Qt::Key_W && con2 > 19)
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
}
