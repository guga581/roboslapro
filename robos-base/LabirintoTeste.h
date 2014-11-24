#ifndef LABIRINTOTESTE_H
#define LABIRINTOTESTE_H
#include <fstream>
#include "Labirinto.h"



using namespace std;

class LabirintoTeste : public Labirinto
{
public:
    LabirintoTeste();	// Construtor
    bool isEmpty(const Point& ponto) const;
    int  getWidth();
    int  getHeight();
    void loadMaze(string arquivo);
    int  getRobot();
    Point getIniPos();
    char get_matriz(int x,int y)
    {
        return lab[x][y];
    }
    int qual;

    // O labirinto em si
private:
    char lab[100][100];
    int dimx, dimy;		// Tamanho do labirinto
    // char lab[100][100];	// O labirinto em si
    int robot;
    Point posIni;
};

#endif
