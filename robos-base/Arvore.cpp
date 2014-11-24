#include <iostream>
#include <vector>
#include "Arvore.h"

vector<Leaf> Arv_Pos::get_caminhamento()
{
    return caminhamento;
}

void Arv_Pos::add_folha(Leaf l)
{
    caminhamento.push_back(l);
}

void Arv_Pos::preenche_arv()
{

}

