#include <stdlib.h>
#include <stdio.h>
int mostrarMenu(){
    printf("\n| 1. Sacar...................| \n");
    printf("\n| 2. Depositar...............|\n");
    printf("\n| 3. Efetuar pix.............|\n");
    printf("\n| 4. Cadastrar novo cliente..|\n");
    printf("\n| 5. Transferencia...........|\n");
    printf("\n| 6. Consultar saldo.........|\n");
    printf("\n| 7. Selecionar cliente......|\n");
    printf("\n| 8. Sair....................|\n");
}

int main(void){
        //Clientes
typedef struct{
    int codigo;
    char nome[50];
    int agencia;
    char contaCorrente[50];
    float saldoAtual;
} clientesBanco; clientesBanco cliente[5];
int numeroDeClientes;
        //Cadastrar clientes
    printf("\nQuantos clientes vai cadastrar? ");
    scanf("%d",&numeroDeClientes);
    system("cls");
    for(int i = 0; i < numeroDeClientes; i++){
        printf("\n|     Cadastrando o cliente %d     |\n",i+1);
        printf("\nCodigo: (obs: numero do cliente)");
        scanf("%d",&cliente[i].codigo);
        scanf("%c");
        printf("Nome: ");
        fgets(cliente[i].nome, 50, stdin);
        printf("Agencia: ");
        scanf("%d",&cliente[i].agencia);
        scanf("%c");
        printf("Conta corrente: ");
        fgets(cliente[i].contaCorrente, 50, stdin);
        printf("Saldo atual: ");
        scanf("%f",&cliente[i].saldoAtual);
        system("cls");
    }
        // mostrar clientes e selecionar um
    for(int i = 0; i < numeroDeClientes; i++){
    printf("----------------------------------\n");
    printf(" ~Codigo: %d ~Nome: %s\n",cliente[i].codigo, cliente[i].nome);
    printf(" ~Agencia: %d ~Conta: %s\n",cliente[i].agencia, cliente[i].contaCorrente);
    printf("  ~~~~ Saldo: %.2f ~~~~\n",cliente[i].saldoAtual);
    printf("----------------------------------\n");
    }
    int clienteAtual;
    printf("\nInforme o cliente que deseja fazer uma operacao: (obs: codigo do cliente)");
    scanf("%d",&clienteAtual);
    clienteAtual = clienteAtual - 1;
    system("cls");

        // Menu
float saque, depositar, pix;
printf(mostrarMenu());
int alternativa, caseAlternativa;
char pessoa[100];
       //Alternativas
do{
    printf("\n|  Escolha uma alternativa:  |\n");
    scanf("%d",&alternativa);
    system("cls");
    switch(alternativa){
        case 1: // sacar
            do{
                printf("\nQuanto deseja sacar? ");
                scanf("%f",&saque);
                if(cliente[clienteAtual].saldoAtual < saque){
                    printf("\nVoce nao possui saldo suficiente para fazer esse saque");
                    printf("\nSaldo atual: R$ %.2f\n",cliente[clienteAtual].saldoAtual);
                    printf("\nPressione enter para continuar....");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    printf("\n| 1. Sacar................|");
                    printf("\n| 2. Voltar...............|");
                    printf("\n| Escolha uma alternativa |\n");
                    scanf("%d",&caseAlternativa);
                    system("cls");
                } else {
                    cliente[clienteAtual].saldoAtual = cliente[clienteAtual].saldoAtual - saque;
                    printf("\nVoce efetuou o saque de R$ %.2f da conta do(a) %s",saque,cliente[clienteAtual].nome);
                    printf("\nSaldo atual da conta: R$ %.2f\n",cliente[clienteAtual].saldoAtual);
                    printf("\n| 1. Sacar...............|");
                    printf("\n| 2. Voltar...............|");
                    printf("\n| Escolha uma alternativa |\n");
                    scanf("%d",&caseAlternativa);
                    system("cls");
                }

            } while(caseAlternativa != 2);
                alternativa = 0;
                printf(mostrarMenu());
        break;
        case 2: // depositar
            do{
                printf("\nQuanto deseja depositar? ");
                scanf("%f",&depositar);
                printf("\nVoce efetuou o deposito de R$ %.2f",depositar);
                printf("\n| 1. Depositar............|\n");
                printf("\n| 2. Voltar...............|\n");
                printf("\n| Escolha uma alternativa |\n");
                scanf("%d",&caseAlternativa);
            } while(caseAlternativa != 2);
                alternativa = 0;
        break;
        case 3: // efetuar pix
            do{
                printf("\nDigite o numero de telefone, cpf ou chave aleatoria da pessoa: ");
                scanf("%s",&pessoa);
                printf("\nQuanto deseja transferir para %s ? ",pessoa);
                scanf("%f",&pix);
                printf("\nVoce efetuou um pix de %.2f para %s \n",pix, pessoa);
                printf("\n| 1. Continuar............|\n");
                printf("\n| 2. Voltar...............|\n");
                printf("\n| Escolha uma alternativa |\n");
                scanf("%d",&caseAlternativa);
            } while(caseAlternativa != 2);
                alternativa = 0;
        break;
        case 4: // cadastrar novo cliente
            printf("\nAlternativa 4");
        break;
        case 5: // transferencia
            printf("\nAlternativa 5");
        break;
        case 6: // Consultar saldo
                printf("\n| CONSULTANDO SALDO |\n");
                printf("\nNome: %s",cliente[clienteAtual].nome);
                printf("Agencia: %d\n",cliente[clienteAtual].agencia);
                printf("Conta corrente: %s",cliente[clienteAtual].contaCorrente);
                printf("SALDO: %.2f \n",cliente[clienteAtual].saldoAtual);
                printf("\nPressione enter para voltar ao inicio....");
                scanf("%c");
                scanf("%c");
                system("cls");
                alternativa = 0;
                printf(mostrarMenu());
        break;
        case 7: // ver clientes e mudar cliente
           do{
            for(int i = 0; i < numeroDeClientes; i++){
                printf("----------------------------------\n");
                printf(" ~Codigo: %d ~Nome: %s\n",cliente[i].codigo, cliente[i].nome);
                printf(" ~Agencia: %d ~Conta: %s\n",cliente[i].agencia, cliente[i].contaCorrente);
                printf("  ~~~~ Saldo: %.2f ~~~~\n",cliente[i].saldoAtual);
                printf("----------------------------------\n");
            }
            printf("\nInforme o cliente que deseja fazer uma operacao: (obs: codigo do cliente)");
            scanf("%d",&clienteAtual);
            clienteAtual = clienteAtual - 1;
            system("cls");
            printf("\n| 1. Ver e mudar novamente............|\n");
            printf("\n| 2. Voltar pro inicio...............|\n");
            printf("\n| Escolha uma alternativa |\n");
            scanf("%d",&caseAlternativa);
        } while(caseAlternativa != 2);
            system("cls");
            alternativa = 0;
            printf(mostrarMenu());
        break;
        case 8: // sair
            printf("\nObrigado por usar!\nby: devMRNGN\n");
        break;
    }
} while(alternativa < 1 || alternativa > 8);










return 0;
}
