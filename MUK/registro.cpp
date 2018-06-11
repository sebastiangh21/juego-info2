#include "registro.h"
#include "ui_registro.h"
#include "QDebug"
#include "QMessageBox"
#include "form.h"

registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    Creartabla();
}
registro::~registro()
{
    delete ui;
}
void registro::Creartabla()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuario("
                    "nombre VARCHAR(25),"
                    "pass VARCHAR(25),"
                    "nick VARCHAR(25) PRIMARY KEY"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug() << "Tabla creada";}
    else{ qDebug() << " Tabla no creada"<< crear.lastError();}
}
void registro::on_pushButton_clicked()
{
    QString user= ui->Usuario->text();
    QString contra= ui->Contra->text();
    QString nick= ui->nick->text();
    QString insertar;
    insertar.append(" INSERT INTO usuario(nombre,pass,nick)"
                    " VALUES (:nombre,:pass,:nick)");
    QSqlQuery insertar_db;
    insertar_db.prepare(insertar);
    insertar_db.bindValue(":nombre", user);
    insertar_db.bindValue(":pass", contra);
    insertar_db.bindValue(":nick",nick);
    if(insertar_db.exec()){
        QMessageBox::information(this,tr("Exito"),tr("Registro Exitoso"));
        close();
    }
    else{
        QMessageBox::critical(this,tr("ERROR"),tr("El nickname ya esta en uso"));
    }
}
