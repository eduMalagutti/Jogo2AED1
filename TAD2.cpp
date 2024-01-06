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

void InsereSim(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->sim, filho, info);
}

void InsereNaosei(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->naoSei, filho, info);
}

void InsereNao(node *&paiPtr, node *&filho, string info)
{
    Insere(paiPtr->nao, filho, info);
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
    // Array de ponteiros, para cada node de pergunta
    // Array de ponteiros para node jogador
    node *j[78];
    for (int i = 0; i < 78; i++)
    {
        j[i] = nullptr;
    }
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
    Cria(p[0], "ja ganhou algum titulo pelo clube?");
    // ---- segundo nível ----
    InsereSim(p[0], p[1] , "eh do setor defensivo?");
    InsereNaosei(p[0], p[2],"eh do setor defensivo?");
    InsereNao(p[0], p[3],"eh do setor defensivo?");
    // ---- terceiro nível ----
    //sub: Titulo-Sim
    InsereSim(p[1], p[4] ,"saiu do clube em 2023?");
    InsereNaosei(p[1], p[5],"saiu do clube em 2023?");
    InsereNao(p[1], p[6],"eh um dos melhores em campo atualmente?");
    //sub: Titulo-Naosei
    InsereSim(p[2], p[7] , "saiu do clube em 2023?");
    InsereNaosei(p[2], p[8],"saiu do clube em 2023?");
    InsereNao(p[2], p[9],"Eh calvo? (Tem duas entradas pro show da Taylor swift)");
    //sub: Titulo-Nao
    InsereSim(p[3], p[10] , "quase foi vendido pro psg?");
    InsereNaosei(p[3], p[11],"quase foi vendido pro psg?");
    InsereNao(p[3], p[12],"Eh calvo? (Tem duas entradas pro show da Taylor swift)");
    
    //Agora vou fazer por Arvore e não por nível, vai ficar bem mais fácil de perceber erros
    //Vamos fazer desse jeito, 3 linhas seguidas para arrumar os ponteiros de um node e depois pula a liinha e faz o proximo

    // ---- Título-Sim ; Defensivo-Sim ----
    InsereSim(p[4], p[13], "Jogou muitos anos com a camisa do Corinthians");
    InsereNaosei(p[4], p[14], "Eh lindo e idolo?");
    InsereNao(p[4], p[14], "Eh lindo e idolo?");
    
    InsereSim(p[5], j[0], "Gil Zagueiro");
    InsereNaosei(p[5], j[1], "Balbuena");
    InsereNao(p[5], j[1], "Balbuena");

    InsereSim(p[6], j[2], "Cassio");
    InsereNaosei(p[6], p[15], "Aposentou o Hazard");
    InsereNao(p[6], p[16], "Aposentou o Hazard");

    InsereSim(p[7],j[3],"Fagner");
    InsereNao(p[7],p[17],"É careca?");
    InsereNaosei(p[7],p[17],"É careca?");

    InsereSim(p[8],j[4],"Fabio Santos");
    InsereNao(p[8],p[18],"Gil Zagueiro?");
    InsereNaosei(p[8],p[18],"Gil Zagueiro?");

    InsereSim(p[9],j[5],"Gil Zagueiro");
    InsereNaosei(p[9],j[6],"Gil Zagueiro");
    InsereNao(p[9],j[6],"Gil Zagueiro");

    // -----Título Sim; Defensivo = Não sei
    InsereSim(p[10],j[7],"Balbuena");
    InsereNaosei(p[10], p[19], "Eh lindo e idolo?");
    InsereNao(p[10], p[19], "Eh lindo e idolo?");

    InsereSim(p[11],j[8],"Cássio");
    InsereNao(p[11],p[20],"Quebra perna dos adversários");
    InsereNaosei(p[11],p[20],"Quebra perna dos adversários");

    InsereSim(p[12],j[9],"Fagner");
    InsereNao(p[12],p[21],"É careca?");
    InsereNaosei(p[12],p[21],"É careca?");

    InsereSim(p[13],j[10],"Fabio Santos");
    InsereNao(p[13],p[22],"Gil Zagueiro?");
    InsereNaosei(p[13],p[22],"Gil Zagueiro?");

    InsereSim(p[14],j[11],"Gil Zagueiro");
    InsereNao(p[14],p[23],"Melhores em campos atualmente");
    InsereNaosei(p[14],p[23],"Melhores em campos atualmente");

    InsereSim(p[15],p[24],"É craque de bola?");
    InsereNao(p[15],p[25],"Ganhou mundial de 2012?");
    InsereNaosei(p[15],p[25],"Ganhou mundial de 2012?");
    // Caminho- Craque de Bola
    InsereSim(p[16],j[12],"Renato Augusto");
    InsereNao(p[16],p[26],"Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[16],p[26],"Entre ele e seu irmão, ele é o bagre?");

    InsereSim(p[17],j[13],"Ángel Romero");
    //Final Craque de Bola

    //Caminho Ganhou Mundial 2012
    InsereSim(p[18],j[14],"Paulinho");
    InsereNao(p[18],p[27],"Não fede nem cheira?");
    InsereNaosei(p[18],p[27],"Não fede nem cheira?");  

    InsereSim(p[19],j[15],"Maycon");
    //Final caminho Mundial

    // ----Título = Sim; Defensivo = Não
    InsereSim(p[20],p[28],"É craque de bola?");
    InsereNao(p[29],p[29],"Ganhou mundial de 2012?");
    InsereNaosei(p[20],p[29],"Ganhou mundial de 2012?");
    //Caminho é craque
    InsereSim(p[21],j[16],"Renato Augusto");
    InsereNao(p[21],p[30],"Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[21],p[30],"Entre ele e seu irmão, ele é o bagre?");

    InsereSim(p[22],j[17],"Ángel Romero");
    //Final Craque de Bola

    //Caminho Ganhou Mundial 2012
    InsereSim(p[23],j[18],"Paulinho");
    InsereNao(p[23],p[31],"Não fede nem cheira?");
    InsereNaosei(p[23],p[31],"Não fede nem cheira?");  

    InsereSim(p[24],j[19],"Maycon");
    //Final caminho Mundial

    // --------Título = Não sei; Defesivo = Sim ---------
    InsereSim(p[25],j[20],"Balbuena");
    InsereNaosei(p[25], p[32], "Eh lindo e idolo?");
    InsereNao(p[25], p[32], "Eh lindo e idolo?");

    InsereSim(p[26],j[21],"Cássio");
    InsereNao(p[26],p[33],"Quebra perna dos adversários");
    InsereNaosei(p[26],p[33],"Quebra perna dos adversários");

    InsereSim(p[27],j[22],"Fagner");
    InsereNao(p[27],p[34],"É careca?");
    InsereNaosei(p[27],p[34],"É careca?");

    InsereSim(p[28],j[23],"Fabio Santos");
    InsereNao(p[28],p[35],"Gil Zagueiro?");
    InsereNaosei(p[28],p[35],"Gil Zagueiro?");

    InsereSim(p[29],j[24],"Gil Zagueiro");
    InsereNao(p[29],p[36],"Quase foi vendido para o PSG?");
    InsereNaosei(p[29],p[36],"Quase foi vendido para o PSG?");

    InsereSim(p[],j[],"Moscardo");
    InsereNao(p[],p[],"Substituto do Cássio?");
    InsereNaosei(p[],p[],"Substituto do Cássio?");

    InsereSim(p[],j[],"Carlos Miguel");
    InsereNao(p[],p[],"Argentino?");
    InsereNaosei(p[],p[],"Argentino?");

    InsereSim(p[],j[],"Fausto Vera");
    InsereNao(p[],p[],"Substituto do Balbuena?");
    InsereNaosei(p[],p[],"Substituto do Balbuena?");

    InsereSim(p[],j[],"Veríssimo");
    
    



    // Defensivo = Não sei
    InsereSim(p[],p[],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNaosei(p[], p[], "Eh lindo e idolo?");
    InsereNao(p[], p[], "Eh lindo e idolo?");
    //Caminho Loira
    InsereSim(p[],j[],"Róger Guedes");
    InsereNaosei(p[],j[],"Gil Zagueiro");
    InsereNao(p[],j[],"Gil Zagueiro");

    InsereSim(p[],j[],"Gil Zagueiro");
    InsereNao(p[],p[],"Paraguaio?");
    InsereNaosei(p[],p[],"Paraguaio?");

    InsereSim(p[],j[],"Balbuena");
    InsereNao(p[],p[],"Não tem nenhuma característica relevante?");
    InsereNaosei(p[],p[],"Não tem nenhuma característica relevante?");

    InsereSim(p[],j[],"Giuliano");
    InsereNao(p[],j[],"Giuliano");
    InsereNaosei(p[],j[],"Giuliano");
    //fim Loira

    //Caminho Ídolo e lindo
    InsereSim(p[], j[]], "Cassio");
    InsereNaosei(p[], p[], "Aposentou o Hazard e Constuma quebrar a perna dos jogadores");
    InsereNao(p[], p[], "Aposentou o Hazard e costuma quebrar a perna dos jogadores");

    InsereSim(p[],j[],"Fagner");
    InsereNao(p[],p[],"É careca?");
    InsereNaosei(p[],p[],"É careca?");

    InsereSim(p[],j[],"Fabio Santos");
    InsereNao(p[],p[],"Gil Zagueiro?");
    InsereNaosei(p[],p[],"Gil Zagueiro?");

    InsereSim(p[],j[],"Gil Zagueiro");
    InsereNao(p[],p[],"É craque da bola?");
    InsereNaosei(p[],p[],"É craque da bola?");

    InsereSim(p[],j[],"Renato Augusto");
    InsereNao(p[],p[],"Ganhou Mundial de 2012?");
    InsereNaosei(p[],p[],"Ganhou Mundial de 2012?");

    InsereSim(p[],j[],"Paulinho");
    InsereNao(p[],p[],"Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[],p[],"Entre ele e seu irmão, ele é o bagre?");

    InsereSim(p[22],j[17],"Ángel Romero");
    InsereSim(p[3], p[10] , "quase foi vendido pro psg?");
    InsereNaosei(p[3], p[11],"quase foi vendido pro psg?");

    InsereSim(p[],j[],"Moscardo");
    InsereNao(p[],p[],"Substituto do Cássio?");
    InsereNaosei(p[],p[],"Substituto do Cássio?");

    InsereSim(p[],j[],"Carlos Miguel");
    InsereNao(p[],p[],"Argentino?");
    InsereNaosei(p[],p[],"Argentino?");

    InsereSim(p[],j[],"Fausto Vera");
    InsereNao(p[],p[],"Substituto do Balbuena?");
    InsereNaosei(p[],p[],"Substituto do Balbuena?");

    InsereSim(p[],j[],"Veríssimo");
    InsereNao(p[],p[],"É calvo??");
    InsereNaosei(p[],p[],"É calvo??");

    InsereSim(p[],p[],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[],p[],"Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[],p[],"Jogou no time estreante da série B (Santos)?");
    //Caminho Loira
    InsereSim(p[],j[],"Rogér Guedes");
    //FIm Loira

    //Caminho Santos
    InsereSim(p[],j[],"Giuliano");
    InsereNao(p[],p[],"Paraguaio menos importante do time?");
    InsereNaosei(p[],p[],"Paraguaio menos importante do time?");

    InsereSim(p[],j[],"Rojas");
    InsereNao(p[],p[],"Perito em perder gol?");
    InsereNaosei(p[],p[],"Perito em perder gol?");

    InsereSim(p[],p[],"Titúlo exclusivo de bagre d'or?");
    InsereNao(p[],j[],"Róger Guedes");
    InsereNaosei(p[],j[],"Renato Augusto");

    InsereSim(p[],j[],"Yuri ALberto");
    InsereNao(p[],p[],"Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[],p[],"Foi pego a paulada pela torcida no motel?");

    InsereSim(p[],j[],"Luan");
    //Fim Santos
    //FIm ÍDolo e lindo

    //Caminho Defensivo Não
    InsereSim(p[],p[],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[],p[],"Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[],p[],"Jogou no time estreante da série B (Santos)?");
    //Caminho Loira
    InsereSim(p[],j[],"Rogér Guedes");
    //FIm Loira

    //Caminho Santos
    InsereSim(p[],j[],"Giuliano");
    InsereNao(p[],p[],"Paraguaio menos importante do time?");
    InsereNaosei(p[],p[],"Paraguaio menos importante do time?");

    InsereSim(p[],j[],"Rojas");
    InsereNao(p[],p[],"Perito em perder gol?");
    InsereNaosei(p[],p[],"Perito em perder gol?");

    InsereSim(p[],p[],"Titúlo exclusivo de bagre d'or?");
    InsereNao(p[],p[],"É craque da bola");
    InsereNaosei(p[],p[],"É craque da bola");
    //caminho craque
    InsereSim(p[],j[],"Renato Augusto");
    InsereNao(p[],j[],"Ángel Romero");
    InsereNaosei(p[],j[],"Ángel Romero");
    //fim caminho bagre

    //caminho bagre
    InsereSim(p[],j[],"Yuri ALberto");
    InsereNao(p[],p[],"Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[],p[],"Foi pego a paulada pela torcida no motel?");

    InsereSim(p[],j[],"Luan");
    //fim bagre



    // --------Título = Não; Defensivo = Sim ------------
    InsereSim(p[],j[],"Moscardo");
    InsereNao(p[],p[],"Substituto do Cássio?");
    InsereNaosei(p[],p[],"Substituto do Cássio?");

    InsereSim(p[],j[],"Carlos Miguel");
    InsereNao(p[],p[],"Argentino?");
    InsereNaosei(p[],p[],"Argentino?");

    InsereSim(p[],j[],"Fausto Vera");
    InsereNao(p[],p[],"Substituto do Balbuena?");
    InsereNaosei(p[],p[],"Substituto do Balbuena?");

    InsereSim(p[],j[],"Veríssimo");


    //Defensivo = não sei
    InsereSim(p[],j[],"Moscardo");
    InsereNao(p[],p[],"Substituto do Cássio?");
    InsereNaosei(p[],p[],"Substituto do Cássio?");

    InsereSim(p[],j[],"Carlos Miguel");
    InsereNao(p[],p[],"Argentino?");
    InsereNaosei(p[],p[],"Argentino?");

    InsereSim(p[],j[],"Fausto Vera");
    InsereNao(p[],p[],"Substituto do Balbuena?");
    InsereNaosei(p[],p[],"Substituto do Balbuena?");

    InsereSim(p[],j[],"Veríssimo");
    InsereNao(p[],p[],"É calvo??");
    InsereNaosei(p[],p[],"É calvo??");

    InsereSim(p[],p[],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[],p[],"Jogou no time estreante da série B (Santos)?");
    InsereNaosei(p[],p[],"Jogou no time estreante da série B (Santos)?");
    //Caminho Loira
    InsereSim(p[],j[],"Rogér Guedes");
    //FIm Loira

    //Caminho Santos
    InsereSim(p[],j[],"Giuliano");
    InsereNao(p[],p[],"Paraguaio menos importante do time?");
    InsereNaosei(p[],p[],"Paraguaio menos importante do time?");

    InsereSim(p[],j[],"Rojas");
    InsereNao(p[],p[],"Perito em perder gol?");
    InsereNaosei(p[],p[],"Perito em perder gol?");

    InsereSim(p[],p[],"Titúlo exclusivo de bagre d'or?");

    InsereSim(p[],j[],"Yuri ALberto");
    InsereNao(p[],p[],"Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[],p[],"Foi pego a paulada pela torcida no motel?");

    InsereSim(p[],j[],"Luan");
    //Fim Santos

    //Caminho Não defensivo
    InsereSim(p[],p[],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[],p[],"Paraguaio menos importante do time?");
    InsereNaosei(p[],p[],"Paraguaio menos importante do time?");
    //Caminho Loira
    InsereSim(p[],j[],"Rogér Guedes");
    //FIm Loira

    //Caminho Paraguai
    InsereSim(p[],j[],"Rojas");
    InsereNao(p[],p[],"Perito em perder gol?");
    InsereNaosei(p[],p[],"Perito em perder gol?");

    InsereSim(p[],p[],"Titúlo exclusivo de bagre d'or?");
    InsereNao(p[],p[],"Não tem nenhuma característica relevante?");
    InsereNaosei(p[],p[],"Não tem nenhuma característica relevante?");

    //caminho bagre
    InsereSim(p[],j[],"Yuri ALberto");
    InsereNao(p[],p[],"Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[],p[],"Foi pego a paulada pela torcida no motel?");

    InsereSim(p[],j[],"Luan");
    //fim caminho bagre

    //caminho relevância
    InsereSim(p[],j[],"Giuliano");
    InsereNao(p[],j[],"Giuliano");
    InsereNaosei(p[],j[],"Giuliano");
    //fim caminho relevÇancia
    //fim caminho paraguai



    PrintArv(p[0]);
}