//Arquivo criado para responder o item 5 da entrega para o professor
#include <iostream>
#include "TAD2.hpp"

using namespace std;

int main()
{

    cout << "================================================" << endl;
    cout << "                  AdivinhaTimao                 " << endl; // pesquisar o caracter de ã em ascii
    cout << "================================================" << endl;
    cout << endl;
    cout << "Advinha Timao é um jogo cativante que desafia os fas do Corinthians a testarem seus conhecimentos sobre o elenco do time de 2023." << endl;
    cout << "Inspirado no estilo do Akinator, este jogo oferece aos jogadores a oportunidade de escolherem um jogador do Corinthians e desafiarem o sistema adivinhador a descobrir quem é." << endl;
    cout << "Com uma gama exclusiva de jogadores do elenco do Timao em 2023, os usuarios serao surpreendidos com a precisao do jogo ao tentar descobrir qual jogador foi escolhido," << endl;
    cout << "oferecendo uma experiencia empolgante e divertida para os apaixonados pelo futebol e pelo Corinthians." << endl;
    cout << "Para jogar utilize a letra s para dizer que sim, n para dizer que nao, ns para dizer nao sei e x para encerrar o jogo a qualquer momento" << endl;
    cout << endl;
    cout << "Jogadores que podem ser encontrados ate agora:" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << "Cassio" << endl;
    cout << endl;

    string start, escolha;

    cout << "Para iniciar o jogo digite start: ";
    cin >> start;
    while (start != "start")
    {
        cin >> start;
    }

    bool acabou = false;

    node *raiz = p[0];

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
                if (start == "s")
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
                else if (escolha == "n")
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
            cout << "Voce pensou em " << raiz->info << "?? ";
            cin >> escolha;
            while (escolha != "s" && escolha != "n")
            {
                cin >> start;
            }
            if (escolha == "s")
            {
                cout << "Obrigado por jogar AdivinhaTimao!!!";
                cout << "Continuar? s ou n:";
                cin >> start;
                while (start != "s" && start != "n")
                {
                    cin >> start;
                }
                if (start == "s")
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
                raiz = p[0];
            }
        }
    }
    return 0;
}