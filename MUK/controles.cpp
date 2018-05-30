#include "controles.h"
#include "ui_controles.h"
#include "mainwindow.h"

controles::controles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controles)
{
    ui->setupUi(this);
}

controles::~controles()
{
    delete ui;
}

void controles::on_volver_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    close();
}
