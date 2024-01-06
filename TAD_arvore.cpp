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
    
    // ---- quarto nível -----
    // sub: Título-Sim
    InsereSim(p[4],p[13], "Jogou muitos anos com a camisa do Corinthians");
    InsereNao(p[4],p[14],"É bonito e lindo?");
    InsereNaosei(p[4],p[15],"É bonito e lindo?");
    //p[14] = Balbuena;
    InsereNao(p[4],p[16],"É lindo e Ídolo");
    InsereNaosei(p[4],p[17],"É lindo e Ídolo");
    InsereSim(p[4],p[18],"É craque de bola?");
    InsereNao(p[4],p[19],"Ganhou Mundial de 2012");
    InsereNaosei(p[4],p[20],"Ganhou Mundial de 2012");
    // sub: Título-NãoSei
    //[21] = Balbuena]
    InsereNao(p[4],p[22],"É bonito e Ídolo?");
    InsereNao(p[4],p[23],"É bonito e Ídolo?");
    InsereSim(p[4],p[24],"Loira mais amada do clube?");
    InsereNao(p[4],p[25],"É lindo e Ídolo?");
    InsereNaosei(p[4],p[26],"É lindo e Ídolo?");
    InsereSim(p[4],p[27],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[4],p[28],"Jogou no time estreante da série B(Santos)");
    InsereNaosei(p[4],p[29],"Jogou no time estreante da série B(Santos)");
    // sub: Título-Não
    //p[30] = Moscardo
    InsereNao(p[4],p[31],"Substituo do Cássio?");
    InsereNaosei(p[4],p[32],"Substituo do Cássio?");
    //p[33] = Moscardo
    InsereNao(p[4],p[34],"Substituo do Cássio?");
    InsereNaosei(p[4],p[35],"Substituo do Cássio?");
    InsereSim(p[4],p[36],"Era a loira mais amada e se vendeu pra Arábia?");
    InsereNao(p[4],p[37],"Paraguai menos importante do time?");
    InsereNaosei(p[4],p[38],"Paraguai menos importante do time?");

    // --- quinto nível ----
    // sub: Título-Sim
    //Sim p[39] == Gil Zagueiro
    //Nãosei p[40] == Balbuena
    //Não p[41] == Balbuena
    //SIm p[42] == Cássio
    InsereNao(p[5],p[43],"Aposentou o Hazard");
    InsereNaosei(p[5],p[43],"Aposentou o Hazard");
    //Sim p[44] == Cássio
    InsereNao(p[5],p[45],"Quebra Perna dos adversários");
    InsereNaosei(p[5],p[45],"Quebra Perna dos adversários");
    //Sim p[46] = Renato Augusto
    InsereNao(p[5],p[47],"Entre ele e seu irmão, ele é o bagre");
    InsereNaosei(p[5],p[48],"Entre ele e seu irmão, ele é o bagre");
    //Sim p[49] == Paulinho
    InsereNao(p[5],p[50],"Não fede nem cheira");
    InsereNaosei(p[5],p[50],"Não fede nem cheira");
    // sub: Título-Naosei
    // Sim p[51] == Cássio
    InsereNao(p[5],p[52],"Quebra perna dos adversários");
    InsereNaosei(p[5],p[53],"Quebra perna dos adversários");
    //Sim p[54] == Róger Guedes
    InsereNao(p[5],p[55],"Gil Zagueiro?");
    InsereNaosei(p[5],p[56],"Gil Zagueiro?");
    //Sim p[57] == Cássio
    InsereNao(p[5],p[58],"Quebra a perna dos adversários?");
    InsereNaosei(p[5],p[59],"Quebra a perna dos adversários?");
    //Sim p[60] == Róger Guedes
    //Sim p[61] == Giuliano
    InsereNao(p[5],p[62],"Paraguaio menos importante do time?");
    InsereNaosei(p[5],p[63],"Paraguaio menos importante do time?");
    // sub: Título-Não
    // Sim p[64] == Carlos Miguel
    InsereNao(p[5],p[65],"Argentino?");
    InsereNaosei(p[5],p[66],"Argentino?");
    // Sim p[67] == Carlos Miguel
    InsereNao(p[5],p[68],"Argentino?");
    InsereNaosei(p[5],p[69],"Argentino?");
    //Sim p[70] == Róger Guedes
    //Sim p[71] == Rojas
    InsereNao(p[5],p[72],"Perito em perder gols?");
    InsereNaosei(p[5],p[73],"Perito em perder gols?");

    // ----Sexto Nível-----
    // sub: Título Sim
    //Sim p[74] == Fagner
    InsereNao(p[6],p[75],"É careca?");
    InsereNaosei(p[6],p[76],"É careca?");
    //Sim p[77] == Fagner
    InsereNao(p[6],p[78],"É careca?");
    InsereNaosei(p[6],p[79],"É careca?");
    //Sim p[80] == Angel Romero
    //Sim p[81] == Maycon
    // sub: TítuloNãoSei
    //Sim p[82] == Fagner
    InsereNao(p[6],p[83],"É careca?");
    InsereNaosei(p[6],p[84],"É careca?");
    //Sim p[85] == Gil Zagueiro
    InsereNao(p[6],p[86],"Nasceu no Paraguai?");
    InsereNaosei(p[6],p[87],"Nasceu no Paraguai?");
    //Sim p[88] == Fagner
    InsereNao(p[6],p[89],"É careca?");
    InsereNaosei(p[6],p[90],"É careca?");
    //Sim p[91] == Rojas
    InsereNao(p[6],p[91],"Perito em perder gol?");
    InsereNaosei(p[6],p[92],"Perito em perder gol?");
    // sub: TítuloNão
    //Sim p[93] == Fausto Vera
    InsereNao(p[6],p[94],"Substituto do Balbuena?");
    InsereNaosei(p[6],p[95],"Substituto do Balbuena?");
    //Sim p[96] == Fausto Vera
    InsereNao(p[6],p[97],"Substituto do Balbuena?");
    InsereNaosei(p[6],p[98],"Substituto do Balbuena?");
    InsereSim(p[6],p[99],"Título exclusivo de Bagre d'or?");
    InsereNao(p[6],p[100],"Perito em perder gol?");
    InsereNaosei(p[6],p[101],"Perito em perder gol?");

    // ------Sétimo Nível--------
    // sub: Título Sim
    //Sim p[102] == Fabio Santos
    InsereNao(p[7],p[103],"Gil Zagueiro?");
    InsereNaosei(p[7],p[104],"Gil Zagueiro?");
    //Sim p[105] == Fabio Santos
    InsereNao(p[7],p[106],"Gil Zagueiro?");
    InsereNaosei(p[7],p[107],"Gil Zagueiro?");
    // sub: Título Não Sei
    //Sim p[108] == Fabio Santos
    InsereNao(p[7],p[109],"Gil Zagueiro?");
    InsereNaosei(p[7],p[110],"Gil Zagueiro?");
    //Sim p[111] == Balbuena
    InsereNao(p[7],p[112],"Não tem nenhuma característica relevante?");
    InsereNaosei(p[7],p[113],"Não tem nenhuma característica relevante?");
    //Sim p[114] == Fabio Santos
    InsereNao(p[7],p[115],"Gil Zagueiro?");
    InsereNaosei(p[7],p[116],"Gil Zagueiro?");
    InsereSim(p[7],p[117],"Título exclusivo de Bagre d'or");
    InsereNao(p[7], p[118],"É craque de bola?");
    InsereNaosei(p[7], p[119],"É craque de bola?");
    // sub: Título Não
    //Sim p[120] == Veríssimo
    //Sim p[121] == Veríssimo
    InsereNao(p[7],p[122],"É calvo(Tem duas entradas para Taylor Swift)");
    InsereNaosei(p[7],p[123],"É calvo(Tem duas entradas para Taylor Swift)");
    //Sim p[124] == Yuri Alberto
    InsereNao(p[7],p[124],"Foi pego a paulada pela torcida no motel");
    InsereNaosei(p[7],p[125],"Foi pego a paulada pela torcida no motel");
    //Sim p[126] == Giulano
    //Não p[127] == Giuliano

    // --------Oitavo Nível---------
    // sub: Título Sim
    //Sim p[128] == Gil Zagueiro
    //Não p[129] == Gil Zagueiro
    //Não p[130] == Gil Zagueiro
    InsereNao(p[8],p[131],"Melhores em campos atualmente");
    InsereNaosei(p[8],p[132],"Melhores em campos atualmente");
    // sub: Título Não Sei
    //Sim p[131] == Gil Zagueiro
    InsereNao(p[8],p[132],"Quase foi vendido para o PSG");
    InsereNaosei(p[8],p[133],"Quase foi vendido para o PSG");
    //Sim p[134] == Giuliano
    //Não p[135] == Giuliano
    //Nãosei p[136] == Giuliano
    //Sim p[137] == Gil Zagueiro
    InsereNao(p[8],p[138],"É craque de bola");
    InsereNaosei(p[8],p[139],"É craque de bola");
    //Sim p[140] == Yuri Alberto
    InsereNao(p[8],p[141],"Foi pego na paulada pela torcida no motel?");
    InsereNaosei(p[8],p[142],"Foi pego na paulada pela torcida no motel?");
    //Sim p[143] == Renato Augusto
    //Sim p[144] == Angel Romero
    // sub: Título Não
    InsereSim(p[8],p[145],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[8],p[146],"Jogou no time estreante da série B(Santos)");
    InsereNaosei(p[8],p[147],"Jogou no time estreante da série B(Santos)");
    //SIm p[148] == Luan

    // -------Nono Nível--------
    // sub: Título Sim
    InsereSim(p[9],p[149],"É craque de bola?");
    InsereNao(p[9],p[150],"Ganhou mundial de 2012?");
    InsereNaosei(p[9],p[151],"Ganhou mundial de 2012?");
    // sub: Título Não sei
    //Sim p[152] == Moscardo
    InsereNao(p[9],p[153],"Substituto do Cássio?");
    InsereNaosei(p[9],p[154],"Substituto do Cássio?");
    //Sim p[155] == Renato Augusto
    InsereNao(p[9],p[156],"Ganhou Mundial de 2012?");
    InsereNaosei(p[9],p[157],"Ganhou Mundial de 2012?");
    //Sim p[158] == Luan
    // sub: Título Não
    //Sim p[159] == Róger Guedes
    //Sim p[160] == Giuliano
    InsereNao(p[9],p[161],"Paraguaio menos importante do time?");
    InsereNaosei(p[9],p[162],"Paraguaio menos importante do time?");

    // --------Décimo Nível----------
    // sub: Título Sim
    //Sim p[163] == Renato Augusto
    InsereNao(p[10],p[164],"Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[10],p[165],"Entre ele e seu irmão, ele é o bagre?");
    //Sim p[166] == Paulinho
    InsereNao(p[10],p[167],"Não fede nem cheira?");
    InsereNaosei(p[10],p[168],"Não fede nem cheira?");
    //sub: Título Não sei
    //Sim p[169] == Carlos Miguel
    InsereNao(p[10],p[170],"Argentino??");
    InsereNaosei(p[10],p[171],"Argentino??");
    //Sim p[172] == Paulinho
    InsereNao(p[10],p[173],"Entre ele e seu irmão, ele é o bagre?");
    InsereNaosei(p[10],p[174],"Entre ele e seu irmão, ele é o bagre?");
    // sub: Título Não
    //Sim p[175] == Rojas
    InsereNao(p[10],p[176],"Perito em perder gol?");
    InsereNaosei(p[10],p[177],"Perito em perder gol?");

    // --------Décimo Primeiro Nível-------
    // sub: Título Sim
    //Sim p[178] == Angél Romero
    //Sim p[179] == Maycon
    //sub: Título Não sei
    //Sim p[180] == Fausto vera
    InsereNao(p[11],p[181],"Substituto do Balbuena?");
    InsereNaosei(p[11],p[182],"Substituto do Balbuena?");
    //Sim p[183] == Angél Romero
    InsereNao(p[11],p[184],"Foi vendido para o PSG?");
    InsereNaosei(p[11],p[185],"Foi vendido para o PSG?");
    // sub:Título Não
    InsereSim(p[11],p[186],"Título exclusivo de Bagre d'or?");

    // --------Décimo Segundo Nível---------
    // Não possui no Título Sim
    // sub: Título Não sei
    //Sim p[187] == Veríssimo
    //Sim p[188] == Moscardo
    InsereNao(p[12],p[189],"Substituto do Cássio?");
    InsereNaosei(p[12],p[190],"Substituto do Cássio?");
    // sub: Título Não
    //Sim p[191] == Yuri Alberto
    InsereNao(p[12],p[192],"Foi pego na paulada pela torcida no motel?");

    // ----------Décimo Terceito Nível------
    // sub: Título Não sei
    //Sim p[193] == Carlos Miguel
    InsereNao(p[13],p[193],"Argentino?");
    InsereNaosei(p[13],p[194],"Argentino?");
    // sub: Título Não
    //Sim p[195] == Luan

    //----------Décimo Quarto Nível--------
    // sub: Título Não sei
    //Sim p[196] == Fausto Vera
    InsereNao(p[14],p[197],"Substituto do Balbuena?");
    InsereNao(p[14],p[198],"Substituto do Balbuena?");

    // ------Décimo Quinto Nível--------
    // sub: Título Não sei
    //Sim p[199] == Veríssimo
    InsereNao(p[15],p[200],"É calvo?");
    InsereNaosei(p[15],p[200],"É calvo?");

    // -------Décimo Sexto Nível ----------
    // sub: Título Não sei
    InsereSim(p[16],p[201],"Era a loirinha mais amada e se vendeu pra Arábia?");
    InsereNao(p[16],p[202],"Jogou no time estreante da série B(Santos)?");
    InsereNaosei(p[16],p[203],"Jogou no time estreante da série B(Santos)?");

    // -------Décimo Sétimo Nível ---------
    // sub: Título Não sei
    //Sim p[204] == Róger Guedes
    //Sim p[205] == Giuliano
    InsereNao(p[17],p[206],"Paraguaio menos importante?");
    InsereNaosei(p[17],p[207],"Paraguaio menos importante?");

    // ------Décimo Oitavo Nível --------
    // sub: Título Não sei
    //Sim p[208] == Rojas
    InsereNao(p[18],p[209],"Perito em perder gol?");
    InsereNaosei(p[18],p[210],"Perito em perder gol?");

    // ------Décimo Nono Nível --------
    // sub: Título Não sei
    InsereSim(p[19],p[211],"Título exclusivo de Bagre d'or?");
    //Não p[212] == Róger Guedes
    //Não sei p[213] == Renato Augusto

    // ------Vigésimo --------
    // sub: Título Não sei
    //Sim p[214] == Yuri Alberto
    InsereNao(p[20],p[215],"Foi pego a paulada pela torcida no motel?");
    InsereNaosei(p[20],p[216],"Foi pego a paulada pela torcida no motel?");

    // ------Vigésimo primeiro --------
    // sub: Título Não sei
    //Sim p[217] == Luan

    PrintArv(p[0]);
    
}