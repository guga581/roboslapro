
#include "RoboR2-D2.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

RoboR2D2::RoboR2D2(const Point& posIni, Labirinto *l, int maxSteps)
    : Robo(posIni, l, maxSteps)
{
    srand(time(NULL));
    roboTex = CarregaTextura("b9.jpg", false);
    dirInicial = 0;
}

void RoboR2D2::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = posIni.getX();
    int y = posIni.getY();
    steps.push_back(Point(x,y));
    int dx, dy;
    int pontx,ponty;
    dx = x;
    dy = y;
    while(!saiu && cont < maxSteps)
    {
        if((!lab->isEmpty(Point(dx-1, dy))))
        {
            dx-=1;
            steps.push_back(Point(dx,dy));
            pontx=-1;
            ponty=0;
        }

        if(dx >= lab->getWidth() || dx < 0
                || dy >= lab->getHeight() || dy < 0)
        saiu = true;

    }
}

void RoboR2D2::draw()
{
    float rx,ry;
    float deltax = GL::getDeltaX();
    float deltay = GL::getDeltaY();
    rx = pos.getX() * deltax;
    ry = pos.getY() * deltay;
    GL::enableTexture(roboTex->texid);
    GL::setColor(255,255,255);
    GL::drawRect(rx, ry, rx+deltax, ry+deltay);
    GL::disableTexture();
}
