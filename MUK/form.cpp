#include "form.h"
#include "ui_form.h"
#include "principal.h"
#include "mainwindow.h"
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QTextStream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}
void Form::inicializacion()
{
    Muk = new muk();//se declara variable de personaje principal
    Muk->setPos(0, 550);
    Muk->setvida(15);
    Muk->setvx(15);//se la asigna vida
    timer =new QTimer();// se declara el timer
    timer->start(40);
    ui->label_2->setNum(15);
    QPalette palette2 = ui->label_2->palette();
    palette2.setColor(ui->label_2->foregroundRole(), Qt::white);
    ui->label_2->setPalette(palette2);
    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    scene = new QGraphicsScene();
    QFont f("PMingLiU-ExtB", 15);
    ui->label->setText(QString("Vida"));
    ui->label->setFont(f);
    QPalette palette = ui->label->palette();
    palette.setColor(ui->label->foregroundRole(), Qt::white);
    ui->label->setPalette(palette);
    int v, ve;
    if(level == 1) v = 4, ve = 10;//configurando dificultad
    else v = 6, ve = 12;
    if(nivel == 1)
    {
        scene->setSceneRect(0,0,2500,700);//se configura la scena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);//rectas fronteras
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,150);
        r.append(new QGraphicsRectItem(0,0,250,20));//barras de salto
        r.last()->setPos(80, 350);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 450);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(950, 500);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 205);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1000, 250);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(10, 130);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        ene.append(new muk());//se declaran enemigos estables
        ene.last()->setPos(1125,185);
        scene->addItem(ene.last());
        ene.last()->setpx(1125);
        ene.last()->setpx1(1010);
        ene.last()->setpx2(1230);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        ene.append(new muk());
        ene.last()->setPos(205,285);
        scene->addItem(ene.last());
        ene.last()->setpx(205);
        ene.last()->setpx1(90);
        ene.last()->setpx2(300);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        ene.append(new muk());
        ene.last()->setPos(135,65);
        scene->addItem(ene.last());
        ene.last()->setpx(135);
        ene.last()->setpx1(20);
        ene.last()->setpx2(233);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        ene.append(new muk());
        ene.last()->setPos(625,140);
        scene->addItem(ene.last());
        ene.last()->setpx(625);
        ene.last()->setpx1(520);
        ene.last()->setpx2(730);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        ene.append(new muk());
        ene.last()->setPos(1075,435);
        scene->addItem(ene.last());
        ene.last()->setpx(1075);
        ene.last()->setpx1(970);
        ene.last()->setpx2(1170);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));//barras de salto
        r.last()->setPos(1380, 450);
        r.last()->setBrush(QBrush(":/rect.png"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1800, 255);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(2200, 350);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1380, 200);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(2250, 150);
        r.last()->setBrush(QBrush(":/rect"));
        scene->addItem(r.last());

        ene.append(new muk());//se declaran enemigos estables
        ene.last()->setPos(1500,385);
        scene->addItem(ene.last());
        ene.last()->setpx(1500);
        ene.last()->setpx1(1380);
        ene.last()->setpx2(1590);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);

        ene.append(new muk());
        ene.last()->setPos(1925,190);
        scene->addItem(ene.last());
        ene.last()->setpx(1925);
        ene.last()->setpx1(1810);
        ene.last()->setpx2(2010);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);

        ene.append(new muk());
        ene.last()->setPos(2375,285);
        scene->addItem(ene.last());
        ene.last()->setpx(2375);
        ene.last()->setpx1(2180);
        ene.last()->setpx2(2430);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);

        ene.append(new muk());
        ene.last()->setPos(1505,135);
        scene->addItem(ene.last());
        ene.last()->setpx(1505);
        ene.last()->setpx1(1390);
        ene.last()->setpx2(1590);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
    }
    else if(nivel == 2)
    {
        scene->setSceneRect(0,0,2500,700);//se configura la scena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);//rectas fronteras
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,10);
        jefe = 1;
        Jefe = new muk();//se declara Jefe
        Jefe->imagen(QString(":/sapo1.png"));
        Jefe->setPos(1200, 555);
        if(level == 1) Jefe->setvida(20);
        else Jefe->setvida(25);
        scene->addItem(Jefe);
        QFont f("PMingLiU-ExtB", 14);
        ui->label_3->setText(QString("Sapo jefe"));
        ui->label_3->setFont(f);
        QPalette palette = ui->label_3->palette();
        palette.setColor(ui->label_3->foregroundRole(), Qt::white);
        ui->label_3->setPalette(palette);
        ui->label_4->setNum(Jefe->getvida());
        QPalette palette2 = ui->label_4->palette();
        palette2.setColor(ui->label_4->foregroundRole(), Qt::white);
        ui->label_4->setPalette(palette2);
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(400, 250);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(1250, 250);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(2100, 250);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());

        ene.append(new muk());//se declaran enemigos estables
        ene.last()->setPos(450,185);
        scene->addItem(ene.last());
        ene.last()->setpx(450);
        ene.last()->setpx1(400);
        ene.last()->setpx2(450);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);

        ene.append(new muk());//se declaran enemigos estables
        ene.last()->setPos(1300,185);
        scene->addItem(ene.last());
        ene.last()->setpx(1300);
        ene.last()->setpx1(1220);
        ene.last()->setpx2(1330);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);

        ene.append(new muk());
        ene.last()->setPos(2150,185);
        scene->addItem(ene.last());
        ene.last()->setpx(2150);
        ene.last()->setpx1(2100);
        ene.last()->setpx2(2150);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
    }
    else if(nivel == 3)
    {
        scene->setSceneRect(0,0,2500,700);//se configura la scena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);//rectas fronteras
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,150);
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(0, 490);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(300, 420);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());//se declaran enemigos estables
        ene.last()->setPos(425,375);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(425);
        ene.last()->setpx1(300);
        ene.last()->setpx2(510);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(300, 164);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(425,119);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(425);
        ene.last()->setpx1(300);
        ene.last()->setpx2(510);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));//barras de salto
        r.last()->setPos(720, 284);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,20,60));
        r.last()->setPos(845, 104);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,20,60));
        r.last()->setPos(845, 360);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());//se declaran enemigos estables
        ene.append(new muk());
        ene.last()->setPos(845,239);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(845);
        ene.last()->setpx1(720);
        ene.last()->setpx2(930);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1120, 420);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1245,375);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(1245);
        ene.last()->setpx1(1120);
        ene.last()->setpx2(1330);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1120, 164);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1245,119);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(1245);
        ene.last()->setpx1(1120);
        ene.last()->setpx2(1330);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1520, 284);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,20,60));
        r.last()->setPos(1665, 104);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,20,60));
        r.last()->setPos(1665, 360);
        r.last()->setBrush(QBrush(":/barra.png"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1665,239);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(1665);
        ene.last()->setpx1(1510);
        ene.last()->setpx2(1720);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1940, 420);
        ene.append(new muk());
        ene.last()->setPos(2065,375);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(2065);
        ene.last()->setpx1(1940);
        ene.last()->setpx2(2150);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(1940, 164);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(2065,119);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(2065);
        ene.last()->setpx1(1940);
        ene.last()->setpx2(2150);
        ene.last()->sett(0);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,150,20));
        r.last()->setPos(2340, 170);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(2440,125);
        ene.last()->imagen(QString(":/araña1.png"));
        scene->addItem(ene.last());
        ene.last()->setpx(2440);
        ene.last()->setpx1(2340);
        ene.last()->setpx2(2440);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
    }
    else if(nivel == 4)
    {
        scene->setSceneRect(0,0,2500,700);
        ui->graphicsView->setScene(scene);//se configura la scena
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,150);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(150, 300);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());//enemigos estables
        ene.last()->setPos(300,235);
        scene->addItem(ene.last());
        ene.last()->setpx(300);
        ene.last()->setpx1(150);
        ene.last()->setpx2(410);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(0, 100);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(50,35);
        scene->addItem(ene.last());
        ene.last()->setpx(50);
        ene.last()->setpx1(5);
        ene.last()->setpx2(60);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(600, 445);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(750,400);
        scene->addItem(ene.last());
        ene.last()->setpx(750);
        ene.last()->setpx1(600);
        ene.last()->setpx2(860);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(600, 189);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(750,144);
        scene->addItem(ene.last());
        ene.last()->setpx(750);
        ene.last()->setpx1(600);
        ene.last()->setpx2(860);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(1200, 445);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1350,400);
        scene->addItem(ene.last());
        ene.last()->setpx(1350);
        ene.last()->setpx1(1200);
        ene.last()->setpx2(1460);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(1200, 189);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1350,144);
        scene->addItem(ene.last());
        ene.last()->setpx(1350);
        ene.last()->setpx1(1200);
        ene.last()->setpx2(1460);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(1800, 445);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1950,400);
        scene->addItem(ene.last());
        ene.last()->setpx(1950);
        ene.last()->setpx1(1800);
        ene.last()->setpx2(2060);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,300,20));
        r.last()->setPos(1800, 189);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(1950,144);
        scene->addItem(ene.last());
        ene.last()->setpx(1950);
        ene.last()->setpx1(1800);
        ene.last()->setpx2(2060);
        ene.last()->sett(0);
        ene.last()->setvx(9);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,200,20));
        r.last()->setPos(2300, 500);//barras de salto
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(2400,435);
        scene->addItem(ene.last());
        ene.last()->setpx(2400);
        ene.last()->setpx1(2300);
        ene.last()->setpx2(2460);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(2250, 100);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(2370,35);
        scene->addItem(ene.last());
        ene.last()->setpx(2370);
        ene.last()->setpx1(2250);
        ene.last()->setpx2(2460);
        ene.last()->sett(1);
        ene.last()->setvx(ve);
        ene.last()->setvida(v);
    }
    else if(nivel == 5)
    {
        a = 1;
        jefe = 2;
        scene->setSceneRect(0,0,1350,700);//se confugura scena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(1350,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,1350,0);//rectas limites
        l2=new QGraphicsLineItem(1350,0,1350,600);
        l3=new QGraphicsLineItem(0,600,1350,600);
        l4=new QGraphicsLineItem(0,0,0,1350);
        l5=new QGraphicsLineItem(1350,0,1350,100);
        Jefe = new muk();
        Jefe->imagen(QString(":/spiderman.png"));
        Jefe->setPos(1270, 300);
        if(level == 1) Jefe->setvida(20);
        else Jefe->setvida(25);
        scene->addItem(Jefe);
        QFont f("PMingLiU-ExtB", 14);
        ui->label_3->setText(QString("Araña jefe"));
        ui->label_3->setFont(f);
        QPalette palette = ui->label_3->palette();
        palette.setColor(ui->label_3->foregroundRole(), Qt::white);
        ui->label_3->setPalette(palette);
        ui->label_4->setNum(Jefe->getvida());
        QPalette palette2 = ui->label_4->palette();
        palette2.setColor(ui->label_4->foregroundRole(), Qt::white);
        ui->label_4->setPalette(palette2);
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(300, 500);//barras de salto
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(400, 395);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(300, 300);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(400, 195);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(300, 100);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,50,20));
        r.last()->setPos(650, 300);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        t = new muk();
        t->setPos(1295, -218);
        t->imagen(QString(":/telaraña.png"));
        scene->addItem(t);
    }
    else if(nivel == 7)
    {
        a = 1;
        scene->setSceneRect(0,0,1350,700);//se configura la ecena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(1350,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,1350,0);
        l2=new QGraphicsLineItem(1350,0,1350,600);
        l3=new QGraphicsLineItem(0,600,1350,600);
        l4=new QGraphicsLineItem(0,0,0,1350);
        l5=new QGraphicsLineItem(1350,0,1350,100);
        r.append(new QGraphicsRectItem(0,0,200,20));//barras de salto
        r.last()->setPos(200, 470);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,200,20));
        r.last()->setPos(950, 470);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,200,20));
        r.last()->setPos(550, 340);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,200,20));
        r.last()->setPos(200, 210);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,200,20));
        r.last()->setPos(950, 210);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        jefe = 4;
        Jefe = new muk();//se declara jugador 2
        Jefe->imagen(QString(":/sapo1.png"));
        Jefe->setPos(1200, 550);
        Jefe->setvida(15);
        Jefe->setvx(15);
        scene->addItem(Jefe);
        ui->label->setText(QString("P1"));
        QFont f("PMingLiU-ExtB", 14);
        ui->label_3->setText(QString("    P2"));
        ui->label_3->setFont(f);
        QPalette palette = ui->label_3->palette();
        palette.setColor(ui->label_3->foregroundRole(), Qt::white);
        ui->label_3->setPalette(palette);
        ui->label_4->setNum(Jefe->getvida());
        QPalette palette2 = ui->label_4->palette();
        palette2.setColor(ui->label_4->foregroundRole(), Qt::white);
        ui->label_4->setPalette(palette2);
    }
    l3->setOpacity(0);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
    scene->addItem(Muk);
}

void Form::setnivel(int n)
{
    nivel = n;
}

void Form::setniveltotal(int n)
{
    niveltotal = n;
}
void Form::animar()
{
    coliciones();
    moverbalas();
    teclas();
    moverenemigos();
    moverjefe();
}
void Form::coliciones()//se verifica las coliciones por las cuales el personaja baja o se queda estable en la scena
{
    if(!Muk->collidingItems().empty())
    {
        if(Muk->collidingItems().size() < 2)
        {
            //colicciones con limites veticales
            if((Muk->collidesWithItem(l2) || Muk->collidesWithItem(l4)) && con2 > 20) b2 = 1, con2 = 22;
            else b2 = 0;
        }
        else b2 = 0;
        if(b2 == 0)
        {
            for(int i = 0; i < r.size(); i++)//colicciones con las barras
            {
                if(Muk->collidesWithItem(r.at(i)))
                {
                    if(Muk->pos().y() > r.at(i)->pos().y()-34)
                    {
                        bt3 = 0;
                        bt4 = 0;
                        b2 = 1;
                        con2 = 22;
                    }
                    else b2 = 0, Muk->setPos(Muk->x(),r.at(i)->pos().y()-39);
                    break;
                }
                else if(con2 > 20) b2 = 1;
            }
        }
        if(Muk->collidesWithItem(l3)) b2 = 0;
        if(Muk->collidesWithItem(l1)) b2 = 1, con2 = 22;
        if(jefe != 0)
        {
            if(Muk->collidesWithItem(Jefe) && con2 > 20)
            {
                if(Muk->collidingItems().size() < 2) b2 =1;
                else if(Muk->collidingItems().size() == 2 && (Muk->collidesWithItem(l2) || Muk->collidesWithItem(l4))) b2 = 1;
            }
        }
    }
    else if(con2 == 0) con2 = 22;
}
void Form::teclas()//se realiza acciones con las teclas seleccionadas
{
    Muk->movMuk(d);
    if(bt1 == 1 && b == 0)//tecla de tiro rectilineo
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(1);//tiro rectilineo
        bala.last()->setact(1);
        Muk->disMuk(d);
    }
    if(bt2 == 1 && b == 0)//tecla de tiro parabolico
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(0);//tiro parabolico
        bala.last()->setact(1);
        Muk->disMuk(d);
    }
    if(bt3 == 1 && !Muk->collidesWithItem(l4)) Muk->setPos(Muk->x()-m, Muk->y());
    if(bt4 == 1 && !Muk->collidesWithItem(l2)) Muk->setPos(Muk->x()+m, Muk->y());
    if(nivel != 7 && nivel != 5)if(Muk->x() > 600 && Muk->x() < 1740) scene->setSceneRect(Muk->x()-600,0,scene->width(), scene->height());
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
    if(ene.length() < 1 &&  Muk->collidesWithItem(l5))
    {
        if(nivel >= niveltotal) niveltotal = nivel+1;
        mensaje(QString("Nivel Completo"));
    }
}
void Form::moverenemigos()//se mueven y se agregan balas
{
    con3++;
    for(int i = 0; i<ene.length(); i++)
    {
        if(ene.at(i)->getpx() < ene.at(i)->getpx1() || ene.at(i)->getpx() > ene.at(i)->getpx2()) ene.at(i)->setd(-1);
        ene.at(i)->mover(1);// se mueve enemigo
        if(nivel == 1 || nivel == 2) ene.at(i)->movsapo(ene.at(i)->getd());
        else if(nivel == 3 || nivel == 5) ene.at(i)->movara(ene.at(i)->getd());
        else if(nivel == 4)
        {
            if(ene.at(i)->gett() == 1) ene.at(i)->movsapo(ene.at(i)->getd());
            else ene.at(i)->movara(ene.at(i)->getd());
        }
        ene.at(i)->setPos(ene.at(i)->getpx(), ene.at(i)->y());
        if(con3 > 15)
        {//se agregabala
            if(ene.at(i)->gett() == 1 && Muk->y() < ene.at(i)->y()+200 && Muk->y() > ene.at(i)->y()-300)
            {
                if(ene.at(i)->getpx() < Muk->x()) agregarbala(ene.at(i), 1);
                else agregarbala(ene.at(i), -1);
                bala.last()->getbaf()->setvx(ene.at(i)->getvx());
                bala.last()->getbaf()->seta(ene.at(i)->gett());
                if(nivel == 1 || nivel == 2) bala.last()->balasapo();
                if(nivel == 3) bala.last()->setact(2), bala.last()->balasapo();
                if(nivel == 4) bala.last()->balasapo();
            }
            else if(ene.at(i)->gett() == 0 && Muk->x() < ene.at(i)->x()+500 && Muk->x() > ene.at(i)->x()-500)
            {
                if(ene.at(i)->getpx() < Muk->x()) agregarbala(ene.at(i), 1);
                else agregarbala(ene.at(i), -1);
                bala.last()->getbaf()->setvx(ene.at(i)->getvx());
                bala.last()->getbaf()->seta(ene.at(i)->gett());
                if(nivel == 1 || nivel == 2) bala.last()->balasapo();
                if(nivel == 3) bala.last()->setact(2), bala.last()->balasapo();
                else if(nivel == 4 && ene.at(i)->gett() == 0) bala.last()->setact(2), bala.last()->balasapo();
            }
        }
    }
    if(con3 > 15) con3 = 0;
}
void Form::moverjefe()//funcion que contiene los jefes y sus acciones
{
    if(jefe == 1)//mov de jefe 1
    {
        if(Muk->x() >= Jefe->x() && con4 == 0) con4 = 46;
        else if(Muk->x() < Jefe->x() && con4 == 0) con4 = 26;
        if(Muk->collidesWithItem(Jefe))
        {
            bt3 = 0, bt4 = 0;
            if(b4 == 0) b4 = 1, Muk->setvida(Muk->getvida()-1), ui->label_2->setNum(Muk->getvida());
        }
        else b4 = 0;
        if(con4 > 26 && !Jefe->collidesWithItem(l2))
        {
            if(con4 > 36)Jefe->setPos(Jefe->x()+8, Jefe->y()-7);
            else Jefe->setPos(Jefe->x()+8, Jefe->y()+7);
            Jefe->movsapoj(1);
        }
        else if(con4 > 2 && !Jefe->collidesWithItem(l4))
        {
            if(con4 > 14)Jefe->setPos(Jefe->x()-8, Jefe->y()-7);
            else Jefe->setPos(Jefe->x()-8, Jefe->y()+7);
            Jefe->movsapoj(-1);
        }
        if(con4 == 27 || con4 == 3) con4 = 1;
        if(Jefe->collidesWithItem(l4) || Jefe->collidesWithItem(l2))
        {
            if(!Jefe->collidesWithItem(l3)) Jefe->setPos(Jefe->x(), Jefe->y()+6), con4 = 2;
            else if(con4 > 0) con4 = -30, a = 1;
            else con4 += 2;
        }
        if(con4 == 1) a = 0;
        if(Jefe->getvida() == 0)
        {
            timer->stop();
            if(nivel >= niveltotal) niveltotal = nivel+1;
            mensaje(QString("Nivel Completo"));
        }
        con4--;
    }
    else if(jefe == 2)//mov del jefe 2
    {
        if(con4 > 8) con4 = 0;
        if(con4 == 0 && Muk->x() < 1200)
        {
            agregarbala(Jefe, -1);
            bala.last()->getbaf()->tiroa(Jefe->x(),Jefe->y(),Muk->x(),Muk->y());
            bala.last()->getbaf()->seta(2);
            bala.last()->setact(2);
            bala.last()->getbaf()->setvx(11);
            bala.last()->balasapo();
        }
        if(Muk->x() > 1000 && con4 == 0 && Muk->x() < 1200)
        {
            bala.last()->getbaf()->setx(Jefe->x()+30);
            bala.last()->getbaf()->sety(Jefe->y()+70);
            bala.last()->setPos(bala.last()->getbaf()->getx(), bala.last()->getbaf()->gety());
            bala.last()->getbaf()->setvx(9);
            bala.last()->getbaf()->tiroa(Jefe->x()+30 ,Jefe->y()+70,Muk->x(),Muk->y());
        }
        if(b4 == 0) Jefe->setPos(Jefe->x(), Jefe->y()-6), t->setPos(t->x(), t->y()-6);
        else Jefe->setPos(Jefe->x(), Jefe->y()+6), t->setPos(t->x(), t->y()+6);
        if(Jefe->y() < 80) b4 = 1;
        else if(Jefe->y() > 350) b4 = 0;
        if(Jefe->getvida() == 0)
        {
            timer->stop();
            if(nivel >= niveltotal) niveltotal = nivel+1;
            mensaje(QString("FIN"));
        }
        con4++;
        aj = 1;
    }
    else if(jefe == 4)
    {
        if(bt8 == 1 && b6 == 0)//se agrega bala
        {
            b6 = 1;
            agregarbala(Jefe, d2);
            bala.last()->getbaf()->seta(1);//tiro rectilineo
            bala.last()->setact(1);
            Jefe->disMuk(d2);
        }
        if(bt9 == 1 && b6 == 0)// se agrega bala
        {
            b6 = 1;
            agregarbala(Jefe, d2);
            bala.last()->getbaf()->seta(0);//tiro parabolico
            bala.last()->setact(1);
            Jefe->disMuk(d2);
        }
        Jefe->movMuk(d2);
        if(bt6 == 1 && !Jefe->collidesWithItem(l4)) Jefe->setPos(Jefe->x()-8, Jefe->y());
        if(bt7 == 1 && !Jefe->collidesWithItem(l2)) Jefe->setPos(Jefe->x()+8, Jefe->y());
        if(con5 < 20 && b5 == 0)//condiciones de salto
        {
            Jefe->setPos(Jefe->x(), Jefe->y()-8);//salto
            con5 ++;
        }
        //condiones de caida
        else if(Jefe->collidingItems().empty() || b5 == 1) Jefe->setPos(Jefe->x(), Jefe->y()+8);
        else
        {
            if(con5 > 100) con5 = 20;
            con5++;
        }
        b5 = 0;
        for(int i = 0; i < r.length(); i++)// se verifica coliccion con las barras
        {
            if(Jefe->collidesWithItem(r.at(i)))
            {
                if((Jefe->pos().y()+35) > r.at(i)->pos().y())
                {
                    con5 = 22;
                    bt6 = 0;
                    bt7 = 0;
                    b5 = 1;
                }
                else b5 = 0;
                break;
            }
        }
        if(!Jefe->collidingItems().empty() && b5 == 0)
        {
            if(Jefe->collidingItems().size() < 2)
            {
                if((Jefe->collidesWithItem(l2) || Jefe->collidesWithItem(l4)) && con5 > 20) b5 = 1, con5 = 22;
                else b5 = 0;
            }
            else b5 = 0;
            if(Jefe->collidesWithItem(Muk) && Jefe->pos().y() < Muk->pos().y() && con5 > 20) b5 =1;
            if(Jefe->collidesWithItem(l1)) b5 = 1, con5 = 22;
        }
        if(Jefe->collidesWithItem(l3)) b5 = 0;
        if (b6 == 1) con6++;
        if(con6 > 12) con6 = 0, b6 = 0;
        if(Jefe->getvida() < 1 || Muk->getvida() < 1)
        {
            timer->stop();//se define si un jugador gano o si hubo un empate
            if(Muk->getvida() < 1 && Jefe->getvida() > 0) mensaje(QString("Ganador P2"));
            else if(Muk->getvida() > 0 && Jefe->getvida() < 1) mensaje(QString("Ganador P1"));
            else mensaje(QString("Empate"));
        }
    }
}
void Form::moverbalas()//se mueven balas sus coliciones y cuando se le quita vida a los miembros de la scena
{
    QList<int> l;
    bool e;
    for(int i = 0;i < bala.length(); i++)
    {
        e = 1;
        bala.at(i)->getbaf()->mover();//se llama la funcion que mueve la parte fisica de las balas
        bala.at(i)->setPos(bala[i]->getbaf()->getx(), bala[i]->getbaf()->gety());
        if(bala.at(i)->x() < 0 || bala.at(i)->x() > 2500 || bala.at(i)->y() < 0 || bala.at(i)->y() > 600)
        {
            if(!l.contains(i))l.append(i); //si la bala se sale de los limites re agrega a lista a borrar
            e = 0;
        }
        if(!bala.at(i)->collidingItems().empty() && e == 1)
        {
            //si la bala coliciona con Muk este pierde vida
            if(Muk->collidesWithItem(bala.at(i))) Muk->setvida(Muk->getvida()-1), ui->label_2->setNum(Muk->getvida());
            //si la vida de Muk es menor a 1 se regresa a seleccion de niveles
            if(Muk->getvida() < 1 && nivel != 7) timer->stop(), mensaje(QString("Has Fallado"));
            if(bala.at(i)->getact() == 2 && Muk->collidesWithItem(bala.at(i))) m = 4, con7 = 0;
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
                if(a == 1)
                {
                    if(Jefe->collidesWithItem(bala.at(i)))
                    {
                        Jefe->setvida(Jefe->getvida()-1), ui->label_4->setNum(Jefe->getvida());
                    }
                }
            }
            if(!l.contains(i))l.append(i);
            for(int j = 0; j < bala.length(); j++)
            {
                if(j != i && bala.at(l.last())->collidesWithItem(bala.at(j)))
                {
                    if(!l.contains(j)) l.append(j);
                }
            }
        }
    }
    if (b == 1) con++;
    if(con > 11) con = 0, b = 0;
    if(m == 4)
    {
        con7++;
    }
    if(con7 == 24) m = 8, con7 = 0;
    std::sort(l.begin(),l.end());
    while(l.length() > 0)
    {
        scene->removeItem(bala.at(l.last()));
        bala.removeAt(l.last());
        l.removeLast();
    }
}
void Form::agregarbala(muk *m, int di)//se agrega bala
{
    bala.append(new balas());
    bala.last()->getbaf()->setx(m->x()+(di*60));//se da posicion x
    bala.last()->getbaf()->sety(m->y());//se da posicion y
    bala.last()->getbaf()->setd(di);//se da direccion
    bala.last()->setPos(bala.last()->getbaf()->getx(), bala.last()->getbaf()->gety());//se da pocion en la scena
    scene->addItem(bala.last());
}
void Form::keyPressEvent(QKeyEvent *event){//funcion que detecta cuando se preciona una tecla
    if(event->key()==Qt::Key_Space) bt1 = 1;
    else if(event->key()==Qt::Key_M) bt2 = 1;
    if(event->key()==Qt::Key_U) bt8 = 1;
    else if(event->key()==Qt::Key_O) bt9 = 1;
    if(event->key()==Qt::Key_A) d = -1, bt3 = 1;
    if(event->key()==Qt::Key_D) d = 1, bt4 = 1;
    if(event->key()==Qt::Key_W && con2 > 22) con2 = 0;
    if(event->key()==Qt::Key_G) guardar();
    if(event->key()==Qt::Key_C) cargar();
    if(event->key()==Qt::Key_J) d2 = -1, bt6 = 1;
    if(event->key()==Qt::Key_L) d2 = 1, bt7 = 1;
    if(event->key()==Qt::Key_I && con5 > 22) con5 = 0;
}
void Form::keyReleaseEvent(QKeyEvent *event)//funcion que detecta cuando se suelta una tecla
{
    if(event->key()==Qt::Key_Space) bt1 = 0;
    if(event->key()==Qt::Key_M) bt2 = 0;
    if(event->key()==Qt::Key_A) bt3 = 0;
    if(event->key()==Qt::Key_D) bt4 = 0;
    if(event->key()==Qt::Key_J) bt6 = 0;
    if(event->key()==Qt::Key_L) bt7 = 0;
    if(event->key()==Qt::Key_U) bt8 = 0;
    if(event->key()==Qt::Key_O) bt9 = 0;
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

void Form::guardar()//se escribe en un archivo de texto los avances del usuario
{
   if(nivel != 7)
   {
       timer->stop();
       QFile file(usu);// se guardan los datos de la scena en un archivo de texto
       file.open(QIODevice::WriteOnly | QIODevice::Truncate  | QIODevice::Text);
       QTextStream text(&file);
       text<< niveltotal;//se guardan el niveltotal en el primer renglon del archivo
       text<< "  \n";
       text<< level;//se guardan el level en un archivo
       text<< "  \n";
       text<< nivel;//se guarda nivel en un renglon
       text<< "  \n";
       for(int j = 0; j < ene.size(); j++)// en un renglo se guarda los datos de los enemigos
       {
           text<< ene.at(j)->getpx();
           text<< " ";
           text<< ene.at(j)->pos().y();
           text<< " ";
           text<< ene.at(j)->getpx1();
           text<< " ";
           text<< ene.at(j)->getpx2();
           text<< " ";
           text<< ene.at(j)->getvida();
           text<< " ";
           text<< ene.at(j)->getvx();
           text<< " ";
           text<< ene.at(j)->getd();
           text<< " ";
           text<< ene.at(j)->gett();
           text<< " ";
           text<< '\n';
       }
       text<<"# \n";
       for(int i = 0; i < bala.length(); i++)// en un renglo se guarda los datos de las balas
       {
           text<< bala.at(i)->pos().x();
           text<< " ";
           text<< bala.at(i)->pos().y();
           text<< " ";
           text<< bala.at(i)->getbaf()->getd();
           text<< " ";
           text<< bala.at(i)->getbaf()->getvy();
           text<< " ";
           text<< bala.at(i)->getbaf()->geta();
           text<< " ";
           text<< bala.at(i)->getact();
           text<<" ";
           text<< bala.at(i)->getbaf()->getvx();
           text<<" ";
           text<< bala.at(i)->getbaf()->getb();
           text<<" ";
           text<< bala.at(i)->getbaf()->getp();
           text<<" ";
           text<<'\n';
       }
       text<<"## \n";
       text<<Muk->pos().x();//se guardan los datos del personaje principal
       text<<" ";
       text<<Muk->pos().y();
       text<<" ";
       text<<Muk->getvida();
       text<<" ";
       text<<d;
       text<<" ";
       text<<con2;
       text<<" ";
       text<<b2;
       text<<" ";
       text<<'\n';
       text<<"### \n";
       if(nivel == 2 || nivel == 5)//se guardan los datos de los jefes
       {
           text<<Jefe->pos().x();
           text<<" ";
           text<<Jefe->pos().y();
           text<<" ";
           text<<Jefe->getvida();
           text<<" ";
           text<<con4;
           text<<" ";
           text<<a;
           text<<" ";
           text<<'\n';
       }
       text<<"#### \n";
       file.close();
       timer->start(40);
   }
}

void Form::cargar()//se carga los progresos de un usuario
{
    timer->stop();
    QFile file(usu);
    if(nivel != 7 && file.exists())//se verifica la existencia del archivo de texto
    {
        QString linea;
        file.open(QIODevice::ReadOnly);
        linea = file.readLine();
        int n = 0;
        n = linea.indexOf(" ");
        niveltotal = linea.left(n).toInt();//se lee la primera linea y se guarda el nivel total
        linea = file.readLine();
        n = linea.indexOf(" ");
        level = linea.left(n).toInt();//se lee la linea y se guarda en level
        linea = file.readLine();
        n = linea.indexOf(" ");
        nivel = linea.left(n).toInt();//se lee la linea y se guarda en nivel
        inicializacion();
        timer->stop();
        for(int i = 0; i<ene.size(); i++) scene->removeItem(ene.at(i));
        ene.clear();
        for(int i = 0; i<bala.size(); i++) scene->removeItem(bala.at(i));
        bala.clear();
        linea = file.readLine();
        while(linea != "# \r\n")//se leen los datos y se configuran los enemigos
        {
            ene.append(new muk());
            int n=0;
            int n2 = 0;
            while(n>=0){
                n = linea.indexOf(" ");
                if(n!=0){
                    if(n2 == 0) ene.last()->setpx(linea.left(n).toInt());
                    else if(n2 == 1) ene.last()->setPos(ene.last()->getpx(),linea.left(n).toInt());
                    else if(n2 == 2) ene.last()->setpx1(linea.left(n).toInt());
                    else if(n2 == 3) ene.last()->setpx2(linea.left(n).toInt());
                    else if(n2 == 4) ene.last()->setvida(linea.left(n).toInt());
                    else if(n2 == 5) ene.last()->setvx(linea.left(n).toInt());
                    else if(n2 == 6) ene.last()->setd(linea.left(n).toInt());
                    else if(n2 == 7) ene.last()->sett(linea.left(n).toInt()), scene->addItem(ene.last());
                    if(nivel == 1 || nivel == 2) ene.last()->movsapo(ene.last()->getd());
                    n2++;
                }
                if(linea.left(n) == "\r\n")
                {
                    linea=linea.remove(0,n+1);
                    break;
                }
                linea=linea.remove(0,n+1);
            }
            linea = file.readLine();
        }
        linea = file.readLine();
        while(linea != "## \r\n")//se leen los datos y se configuran los balas
        {
            bala.append(new balas());
            int n=0;
            int n2 = 0;
            while(n>=0){
                n = linea.indexOf(" ");
                if(n!=0){
                    if(n2 == 0) bala.last()->getbaf()->setx(linea.left(n).toInt());
                    else if(n2 == 1) bala.last()->getbaf()->sety(linea.left(n).toInt());
                    else if(n2 == 2) bala.last()->getbaf()->setd(linea.left(n).toInt());
                    else if(n2 == 3) bala.last()->getbaf()->setvy(linea.left(n).toInt());
                    else if(n2 == 4) bala.last()->getbaf()->seta(linea.left(n).toInt());
                    else if(n2 == 5) bala.last()->setact(linea.left(n).toInt());
                    else if(n2 == 6) bala.last()->getbaf()->setvx(linea.left(n).toInt());
                    else if(n2 == 7) bala.last()->getbaf()->setb(linea.left(n).toInt());
                    else if(n2 == 8) bala.last()->getbaf()->setp(linea.left(n).toInt()), scene->addItem(bala.last());
                    n2++;
                }
                if(linea.left(n) == "\r\n")
                {
                    linea=linea.remove(0,n+1);
                    break;
                }
                linea=linea.remove(0,n+1);
            }
            linea = file.readLine();
        }
        linea = file.readLine();
        while(linea != "### \r\n")//se lee la linea y se le da los valores a Muk
        {
            int n=0;
            int n2 = 0;
            while(n>=0){
                n = linea.indexOf(" ");
                if(n!=0){
                    if(n2 == 0) Muk->setpx(linea.left(n).toInt());
                    else if(n2 == 1) Muk->setPos(Muk->getpx(), linea.left(n).toInt());
                    else if(n2 == 2) Muk->setvida(linea.left(n).toInt()), ui->label_2->setNum(linea.left(n).toInt());
                    else if(n2 == 3) d = linea.left(n).toInt();
                    else if(n2 == 4) con2 = linea.left(n).toInt();
                    else if(n2 == 5) b2 = linea.left(n).toInt();
                    n2++;
                }
                if(linea.left(n) == "\r\n")
                {
                    linea=linea.remove(0,n+1);
                    break;
                }
                linea=linea.remove(0,n+1);
            }
            linea = file.readLine();
        }
        linea = file.readLine();
       while(linea != "#### \r\n")//se lee la linea y se le da los valores a Jefe
        {
            int n=0;
            int n2 = 0;
            while(n>=0){
                n = linea.indexOf(" ");
                if(n!=0){
                    if(n2 == 0) Jefe->setpx(linea.left(n).toInt());
                    else if(n2 == 1) Jefe->setPos(Jefe->getpx(), linea.left(n).toInt());
                    else if(n2 == 2) Jefe->setvida(linea.left(n).toInt());
                    else if(n2 == 3) con4 = linea.left(n).toInt();
                    else if(n2 == 4) a = linea.left(n).toInt();
                    n2++;
                }
                if(linea.left(n) == "\r\n")
                {
                    linea=linea.remove(0,n+1);
                    break;
                }
                linea=linea.remove(0,n+1);
            }
            linea = file.readLine();
        }
    }
    file.close();
    timer->start(40);
}

void Form::setusuario(QString nom)
{
    usu = nom;//se recive el usuario
}

void Form::mensaje(QString men)
{
    timer->stop();
    QFont f("PMingLiU-ExtB", 20);
    ui->label_5->setText(QString(men));
    ui->label_5->setFont(f);
    QPalette palette = ui->label_5->palette();
    palette.setColor(ui->label_5->foregroundRole(), Qt::white);
    ui->label_5->setPalette(palette);
    QFont f2("PMingLiU-ExtB", 15);
    ui->label_6->setText(QString("Nota: Para guardar tu progreso durante un nivel preciona G"));
    ui->label_6->setFont(f2);
    QPalette palette2 = ui->label_6->palette();
    palette2.setColor(ui->label_6->foregroundRole(), Qt::white);
    ui->label_6->setPalette(palette2);//se pone formato al texto que se mostrara en pantalla
    connect(timer,SIGNAL(timeout()),this,SLOT(final()));//se redefine la respuesta del timer para finalizar
    timer->start(5500);
}

void Form::setlevel(int l)
{
    level = l;
}
void Form::final()
{
    QFile file(usu);//se verifica si el archivo de texto existe
    if(file.exists())
    {//se guarda el nivel total en el ultimo punto de acceso
        int t = niveltotal;
        cargar();
        niveltotal = t;
        guardar();
    }
    file.close();
    timer->stop();
    if(nivel != 7)
    {//se regresa al menu de seleccion de niveles
        principal *p = new principal();
        p->setniveltotal(niveltotal);
        p->show();
    }
    else
    {//si nivel es 7(multijugador) se regresa al menu principal
        MainWindow *p = new MainWindow();
        p->show();
    }
    close();
}
