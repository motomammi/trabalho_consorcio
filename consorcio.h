#ifndef CONSORCIO_H_INCLUDED
#define CONSORCIO_H_INCLUDED
struct dadosconsorcio{
    char Nome[51];
    int Telefone[51];
    int CPF[20];
    char Endereco[51];
    int CEP[20];
    char ID[20];

};

int novamentbusca;

typedef struct dadosconsorcio Dados;
Dados DigitarDados(int n);
void AtivarCliente();
int Contagem();
Dados PesquisarUsuario();
void TelaPaciente();
void printarDados(Dados X);
void BuscarCliente();
void Interface(int n);
void caixa();
void listagem();
void SimularConsorcio(int n);
void AlterarDados(Dados P, int n);

#endif // CONSORCIO_H_INCLUDED
