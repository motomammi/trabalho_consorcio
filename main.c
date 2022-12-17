#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "consorcio.h"

void TelaPrincipal(){
    Borda(0, 0, 118, 29, 1, 0);
    gotoxy(51, 3);printf("CONSORCIO YALEN");
}

int main()
{
    char opcoes[][51] = {"Cadastrar", "Pesquisar", "Fazer Consorcio","Listar Consorcios", "Encerrar Programa" };
    int escolha = 0, mn;
    int X[]= {53, 53, 50, 49, 49};
    int Y[]= {9, 12, 15, 18, 21};

    while(1){
        system("cls");

        TelaPrincipal();

        Borda(52,8,9,2,0,0);
        Borda(52,11,9,2,0,0);
        Borda(49,14,15,2,0,0);
        Borda(48,17,17,2,0,0);
        Borda(48,20,17,2,0,0);

        escolha = menu(opcoes, X, Y, escolha, 5);

        if (escolha == 0){
            AtivarCliente();
            textbackground(BLACK);
        }

        else if(escolha == 1){
            BuscarCliente();
            textbackground(BLACK);
        }

        else if(escolha == 2){
            Interface(1);
            //BuscarCliente();
            listagem();
        }

        else if (escolha == 4){
            gotoxy(0,25);
            exit(1);
        }
    }

    gotoxy(0, 25);
    return 0;
}
