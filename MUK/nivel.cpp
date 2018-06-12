#include "nivel.h"
#include "ui_nivel.h"
#include "mainwindow.h"
#include "QDebug"

nivel::nivel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nivel)
{
    ui->setupUi(this);
}

void nivel::setusu(QString u)
{
    usu = u;
}

nivel::~nivel()
{
    delete ui;
}

void nivel::on_radioButton_2_clicked()
{
    level = 2;
}

void nivel::on_radioButton_clicked()
{
    level = 1;
}

void nivel::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow();
    w->setlevel(level);
    w->setusu(usu);
    w->show();
    close();
}
