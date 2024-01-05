#include <iostream>
using namespace std;

struct node
{
    string info;
    node *sim;
    node *naoSei;
    node *nao;
};

node *Cria(node *raiz, string info)
{
    node *nodeTemp;
    nodeTemp = new node;
    nodeTemp->info = info;
    nodeTemp->sim = nullptr;
    nodeTemp->naoSei = nullptr;
    nodeTemp->nao = nullptr;
    raiz = nodeTemp;
    nodeTemp = nullptr;
    return raiz;
}

node *Insere(node *paiPtr, node *filho, string info)
{
    node *nodeTemp;
    nodeTemp = new node;
    nodeTemp->info = info;
    nodeTemp->sim = nullptr;
    nodeTemp->naoSei = nullptr;
    nodeTemp->nao = nullptr;
    filho = nodeTemp;
    paiPtr = filho;
    return paiPtr;
}

node *InsereSim(node *paiPtr, node *filho, string info)
{
    paiPtr->sim = Insere(paiPtr->sim, filho, info);
    return paiPtr->sim;
}

node *InsereNaosei(node *paiPtr, node *filho, string info)
{
    paiPtr->naoSei = Insere(paiPtr->naoSei, filho, info);
    return paiPtr->naoSei;
}

node *InsereNao(node *paiPtr, node *filho, string info)
{
    paiPtr->nao = Insere(paiPtr->nao, filho, info);
    return paiPtr->nao;
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

int main()
{
    //Array de ponteiros, para cada node de pergunta
    node *p[95];
    for (int i = 0; i < 95; i++)
    {
        p[i] = nullptr;
    }

    //Escrever as perguntas aqui: (não coloca acento e "ç", o console buga)
    // ja ganhou algum titulo pelo clube?
    // eh do setor defensivo?
    // saiu do clube em 2023?
    // eh um dos melhores em campo atualmente?
    // quase foi vendido pro psg?
    // foi vendido pro psg?
    // É calvo? (Tem duas entradas pro show da Taylor swift)


    // ---- Raiz ----
    p[0] = Cria(p[0], "ja ganhou algum titulo pelo clube?");
    // ---- segundo nível ----
    InsereSim(p[0], p[1] , "eh do setor defensivo?");
    InsereNaosei(p[0], p[2],"eh do setor defensivo?");
    InsereNao(p[0], p[3],"eh do setor defensivo?");
    // ---- terceiro nível ----
    //sub: Titulo-Sim
    InsereSim(p[1], p[4] , "saiu do clube em 2023?");
    InsereNaosei(p[1], p[5],"saiu do clube em 2023?");
    InsereNao(p[1], p[6],"eh um dos melhores em campo atualmente?");
    //sub: Titulo-Naosei
    InsereSim(p[2], p[7] , "saiu do clube em 2023?");
    InsereNaosei(p[2], p[8],"saiu do clube em 2023?");
    InsereNao(p[2], p[9],"É calvo? (Tem duas entradas pro show da Taylor swift)");
    //sub: Titulo-Nao
    InsereSim(p[3], p[10] , "quase foi vendido pro psg?");
    InsereNaosei(p[3], p[11],"foi vendido pro psg?");
    InsereNao(p[3], p[12],"É calvo? (Tem duas entradas pro show da Taylor swift)");

    PrintArv(p[0]);
    
}