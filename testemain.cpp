//Arquivo criado para responder o item 5 da entrega para o professor
#include <iostream>
#include "TAD2.hpp"

using namespace std;

int main()
{
    node *p[20];
    for(int i = 0; i < 20;i++)
    {
        p[i] = nullptr;
    }
    node *j = nullptr;

    Cria(p[0], "ja ganhou algum titulo pelo clube?");
    InsereSim(p[0], p[1], "eh do setor defensivo?");
    InsereSim(p[1], p[4], "saiu do clube em 2023?");
    InsereSim(p[4], p[13], "Jogou muitos anos com a camisa do Corinthians");
    InsereSim(p[13], j, "Gil Zagueiro");

    cout << endl;
    cout << endl;
    cout << "================================================" << endl;
    cout << "                  AdivinhaTimao                 " << endl; // pesquisar o caracter de ã em ascii
    cout << "================================================" << endl;
    cout << endl;
    cout << "Advinha Timao eh um jogo cativante que desafia os fas do Corinthians a testarem seus conhecimentos sobre o elenco do time de 2023." << endl;
    cout << "Inspirado no estilo do Akinator, este jogo oferece aos jogadores a oportunidade de escolherem um jogador do Corinthians e desafiarem o sistema adivinhador a descobrir quem eh." << endl;
    cout << "Com uma gama exclusiva de jogadores do elenco do Timao em 2023, os usuarios serao surpreendidos com a precisao do jogo ao tentar descobrir qual jogador foi escolhido," << endl;
    cout << "oferecendo uma experiencia empolgante e divertida para os apaixonados pelo futebol e pelo Corinthians." << endl;
    cout << "Para jogar utilize a letra s para dizer que sim, n para dizer que nao, ns para dizer nao sei e x para encerrar o jogo a qualquer momento" << endl;
    cout << endl;
    cout << "Jogadores que podem ser encontrados ate agora:" << endl;
    cout << "Cassio" << endl;
    cout << "Carlos Miguel" << endl;
    cout << "Verissimo" << endl;
    cout << "Gil" << endl;
    cout << "Balbuena" << endl;
    cout << "Fabio Santos" << endl;
    cout << "Fagner" << endl;
    cout << "Fausto Vera" << endl;
    cout << "Gabriel Moscardo" << endl;
    cout << "Renato Augusto" << endl;
    cout << "Maycon" << endl;
    cout << "Giuliano" << endl;
    cout << "Rojas" << endl;
    cout << "Paulinho" << endl;
    cout << "Yuri Alberto" << endl;
    cout << "Romero" << endl;
    cout << "Roger Guedes" << endl;
    cout << "Luan (Mencao honrosa)" << endl;
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
            if (raiz == nullptr)
            {
                cout << "Nao consegui adivinhar o jogador ;(" << endl;
                cout << "Continuar? s ou n: ";
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
                cout << "AAAEEEEEE!!! Obrigado por jogar AdivinhaTimao!!!";
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