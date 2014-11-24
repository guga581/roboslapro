#include "Walle.h"
#include "GL.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


Walle::Walle(const Point& posIni, Labirinto *l, int maxSteps)
    : Robo(posIni, l, maxSteps)
{
    roboTex = CarregaTextura("walle.jpg", true);
}

void Walle::generateSteps()
{
    char mat[lab->getHeight()][lab->getWidth()];
    for(int i=0; i<lab->getHeight(); i++)
        for(int j=0; j<lab->getWidth(); j++)
            mat[i][j]=lab->get_matriz(i,j);


    Ponto origem;
    origem.i = posIni.getX();
    origem.j = posIni.getY();

    Node* saida = NULL;

    Node* raiz = new Node;
    raiz->p = origem;

    vector<Ponto> consistencia;
    vector<Node*> verificar;
    verificar.push_back(raiz);

    while(verificar.size() != 0)
    {
        Node* n  = verificar[0];
        Ponto p = n->p;
        Ponto t1, t2, t3, t4;
        t1.i = p.i-1;
        t1.j = p.j;
        t2.i = p.i+1;
        t2.j = p.j;
        t3.i = p.i;
        t3.j = p.j-1;
        t4.i = p.i;
        t4.j = p.j+1;
        vector<Ponto> testes;
        testes.push_back(t1);
        testes.push_back(t2);
        testes.push_back(t3);
        testes.push_back(t4);

        while(testes.size() != 0)
        {
            Ponto t = testes[0];
            if(t.i < 0 || t.i > lab->getHeight()-1 || t.j < 0 || t.j > lab->getWidth()-1)
            {
                testes.erase(testes.begin());
                continue;
            }
            bool isPai = false;
            for(int i=0; i < n->parentes.size(); i++)
            {
                if(t.i == n->parentes[i]->p.i && t.j == n->parentes[i]->p.j)
                {
                    isPai = true;
                    break;
                }
            }

            if(isPai)
            {
                testes.erase(testes.begin());
                continue;
            }

            if(mat[t.i][t.j] != ' ')
            {
                testes.erase(testes.begin());
                continue;
            }

            Node* f = new Node;
            f->parentes.push_back(n);
            f->p = t;
            n->filhos.push_back(f);
            testes.erase(testes.begin());

            bool found = false;
            for(int i=0; i < consistencia.size(); i++)
            {
                Ponto p2 = consistencia[i];
                if(t.i == p2.i && t.j == p2.j)
                {
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                if( !(t.i == origem.i && t.j == origem.j) && (t.i == 0 || t.i == lab->getHeight()-1 || t.j == 0 || t.j == lab->getWidth()-1) )
                {
                    Node* s = new Node;
                    s->p.i = t.i;
                    s->p.j = t.j;
                    s->parentes = n->parentes;
                    saida = s;
                }
                consistencia.push_back(t);
                verificar.push_back(f);
            }
        }

        verificar.erase(verificar.begin());
    }

    if(saida != NULL)
    {
        steps.push_back(Point(saida->p.j, saida->p.i));

        while(saida != NULL && saida->parentes.size() != 0)
        {
            steps.insert(steps.begin(), Point(saida->p.j, saida->p.i));
            saida = saida->parentes[0];
        }

        steps.insert(steps.begin(), Point(saida->p.j, saida->p.i));
    }

    if(steps.size() > maxSteps)
        steps.erase(steps.begin()+maxSteps, steps.end());
}

void Walle::draw()
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

