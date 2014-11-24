#ifndef R2D2_H_INCLUDED
#define R2D2_H_INCLUDED
#include "Labirinto.h"
#include "Robo.h"
#include "Texture.h"

using namespace std;

class R2D2: public Robo
{
public:
    R2D2(const Point& posIni, Labirinto *l, int maxSteps);	// Construtor
    void draw();
    void generateSteps();
    vector<Point> getSteps();
private:
    TEX* roboTex; // id de textura do robo
};


#endif // R2D2_H_INCLUDED
