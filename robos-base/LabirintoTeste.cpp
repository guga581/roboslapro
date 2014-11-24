#include "LabirintoTeste.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

LabirintoTeste :: LabirintoTeste() {
}

// Deveria carregar o labirinto de um arquivo,
// aqui so gera um espaco fechado, com uma saida na parte de baixo
void LabirintoTeste :: loadMaze(string arquivo) {
    ifstream arq;

    arq.open(arquivo.c_str(), ios::in);
    if (!arq.is_open())
        return;
    string aux, antesmatriz;
    ostringstream junta;
    int linha, coluna, pontox, pontoy, robo, x=0;
    arq >> aux >> linha >> coluna >> aux >> pontox >> pontoy >> aux >> robo;
    dimx=coluna;
    dimy=linha;
    getline(arq, aux);
    for(int i=0; i<linha; i++)
    {
        getline(arq, aux);
        junta << aux;
    }
    antesmatriz = junta.str();
    antesmatriz.c_str();
    for(int i=0; i<linha; i++)
    {
        for(int j=0; j<coluna; j++)
        {
            lab[i][j] = antesmatriz[x];
            x++;
        }
    }
    arq.close();
    robot = robo;
    posIni = Point(pontox, pontoy);
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
