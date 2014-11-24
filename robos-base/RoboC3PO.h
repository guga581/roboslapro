#ifndef ROBOC3PO_H
#define ROBOC3PO_H

#include "Labirinto.h"
#include "Robo.h"
#include "Texture.h"

using namespace std;

class RoboC3PO: public Robo{
    public:
        RoboC3PO(const Point& posIni, Labirinto *l, int maxSteps);
        void draw();
        void generateSteps();
        vector<Point> getSteps();
    private:
        TEX* roboTex;
        int dirInicial;

};

#endif // ROBOC3PO
