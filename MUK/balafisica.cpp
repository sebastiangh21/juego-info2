#include "balafisica.h"

balafisica::balafisica()
{
    x = 0, y = 0, d = 0, vy = -13, ay = 1;
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

void balafisica::seta(bool r)
{
    a = r;
}
void balafisica::setx(int b)
{
    x = b;
}
void balafisica::mover()
{
    if (a == true)
    {
        x += (d*17);
    }
    else
    {
        x += (d*17);
        y += vy + ay;
        vy += + ay;
    }
}
