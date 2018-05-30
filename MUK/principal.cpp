#include "principal.h"
#include "ui_principal.h"
#include "mainwindow.h"

principal::principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
    a = new Form();
}

principal::~principal()
{
    delete ui;
}
void principal::on_volver_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    close();
}

void principal::on_nivel1_clicked()
{
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
    nivel = 1;
}

void principal::on_nivel2_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
    nivel = 2;
}

void principal::on_nivel3_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
}

void principal::on_nivel4_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
}

void principal::on_nivel5_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel6->setChecked(false);
}

void principal::on_nivel6_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
}

void principal::on_jugar_clicked()
{
    a->setnivel(nivel);
    a->inicializacion();
    a->show();
    close();
}
