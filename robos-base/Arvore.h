#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

struct Ponto
{
    int i, j;
};

typedef struct NODE
{
    vector<struct NODE*> parentes;
    vector<struct NODE*> filhos;
    Ponto p;
} Node;
/*
class Arvore
{
public:

    void setRaiz(Node n);
    Node getRaiz();

private:
    Node raiz;
};*/

#endif // ARVORE_H_INCLUDED
