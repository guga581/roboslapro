#include "RoboC3PO.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

RoboC3PO :: RoboC3PO(const Point& posIni, Labirinto *l, int maxSteps) : Robo(posIni, l, maxSteps)
{
    srand(time(NULL));
    roboTex = CarregaTextura("c3po.jpg", false);
    dirInicial = rand()%4;

}

void RoboC3PO::draw()
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

void RoboC3PO::generateSteps()
{
    int cont = 1;
    bool saiu = false;
    int x = posIni.getX();
    int y = posIni.getY();
    steps.push_back(Point(x,y));
    int dx, dy;
    dx = x;
    dy = y;
    while(!saiu && cont < maxSteps)
    {
        switch (dirInicial)
        {
        case 0: //o robo vai para a baixo
            if(!lab->isEmpty(Point(dx, dy+1))) //verifica se bloco a frente do robo esta obstruido
            {
                if(!lab->isEmpty(Point(dx-1, dy))) //o bloco a frente do robo esta obstruido, verifica se a direita do robo esta obstruida
                {
                    dirInicial = 1; // direita obstruida, manda o robo seguir para a esquerda
                }
                else
                {
                    dirInicial=3; // direita nao obstruida,  o robo segue a direita
                }
            }
            else //esquerda do robo esta livre, pode seguir o movimento
            {
                dy+=1;
                steps.push_back(Point(dx,dy));
                cont++;
            }
            break;
            /*
             *  Mantem a mesma logica anterior, apenas com pequenas alteracoes para a coerencia do robo
             *
             */
        case 1: // Robo anda para a direita do usuario
            if(!lab->isEmpty(Point(dx+1, dy)))
            {
                if(!lab->isEmpty(Point(dx, dy+1)))
                {
                    dirInicial=2;
                }
                else
                {
                    dirInicial = 0;
                }
            }
            else
            {
                dx+=1;
                steps.push_back(Point(dx,dy));
                cont++;
            }
            break;
        case 2: //Robo esta subindo o labirinto
            if(!lab->isEmpty(Point(dx, dy-1)))
            {
                if(!lab->isEmpty(Point(dx+1, dy)))
                {
                    dirInicial=3;
                }
                else
                {
                    dirInicial=1;
                }
            }
            else
            {
                dy-=1;
                steps.push_back(Point(dx,dy));
                cont++;
            }
            break;
        case 3:// Robo segue a esquerda do usuario.
            if(!lab->isEmpty(Point(dx-1, dy)))
            {
                if(!lab->isEmpty(Point(dx, dy-1)))
                {
                    dirInicial=0;
                }
                else
                {
                    dirInicial=2;
                }

            }
            else
            {
                dx-=1;
                steps.push_back(Point(dx,dy));
                cont++;
            }
            break;
        }
        if(dx >= lab->getWidth() || dx < 0
                || dy >= lab->getHeight() || dy < 0)
            saiu = true;

    }
}
