
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
}

void RoboR2D2::generateSteps()
{
    int cont = 1,ladoDx=0, ladoDy=1;
    bool saiu = false;
    int x = posIni.getX();
    int y = posIni.getY();
    steps.push_back(Point(x,y));
    while(!saiu && cont < maxSteps)
    {
        int dx=0, dy=0;
        if(lab->isEmpty(Point(x+ladoDx, y+ladoDy)))
        {
            dx+=ladoDx;
            dy+=ladoDy;
        }
        else{
            ladoDx=1;
            ladoDy=0;
            if(lab->isEmpty(Point(x+ladoDx, y+ladoDy))){
                dx+=ladoDx;
                dy+=ladoDy;
            }
            else{
                ladoDx=0;
                ladoDy=-1;
                if(lab->isEmpty(Point(x+ladoDx, y+ladoDy))){
                    dx+=ladoDx;
                    dy+=ladoDy;
                }
                else{
                    ladoDx=-1;
                    ladoDy=0;
                     if(lab->isEmpty(Point(x+ladoDx, y+ladoDy))){
                        dx+=ladoDx;
                        dy+=ladoDy;
                    }
                    else{
                        ladoDx=0;
                        ladoDy=1;
                         if(lab->isEmpty(Point(x+ladoDx, y+ladoDy)))
                            {
                                dx+=ladoDx;
                                dy+=ladoDy;
                            }
                    }
                }

            }
        }
        x += dx;
        y += dy;
        steps.push_back(Point(x, y));
        cont++;
        if(x >= lab->getWidth() || x < 0
                || y >= lab->getHeight() || y < 0)
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
