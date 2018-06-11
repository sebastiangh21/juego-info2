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

void principal::setniveltotal(int n)
{
    niveltotal = n;
}

void principal::setusu(QString u)
{
    usu = u;
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
    if(niveltotal >= 2) nivel = 2;
    else nivel = 0;
}

void principal::on_nivel3_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
    if(niveltotal >= 3) nivel = 3;
    else nivel = 0;
}

void principal::on_nivel4_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel5->setChecked(false);
    ui->nivel6->setChecked(false);
    if(niveltotal >= 4) nivel = 4;
    else nivel = 0;
}

void principal::on_nivel5_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel6->setChecked(false);
    if(niveltotal >= 5) nivel = 5;
    else nivel = 0;
}

void principal::on_nivel6_clicked()
{
    ui->nivel1->setChecked(false);
    ui->nivel2->setChecked(false);
    ui->nivel3->setChecked(false);
    ui->nivel4->setChecked(false);
    ui->nivel5->setChecked(false);
    if(niveltotal >= 6) nivel = 6;
    else nivel = 0;
}

void principal::on_jugar_clicked()
{
    if(nivel != 0)
    {
        a->setnivel(nivel);
        a->setniveltotal(niveltotal);
        a->setusuario(usu);
        a->inicializacion();
        a->show();
        close();
    }
}
