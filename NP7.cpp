#include <iostream>
using namespace std;

struct node
{
    int info;
    node *dir;
    node *esq;
};

struct arvore
{
    node *raiz;
};

node *Insere(node *raiz, int x, bool &ok);

bool estaNaArvore(node *raiz, int x);

node *Retira(node *raiz, int x, bool &ok);

void PrintInOrder(node *raiz);

node *Insere(node *raiz, int x, bool &ok)
{
    node *nodeTemp;
    if (raiz == nullptr)
    {
        nodeTemp = new node;
        nodeTemp->info = x;
        nodeTemp->dir = nullptr;
        nodeTemp->esq = nullptr;
        raiz = nodeTemp;
        nodeTemp = nullptr;
        ok = true;
        return raiz;
    }
    else if (raiz->info == x)
    {
        ok = false;
        return raiz;
    }
    else if (x < raiz->info)
    {
        raiz->esq = Insere(raiz->esq, x, ok);
        return raiz;
    }
    else
    {
        raiz->dir = Insere(raiz->dir, x, ok);
        return raiz;
    }
}

bool estaNaArvore(node *raiz, int x)
{
    if (raiz == nullptr)
        return false;
    if (raiz->info == x)
        return true;

    if (x < raiz->info)
    {
        return estaNaArvore(raiz->esq, x);
    }
    else
    {
        return estaNaArvore(raiz->dir, x);
    }
}

node *Retira(node *raiz, int x, bool &ok)
{
    if (raiz == nullptr)
    {
        ok = false;
        return raiz;
    }

    if (x < raiz->info)
    {
        raiz->esq = Retira(raiz->esq, x, ok);
    }
    else if (x > raiz->info)
    {
        raiz->dir = Retira(raiz->dir, x, ok);
    }
    else
    {
        //1 ou nenhum filho
        if (raiz->esq == nullptr)
        {
            node *temp = raiz->dir;
            delete raiz;
            ok = true;
            return temp;
        }
        else if (raiz->dir == nullptr)
        {
            node *temp = raiz->esq;
            delete raiz;
            ok = true;
            return temp;
        }

        //2 filhos
        node *temp = raiz->esq;
        while (temp->dir != nullptr)
        {
            temp = temp->dir;
        }
        raiz->info = temp->info;
        raiz->esq = Retira(raiz->esq, temp->info, ok);
    }

    return raiz;
}

void PrintInOrder(node *raiz)
{
    if (raiz != nullptr)
    {
        PrintInOrder(raiz->esq);
        cout << raiz->info << " / ";
        PrintInOrder(raiz->dir);
    }
}

int main()
{
    node *arv1 = nullptr;
    bool ok = true;

    arv1 = Insere(arv1, 5, ok);
    Insere(arv1, 1, ok);
    Insere(arv1, 10, ok);
    Insere(arv1, 7, ok);
    Insere(arv1, 4, ok);
    Insere(arv1, 10, ok);

    PrintInOrder(arv1);
    cout << endl;
    int x = 7;
    cout << "o  numero " << x << " esta na arvore? ";
    estaNaArvore(arv1, x) ? cout << "Sim" : cout << "Nao";
    cout << endl;

    Retira(arv1, 7, ok);
    cout << "Retirando 7" << endl;
    PrintInOrder(arv1);
    cout << endl;
    Retira(arv1, 4, ok);
    cout << "Retirando 4" << endl;
    PrintInOrder(arv1);
    cout << endl;
}