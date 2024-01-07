#include <iostream>
// #include "TAD_arvore.hpp"
using namespace std;

int main()
{
    cout << "================================================" << endl;
    cout << "                  AdivinhaTimao                 " << endl; // pesquisar o caracter de ã em ascii
    cout << "================================================" << endl
         << endl;
    cout << "Advinha Timão é um jogo cativante que desafia os fãs do Corinthians a testarem seus conhecimentos sobre o elenco do time de 2023."<< endl;
    cout <<" Inspirado no estilo do Akinator, este jogo oferece aos jogadores a oportunidade de escolherem um jogador do Corinthians e desafiarem o sistema adivinhador a descobrir quem é."<< endl;
    cout << "Com uma gama exclusiva de jogadores do elenco do Timão em 2023, os usuários serão surpreendidos com a precisão do jogo ao tentar descobrir qual jogador foi escolhido, oferecendo uma experiência empolgante e divertida para os apaixonados pelo futebol e pelo Corinthians." << endl;

    string start, escolha;
    cout << "Para iniciar o jogo digite a letra s: ";
    cin >> start;
    while (start != "s")
    {
        cin >> start;
    }

    bool acabou = false;
    // node *raiz = p[0];
    while (!acabou)
    {
        if (raiz->sim != nullptr)
        {
            if (raiz->naoSei == nullptr)
            {
                cout << "Nao consegui adivinhar o jogador ;(" << endl;
                cout << "Continuar? s ou n:";
                cin >> start;
                while (start != "s" && start != "n")
                {
                    cin >> start;
                }
                if(start == "s")
                {
                    raiz = p[0];
                }
                else
                {
                    acabou = true;
                }
            }
            else
            {
                cout << raiz->info;
                
                cin >> escolha;
                while (escolha != "s" && escolha != "n" && escolha != "ns" && escolha != "x")
                {
                    cin >> start;
                }

                if (escolha == "s")
                {
                    raiz = raiz->sim;
                }
                else if (escolha == "ns")
                {
                    raiz = raiz->naoSei;
                }
                else if(escolha == "n")
                {
                    raiz = raiz->nao;
                }
                else
                {
                    acabou = true;
                }
            }
        }
        else
        {
            
        }
    }
    return 0;
}