#ifndef WALLE_H_INCLUDED
#define WALLE_H_INCLUDED
#include "Arvore.h"
#include "Labirinto.h"
#include "Robo.h"
#include "Texture.h"

using namespace std;

class Walle:public Robo
{
public:
    Walle(const Point& posIni, Labirinto *l, int maxSteps);	// Construtor
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex;
};




#endif // WALLE_H_INCLUDED
