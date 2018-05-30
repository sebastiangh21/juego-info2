#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new principal();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_play_clicked()
{
    a->show();
    close();
}

void MainWindow::on_controles_clicked()
{
    c = new controles();
    c->show();
    close();
}
