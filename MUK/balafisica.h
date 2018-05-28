#ifndef BALAFISICA_H
#define BALAFISICA_H


class balafisica
{
private:
    int x, y, d, vy, ay, vx;
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
    void setvx(int a);
};

#endif // BALAFISICA_H
