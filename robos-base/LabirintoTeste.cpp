#include "LabirintoTeste.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

LabirintoTeste :: LabirintoTeste()
{
}

// Deveria carregar o labirinto de um arquivo,
// aqui so gera um espaco fechado, com uma saida na parte de baixo
void LabirintoTeste :: loadMaze(string arquivo)
{
    ifstream arq;
    arq.open(arquivo.c_str(), ios::in); // transforma a variaval arquivo em constante -> c_srt()

    string aux, auxmat;
    ostringstream aux2;

    int linha, coluna, ix, iy, robo, x=0;

    //leitura do arquivo. variavel aux usada para conteudo desnecessario do arquivo

    arq >> aux >> linha >> coluna >>
    aux >> iy >> ix >>
    aux >> robo;

    dimx=coluna;
    dimy=linha;
    getline(arq, aux);
    for(int i=0; i<linha; i++)
    {
        getline(arq, aux);
        aux2 << aux;
    }
    auxmat = aux2.str(); // coloca uma ostringstrem em uma string

    for(int i=0; i<linha; i++)
        for(int j=0; j<coluna; j++)
        {

            lab[i][j] = auxmat[x]; //forma a matriz
            x++;
        }
    arq.close(); //fecha o arquivo
    robot = robo; // atrinui o inteiro do robo para a variavel da classe
    posIni = Point(ix, iy); // coloca posicao inicial lida no arquivo na classe point e atribui ela para a variavel da classe
}

// Retorna true se a posição x,y do labirinto
// estiver livre (i.e. contenha um espaço em branco)
bool LabirintoTeste :: isEmpty(const Point& pos) const
{
    if(pos.getX()<0 || pos.getX()>=dimx
            || pos.getY()<0 || pos.getY()>=dimy) return true;
    return (lab[pos.getY()][pos.getX()]==' ');
}

// Retorna dimensoes do labirinto
int LabirintoTeste :: getWidth()
{
    return dimx;
}
int LabirintoTeste :: getHeight()
{
    return dimy;
}

int LabirintoTeste::getRobot()
{
    return robot;
}

Point LabirintoTeste::getIniPos()
{
    return posIni;
}
