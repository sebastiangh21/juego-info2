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
    dbmain = QSqlDatabase::addDatabase("QSQLITE");// crea una base de datos.
    dbmain.setDatabaseName(nombre); // se le da el nombre a la base de datos
    if(dbmain.open()){}
    else{qDebug() << "error";}
}

login::~login()
{
    delete ui;
}

void login::on_commandLinkButton_clicked()
{
    QString nick= ui->nick->text(); // se guarda el nick ingresado por el usuario
    QString contra= ui->contra->text(); // se guarda la contraseña.
    QSqlQuery buscar; // variable para trabajar sobre la base de datos
    QString pass2;
    QString consulta;
    QString nombre;
    consulta.append("SELECT * FROM usuario where nick= '"+nick+"'"); // guarda el nick para se consultado
    buscar.prepare(consulta); // prepara la busqueda del nick en la base de datos
    if(buscar.exec()){
        while(buscar.next()){ // while que busca hasta encontrar si existe el usuario
            pass2=buscar.value(1).toByteArray().constData();
            nombre=buscar.value(0).toByteArray().constData();
        }}
    else{qDebug()<< "error de consulta"; // else para decir al usuario que el nick o usuario no existe.
    QMessageBox::critical(this,tr("ERROR"),tr("Usuario No Existe"));}

    if(pass2==contra){//  si la contraseña y su usuario son correctos ,entra al juego.
        QMessageBox::information(this,tr("Bienvenido"),tr("Bienvenido").arg(nombre));
        MainWindow *main= new MainWindow(0);
        nick += ".txt";
        main->setusu(nick);
        main->show();
        close();

    }
    else{
        QMessageBox::critical(this,tr("ERROR"),tr("Contraseña ó Usuario incorrecto"));
        // mensaje por si quedo mal el ususario o contraseña y vuelva a intentar



    }

}

void login::on_pushButton_clicked() // boton añadido para poder registrarse
{
    registro *regis= new registro(0);
    regis->show();
}
