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
<<<<<<< HEAD
    roboTex = CarregaTextura("b9.jpg", false);
    dirInicial = 0;
=======
    roboTex = CarregaTextura("r2.jpg", false);
>>>>>>> 491a9608ced5ce3eeb076350667a9e4351f9a69f
}

void RoboR2D2::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = posIni.getX();
    int y = posIni.getY();
    steps.push_back(Point(x,y));
    int dx, dy;
<<<<<<< HEAD
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
=======
    dx = x;
    dy = y;
    dirInicial = 0;
    while(!saiu && cont < maxSteps)
    {

            switch (dirInicial)
            {
            case 0:
                //vai para baixo
                if(lab->isEmpty(Point(dx+1, dy))) {
                        dx+=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                        dirInicial=1;}
                else
                {
                    if(!lab->isEmpty(Point(dx, dy+1))) {dirInicial=3;}
                    else
                    {
                        dy+=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                    }
                }
                break;
            case 1:
                //vai para esquerda(robo)
                if(lab->isEmpty(Point(dx, dy-1))) {
                                                dy-=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                        dirInicial=2;}
                else
                {
                    if(!lab->isEmpty(Point(dx+1, dy))) {dirInicial=0;}
                    else
                    {
                        dx+=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                    }
                }
                break;
            case 2:
                //vai para cima
                if(lab->isEmpty(Point(dx-1, dy))){
                                      dx-=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                    dirInicial=3;}
                else
                {
                    if(!lab->isEmpty(Point(dx, dy-1))) {dirInicial=1;}
                    else
                    {
                        dy-=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                    }
                }
                break;
            case 3:
                //vai para direita(robo)
                if(lab->isEmpty(Point(dx, dy+1)))
                    {
                        dy+=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                        dirInicial = 0;
                }
                else
                {
                    if(!lab->isEmpty(Point(dx-1, dy))) {dirInicial=2;}
                    else
                    {
                        dx-=1;
                        steps.push_back(Point(dx,dy));
                        cont++;
                    }
                }
                break;
            }
        if(dx >= lab->getWidth() || dx < 0
                || dy >= lab->getHeight() || dy < 0)
            saiu = true;
>>>>>>> 491a9608ced5ce3eeb076350667a9e4351f9a69f

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
