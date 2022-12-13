#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void TelaPrincipal(){
    Borda(0, 0, 79, 23, 1, 0);
    gotoxy(32, 1);printf("CLINICA MEDICA");
}

char opcoes[][51] = {"Simular consorcio", "Compra de consorcio","Nossas politicas", "Fechar" };
int x[] = {1, 1, 1, 1 };//pra que que serve?
int y[] = {3, 4, 5, 6};

int main()
{
    int escolha = 0;
    do{
    TelaPrincipal();
    escolha = menu(opcoes, x, y, escolha, 4);
    if(escolha == 0){

    }
    if(escolha == 1);
    if(escolha == 2);
    if(escolha == 3){
        Borda(28, 10, 21, 2, 0, 0);
        gotoxy(29, 11);
        printf("Obrigado pelo acesso!");
        break;
    }
    }while(escolha != -1);


    gotoxy(0, 25);
    return 0;
}
