#include <stdio.h>
#include "consorcio.h"


/*FILE *fpDadosCliente;
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
}*/

Dados DigitarDados(){
    Dados D;

    gotoxy(27, 6);
    scanf(" %[^\n]", D.Nome);

    gotoxy(27, 9);
    scanf(" %[^\n]", D.Telefone);

    gotoxy(27, 12);
    scanf(" %[^\n]", D.CPF);

    gotoxy(27, 15);
    scanf(" %[^\n]", D.Endereco);

    gotoxy(27, 18);
    scanf(" %[^\n]", D.CEP);


    /*printf("Digite o Valor: ");
    scanf(" %lf", &M.ValorPago);*/

    return D;
}


void AtivarCliente()
{
    int Escolha = 0;
    char opcoes[][51] = {"Simular consorcio", "Compra de consorcio","Alterar", "Pesquisar","Cadastro", "Fechar" };
    int x[] = {1, 1, 1, 1, 1, 1};//pra que que serve?
    int y[] = {3, 4, 5, 6, 7, 8};
    Dados D;
    char OpcoesConfirma[][51]= {"Confirma","Cancela"};

    do
    {
        DigitarDados();
        Borda(16,18,10,2,0,0);
        Borda(28,18,10,2,0,0);
        Borda(40,18,10,2,0,0);
        Borda(52,18,10,2,0,0);
        Borda(55,18,10,2,0,0);
        Escolha = menu(opcoes, x, y, Escolha, 6);


        if(Escolha==0)
        {
            DigitarDados();
            D = DigitarDados();
            Borda;
            Borda(16,18,10,2,0,0);
            Borda(28,18,10,2,0,0);
            Escolha = menu(OpcoesConfirma,x, y, Escolha, 2);
            //if(Escolha==0)SalvarNovoPaciente(P);
        }
        if(Escolha==1)
        {
            DigitarDados();
           // D =PesquisarPaciente();
            if(strlen(D.CEP)>0)
            {

                system("Pause");
            }

        }
    }
    while(Escolha!=3);


}
void SimularConsorcio(){//precisa dessa função?
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(16, 6); printf("     NOME: ");
    gotoxy(16, 9); printf(" TELEFONE: ");
    gotoxy(16, 12); printf("     CPF: ");
    gotoxy(16, 15); printf("ENDERECO: ");
    gotoxy(16, 18); printf("     CEP: ");
    Borda(26, 5, 30, 2, 0, 0);
    Borda(26, 8, 30, 2, 0, 0);
    Borda(26, 11, 30, 2, 0, 0);
    Borda(26, 14, 30, 2, 0, 0);
    Borda(26, 17, 30, 2, 0, 0);
}
/*void TelaPaciente()
{
    Borda(14,3,60,18,1,1);
    gotoxy(16,6);
    printf(" CPF: ");

    gotoxy(16,9);
    printf(" Nome: ");

    gotoxy(16, 12);
    printf(" Endereco: ");

    gotoxy(16, 15);
    printf(" Telefone: ");


    Borda(26,5,37,2,0,0);
    Borda(26,8,37,2,0,0);
    Borda(26,11,37,2,0,0);
    Borda(26,14,37,2,0,0);
}*/

/*void ImprimirConsulta(Consulta C){//precisa dessa função?
    Borda(14, 3, 52, 18, 1, 1);
    gotoxy(16, 6);
    printf("\tCRM-Medico: %s\n", C.CRMMedico);
    gotoxy(16, 9);
    printf("\tCPF-Paciente: %s\n", C.CPFPaciente);
    gotoxy(16, 12);
    printf("\tData: %s\n", C.DataConsulta);
    gotoxy(16, 15);
    printf("\tHora: %s\n", C.HoraConsulta);
}*/
