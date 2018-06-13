#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "nivel.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new principal();
}

void MainWindow::setusu(QString u)
{
    usu = u;
}

void MainWindow::setlevel(int l)
{
    level = l;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_play_clicked()
{
    QFile file(usu);//se abre seleccion de controles
    if(file.exists())
    {
        QString linea;
        file.open(QIODevice::ReadOnly);
        linea = file.readLine();
        int n = 0;
        n = linea.indexOf(" ");
        a->setniveltotal(linea.left(n).toInt());
        a->setusu(usu);
    }
    else
    {
        a->setniveltotal(1);
        a->setusu(usu);
    }
    file.close();
    a->setlevel(level);
    a->show();
    close();
}

void MainWindow::on_controles_clicked()
{
    c = new controles();//se habre las instrucciones
    c->show();
    close();
}

void MainWindow::on_cargar_clicked()
{
    QFile file(usu);
    if(file.exists())//se carga la ultima partida guardada
    {
        Form *f = new Form();
        f->inicializacion();
        f->setusuario(usu);
        f->cargar();
        f->show();
        close();
    }
    file.close();
}

void MainWindow::on_multi_clicked()
{
    Form *f = new Form();//se habre el multijugador
    f->setnivel(7);
    f->inicializacion();
    f->setusuario(usu);
    f->show();
    close();
}

void MainWindow::on_pushButton_clicked()
{
    nivel *n = new nivel();//muestra la eleccion de dificultad
    n->setusu(usu);
    n->show();
    close();
}
