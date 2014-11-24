#include "LabirintoTeste.h"
#include <iostream>

LabirintoTeste :: LabirintoTeste() {
}

// Deveria carregar o labirinto de um arquivo,
// aqui so gera um espaco fechado, com uma saida na parte de baixo
void LabirintoTeste :: loadMaze(string arquivo) {
    dimx = 20; dimy = 20;
    for(int i=0; i<dimy; i++)
        for(int j=0; j<dimx; j++)
            lab[i][j] = ' ';
    for(int i=0; i<dimx; i++)
    {
        lab[0][i] = '*';
        lab[dimy-1][i] = '*';
        lab[i][0] = '*';
        lab[i][dimx-1] = '*';
    }
    lab[dimy-2][dimx-1] = ' '; // saida
    robot = 1;
    posIni = Point(1,1);
}

// Retorna true se a posição x,y do labirinto
// estiver livre (i.e. contenha um espaço em branco)
bool LabirintoTeste :: isEmpty(const Point& pos) const {
    if(pos.getX()<0 || pos.getX()>=dimx
                    || pos.getY()<0 || pos.getY()>=dimy) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}

// Retorna dimensoes do labirinto
int LabirintoTeste :: getWidth() { return dimx; }
int LabirintoTeste :: getHeight() { return dimy; }

int LabirintoTeste::getRobot() { return robot; }

Point LabirintoTeste::getIniPos() { return posIni; }
