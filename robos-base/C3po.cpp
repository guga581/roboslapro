#include "C3po.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

struct ponto
{
    int i, j;
};

C3po::C3po(const Point& posIni, Labirinto *l, int maxSteps)
    : Robo(posIni, l, maxSteps)
{
    roboTex = CarregaTextura("C3po.jpg", true);
}

void C3po::generateSteps()
{
    bool saiu = false;//interrompe os paços
    bool step; //
    int numero=maxSteps-1;
    ponto point;
    point.i = posIni.getX();
    point.j = posIni.getY();
    steps.push_back(Point (point.j, point.i));
    //matriz de embasamento do algoritmo
    char mat[lab->getHeight()][lab->getWidth()];
    for(int i=0; i<lab->getHeight(); i++)
        for(int j=0; j<lab->getWidth(); j++)
            mat[i][j]=lab->get_matriz(i,j);
    //preenche a matriz para se analisada pelo algoritmo

    char direction = 'r';

    for(int a=0; a<numero; a++)
    {
        switch (direction)
        {
        case 'r':
            if(mat[point.i][point.j+1]==' ')
            {
                step = true;
            }
            else step = false;
            break;

        case 'l':
            if(mat[point.i][point.j-1]==' ')
            {
                step = true;
            }
            else step = false;
            break;

        case 'd':
            if(mat[point.i+1][point.j]==' ')
            {
                step = true;
            }
            else step = false;
            break;

        case 'u':
            if(mat[point.i-1][point.j]==' ')
            {
                step = true;
            }
            else step = false;
            break;
        }
        if(step==true&&!saiu)
        {
            switch (direction)
            {
            case 'r':
                point.j=point.j+1;
                break;
            case 'l':
                point.j=point.j-1;
                break;
            case 'd':
                point.i=point.i+1;
                break;
            case 'u':
                point.i=point.i-1;
                break;
            }
            steps.push_back(Point (point.j, point.i));
        }
        else
        {
            switch (direction)
            {
            case 'r':
                if(mat[point.i][point.j+1]==' ')
                {
                    direction= 'r';
                }
                else direction = 'd';
                break;

            case 'l':
                if(mat[point.i][point.j-1]==' ')
                {
                    direction=  'l';
                }
                else direction ='u';
                break;

            case 'd':
                if(mat[point.i+1][point.j]==' ')
                {
                    direction= 'd';
                }
                else direction= 'l';
                break;

            case 'u':
                if(mat[point.i-1][point.j+1]==' ')
                {
                    direction= 'u';
                }
                else direction = 'r';
                break;
            }
        }
        if(point.i==lab->getHeight()-1||point.j==lab->getWidth()-1||point.i ==0||point.j==0)
        {
            saiu = true;
            switch (direction)
            {
            case 'r':
                point.i = point.i-1;
                break;

            case 'l':
                point.i = point.i+1;
                break;

            case 'd':
                point.j = point.j-1;
                break;

            case 'u':
                point.j = point.j+1;
                break;
            }
            steps.push_back(Point (point.j, point.i));
            numero=a;
        }
    }

}

void C3po::draw()
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
