#ifndef NIVEL_H
#define NIVEL_H

#include <QWidget>

namespace Ui {
class nivel;
}

class nivel : public QWidget
{
    Q_OBJECT

public:
    explicit nivel(QWidget *parent = 0);
    void setusu(QString u);
    ~nivel();

private slots:
    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::nivel *ui;
    int level = 1;
    QString usu;
};

#endif // NIVEL_H
