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


// Codigo de teste: tudo que ta aqui pra baixo pode ir para o arquivo JogoMain.cpp depois. E esse pode virar um .hpp (ai tem que tirar a main)
//
// Instrução de uso: para inserir node na arvore, use as funções insereSim, InsereNaosei e InsereNao. Para cada ponteiro saindo de um node pai
// do mesmo jeito que eu fiz a raíz e o segundo nível.
//
// Vou classificar as sub arvores com descrição dos nós pais. Por exemplo "sub: Titulo-Sim" é a arvore que segue 
// o caminho para a resposta sim, na pergunta de se ja ganhou um titulo