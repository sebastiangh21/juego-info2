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
    ~MainWindow();

private slots:
    void on_play_clicked();

    void on_controles_clicked();

private:
    Ui::MainWindow *ui;
    principal *a;
    controles *c;
};

#endif // MAINWINDOW_H
