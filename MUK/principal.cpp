#include "principal.h"
#include "ui_principal.h"

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

void principal::on_pushButton_clicked()
{
    a->getnivel(1);
    a->inicializacion();
    a->show();
    close();
}
