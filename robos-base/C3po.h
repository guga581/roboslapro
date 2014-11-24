#ifndef C3PO_H_INCLUDED
#define C3PO_H_INCLUDED
#include "Labirinto.h"
#include "Robo.h"
#include "Texture.h"

using namespace std;

class C3po: public Robo
{
public:
    C3po(const Point& posIni, Labirinto *l, int maxSteps);	// Construtor
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex; // id de textura do robo
};



#endif // C3PO_H_INCLUDED
