#ifndef CONTROLES_H
#define CONTROLES_H

#include <QWidget>

namespace Ui {
class controles;
}

class controles : public QWidget
{
    Q_OBJECT

public:
    explicit controles(QWidget *parent = 0);
    ~controles();

private slots:
    void on_volver_clicked();

private:
    Ui::controles *ui;
};

#endif // CONTROLES_H
