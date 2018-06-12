#include "imageinicio.h"
#include "ui_imageinicio.h"
#include <stdlib.h>
#include <login.h>
#include <time.h>

void logi();

imageinicio::imageinicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::imageinicio)
{
    ui->setupUi(this);
    srand (time(NULL));
    pregunta();
    res = {"Oruga","Lagarto","Rana","Paloma","Serpiente"};
}

void imageinicio::pregunta()
{
    ele = rand() % 5 +1;
    if(ele == 1)
    {
        ui->imagen->setPixmap(QPixmap(":/animal1.jpg"));
        ui->imagen->setScaledContents(1);
        ui->opcion1->setText("Rana");
        ui->opcion2->setText("Mantis");
        ui->opcion3->setText("Oruga");
    }
    else if(ele == 2)
    {
        ui->imagen->setPixmap(QPixmap(":/animal2.jpg"));
        ui->imagen->setScaledContents(1);
        ui->opcion1->setText("Iguana");
        ui->opcion2->setText("Lagarto");
        ui->opcion3->setText("Serpiente");
    }
    else if(ele == 3)
    {
        ui->imagen->setPixmap(QPixmap(":/animal3.jpg"));
        ui->opcion1->setText("Rana");
        ui->opcion2->setText("Mariposa");
        ui->opcion3->setText("Oruga");
    }
    else if(ele == 4)
    {
        ui->imagen->setPixmap(QPixmap(":/animal4.jpg"));
        ui->opcion1->setText("Paloma");
        ui->opcion2->setText("Mantis");
        ui->opcion3->setText("Conejo");
    }
    else if(ele == 5)
    {
        ui->imagen->setPixmap(QPixmap(":/animal5.jpg"));
        ui->opcion1->setText("Rana");
        ui->opcion2->setText("Serpiente");
        ui->opcion3->setText("Lagartija");
    }
}

imageinicio::~imageinicio()
{
    delete ui;
}

void imageinicio::on_opcion1_clicked()
{
    if(res.at(ele-1) == ui->opcion1->text())
    {
        logi();
        close();
    }
    else pregunta();
    ui->opcion1->setCheckable(0);
}

void imageinicio::on_opcion2_clicked()
{
    if(res.at(ele-1) == ui->opcion2->text())
    {
        logi();
        close();
    }
    else pregunta();
    ui->opcion2->setCheckable(0);
}

void imageinicio::on_opcion3_clicked()
{
    if(res.at(ele-1) == ui->opcion3->text())
    {
        logi();
        close();
    }
    else pregunta();
    ui->opcion3->setCheckable(0);
}

void logi()
{
    login *w = new login();
    w->show();
}
