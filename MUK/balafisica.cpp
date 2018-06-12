#include "balafisica.h"

balafisica::balafisica()
{
    x = 0, y = 0, d = 0, vy = -13, ay = 1, vx = 17, a = 0, p = 0, b = 0;
}

float balafisica::getx()
{
    return x;
}

float balafisica::gety()
{
    return y;
}

void balafisica::sety(float c)
{
    y = c;
}

void balafisica::setd(float e)
{
    d = e;
}

float balafisica::getd()
{
    return d;
}

void balafisica::seta(float r)
{
    a = r;
}

void balafisica::setvx(float a)
{
    vx = a;
}
bool balafisica::geta()
{
    return a;
}
void balafisica::setvy(float a)
{
    vy = a;
}

void balafisica::setp(float e)
{
    p = e;
}

float balafisica::getp()
{
    return p;
}

void balafisica::setb(float e)
{
    b = e;
}

float balafisica::getb()
{
    return b;
}
float balafisica::getvy()
{
    return vy;
}

float balafisica::getvx()
{
    return vx;
}
void balafisica::setx(float b)
{
    x = b;
}
void balafisica::tiroa(float x1, float y1, float x2, float y2)
{
    if(x1 == x2) vx = 0;
    else p = (y2-y1)/(x2-x1);
    b = y1-p*x1;
}
void balafisica::mover()
{
    if(a == 0)
    {
        x += (d*vx);
        y += vy + ay;
        vy += + ay;
    }
    else if (a == 1)
    {
        x += (d*vx);
    }
    else if(a == 2)
    {
        x += (d*vx);
        y = p*x + b;
    }
}
