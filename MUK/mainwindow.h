#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "principal.h"
#include "controles.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setusu(QString u);
    ~MainWindow();

private slots:
    void on_play_clicked();

    void on_controles_clicked();

    void on_cargar_clicked();

    void on_multi_clicked();

private:
    Ui::MainWindow *ui;
    principal *a;
    controles *c;
    QString usu;
};

#endif // MAINWINDOW_H
