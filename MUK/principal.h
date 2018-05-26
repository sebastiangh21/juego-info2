#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include "form.h"


namespace Ui {
class principal;
}

class principal : public QWidget
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::principal *ui;
    Form *a;
};

#endif // PRINCIPAL_H
