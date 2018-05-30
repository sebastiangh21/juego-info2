#include "balafisica.h"

balafisica::balafisica()
{
    x = 0, y = 0, d = 0, vy = -13, ay = 1, vx = 17;
}

int balafisica::getx()
{
    return x;
}

int balafisica::gety()
{
    return y;
}

void balafisica::sety(int c)
{
    y = c;
}

void balafisica::setd(int e)
{
    d = e;
}

int balafisica::getd()
{
    return d;
}

void balafisica::seta(bool r)
{
    a = r;
}

void balafisica::setvx(int a)
{
    vx = a;
}
bool balafisica::geta()
{
    return a;
}
void balafisica::setvy(int a)
{
    vy = a;
}
int balafisica::getvy()
{
    return vy;
}

int balafisica::getvx()
{
    return vx;
}
void balafisica::setx(int b)
{
    x = b;
}
void balafisica::mover()
{
    if (a == true)
    {
        x += (d*vx);
    }
    else
    {
        x += (d*vx);
        y += vy + ay;
        vy += + ay;
    }
}
