//TAD_arvore2.hpp
#include <iostream>
using namespace std;

struct node
{
    string info;
    node *sim;
    node *naoSei;
    node *nao;
};

void Cria(node *&raiz, string info)
{
    node *nodeTemp;
    nodeTemp = new node;
    nodeTemp->info = info;
    nodeTemp->sim = nullptr;
    nodeTemp->naoSei = nullptr;
    nodeTemp->nao = nullptr;
    raiz = nodeTemp;
    nodeTemp = nullptr;
}

void Insere(node *&paiPtr, node *&filho, string info)
{
    node *nodeTemp;
    nodeTemp = new node;
    nodeTemp->info = info;
    nodeTemp->sim = nullptr;
    nodeTemp->naoSei = nullptr;
    nodeTemp->nao = nullptr;
    filho = nodeTemp;
    paiPtr = filho;
}

string InsereSim(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->sim, filho, info);
    return paiPtr->info;
}

string InsereNaosei(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->naoSei, filho, info);
    return paiPtr->info;
}

string InsereNao(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->nao, filho, info);
    return paiPtr->info;
}

void PrintArv(node *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->info << endl;
        PrintArv(raiz->sim);
        PrintArv(raiz->naoSei);
        PrintArv(raiz->nao);
    }
}