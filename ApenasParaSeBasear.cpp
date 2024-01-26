// Jogomain.cpp
#include <iostream>
#include "TAD2.hpp"

using namespace std;

int main()
{

    // Instrução de uso: para inserir node na arvore, use as funções insereSim, InsereNaosei e InsereNao. Para cada ponteiro saindo de um node pai
    // do mesmo jeito que eu fiz a raíz e o segundo nível.
    //
    // Vou classificar as sub arvores com descrição dos nós pais. Por exemplo "sub: Titulo-Sim" é a arvore que segue
    // o caminho para a resposta sim, na pergunta de se ja ganhou um titulo

    // Array de ponteiros, para cada node de pergunta
    // Array de ponteiros para node jogador
    node *j[87];
    for (int i = 0; i < 86; i++)
    {
        j[i] = nullptr;
    }
    node *p[86];
    for (int i = 0; i < 86; i++)
    {
        p[i] = nullptr;
    }

    // Escrever as perguntas aqui: (não coloca acento e "ç", o console buga)
    //  ja ganhou algum titulo pelo clube?
    //  eh do setor defensivo?
    //  saiu do clube em 2023?
    //  eh um dos melhores em campo atualmente?
    //  quase foi vendido pro psg?
    //  foi vendido pro psg?
    //  É calvo? (Tem duas entradas pro show da Taylor swift)

    // ---- Raiz ----
    Cria(p[0], "ja ganhou algum titulo pelo clube?");
    // ---- segundo nível ----
    InsereSim(p[0], p[1], "eh do setor defensivo?");
    InsereNaosei(p[0], p[2], "eh do setor defensivo?");
    InsereNao(p[0], p[3], "eh do setor defensivo?");
    // ---- terceiro nível ----
    // sub: Titulo-Sim
    InsereSim(p[1], p[4], "saiu do clube em 2023?");
    InsereNaosei(p[1], p[5], "saiu do clube em 2023?");
    InsereNao(p[1], p[6], "eh um dos melhores em campo atualmente?");
    // sub: Titulo-Naosei
    InsereSim(p[2], p[7], "saiu do clube em 2023?");
    InsereNaosei(p[2], p[8], "saiu do clube em 2023?");
    InsereNao(p[2], p[9], "Eh calvo? (Tem duas entradas pro show da Taylor swift)");
    // sub: Titulo-Nao
    InsereSim(p[3], p[10], "quase foi vendido pro psg?");
    InsereNaosei(p[3], p[11], "quase foi vendido pro psg?");
    InsereNao(p[3], p[12], "Eh calvo? (Tem duas entradas pro show da Taylor swift)");

    // Agora vou fazer por Arvore e não por nível, vai ficar bem mais fácil de perceber erros
    // Vamos fazer desse jeito, 3 linhas seguidas para arrumar os ponteiros de um node e depois pula a liinha e faz o proximo

    // --------- Título= Sim ; Defensivo = Sim ---------
    InsereSim(p[4], p[13], "Jogou muitos anos com a camisa do Corinthians");
    InsereNaosei(p[4], p[14], "Eh lindo e idolo?");
    InsereNao(p[4], p[14], "Eh lindo e idolo?");

    InsereSim(p[13], j[0], "Gil Zagueiro");
    InsereNaosei(p[13], j[1], "Balbuena");
    InsereNao(p[13], j[1], "Balbuena");

    InsereSim(p[14], j[2], "Cassio");
    InsereNaosei(p[14], p[15], "Aposentou o Hazard");
    InsereNao(p[14], p[15], "Aposentou o Hazard");

    InsereSim(p[15], j[3], "Fagner");
    InsereNao(p[15], p[16], "É careca?");
    InsereNaosei(p[15], p[16], "É careca?");

    InsereSim(p[16], j[4], "Fabio Santos");
    InsereNao(p[16], p[17], "Gil Zagueiro?");
    InsereNaosei(p[16], p[17], "Gil Zagueiro?");

    InsereSim(p[17], j[5], "Gil Zagueiro");
    InsereNaosei(p[17], j[6], "Gil Zagueiro");
    InsereNao(p[17], j[6], "Gil Zagueiro");

    // --------- Título = Sim; Defensivo = Não sei ------------
    InsereSim(p[5], j[7], "Balbuena");
    InsereNaosei(p[5], p[18], "Eh lindo e idolo?");
    InsereNao(p[5], p[18], "Eh lindo e idolo?");

    InsereSim(p[11], j[8], "Cássio");
    InsereNao(p[11], p[19], "Quebra perna dos adversários");
    InsereNaosei(p[11], p[19], "Quebra perna dos adversários");

    InsereSim(p[12], j[9], "Fagner");
    InsereNao(p[12], p[20], "É careca?");
    InsereNaosei(p[12], p[20], "É careca?");

    InsereSim(p[13], j[10], "Fabio Santos");
    InsereNao(p[13], p[22], "Gil Zagueiro?");
    InsereNaosei(p[13], p[22], "Gil Zagueiro?");

    InsereSim(p[14], j[11], "Gil Zagueiro");
    InsereNao(p[14], p[23], "Melhores em campos atualmente");
    InsereNaosei(p[14], p[23], "Melhores em campos atualmente");

    InsereSim(p[15], p[24], "É craque de bola?");
    InsereNao(p[15], p[25], "Ganhou mundial de 2012?");
    InsereNaosei(p[15], p[25], "Ganhou mundial de 2012?");
    // Caminho- Craque de Bola
    InsereSim(p[16], j[12], "Renato Augusto");
    InsereNao(p[16], p[26], "Entre ele e seu irmão, ele eh o bagre?");
    InsereNaosei(p[16], p[26], "Entre ele e seu irmão, ele eh o bagre?");

    InsereSim(p[26], j[13], "Ángel Romero");
    // Final Craque de Bola

    // Caminho Ganhou Mundial 2012
    InsereSim(p[18], j[14], "Paulinho");
    InsereNao(p[18], p[27], "Não fede nem cheira?");
    InsereNaosei(p[18], p[27], "Não fede nem cheira?");

    InsereSim(p[27], j[15], "Maycon");
    // Final caminho Mundial

    // ----Título = Sim; Defensivo = Não
    InsereSim(p[20], p[28], "É craque de bola?");
    InsereNao(p[20], p[29], "Ganhou mundial de 2012?");
    InsereNaosei(p[20], p[29], "Ganhou mundial de 2012?");
    // Caminho é craque
    InsereSim(p[21], j[16], "Renato Augusto");
    InsereNao(p[21], p[30], "Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[21], p[30], "Entre ele e seu irmão, ele é o bagre?");

    InsereSim(p[30], j[17], "Ángel Romero");
    // Final Craque de Bola

    // Caminho Ganhou Mundial 2012
    InsereSim(p[23], j[18], "Paulinho");
    InsereNao(p[23], p[31], "Não fede nem cheira?");
    InsereNaosei(p[23], p[31], "Não fede nem cheira?");

    InsereSim(p[31], j[19], "Maycon");
    // Final caminho Mundial

    // --------Título = Não sei; Defesivo = Sim ---------
    InsereSim(p[25], j[20], "Balbuena");
    InsereNaosei(p[25], p[32], "Eh lindo e idolo?");
    InsereNao(p[25], p[32], "Eh lindo e idolo?");

    InsereSim(p[26], j[21], "Cássio");
    InsereNao(p[26], p[33], "Quebra perna dos adversários");
    InsereNaosei(p[26], p[33], "Quebra perna dos adversários");

    InsereSim(p[27], j[22], "Fagner");
    InsereNao(p[27], p[34], "É careca?");
    InsereNaosei(p[27], p[34], "É careca?");

    InsereSim(p[28], j[23], "Fabio Santos");
    InsereNao(p[28], p[35], "Gil Zagueiro?");
    InsereNaosei(p[28], p[35], "Gil Zagueiro?");

    InsereSim(p[29], j[24], "Gil Zagueiro");
    InsereNao(p[29], p[36], "Quase foi vendido para o PSG?");
    InsereNaosei(p[29], p[36], "Quase foi vendido para o PSG?");

    InsereSim(p[30], j[25], "Moscardo");
    InsereNao(p[30], p[37], "Substituto do Cássio?");
    InsereNaosei(p[30], p[37], "Substituto do Cássio?");

    InsereSim(p[31], j[26], "Carlos Miguel");
    InsereNao(p[31], p[38], "Argentino?");
    InsereNaosei(p[31], p[38], "Argentino?");

    InsereSim(p[32], j[37], "Fausto Vera");
    InsereNao(p[32], p[39], "Substituto do Balbuena?");
    InsereNaosei(p[32], p[39], "Substituto do Balbuena?");

    InsereSim(p[32], j[38], "Veríssimo");

    // -------Título = Não sei;Defensivo = Não sei-------
    InsereSim(p[33], p[40], "Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNaosei(p[33], p[41], "Eh lindo e idolo?");
    InsereNao(p[33], p[41], "Eh lindo e idolo?");
    // Caminho Loira
    InsereSim(p[34], j[39], "Róger Guedes");
    InsereNaosei(p[34], j[40], "Gil Zagueiro");
    InsereNao(p[34], j[40], "Gil Zagueiro");

    InsereSim(p[35], j[41], "Gil Zagueiro");
    InsereNao(p[35], p[42], "Paraguaio?");
    InsereNaosei(p[35], p[42], "Paraguaio?");

    InsereSim(p[36], j[42], "Balbuena");
    InsereNao(p[36], p[43], "Não tem nenhuma característica relevante?");
    InsereNaosei(p[36], p[43], "Não tem nenhuma característica relevante?");

    InsereSim(p[37], j[43], "Giuliano");
    InsereNao(p[37], j[44], "Giuliano");
    InsereNaosei(p[37], j[44], "Giuliano");
    // fim Loira

    // Caminho Ídolo e lindo
    InsereSim(p[38], j[45], "Cassio");
    InsereNaosei(p[38], p[43], "Aposentou o Hazard e Constuma quebrar a perna dos jogadores");
    InsereNao(p[38], p[43], "Aposentou o Hazard e costuma quebrar a perna dos jogadores");

    InsereSim(p[39], j[46], "Fagner");
    InsereNao(p[39], p[44], "É careca?");
    InsereNaosei(p[39], p[44], "É careca?");

    InsereSim(p[40], j[47], "Fabio Santos");
    InsereNao(p[40], p[45], "Gil Zagueiro?");
    InsereNaosei(p[40], p[45], "Gil Zagueiro?");

    InsereSim(p[41], j[48], "Gil Zagueiro");
    InsereNao(p[41], p[46], "É craque da bola?");
    InsereNaosei(p[41], p[46], "É craque da bola?");

    InsereSim(p[42], j[49], "Renato Augusto");
    InsereNao(p[42], p[47], "Ganhou Mundial de 2012?");
    InsereNaosei(p[42], p[47], "Ganhou Mundial de 2012?");

    InsereSim(p[43], j[50], "Paulinho");
    InsereNao(p[43], p[48], "Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[43], p[48], "Entre ele e seu irmão, ele é o bagre?");

    InsereSim(p[44], j[51], "Ángel Romero");
    InsereSim(p[44], p[49], "quase foi vendido pro psg?");
    InsereNaosei(p[44], p[49], "quase foi vendido pro psg?");

    InsereSim(p[45], j[52], "Moscardo");
    InsereNao(p[45], p[50], "Substituto do Cássio?");
    InsereNaosei(p[45], p[50], "Substituto do Cássio?");

    InsereSim(p[46], j[53], "Carlos Miguel");
    InsereNao(p[46], p[51], "Argentino?");
    InsereNaosei(p[46], p[51], "Argentino?");

    InsereSim(p[47], j[54], "Fausto Vera");
    InsereNao(p[47], p[52], "Substituto do Balbuena?");
    InsereNaosei(p[47], p[52], "Substituto do Balbuena?");

    InsereSim(p[48], j[55], "Veríssimo");
    InsereNao(p[48], p[53], "É calvo??");
    InsereNaosei(p[48], p[53], "É calvo??");

    InsereSim(p[49], p[54], "Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[49], p[55], "Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[49], p[55], "Jogou no time estreante da série B (Santos)?");
    // Caminho Loira
    InsereSim(p[50], j[56], "Rogér Guedes");
    // FIm Loira

    // Caminho Santos
    InsereSim(p[51], j[57], "Giuliano");
    InsereNao(p[51], p[56], "Paraguaio menos importante do time?");
    InsereNaosei(p[51], p[56], "Paraguaio menos importante do time?");

    InsereSim(p[52], j[58], "Rojas");
    InsereNao(p[52], p[57], "Perito em perder gol?");
    InsereNaosei(p[52], p[57], "Perito em perder gol?");

    InsereSim(p[53], p[58], "Titúlo exclusivo de bagre d'or?");
    InsereNao(p[53], j[59], "Róger Guedes");
    InsereNaosei(p[53], j[59], "Renato Augusto");

    InsereSim(p[54], j[60], "Yuri ALberto");
    InsereNao(p[54], p[59], "Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[54], p[59], "Foi pego a paulada pela torcida no motel?");

    InsereSim(p[55], j[61], "Luan");
    // Fim Santos
    // FIm ÍDolo e lindo

    // ---------Título = Não sei; Defensivo = Não------------
    InsereSim(p[56], p[60], "Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[56], p[61], "Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[56], p[61], "Jogou no time estreante da série B (Santos)?");
    // Caminho Loira
    InsereSim(p[57], j[62], "Rogér Guedes");
    // FIm Loira

    // Caminho Santos
    InsereSim(p[58], j[63], "Giuliano");
    InsereNao(p[58], p[62], "Paraguaio menos importante do time?");
    InsereNaosei(p[58], p[62], "Paraguaio menos importante do time?");

    InsereSim(p[59], j[64], "Rojas");
    InsereNao(p[59], p[63], "Perito em perder gol?");
    InsereNaosei(p[59], p[63], "Perito em perder gol?");

    InsereSim(p[60], p[64], "Titúlo exclusivo de bagre d'or?");
    InsereNao(p[60], p[65], "É craque da bola");
    InsereNaosei(p[60], p[65], "É craque da bola");
    // caminho craque
    InsereSim(p[61], j[65], "Renato Augusto");
    InsereNao(p[61], j[66], "Ángel Romero");
    InsereNaosei(p[61], j[66], "Ángel Romero");
    // fim caminho bagre

    // caminho bagre
    InsereSim(p[62], j[67], "Yuri ALberto");
    InsereNao(p[62], p[66], "Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[62], p[66], "Foi pego a paulada pela torcida no motel?");

    InsereSim(p[63], j[68], "Luan");
    // fim bagre

    // --------Título = Não; Defensivo = Sim ------------
    InsereSim(p[64], j[69], "Moscardo");
    InsereNao(p[64], p[67], "Substituto do Cássio?");
    InsereNaosei(p[64], p[67], "Substituto do Cássio?");

    InsereSim(p[65], j[70], "Carlos Miguel");
    InsereNao(p[65], p[68], "Argentino?");
    InsereNaosei(p[65], p[68], "Argentino?");

    InsereSim(p[66], j[71], "Fausto Vera");
    InsereNao(p[66], p[69], "Substituto do Balbuena?");
    InsereNaosei(p[66], p[69], "Substituto do Balbuena?");

    InsereSim(p[67], j[72], "Veríssimo");

    //-------Título = Não;Defensivo = não sei ---------
    InsereSim(p[68], j[73], "Moscardo");
    InsereNao(p[68], p[70], "Substituto do Cássio?");
    InsereNaosei(p[68], p[70], "Substituto do Cássio?");

    InsereSim(p[69], j[74], "Carlos Miguel");
    InsereNao(p[69], p[71], "Argentino?");
    InsereNaosei(p[69], p[71], "Argentino?");

    InsereSim(p[70], j[75], "Fausto Vera");
    InsereNao(p[70], p[72], "Substituto do Balbuena?");
    InsereNaosei(p[70], p[72], "Substituto do Balbuena?");

    InsereSim(p[71], j[76], "Veríssimo");
    InsereNao(p[71], p[73], "É calvo??");
    InsereNaosei(p[71], p[73], "É calvo??");

    InsereSim(p[72], p[74], "Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[72], p[75], "Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[72], p[75], "Jogou no time estreante da série B (Santos)?");
    // Caminho Loira
    InsereSim(p[73], j[77], "Rogér Guedes");
    // FIm Loira

    // Caminho Santos
    InsereSim(p[74], j[78], "Giuliano");
    InsereNao(p[74], p[76], "Paraguaio menos importante do time?");
    InsereNaosei(p[74], p[76], "Paraguaio menos importante do time?");

    InsereSim(p[75], j[79], "Rojas");
    InsereNao(p[75], p[77], "Perito em perder gol?");
    InsereNaosei(p[75], p[77], "Perito em perder gol?");

    InsereSim(p[76], p[78], "Titúlo exclusivo de bagre d'or?");

    InsereSim(p[77], j[80], "Yuri ALberto");
    InsereNao(p[77], p[79], "Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[77], p[79], "Foi pego a paulada pela torcida no motel?");

    InsereSim(p[78], j[81], "Luan");
    // Fim Santos

    //---------Título = Não; Defensivo = Não ---------------
    InsereSim(p[79], p[80], "Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[79], p[81], "Paraguaio menos importante do time?");
    InsereNaosei(p[79], p[81], "Paraguaio menos importante do time?");
    // Caminho Loira
    InsereSim(p[80], j[82], "Rogér Guedes");
    // FIm Loira

    // Caminho Paraguai
    InsereSim(p[81], j[83], "Rojas");
    InsereNao(p[81], p[82], "Perito em perder gol?");
    InsereNaosei(p[81], p[82], "Perito em perder gol?");

    InsereSim(p[82], p[83], "Titúlo exclusivo de bagre d'or?");
    InsereNao(p[82], p[84], "Não tem nenhuma característica relevante?");
    InsereNaosei(p[82], p[84], "Não tem nenhuma característica relevante?");

    // caminho bagre
    InsereSim(p[83], j[84], "Yuri ALberto");
    InsereNao(p[83], p[85], "Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[83], p[85], "Foi pego a paulada pela torcida no motel?");

    InsereSim(p[84], j[85], "Luan");
    // fim caminho bagre

    // caminho relevância
    InsereSim(p[85], j[86], "Giuliano");
    InsereNao(p[85], j[87], "Giuliano");
    InsereNaosei(p[85], j[87], "Giuliano");
    // fim caminho relevÇancia
    // fim caminho paraguai

    // Fim do processamento da árvore, e começo do código do jogo

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