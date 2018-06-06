#include "form.h"
#include "ui_form.h"
#include "principal.h"
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QTextStream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    timer =new QTimer();
    timer->start(40);
}
void Form::inicializacion()
{
    Muk = new muk();
    Muk->setPos(0, 550);
    Muk->setvida(15);
    Muk->setvx(15);
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
    if(nivel == 1)
    {
        scene->setSceneRect(0,0,2500,700);//1350 700
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,100);
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(80, 350);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 450);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(950, 500);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(500, 205);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,350,20));
        r.last()->setPos(1000, 100);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,250,20));
        r.last()->setPos(10, 130);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(205,285);
        scene->addItem(ene.last());
        ene.last()->setpx(205);
        ene.last()->setpx1(90);
        ene.last()->setpx2(300);
        ene.last()->sett(0);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(135,65);
        scene->addItem(ene.last());
        ene.last()->setpx(135);
        ene.last()->setpx1(20);
        ene.last()->setpx2(233);
        ene.last()->sett(1);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(625,140);
        scene->addItem(ene.last());
        ene.last()->setpx(625);
        ene.last()->setpx1(520);
        ene.last()->setpx2(730);
        ene.last()->sett(1);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(1075,435);
        scene->addItem(ene.last());
        ene.last()->setpx(1075);
        ene.last()->setpx1(970);
        ene.last()->setpx2(1170);
        ene.last()->sett(0);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
    }
    else if(nivel == 2)
    {
        scene->setSceneRect(0,0,2500,700);//1350 700
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setFixedSize(2500,700);
        scene->setBackgroundBrush(QBrush(QImage(":/fondo")));
        l1=new QGraphicsLineItem(0,0,2500,0);
        l2=new QGraphicsLineItem(2500,0,2500,600);
        l3=new QGraphicsLineItem(0,600,2500,600);
        l4=new QGraphicsLineItem(0,0,0,2500);
        l5=new QGraphicsLineItem(2500,0,2500,100);
        jefe = 1;
        Jefe = new muk();
        Jefe->imagen(QString(":/sapo1.png"));
        Jefe->setPos(1200, 555);
        Jefe->setvida(20);
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
        r.last()->setPos(200, 250);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        r.append(new QGraphicsRectItem(0,0,100,20));
        r.last()->setPos(950, 250);
        r.last()->setBrush(QBrush(":/barra"));
        scene->addItem(r.last());
        ene.append(new muk());
        ene.last()->setPos(150,185);
        scene->addItem(ene.last());
        ene.last()->setpx(205);
        ene.last()->setpx1(200);
        ene.last()->setpx2(300);
        ene.last()->sett(0);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
        ene.append(new muk());
        ene.last()->setPos(1000,185);
        scene->addItem(ene.last());
        ene.last()->setpx(1000);
        ene.last()->setpx1(950);
        ene.last()->setpx2(1050);
        ene.last()->sett(0);
        ene.last()->setvx(10);
        ene.last()->setvida(4);
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
    teclas();
    moverbalas();
    moverenemigos();
    moverjefe();
}
void Form::coliciones()
{
    if(!Muk->collidingItems().empty())
    {
        if(Muk->collidingItems().size() < 2)
        {
            if((Muk->collidesWithItem(l2) || Muk->collidesWithItem(l4)) && con2 > 20) b2 = 1, con2 = 22;
            else b2 = 0;
        }
        else b2 = 0;
        if(b2 == 0)
        {
            for(int i = 0; i < r.size(); i++)
            {
                if(Muk->collidesWithItem(r.at(i)))
                {
                    if((Muk->pos().y()+35) > r.at(i)->pos().y())
                    {
                        bt3 = 0;
                        bt4 = 0;
                        b2 = 1;
                        con2 = 22;
                    }
                    else b2 = 0;
                    break;
                }
                else if(con2 > 20) b2 = 1;
            }
        }
        if(Muk->collidesWithItem(l3)) b2 = 0;
        if(Muk->collidesWithItem(l1)) b2 = 1, con2 = 22;
        if(jefe != 0)
        {
            if(Muk->collidesWithItem(Jefe) && Muk->pos().y() < 545 && con2 > 20) b2 =1;
        }

    }
}
void Form::teclas()
{
    Muk->movMuk(d);
    if(bt1 == 1 && b == 0)
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(1);//tiro rectilineo
        bala.last()->setact(1);
        Muk->disMuk(d);
    }
    if(bt2 == 1 && b == 0)
    {
        b = 1;
        agregarbala(Muk, d);
        bala.last()->getbaf()->seta(0);//tiro parabolico
        bala.last()->setact(1);
        Muk->disMuk(d);
    }
    if(bt3 == 1 && !Muk->collidesWithItem(l4)) Muk->setPos(Muk->x()-8, Muk->y());
    if(bt4 == 1 && !Muk->collidesWithItem(l2)) Muk->setPos(Muk->x()+8, Muk->y());
    if(Muk->x() > 400 && Muk->x() < 1540) scene->setSceneRect(Muk->x()-400,0,2500,700);
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
    if(ene.length() < 1 )//&&  Muk->collidesWithItem(l5))
    {
        timer->stop();
        if(nivel >= niveltotal) niveltotal = nivel+1;
        int t = niveltotal;
        cargar();
        connect(timer,SIGNAL(timeout()),this,SLOT(final()));
        timer->start(1000);
        niveltotal = t;
        guardar();
        QFont f("PMingLiU-ExtB", 20);
        ui->label_5->setText(QString("Nivel Completo"));
        ui->label_5->setFont(f);
        QPalette palette = ui->label_5->palette();
        palette.setColor(ui->label_5->foregroundRole(), Qt::white);
        ui->label_5->setPalette(palette);
    }
}
void Form::moverenemigos()
{
    con3++;
    for(int i = 0; i<ene.length(); i++)
    {
        if(ene.at(i)->getpx() < ene.at(i)->getpx1() || ene.at(i)->getpx() > ene.at(i)->getpx2()) ene.at(i)->setd(-1);
        ene.at(i)->mover(1);
        if(nivel == 1 || nivel == 2) ene.at(i)->movsapo(ene.at(i)->getd());
        ene.at(i)->setPos(ene.at(i)->getpx(), ene.at(i)->y());
        if(con3 > 15)
        {
            if(ene.at(i)->getpx() < Muk->x()) agregarbala(ene.at(i), 1);
            else agregarbala(ene.at(i), -1);
            bala.last()->getbaf()->setvx(ene.at(i)->getvx());
            bala.last()->getbaf()->seta(ene.at(i)->gett());
        }
    }
    if(con3 > 15) con3 = 0;
}
void Form::moverjefe()
{
    if(jefe == 1)
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
        }
        else if(con4 > 2 && !Jefe->collidesWithItem(l4))
        {
            if(con4 > 14)Jefe->setPos(Jefe->x()-8, Jefe->y()-7);
            else Jefe->setPos(Jefe->x()-8, Jefe->y()+7);
        }
        if(con4 == 27 || con4 == 3) con4 = 1;
        if(Jefe->collidesWithItem(l4) || Jefe->collidesWithItem(l2))
        {
            if(!Jefe->collidesWithItem(l3)) Jefe->setPos(Jefe->x(), Jefe->y()+6), con4 = 2;
            else if(con4 > 0) con4 = -30, a = 1;
            else con4 += 2;
        }
        if(con4 == 1) a = 0;
        if(Jefe->getvida() == 0) timer->stop();
        con4--;
    }
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
                if(a == 1)
                {
                    if(Jefe->collidesWithItem(bala.at(i)))
                    {
                        Jefe->setvida(Jefe->getvida()-1), ui->label_4->setNum(Jefe->getvida());
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
    bala.last()->getbaf()->setx(m->x()+(di*50));
    bala.last()->getbaf()->sety(m->y()-(40));
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
    if(event->key()==Qt::Key_G) guardar();
    if(event->key()==Qt::Key_L) cargar();
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

void Form::guardar()
{
    timer->stop();
    QFile file(usu);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate  | QIODevice::Text);
    QTextStream text(&file);
    text<< niveltotal;
    text<< "  \n";
    text<< nivel;
    text<< "  \n";
    for(int j = 0; j < ene.size(); j++)
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
    for(int i = 0; i < bala.length(); i++)
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
        text<<'\n';
    }
    text<<"## \n";
    text<<Muk->pos().x();
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
    if(nivel == 2)
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

void Form::cargar()
{
    timer->stop();
    QString linea;
    QFile file(usu);
    file.open(QIODevice::ReadOnly);
    linea = file.readLine();
    int n = 0;
    n = linea.indexOf(" ");
    niveltotal = linea.left(n).toInt();
    linea = file.readLine();
    n = linea.indexOf(" ");
    nivel = linea.left(n).toInt();
    inicializacion();
    for(int i = 0; i<ene.size(); i++) scene->removeItem(ene.at(i));
    ene.clear();
    for(int i = 0; i<bala.size(); i++) scene->removeItem(bala.at(i));
    bala.clear();
    linea = file.readLine();
    while(linea != "# \r\n")
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
    while(linea != "## \r\n")
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
                else if(n2 == 6) bala.last()->getbaf()->setvx(linea.left(n).toInt()), scene->addItem(bala.last());
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
    while(linea != "### \r\n")
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
   while(linea != "#### \r\n")
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
    file.close();
    timer->start(40);
}

void Form::setusuario(QString nom)
{
    usu = nom;
}
void Form::final()
{
    timer->stop();
    principal *p = new principal();
    p->setniveltotal(niveltotal);
    p->show();
    close();
}
