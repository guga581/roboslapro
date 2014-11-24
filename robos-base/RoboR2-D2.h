#ifndef ROBOR2D2_H
#define ROBOR2D2_H

#include "Labirinto.h"
#include "Robo.h"
#include "Texture.h"

using namespace std;

class RoboR2D2: public Robo {
	public:
        RoboR2D2(const Point& posIni, Labirinto *l, int maxSteps);	// Construtor
        void draw();
        void generateSteps();
        vector<Point> getSteps();
    private:
        TEX* roboTex; // id de textura do robo
};

#endif
