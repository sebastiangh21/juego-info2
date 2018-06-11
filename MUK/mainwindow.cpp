#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"


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
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_play_clicked()
{
    QFile file(usu);
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
    a->show();
    close();
}

void MainWindow::on_controles_clicked()
{
    c = new controles();
    c->show();
    close();
}

void MainWindow::on_cargar_clicked()
{
    QFile file(usu);
    if(file.exists())
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
    Form *f = new Form();
    f->setnivel(7);
    f->inicializacion();
    f->setusuario(usu);
    f->show();
    close();
}
