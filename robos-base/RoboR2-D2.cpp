#include "RoboR2-D2.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


RoboR2D2::RoboR2D2(const Point& posIni, Labirinto *l)

    : Robo(posIni, l, NULL)
{
    srand(time(NULL));
    roboTex = CarregaTextura("r2.jpg", false);
}

void RoboR2D2::generateSteps()
{
    bool saiu = false;
    int x = posIni.getX();
    int y = posIni.getY();
    steps.push_back(Point(x,y));
    int dx, dy;
    dx = x;
    dy = y;
    dirInicial = 0; //o robo comeca indo para baixo ate achar uma parede
    while(!saiu)
    {

        switch (dirInicial)
        {
        case 0: //caso 0. o robo esta se direcionando para baixo
            if(lab->isEmpty(Point(dx+1, dy))) //verifica se o braco esquerdo do robo esta na parede, se nao estiver ele entra no vao
            {
                dx+=1;
                steps.push_back(Point(dx,dy));

                dirInicial=1;
            }
            else //caso existir parede, ou seja isEmpty retornar falso ele segue para baixo
            {
                if(!lab->isEmpty(Point(dx, dy+1))) // caso o seu caminho esteja obstruido ele entra no caso 3, que faz com que o robo se movimente para a direita
                {
                    dirInicial=3;
                }
                else // se o caminho a frente nao estiver obstruido ele simplesmente continua o movimento
                {
                    dy+=1;
                    steps.push_back(Point(dx,dy));

                }
            }
            break;

            /*   Para os proximos casos a logica do caso 0 permanece a mesma, apenas com algumas alteracoes nos proximos
             * movimentos, para a coerencia do robo
             *
             */



        case 1: //caso 1. o robo esta se movimentando para esquerda
            if(lab->isEmpty(Point(dx, dy-1)))
            {
                dy-=1;
                steps.push_back(Point(dx,dy));

                dirInicial=2;
            }
            else
            {
                if(!lab->isEmpty(Point(dx+1, dy)))
                {
                    dirInicial=0;
                }
                else
                {
                    dx+=1;
                    steps.push_back(Point(dx,dy));

                }
            }
            break;
        case 2: //o robo esta subindo o labirinto
            if(lab->isEmpty(Point(dx-1, dy)))
            {
                dx-=1;
                steps.push_back(Point(dx,dy));

                dirInicial=3;
            }
            else
            {
                if(!lab->isEmpty(Point(dx, dy-1)))
                {
                    dirInicial=1;
                }
                else
                {
                    dy-=1;
                    steps.push_back(Point(dx,dy));

                }
            }
            break;
        case 3: //o robo vai para a direita
            if(lab->isEmpty(Point(dx, dy+1)))
            {
                dy+=1;
                steps.push_back(Point(dx,dy));
                dirInicial = 0;
            }
            else
            {
                if(!lab->isEmpty(Point(dx-1, dy)))
                {
                    dirInicial=2;
                }
                else
                {
                    dx-=1;
                    steps.push_back(Point(dx,dy));
                }
            }
            break;
        }
        // ao completar cada movimento ele verifica se o ultimo passo feito
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
