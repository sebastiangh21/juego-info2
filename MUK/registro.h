#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include "QtSql/qsqldatabase.h"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"

namespace Ui {
class registro;
}

class registro : public QWidget
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = 0);
    ~registro();
    void Creartabla();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registro *ui;
};

#endif // REGISTRO_H
