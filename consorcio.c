#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "consorcio.h"
#include "interface.h"

FILE *fpDadosCliente;

void AbrirArquivoCliente()
{
    fpDadosCliente = fopen("Cliente.txt", "rb+");
    if(fpDadosCliente == NULL)
    {
        fpDadosCliente = fopen("Cliente.txt", "wb+");
        if(fpDadosCliente == NULL)
        {
            printf("Nao Abriu Cliente.txt\n");
            exit(1);
        }
    }
}

void FecharArquivoCliente()
{
    fclose(fpDadosCliente);
}

void SalvarNovoCliente(Dados D)
{
    fseek(fpDadosCliente,0,SEEK_END);
    fwrite(&D, sizeof(Dados),1,fpDadosCliente);
    fflush(fpDadosCliente);
}

int Contagem(){
    FILE *F;
    int x = 1000;
    F = fopen("Cliente.txt", "rb+");
    if(F == NULL){
        Borda(31, 21, 7, 2, 0, 0);
        gotoxy(16, 22); printf("ID DE PESQUISA:");
        gotoxy(33, 22); printf("%.5d", x);
        return x;
    }
    else{
        fclose(F);
        AbrirArquivoCliente();
        Dados P;
        while(fread(&P,sizeof(Dados),1,fpDadosCliente)){
            x++;
        }
        FecharArquivoCliente();
    }
    Borda(31, 21, 7, 2, 0, 0);
    gotoxy(16, 22); printf("ID DE PESQUISA:");
    gotoxy(33, 22); printf("%.5d", x);
    return x;
}

Dados PesquisarUsuario()
{
    AbrirArquivoCliente();
    char ID[20];

    Dados P;

    gotoxy(27,7);
    scanf(" %[^\n]", &ID);

    fseek(fpDadosCliente,0,SEEK_SET);
    while(fread(&P,sizeof(Dados),1,fpDadosCliente))
    {
        if(strcmp(P.ID,ID) == 0)
        {
            FecharArquivoCliente();
            //gotoxy(3, 32); printf("ACHEIII;");
            //gotoxy(3, 33); printf("%s", P.Nome);
            return P;
        }
    }
    strcpy(P.ID, "");
    //gotoxy(3, 32); printf("Não Achei!");
    FecharArquivoCliente();
    return P;
}

void printarDados(Dados X){
    gotoxy(27, 7); printf("%s", X.ID);
    gotoxy(27,10); printf("%s", X.Nome);
    gotoxy(27, 13); printf("%s", X.Telefone);
    gotoxy(27, 16); printf("%s", X.CPF);
    gotoxy(27, 19); printf("%s", X.CEP);
    return;
}

Dados DigitarDados(int n){
    Dados D;

    gotoxy(27, 7);
    scanf(" %[^\n]", D.Nome);

    if(n == 1){
        gotoxy(27, 10);
        scanf(" %[^\n]", D.Telefone);

        gotoxy(27, 13);
        scanf(" %[^\n]", D.CPF);

        gotoxy(27, 16);
        scanf(" %[^\n]", D.Endereco);

        gotoxy(27, 19);
        scanf(" %[^\n]", D.CEP);
    }

    return D;
}

void Caixa(){
    Borda(26, 9, 30, 2, 0, 0);
    Borda(26, 12, 30, 2, 0, 0);
    Borda(26, 15, 30, 2, 0, 0);
    Borda(26, 18, 30, 2, 0, 0);
    return 0;
}

void Interface(int n){
    if (n == 0) Borda(14, 5, 52, 18, 1, 1);
    else if (n == 1) Borda(2, 1, 114, 27, 1, 0);
    return 0;
}

void SimularConsorcio(int n){
//    Borda(14, 3, 52, 18, 1, 1);
    if(n == 0){Borda(14, 5, 52, 19, 1, 1); gotoxy(16, 7); printf("     NOME: "); Borda(26, 6, 30, 2, 0, 0);}
    else if(n == 1 || n == 3){Interface(0); gotoxy(16, 7); printf("     ID: "); Borda(26, 6, 30, 2, 0, 0);}

    if(n == 0){
        gotoxy(16, 10); printf(" TELEFONE: ");
        gotoxy(16, 13); printf("     CPF: ");
        gotoxy(16, 16); printf("ENDERECO: ");
        gotoxy(16, 19); printf("     CEP: ");
        Caixa();
    }

    else if(n == 3){
        gotoxy(16, 10); printf("     NOME: ");
        gotoxy(16, 13); printf(" TELEFONE: ");
        gotoxy(16, 16); printf("     CPF: ");
        gotoxy(16, 19); printf("     CEP: ");
        Caixa();
    }
}

void AlterarDados(Dados P, int d){
    AbrirArquivoCliente();

    //Dados X, K;
    Dados K;
    int n = atoi(P.ID);

    //gotoxy(2, 32); printf("%d", n);
    //fseek(fpDadosCliente,0,SEEK_SET);
    //system("cl//");

    fseek(fpDadosCliente, n%1000 * sizeof(Dados), SEEK_SET);
    SimularConsorcio(0);
    K = DigitarDados(1);
    if(d == 0) strcpy(K.ID, P.ID);
    fwrite(&K, sizeof(Dados), 1, fpDadosCliente);

    /*while(fread(&P,sizeof(Dados),1,fpDadosCliente))
    {
        if(strcmp(X.ID,P.ID) == 0)
        {
            fseek(fpDadosCliente, -1,SEEK_SET);
            SimularConsorcio(0);
            K = DigitarDados(1);
            fwrite(K,sizeof(Dados), 1, fpDadosCliente);
        }
    }*/

    FecharArquivoCliente();
    return P;
}

int novamentbusca;

void BuscarCliente(){
    char botaofinal[][51] = {"Fechar" };
    char opcoes[][51] = {"Nova Busca", "Alterar dados", "Novo Consorcio","Fechar" }, nesco[][51] = {"Tentar Novamente", "Fechar"};
    int x[] = {16, 28, 44, 60}, y[] = {23, 23, 23, 23};
    int X[] = {18, 57}, Y[] = {23, 23};

    Dados D;

    int esscolha = 0, opt = 0;
    do{
        desbugar();
        novamentbusca = 0;
        SimularConsorcio(1);
        D = PesquisarUsuario();

        if(strcmp(D.ID, "") == 0){
            gotoxy(30,14); printf("Usuario nao Encontrado");
            Borda(17, 22, 16, 2, 0, 0); Borda(56, 22, 6, 2, 0, 0);
            esscolha = menu(nesco, X, Y, esscolha, 2);
            if(esscolha == 0){
                novamentbusca = 1;
            }
            else{
                return 0;
            }
        }

        else{
            SimularConsorcio(3);
            Borda(15,22,10,2,0,0);
            Borda(27,22,14,2,0,0);
            Borda(43,22, 14,2,0,0);
            Borda(59,22, 6,2,0,0);

            printarDados(D);

            do{
                textcolor(BLACK); textbackground(RED);
                esscolha = menu(opcoes, x, y, esscolha, 4);

                if(esscolha == 0){
                    novamentbusca = 1;
                    break;
                }

                else if(esscolha == 1){
                    AlterarDados(D, 0);
                    int j[] = {60}, k[] = {23};
                    Borda(59,22,6,2,0,0);
                    opt = menu(botaofinal, j, k, opt, 1);
                    return 0;
                }

                else if(esscolha == 2){

                }

                else if(esscolha == 3){return 0;}
                //
            }while(esscolha != -1);
        }
    }while(novamentbusca == 1);
    return 0;
}

void AtivarCliente()
{
    desbugar();
    SimularConsorcio(0);
    int Escolha = 0;
    int X[]= {45, 56,};
    int Y[]= {24, 24};

    struct dadosconsorcio D;
    char OpcoesConfirma[][51]= {"Confirmar","Cancelar"};

    do
    {
        D = DigitarDados(1);
        Borda(44,23,9,2,0,0);
        Borda(55,23,8,2,0,0);

        int k = Contagem();
        sprintf(D.ID, "%d", k);

        Borda(31, 21, 7, 2, 0, 0);
        gotoxy(16, 22); printf("ID DE PESQUISA:");
        gotoxy(33, 22); printf("%.5d", k);

        Escolha = menu(OpcoesConfirma, X, Y, Escolha, 2);

        if(Escolha==0)
        {
            //DEVERÁ SALVAR OS DADOS
            AbrirArquivoCliente();
            SalvarNovoCliente(D);
            FecharArquivoCliente();

            break;
        }
        if(Escolha==1)
        {
            break;
        }
    }
    while(Escolha!=3);


}

void listagem(){
    char botaofinal[][51] = {"Fechar" };
    int x[] = {110};//pra que que serve?
    int y[] = {1};

    int escolha = 0;

    //struct dadosconsorcio D;
    //while
    //{
    //D = DigitarDados(0);
    Borda(109,0,6,2,0,0);
    //Borda(31,22,14,2,0,0);
    //Borda(47,22, 6,2,0,0);
    do{
        escolha = menu(botaofinal, x, y, escolha, 1);

        if(escolha == 0){
            break;
        }

    }while(escolha != -1);
    return 0;
}
