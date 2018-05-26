#ifndef BALAFISICA_H
#define BALAFISICA_H


class balafisica
{
private:
    int x, y, d, vy, ay;
    bool a;
public:
    balafisica();
    void mover();
    int getx();
    int gety();
    void setx(int b);
    void sety(int c);
    void setd(int e);
    void seta(bool r);
};

#endif // BALAFISICA_H
