// Arquivos de cabeçalho
#include <iostream>
#include "TAD.hpp"

using namespace std;

// Função main
int main()
{
    // Array de ponteiros, para cada node de pergunta
    node *p[86];
    for (int i = 0; i < 86; i++)
    {
        p[i] = nullptr;
    }

    // Array de ponteiros para node jogador
    node *j[87];
    for (int i = 0; i < 86; i++)
    {
        j[i] = nullptr;
    }

    Cria(p[0], "Ja ganhou algum titulo pelo clube?");

    /////////////////////////////////////////////////////////////////
    /////////// Bloco da pergunta 1 (3 filhos p4, p5, p6) ///////////
    InsereSim(p[0], p[1], "Eh do setor defensivo?");

    // Iníco Filho p4
    InsereSim(p[1], p[4], "Saiu do Corinthians no fim de 2023?");
    
    // Caminho SIM
    InsereSim(p[4], p[13], "Jogou por muitos anos com a camisa do Corinthians?");

    InsereSim(p[13], p[14], "Eh careca (roll on)?");
    InsereNaosei(p[13], j[0], "Balbuena");
    InsereNao(p[13], j[0], "Balbuena");
    InsereSim(p[14], j[1], "Fabio Santos");
    InsereNaosei(p[14], j[2], "Gil Zaguerio");
    InsereNao(p[14], j[2], "Gil Zaguerio");

    // Caminho NAOSEI
    InsereNaosei(p[4], p[15], "Eh lindo e idolo?");

    InsereSim(p[15], j[3], "Cassio");
    InsereNaosei(p[15], p[16], "Melhor lateral do mundo, e ruim com duas pernas?");
    InsereNao(p[15], p[16], "Melhor lateral do mundo, e ruim com duas pernas?");
    InsereSim(p[16], j[4], "Fagner");
    InsereNaosei(p[16], j[5], "Fagner");
    InsereNao(p[16], j[5], "Fagner");

    // Caminho NAO
    InsereNao(p[4], p[15], "Eh lindo e idolo?");

    InsereSim(p[15], j[3], "Cassio");
    InsereNaosei(p[15], p[16], "Melhor lateral do mundo, e ruim com duas pernas?");
    InsereNao(p[15], p[16], "Melhor lateral do mundo, e ruim com duas pernas?");
    InsereSim(p[16], j[4], "Fagner");
    InsereNaosei(p[16], j[5], "Fagner");
    InsereNao(p[16], j[5], "Fagner");


    // Início Filho p5
    InsereNaosei(p[1], p[5], "Saiu do Corinthians no meio da temporada?");

    // Caminho SIM
    InsereSim(p[5], j[6], "Balbuena");

    // Caminho NAOSEI
    InsereNaosei(p[5], p[17], "Eh lindo e idolo?");

    InsereSim(p[17], j[7], "Cassio");
    InsereNaosei(p[17], p[18], "Quebra Perna dos Adversarios?");
    InsereNao(p[17], p[18], "Quebra Perna dos Adversarios?");
    InsereSim(p[18], j[8], "Fagner");
    InsereNaosei(p[18], p[19], "Eh careca (roll on)?");
    InsereNao(p[18], p[19], "Eh careca (roll on)?");
    InsereSim(p[19], j[9], "Fabio Santos");
    InsereNaosei(p[19], p[20], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereNao(p[19], p[20], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereSim(p[20], j[10], "Gil Zagueiro");
    InsereNaosei(p[20], p[21], "Eh um dos Melhores em campo atualmente?");
    InsereNao(p[20], p[21], "Eh um dos Melhores em campo atualmente?");
    InsereSim(p[21], p[22], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[22], j[11], "Renato Augusto");
    InsereNaosei(p[22], p[23], "Entre ele e seu irmao, ele eh o bagre?");
    InsereNao(p[22], p[23], "Entre ele e seu irmao, ele eh o bagre?");
    InsereSim(p[23], j[12], "Angel Romero");
    InsereNaosei(p[23], j[13], "Angel Romero");
    InsereNao(p[23], j[13], "Angel Romero");
    InsereNaosei(p[21], p[24], "Ganhou o mundial de 2012?");
    InsereNao(p[21], p[24], "Ganhou o mundial de 2012?");
    InsereSim(p[24], j[14], "Paulinho");
    InsereNaosei(p[24], p[25], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereNao(p[24], p[25], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereSim(p[25], j[15], "Maycon");
    InsereNaosei(p[25], j[16], "Maycon");
    InsereNao(p[25], j[16], "Maycon");

    // Caminho NAO
    InsereNao(p[5], p[17], "Eh lindo e idolo?");

    InsereSim(p[17], j[7], "Cassio");
    InsereNaosei(p[17], p[18], "Quebra Perna dos Adversarios?");
    InsereNao(p[17], p[18], "Quebra Perna dos Adversarios?");
    InsereSim(p[18], j[8], "Fagner");
    InsereNaosei(p[18], p[19], "Eh careca (roll on)?");
    InsereNao(p[18], p[19], "Eh careca (roll on)?");
    InsereSim(p[19], j[9], "Fabio Santos");
    InsereNaosei(p[19], p[20], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereNao(p[19], p[20], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereSim(p[20], j[10], "Gil Zagueiro");
    InsereNaosei(p[20], p[21], "Eh um dos Melhores em campo atualmente?");
    InsereNao(p[20], p[21], "Eh um dos Melhores em campo atualmente?");
    InsereSim(p[21], p[22], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[22], j[11], "Renato Augusto");
    InsereNaosei(p[22], p[23], "Entre ele e seu irmao, ele eh o bagre?");
    InsereNao(p[22], p[23], "Entre ele e seu irmao, ele eh o bagre?");
    InsereSim(p[23], j[12], "Angel Romero");
    InsereNaosei(p[23], j[13], "Angel Romero");
    InsereNao(p[23], j[13], "Angel Romero");
    InsereNaosei(p[21], p[24], "Ganhou o mundial de 2012?");
    InsereNao(p[21], p[24], "Ganhou o mundial de 2012?");
    InsereSim(p[24], j[14], "Paulinho");
    InsereNaosei(p[24], p[25], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereNao(p[24], p[25], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereSim(p[25], j[15], "Maycon");
    InsereNaosei(p[25], j[16], "Maycon");
    InsereNao(p[25], j[16], "Maycon");


    // Início Filho p6
    InsereNao(p[1], p[6], "Eh um dos Melhores em campo atualmente?");

    // Caminho SIM
    InsereSim(p[6], p[26], "Eh craque de bola (Joga de terno e gravata)?");

    InsereSim(p[26], j[17], "Renato Augusto");
    InsereNaosei(p[26], p[27], "Entre ele e seu irmao, ele eh o bagre?");
    InsereNao(p[26], p[27], "Entre ele e seu irmao, ele eh o bagre?");
    InsereSim(p[27], j[18], "Angel Romero");
    InsereNaosei(p[27], j[19], "Angel Romero");
    InsereNao(p[27], j[19], "Angel Romero");

    // Caminho NAOSEI
    InsereNaosei(p[6], p[28], "Ganhou o mundial de 2012?");

    InsereSim(p[28], j[20], "Paulinho");
    InsereNaosei(p[28], p[29], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereNao(p[28], p[29], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereSim(p[29], j[21], "Maycon");
    InsereNaosei(p[29], j[22], "Maycon");
    InsereNao(p[29], j[22], "Maycon");

    // Caminho NAO
    InsereNao(p[6], p[28], "Ganhou o mundial de 2012?");

    InsereSim(p[28], j[20], "Paulinho");
    InsereNaosei(p[28], p[29], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereNao(p[28], p[29], "Volante horroroso? (Esposa tiltou com a toricda no Insta)");
    InsereSim(p[29], j[21], "Maycon");
    InsereNaosei(p[29], j[22], "Maycon");
    InsereNao(p[29], j[22], "Maycon");


    /////////////////////////////////////////////////////////////////
    /////////// Bloco da pergunta 2 (3 filhos p7, p8, p9) ///////////
    InsereNaosei(p[0], p[2], "Eh do setor defensivo?");

    // Iníco Filho p7
    InsereSim(p[2], p[7], "Saiu do Corinthians no meio da temporada?");

    // Caminho SIM
    InsereSim(p[7], j[23], "Balbuena");

    // Caminho NAOSEI
    InsereNaosei(p[7], p[30], "Eh lindo e idolo?");

    InsereSim(p[30], j[24], "Cassio");
    InsereNaosei(p[30], p[31], "Quebra Perna dos Adversarios?");
    InsereNao(p[30], p[31], "Quebra Perna dos Adversarios?");
    InsereSim(p[31], j[25], "Fagner");
    InsereNaosei(p[31], p[32], "Eh careca (roll on)?");
    InsereNao(p[31], p[32], "Eh careca (roll on)?");
    InsereSim(p[32], j[26], "Fabio Santos");
    InsereNaosei(p[32], p[33], "Gil Zagueiro?");
    InsereNao(p[32], p[33], "Gil Zagueiro?");
    InsereSim(p[33], j[27], "Gil Zaqueiro");
    InsereNaosei(p[33], p[34], "Foi vendido para o PSG?");
    Insere(p[33], p[34], "Foi vendido para o PSG?");
    InsereSim(p[34], j[28], "Moscardo");
    InsereNaosei(p[34], p[35], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereNao(p[34], p[35], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereSim(p[35], j[29], "Carlos Miguel");
    InsereNaosei(p[35], p[36], "Argentino? (Que passa Manito)");
    InsereNao(p[35], p[36], "Argentino? (Que passa Manito)");
    InsereSim(p[36], j[30], "Fausto Vera");
    InsereNaosei(p[36], p[37], "Substituto do Balbuena");
    InsereNao(p[36], p[37], "Substituto do Balbuena");
    InsereSim(p[37], j[31], "Verissimo");
    InsereNaosei(p[37], j[32], "Verissimo");
    InsereNao(p[37], j[32], "Verissimo");

    // Caminho NAO
    InsereNao(p[7], p[30], "Eh lindo e idolo?");

    InsereSim(p[30], j[24], "Cassio");
    InsereNaosei(p[30], p[31], "Quebra Perna dos Adversarios?");
    InsereNao(p[30], p[31], "Quebra Perna dos Adversarios?");
    InsereSim(p[31], j[25], "Fagner");
    InsereNaosei(p[31], p[32], "Eh careca (roll on)?");
    InsereNao(p[31], p[32], "Eh careca (roll on)?");
    InsereSim(p[32], j[26], "Fabio Santos");
    InsereNaosei(p[32], p[33], "Gil Zagueiro?");
    InsereNao(p[32], p[33], "Gil Zagueiro?");
    InsereSim(p[33], j[27], "Gil Zaqueiro");
    InsereNaosei(p[33], p[34], "Foi vendido para o PSG?");
    Insere(p[33], p[34], "Foi vendido para o PSG?");
    InsereSim(p[34], j[28], "Moscardo");
    InsereNaosei(p[34], p[35], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereNao(p[34], p[35], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereSim(p[35], j[29], "Carlos Miguel");
    InsereNaosei(p[35], p[36], "Argentino? (Que passa Manito)");
    InsereNao(p[35], p[36], "Argentino? (Que passa Manito)");
    InsereSim(p[36], j[30], "Fausto Vera");
    InsereNaosei(p[36], p[37], "Substituto do Balbuena?");
    InsereNao(p[36], p[37], "Substituto do Balbuena?");
    InsereSim(p[37], j[31], "Verissimo");
    InsereNaosei(p[37], j[32], "Verissimo");
    InsereNao(p[37], j[32], "Verissimo");


    // Início Filho p8
    InsereNaosei(p[2], p[8], "Saiu do Corinthians no fim de 2023?");

    // Caminho SIM
    InsereSim(p[8], p[38], "Loira mais (calva) amada do Brasil?");

    InsereSim(p[38], j[33], "Roger Guedes");
    InsereNaosei(p[38], p[39], "Gil Zagueiro?");
    InsereNao(p[38], p[39], "Gil Zagueiro?");
    InsereSim(p[39], j[34], "Gil Zagueiro");
    InsereNaosei(p[39], p[40], "Nasceu no Paraguai?");
    InsereNao(p[39], p[40], "Nasceu no Paraguai?");
    InsereSim(p[40], j[35], "Balbuena");
    InsereNaosei(p[40], p[41], "Nao tem nenhuma caracteristica relevante?");
    InsereNao(p[40], p[41], "Nao tem nenhuma caracteristica relevante?");
    InsereSim(p[41], j[36], "Giuliano");
    InsereNaosei(p[41], j[37], "Giuliano");
    InsereNao(p[41], j[37], "Giuliano");

    // Caminho NAOSEI
    InsereNaosei(p[8], p[42], "Eh lindo e idolo?");

    InsereSim(p[42], j[38], "Cassio");
    InsereNaosei(p[42], p[43], "Quebra Perna dos Adversarios?");
    InsereNao(p[42], p[43], "Quebra Perna dos Adversarios?");
    InsereSim(p[43], j[39], "Fagner");
    InsereNaosei(p[43], p[44], "Eh careca (roll on)?");
    InsereNao(p[43], p[44], "Eh careca (roll on)?");
    InsereSim(p[44], j[40], "Fabio Santos");
    InsereNaosei(p[44], p[45], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereNao(p[44], p[45], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereSim(p[45], j[41], "Gil Zaqueiro");
    InsereNaosei(p[45], p[46], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[45], p[46], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[46], j[42], "Renato Augusto");
    InsereNaosei(p[46], p[47], "Ganhou o mundial de 2012?");
    InsereNao(p[46], p[47], "Ganhou o mundial de 2012?");
    InsereSim(p[47], j[43], "Paulinho");
    InsereNaosei(p[47], p[48], "Entre ele e seu irmao, ele eh o bagre?");
    InsereNao(p[47], p[48], "Entre ele e seu irmao, ele eh o bagre?");
    InsereSim(p[48], j[44], "Angel Romero");
    InsereNaosei(p[48], p[49], "Foi vendido para o PSG?");
    InsereNao(p[48], p[49], "Foi vendido para o PSG?");
    InsereSim(p[49], j[45], "Moscardo");
    InsereNaosei(p[49], p[50], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereNao(p[49], p[50], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereSim(p[50], j[46], "Carlos Miguel");
    InsereNaosei(p[50], p[51], "Argentino? (Que passa manito)");
    InsereNao(p[50], p[51], "Argentino? (Que passa manito)");
    InsereSim(p[51], j[47], "Fausto Vera");
    InsereNaosei(p[51], p[52], "Substituto do Balbuena");
    InsereNao(p[51], p[52], "Substituto do Balbuena");
    InsereSim(p[52], j[48], "Verissimo");
    InsereNaosei(p[52], p[53], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereNao(p[52], p[53], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereSim(p[53], p[54], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");
    InsereSim(p[54], j[49], "Roger Guedes");
    InsereNaosei(p[54], j[49], "Roger Guedes");
    InsereNao(p[54], j[49], "Roger Guedes");
    InsereNaosei(p[53], p[55], "Jogou no time estreante da Serie B? (Santastico)");
    InsereNao(p[53], p[55], "Jogou no time estreante da Serie B? (Santastico)");
    InsereSim(p[55], j[50], "Giuliano");
    InsereNaosei(p[55], p[56], "Paraguaio menos importante do time?");
    InsereNao(p[55], p[56], "Paraguaio menos importante do time?");
    InsereSim(p[56], j[51], "Rojas");
    InsereNaosei(p[56], p[57], "Perito em perder gol?");
    InsereNao(p[56], p[57], "Perito em perder gol?");
    InsereSim(p[57], p[58], "Titulo exclusivo de Bagre d'or?");
    InsereNaosei(p[57], j[52], "Roger Guedes");
    InsereNao(p[57], j[52], "Roger Guedes");
    InsereSim(p[58], j[53], "Yuri Alberto");
    InsereNaosei(p[58], p[59], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[58], p[59], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[59], j[54], "Luan");
    InsereNaosei(p[59], j[55], "Luan");
    InsereNao(p[59], j[55], "Luan");

    // Caminho NAO
    InsereNao(p[8], p[42], "Eh lindo e idolo?");

    InsereSim(p[42], j[38], "Cassio");
    InsereNaosei(p[42], p[43], "Quebra Perna dos Adversarios?");
    InsereNao(p[42], p[43], "Quebra Perna dos Adversarios?");
    InsereSim(p[43], j[39], "Fagner");
    InsereNaosei(p[43], p[44], "Eh careca (roll on)?");
    InsereNao(p[43], p[44], "Eh careca (roll on)?");
    InsereSim(p[44], j[40], "Fabio Santos");
    InsereNaosei(p[44], p[45], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereNao(p[44], p[45], "Gil Zagueiro? (Sigam ele no Twitter)");
    InsereSim(p[45], j[41], "Gil Zaqueiro");
    InsereNaosei(p[45], p[46], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[45], p[46], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[46], j[42], "Renato Augusto");
    InsereNaosei(p[46], p[47], "Ganhou o mundial de 2012?");
    InsereNao(p[46], p[47], "Ganhou o mundial de 2012?");
    InsereSim(p[47], j[43], "Paulinho");
    InsereNaosei(p[47], p[48], "Entre ele e seu irmao, ele eh o bagre?");
    InsereNao(p[47], p[48], "Entre ele e seu irmao, ele eh o bagre?");
    InsereSim(p[48], j[44], "Angel Romero");
    InsereNaosei(p[48], p[49], "Foi vendido para o PSG?");
    InsereNao(p[48], p[49], "Foi vendido para o PSG?");
    InsereSim(p[49], j[45], "Moscardo");
    InsereNaosei(p[49], p[50], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereNao(p[49], p[50], "Substituto do Brad Pitt? (Vulgo Cassio)");
    InsereSim(p[50], j[46], "Carlos Miguel");
    InsereNaosei(p[50], p[51], "Argentino? (Que passa manito)");
    InsereNao(p[50], p[51], "Argentino? (Que passa manito)");
    InsereSim(p[51], j[47], "Fausto Vera");
    InsereNaosei(p[51], p[52], "Substituto do Balbuena");
    InsereNao(p[51], p[52], "Substituto do Balbuena");
    InsereSim(p[52], j[48], "Verissimo");
    InsereNaosei(p[52], p[53], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereNao(p[52], p[53], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereSim(p[53], p[54], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");
    InsereSim(p[54], j[49], "Roger Guedes");
    InsereNaosei(p[54], j[49], "Roger Guedes");
    InsereNao(p[54], j[49], "Roger Guedes");
    InsereNaosei(p[53], p[55], "Jogou no time estreante da Serie B? (Santastico)");
    InsereNao(p[53], p[55], "Jogou no time estreante da Serie B? (Santastico)");
    InsereSim(p[55], j[50], "Giuliano");
    InsereNaosei(p[55], p[56], "Paraguaio menos importante do time?");
    InsereNao(p[55], p[56], "Paraguaio menos importante do time?");
    InsereSim(p[56], j[51], "Rojas");
    InsereNaosei(p[56], p[57], "Perito em perder gol?");
    InsereNao(p[56], p[57], "Perito em perder gol?");
    InsereSim(p[57], p[58], "Titulo exclusivo de Bagre d'or?");
    InsereNaosei(p[57], j[52], "Roger Guedes");
    InsereNao(p[57], j[52], "Roger Guedes");
    InsereSim(p[58], j[53], "Yuri Alberto");
    InsereNaosei(p[58], p[59], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[58], p[59], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[59], j[54], "Luan");
    InsereNaosei(p[59], j[55], "Luan");
    InsereNao(p[59], j[55], "Luan");


    // Início Filho p9
    InsereNao(p[2], p[9], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");

    // Caminho SIM
    InsereSim(p[9], p[60], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");

    InsereSim(p[60], j[56], "Roger Guedes");
    InsereNaosei(p[60], j[56], "Roger Guedes");
    InsereNao(p[60], j[56], "Roger Guedes");

    // Caminho NAOSEI
    InsereNaosei(p[9], p[61], "Jogou no time estreante da Serie B? (Santastico)");

    InsereSim(p[61], j[57], "Giuliano");
    InsereNaosei(p[61], p[62], "Paraguaio menos importante do time?");
    InsereNao(p[61], p[62], "Paraguaio menos importante do time?");
    InsereSim(p[62], j[58], "Rojas");
    InsereNaosei(p[62], p[63], "Perito em perder gol?");
    InsereNao(p[62], p[63], "Perito em perder gol?");
    InsereSim(p[63], p[64], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[64], j[59], "Yuri Alberto");
    InsereNaosei(p[64], p[65], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[64], p[65], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[65], j[60], "Luan");
    InsereNaosei(p[65], j[61], "Luan");
    InsereNao(p[65], j[61], "Luan");
    InsereNaosei(p[63], p[66], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[63], p[66], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[66], j[61], "Renato Augusto");
    InsereNaosei(p[66], j[63], "Angel Romero");
    InsereNao(p[66], j[63], "Angel Romero");

    // Caminho NAO
    InsereNao(p[9], p[61], "Jogou no time estreante da Serie B? (Santastico)");

    InsereSim(p[61], j[57], "Giuliano");
    InsereNaosei(p[61], p[62], "Paraguaio menos importante do time?");
    InsereNao(p[61], p[62], "Paraguaio menos importante do time?");
    InsereSim(p[62], j[58], "Rojas");
    InsereNaosei(p[62], p[63], "Perito em perder gol?");
    InsereNao(p[62], p[63], "Perito em perder gol?");
    InsereSim(p[63], p[64], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[64], j[59], "Yuri Alberto");
    InsereNaosei(p[64], p[65], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[64], p[65], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[65], j[60], "Luan");
    InsereNaosei(p[65], j[61], "Luan");
    InsereNao(p[65], j[61], "Luan");
    InsereNaosei(p[63], p[66], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[63], p[66], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[66], j[61], "Renato Augusto");
    InsereNaosei(p[66], j[63], "Angel Romero");
    InsereNao(p[66], j[63], "Angel Romero");


    ////////////////////////////////////////////////////////////////////
    /////////// Bloco da pergunta 3 (3 filhos p10, p11, p12) ///////////
    InsereNao(p[0], p[3], "Eh do setor defensivo?");

    // Iníco Filho p10
    InsereSim(p[3], p[10], "Foi vendido para o PSG?");

    // Caminho SIM
    InsereSim(p[10], j[64], "Moscardo");

    // Caminho NAOSEI
    InsereNaosei(p[10], p[67], "Substituto do Brad Pitt? (Vulgo Cassio)");

    InsereSim(p[67], j[65], "Carlos Miguel");
    InsereNaosei(p[67], p[68], "Argentino? (Que passa manito)");
    InsereNao(p[67], p[68], "Argentino? (Que passa manito)");
    InsereSim(p[68], j[66], "Fausto Vera");
    InsereNaosei(p[68], p[69], "Substituto do Balbuena?");
    InsereNao(p[68], p[69], "Substituto do Balbuena?");
    InsereSim(p[69], j[67], "Verissimo");
    InsereNaosei(p[69], j[68], "Verissimo");
    InsereNao(p[69], j[68], "Verissimo");

    // Caminho NAO
    InsereNao(p[10], p[67], "Substituto do Brad Pitt? (Vulgo Cassio)");

    InsereSim(p[67], j[65], "Carlos Miguel");
    InsereNaosei(p[67], p[68], "Argentino? (Que passa manito)");
    InsereNao(p[67], p[68], "Argentino? (Que passa manito)");
    InsereSim(p[68], j[66], "Fausto Vera");
    InsereNaosei(p[68], p[69], "Substituto do Balbuena?");
    InsereNao(p[68], p[69], "Substituto do Balbuena?");
    InsereSim(p[69], j[67], "Verissimo");
    InsereNaosei(p[69], j[68], "Verissimo");
    InsereNao(p[69], j[68], "Verissimo");


    // Início Filho p11
    InsereNaosei(p[3], p[11], "Foi vendido para o PSG?");

    // Caminho SIM
    InsereSim(p[11], j[69], "Moscardo");

    // Caminho NAOSEI
    InsereNaosei(p[11], p[70], "Substituto do Brad Pitt? (Vulgo Cassio)");

    InsereSim(p[70], j[70], "Carlos Miguel");
    InsereNaosei(p[70], p[71], "Argentino? (Que passa Manito)");
    InsereNao(p[70], p[71], "Argentino? (Que passa Manito)");
    InsereSim(p[71], j[71], "Fausto Vera");
    InsereNaosei(p[71], p[72], "Substituto do Balbuena");
    InsereNao(p[71], p[72], "Substituto do Balbuena");
    InsereSim(p[72], j[72], "Verissimo");
    InsereNaosei(p[72], p[73], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereNao(p[72], p[73], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereSim(p[73], p[74], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");
    InsereSim(p[74], j[73], "Roger Guedes");
    InsereNaosei(p[74], j[73], "Roger Guedes");
    InsereNao(p[74], j[73], "Roger Guedes");
    InsereNaosei(p[73], p[75], "Jogou no time estreante da Serie B? (Santastico)");
    InsereNao(p[73], p[75], "Jogou no time estreante da Serie B? (Santastico)");
    InsereSim(p[75], j[74], "Giuliano");
    InsereNaosei(p[75], p[76], "Paraguaio menos importante");
    InsereNao(p[75], p[76], "Paraguaio menos importante");
    InsereSim(p[76], j[75], "Rojas");
    InsereNaosei(p[76], p[77], "Perito em perder gol?");
    InsereNao(p[76], p[77], "Perito em perder gol?");
    InsereSim(p[77], p[78], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[78], j[76], "Yuri Alberto");
    InsereNaosei(p[78], p[79], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[78], p[79], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[79], j[77], "Luan");
    InsereNaosei(p[79], j[78], "Luan");
    InsereNao(p[79], j[78], "Luan");
    InsereNaosei(p[77], p[80], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[77], p[80], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[80], j[79], "Renato Augusto");
    InsereNaosei(p[80], j[80], "Angel Romero");
    InsereNao(p[80], j[80], "Angel Romero");

    // Caminho NAO
    InsereNao(p[11], p[70], "Substituto do Brad Pitt? (Vulgo Cassio)");

    InsereSim(p[70], j[70], "Carlos Miguel");
    InsereNaosei(p[70], p[71], "Argentino? (Que passa Manito)");
    InsereNao(p[70], p[71], "Argentino? (Que passa Manito)");
    InsereSim(p[71], j[71], "Fausto Vera");
    InsereNaosei(p[71], p[72], "Substituto do Balbuena");
    InsereNao(p[71], p[72], "Substituto do Balbuena");
    InsereSim(p[72], j[72], "Verissimo");
    InsereNaosei(p[72], p[73], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereNao(p[72], p[73], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");
    InsereSim(p[73], p[74], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");
    InsereSim(p[74], j[73], "Roger Guedes");
    InsereNaosei(p[74], j[73], "Roger Guedes");
    InsereNao(p[74], j[73], "Roger Guedes");
    InsereNaosei(p[73], p[75], "Jogou no time estreante da Serie B? (Santastico)");
    InsereNao(p[73], p[75], "Jogou no time estreante da Serie B? (Santastico)");
    InsereSim(p[75], j[74], "Giuliano");
    InsereNaosei(p[75], p[76], "Paraguaio menos importante");
    InsereNao(p[75], p[76], "Paraguaio menos importante");
    InsereSim(p[76], j[75], "Rojas");
    InsereNaosei(p[76], p[77], "Perito em perder gol?");
    InsereNao(p[76], p[77], "Perito em perder gol?");
    InsereSim(p[77], p[78], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[78], j[76], "Yuri Alberto");
    InsereNaosei(p[78], p[79], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[78], p[79], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[79], j[77], "Luan");
    InsereNaosei(p[79], j[78], "Luan");
    InsereNao(p[79], j[78], "Luan");
    InsereNaosei(p[77], p[80], "Eh craque de bola (Joga de terno e gravata)?");
    InsereNao(p[77], p[80], "Eh craque de bola (Joga de terno e gravata)?");
    InsereSim(p[80], j[79], "Renato Augusto");
    InsereNaosei(p[80], j[80], "Angel Romero");
    InsereNao(p[80], j[80], "Angel Romero");


    // Início Filho p12
    InsereNao(p[3], p[12], "Eh Calvo? (Tem duas entradas pro show da Taylor Swift)");

    // Caminho SIM
    InsereSim(p[12], p[81], "Era a loira mais amada do Brasil e se vendeu para Arabia? (traidor)");

    InsereSim(p[81], j[81], "Roger Guedes");
    InsereNaosei(p[81], j[81], "Roger Guedes");
    InsereNao(p[81], j[81], "Roger Guedes");

    // Caminho NAOSEI
    InsereNaosei(p[12], p[82], "Paraguaio menos importante do time?");

    InsereSim(p[82], j[82], "Rojas");
    InsereNaosei(p[82], p[83], "Perito em perder gol?");
    InsereNao(p[82], p[83], "Perito em perder gol?");
    InsereSim(p[83], p[84], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[84], j[83], "Yuri Alberto");
    InsereNaosei(p[84], p[85], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[84], p[85], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[85], j[84], "Luan");
    InsereNaosei(p[85], j[85], "Luan");
    InsereNao(p[85], j[85], "Luan");
    InsereNaosei(p[83], p[86], "Nao tem nenhuma caracteristica relevante?");
    InsereNao(p[83], p[86], "Nao tem nenhuma caracteristica relevante?");
    InsereSim(p[86], j[86], "Giuliano");
    InsereNaosei(p[86], j[87], "Giuliano");
    InsereNao(p[86], j[87], "Giuliano");

    // Caminho NAO
    InsereNao(p[12], p[82], "Paraguaio menos importante do time?");

    InsereSim(p[82], j[82], "Rojas");
    InsereNaosei(p[82], p[83], "Perito em perder gol?");
    InsereNao(p[82], p[83], "Perito em perder gol?");
    InsereSim(p[83], p[84], "Titulo exclusivo de Bagre d'or?");
    InsereSim(p[84], j[83], "Yuri Alberto");
    InsereNaosei(p[84], p[85], "Foi pego a paulada pela torcida no motel?");
    InsereNao(p[84], p[85], "Foi pego a paulada pela torcida no motel?");
    InsereSim(p[85], j[84], "Luan");
    InsereNaosei(p[85], j[85], "Luan");
    InsereNao(p[85], j[85], "Luan");
    InsereNaosei(p[83], p[86], "Nao tem nenhuma caracteristica relevante?");
    InsereNao(p[83], p[86], "Nao tem nenhuma caracteristica relevante?");
    InsereSim(p[86], j[86], "Giuliano");
    InsereNaosei(p[86], j[87], "Giuliano");
    InsereNao(p[86], j[87], "Giuliano");


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Console do game

    cout << endl;
    cout << endl;
    cout << "================================================" << endl;
    cout << "                  AdivinhaTimao                 " << endl;
    cout << "================================================" << endl;
    cout << endl;
    cout << "Advinha Timao eh um jogo cativante que desafia os fas do Corinthians a testarem seus conhecimentos sobre o elenco do time de 2023." << endl;
    cout << "Inspirado no estilo do Akinator, este jogo oferece aos jogadores a oportunidade de escolherem um jogador do Corinthians e desafiarem o sistema adivinhador a descobrir quem eh." << endl;
    cout << "Com uma gama exclusiva de jogadores do elenco do Timao em 2023, os usuarios serao surpreendidos com a precisao do jogo ao tentar descobrir qual jogador foi escolhido," << endl;
    cout << "oferecendo uma experiencia empolgante e divertida para os apaixonados pelo futebol e pelo Corinthians." << endl;
    cout << "Para jogar utilize a letra s para dizer que Sim, n para dizer que Nao, ns para dizer NaoSei e x para encerrar o jogo a qualquer momento" << endl;
    cout << endl;
    cout << "Jogadores que podem ser encontrados:" << endl;
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
                cout << raiz->info << ": ";

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
            cout << "Voce pensou em " << raiz->info << "???";
            cin >> escolha;
            while (escolha != "s" && escolha != "n")
            {
                cin >> start;
            }
            if (escolha == "s")
            {
                cout << "AAAEEEEEE!!! Obrigado por jogar AdivinhaTimao!!!" << endl;
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