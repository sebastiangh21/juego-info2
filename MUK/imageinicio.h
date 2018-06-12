#ifndef IMAGEINICIO_H
#define IMAGEINICIO_H

#include <QWidget>
#include <vector>

namespace Ui {
class imageinicio;
}

class imageinicio : public QWidget
{
    Q_OBJECT

public:
    explicit imageinicio(QWidget *parent = 0);
    void pregunta();
    ~imageinicio();

private slots:
    void on_opcion1_clicked();

    void on_opcion2_clicked();

    void on_opcion3_clicked();

private:
    Ui::imageinicio *ui;
    int ele;
    std::vector<QString> res;
};

#endif // IMAGEINICIO_H
