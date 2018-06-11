#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "QMessageBox"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QString nombre;
    nombre="BaseDeDatos.sqlite";
    dbmain = QSqlDatabase::addDatabase("QSQLITE");
    dbmain.setDatabaseName(nombre);
    if(dbmain.open()){}
    else{qDebug() << "error";}
}

login::~login()
{
    delete ui;
}

void login::on_commandLinkButton_clicked()
{
    QString nick= ui->nick->text();
    QString contra= ui->contra->text();
    QSqlQuery buscar;
    QString pass2;
    QString consulta;
    QString nombre;
    consulta.append("SELECT * FROM usuario where nick= '"+nick+"'");
    buscar.prepare(consulta);
    if(buscar.exec()){
        while(buscar.next()){
            pass2=buscar.value(1).toByteArray().constData();
            nombre=buscar.value(0).toByteArray().constData();
        }}
    else{qDebug()<< "error de consulta";
    QMessageBox::critical(this,tr("ERROR"),tr("Usuario No Existe"));}

    if(pass2==contra){
        QMessageBox::information(this,tr("Bienvenido"),tr("Bienvenido").arg(nombre));
        MainWindow *main= new MainWindow(0);
        nick += ".txt";
        main->setusu(nick);
        main->show();
        close();

    }
    else{
        QMessageBox::critical(this,tr("ERROR"),tr("Contraseña ó Usuario incorrecto"));

    }

}

void login::on_pushButton_clicked()
{
    registro *regis= new registro(0);
    regis->show();
}
