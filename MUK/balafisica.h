#ifndef BALAFISICA_H
#define BALAFISICA_H


class balafisica
{
private:
    float p, b, x, y, vx , d, vy, ay, a;
public:
    balafisica();
    void mover();
    float getx();
    float gety();
    void setx(float b);
    void sety(float c);
    void setd(float e);
    float getd();
    float getvy();
    float getvx();
    void seta(float r);
    bool geta();
    void setvx(float a);
    void setvy(float a);
    void setp(float e);
    float getp();
    void setb(float e);
    float getb();
    void tiroa(float x1, float y1, float x2, float y2);
};

#endif // BALAFISICA_H
