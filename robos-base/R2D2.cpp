#include "R2D2.h"
#include "GL.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

struct ponto
{
    int i, j;
};


R2D2::R2D2(const Point& posIni, Labirinto *l, int maxSteps)
    : Robo(posIni, l, maxSteps)
{
    roboTex = CarregaTextura("r2.jpg", true);
}

void R2D2::generateSteps()
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

    //verifica se é possível andar na direção e gira
    for(int t=0; t<2; t++)
    {
        switch (direction)
        {
        case 'r':
            if(mat[point.i-1][point.j]=='*')
            {
                if(mat[point.i][point.j+1]==' ')
                {
                    direction = 'r';
                }
                else direction = 'd';
            }
            break;

        case 'l':
            if(mat[point.i+1][point.j]=='*')
            {
                if(mat[point.i][point.j-1]==' ')
                {
                    direction = 'l';
                }
                else direction = 'u';
            }
            break;

        case 'd':
            if(mat[point.i][point.j+1]=='*')
            {
                if(mat[point.i+1][point.j]==' ')
                {
                    direction = 'd';
                }
                else direction = 'l';
            }
            break;

        case 'u':
            if(mat[point.i][point.j-1]=='*')
            {
                if(mat[point.i-1][point.j]==' ')
                {
                    direction = 'u';
                }
                else direction = 'r';
            }
            break;
        }
    }
    //TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
    //Preenche o steps com os passos
    for (int i=0; i<numero; i++)
    {
        //verifica se é possível caminhar uma para frente
        switch (direction)
        {
        case 'r':
            if (mat[point.i-1][point.j+1]=='*'&&mat[point.i][point.j+1]!='*')
            {
                step= true;
            }
            else step= false;
            break;

        case 'l':
            if (mat[point.i+1][point.j-1]=='*'&&mat[point.i][point.j-1]!='*')
            {
                step= true;
            }
            else step= false;
            break;
        case 'd':
            if (mat[point.i+1][point.j+1]=='*'&&mat[point.i+1][point.j]!='*')
            {
                step= true;
            }
            else step= false;
            break;
        case 'u':
            if (mat[point.i-1][point.j-1]=='*'&&mat[point.i-1][point.j]!='*')
            {
                step = true;
            }
            else step = false;
            break;

        }
        //TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

        //Avança se possível o robo na orientação dada
        if(!saiu&&step == true)
        {
            switch (direction)
            {
            case 'r':
                point.j = point.j+1;
                break;

            case 'l':
                point.j = point.j-1;
                break;

            case 'd':
                point.i = point.i+1;
                break;

            case 'u':
                point.i = point.i-1;
                break;

            }
            //TTTTTTTTTTT
            //verifica novamente a orientação
            for(int t=0; t<2; t++)
            {
                switch (direction)
                {
                case 'r':
                    if(mat[point.i-1][point.j]=='*')
                    {
                        if(mat[point.i][point.j+1]==' ')
                        {
                            direction = 'r';
                        }
                        else direction = 'd';
                    }
                    break;

                case 'l':
                    if(mat[point.i+1][point.j]=='*')
                    {
                        if(mat[point.i][point.j-1]==' ')
                        {
                            direction = 'l';
                        }
                        else direction = 'u';
                    }
                    break;

                case 'd':
                    if(mat[point.i][point.j+1]=='*')
                    {
                        if(mat[point.i+1][point.j]==' ')
                        {
                            direction = 'd';
                        }
                        else direction = 'l';
                    }
                    break;

                case 'u':
                    if(mat[point.i][point.j-1]=='*')
                    {
                        if(mat[point.i-1][point.j]==' ')
                        {
                            direction = 'u';
                        }
                        else direction = 'r';
                    }
                    break;
                }

            }//TTTTTTTTTTTTTTTTTTTTTT
            //Preenche o vector de paços
            steps.push_back(Point (point.j, point.i));
        }
        //verifica a existencia de quinase preenche com dois andamentos o da curva e a posição certa
        else if(!saiu)
        {
            if(mat[point.i][point.j-1]==' '&&direction=='l')
            {
                point.j = point.j-1;
                steps.push_back(Point (point.j, point.i));
                numero--;
                point.i=point.i+1;
                direction = 'd';
            }
            else if(mat[point.i+1][point.j] ==' '&&direction=='d')
            {
                point.i = point.i+1;
                steps.push_back(Point (point.j, point.i));
                numero--;
                point.j=point.j+1;
                direction = 'r';
            }
            else if(mat[point.i][point.j+1]==' '&&direction=='r')
            {
                point.j = point.j+1;
                steps.push_back(Point (point.j, point.i));
                numero--;
                point.i=point.i-1;
                direction = 'u';

            }
            else if(mat[point.i-1][point.j]==' '&&direction=='u')
            {
                point.i = point.i-1;
                steps.push_back(Point (point.j, point.i));
                numero--;
                point.j=point.j-1;
                direction = 'l';
            }
            steps.push_back(Point (point.j, point.i));
            //TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
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
            numero=i;
        }
    }
    /*for(int i=0; i<maxSteps; i++)
    {
        cout<<steps[i].getX()<<" "<<steps[i].getY()<<" - ";
        if(i%10==0)
            cout<<endl;
    }*/


}

void R2D2::draw()
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

