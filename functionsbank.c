#include <stdlib.h>
#include <stdio.h>
    int mostrarMenu()
{
    printf("| 1. Sacar...................| \n");
    printf("\n| 2. Depositar...............|\n");
    printf("\n| 3. Efetuar pix.............|\n");
    printf("\n| 4. Cadastrar novo cliente..|\n");
    printf("\n| 5. Transferencia...........|\n");
    printf("\n| 6. Consultar saldo.........|\n");
    printf("\n| 7. Selecionar cliente......|\n");
    printf("\n| 8. Sair....................|\n");
}
int mostrarNome(cliente){
    return cliente;
}

int main(void)
{
    // Clientes
    typedef struct
    {
        int codigo;
        char nome[50];
        int agencia;
        char contaCorrente[50];
        float saldoAtual;
    } clientesBanco;
    clientesBanco cliente[10];
    int numeroDeClientes;
    // Cadastrar clientes
    printf("Quantos clientes vai cadastrar? ");
    scanf("%d", & numeroDeClientes);
    system("cls");
    for (int i = 0; i < numeroDeClientes; i++)
    {
        printf("|     Cadastrando o cliente %d     |\n", i + 1);
        printf("\nCodigo: (obs: numero do cliente)");
        scanf("%d", & cliente[i].codigo);
        scanf("%c");
        printf("Nome: ");
        fgets(cliente[i].nome, 50, stdin);
        printf("Agencia: ");
        scanf("%d", & cliente[i].agencia);
        scanf("%c");
        printf("Conta corrente: ");
        fgets(cliente[i].contaCorrente, 50, stdin);
        printf("Saldo atual: ");
        scanf("%f", & cliente[i].saldoAtual);
        system("cls");
    }
    // mostrar clientes e selecionar um
    for (int i = 0; i < numeroDeClientes; i++)
    {
        printf("----------------------------------\n");
        printf(" ~Codigo: %d ~Nome: %s\n", cliente[i].codigo, cliente[i].nome);
        printf(" ~Agencia: %d ~Conta: %s\n", cliente[i].agencia, cliente[i].contaCorrente);
        printf("  ~~~~ Saldo: %.2f ~~~~\n", cliente[i].saldoAtual);
        printf("----------------------------------\n");
    }
    int clienteAtual;
    printf("\nInforme o cliente que deseja fazer uma operacao: (obs: codigo do cliente)");
    scanf("%d", & clienteAtual);
    clienteAtual = clienteAtual - 1;
    system("cls");

    // Menu
    float saque, depositar, pix, transferencia;
    int conta = cliente[clienteAtual].nome;
    int showName = mostrarNome(conta);
    printf("\n -> Cliente: %s \n",showName);
    printf(mostrarMenu());
    int alternativa, caseAlternativa, contaCredora, novoCliente;
    char pessoa[100];
    // Alternativas
    do {
        printf("\n|  Escolha uma alternativa:  |\n");
        scanf("%d", & alternativa);
        system("cls");
        switch (alternativa) {
            case 1: // sacar
                if (numeroDeClientes == 0) {
                    printf("\nVoce nao possui clientes cadastrados ");
                    printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                } else {
                    do {
                        printf("\nQuanto deseja sacar? ");
                        scanf("%f", & saque);
                        if (cliente[clienteAtual].saldoAtual < saque) {
                            printf("\nVoce nao possui saldo suficiente para fazer esse saque");
                            printf("\nSaldo atual: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\nPressione enter para continuar....");
                            scanf("%c");
                            scanf("%c");
                            system("cls");
                            printf("\n| 1. Sacar................|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        }
                        else {
                            cliente[clienteAtual].saldoAtual = cliente[clienteAtual].saldoAtual - saque;
                            printf("\nVoce efetuou o saque de R$ %.2f da conta do(a) %s", saque, cliente[clienteAtual].nome);
                            printf("\nSaldo atual da conta: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\n| 1. Sacar...............|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        }
                    } while (caseAlternativa != 2);
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                }
            break;
            case 2: // depositar
                if (numeroDeClientes == 0) {
                    printf("\nVoce nao possui clientes cadastrados ");
                    printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                } else {
                    do {
                        printf("\nQuanto deseja depositar? ");
                        scanf("%f", & depositar);
                        printf("\nVoce efetuou o deposito de R$ %.2f para conta do(a): %s", depositar, cliente[clienteAtual].nome);
                        cliente[clienteAtual].saldoAtual = cliente[clienteAtual].saldoAtual + depositar;
                        printf("\nSaldo atual: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                        printf("\n| 1. Depositar............|\n");
                        printf("\n| 2. Voltar...............|\n");
                        printf("\n| Escolha uma alternativa |\n");
                        scanf("%d", & caseAlternativa);
                        system("cls");
                    } while (caseAlternativa != 2);
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
            break;
            case 3: // efetuar pix
                if (numeroDeClientes == 0) {
                    printf("\nVoce nao possui clientes cadastrados ");
                    printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                } else {
                    do {
                        printf("\nDigite o numero de telefone, cpf ou chave aleatoria da pessoa: ");
                        scanf("%s", & pessoa);
                        printf("\nQuanto deseja transferir para %s ? ", pessoa);
                        scanf("%f", & pix);
                        if (cliente[clienteAtual].saldoAtual < pix) {
                            printf("\nVoce nao possui saldo suficiente para realizar o pix");
                            printf("\nSaldo atual: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\nPressione enter para continuar....");
                            scanf("%c");
                            scanf("%c");
                            system("cls");
                            printf("\n| 1. Efetuar pix................|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        } else {
                            cliente[clienteAtual].saldoAtual = cliente[clienteAtual].saldoAtual - pix;
                            printf("\nVoce efetuou um pix de R$ %.2f da conta do(a) %s", pix, cliente[clienteAtual].nome);
                            printf("\nSaldo atual da conta: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\n| 1. Efetuar pix..............|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        }
                    } while (caseAlternativa != 2);
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                }
                }
            break;
            case 4: // cadastrar novo cliente
                do {
                    printf("\n|     Cadastrando o cliente %d     |\n", numeroDeClientes + 1);
                    printf("\nCodigo: (obs: numero do cliente)");
                    scanf("%d", & cliente[numeroDeClientes].codigo);
                    scanf("%c");
                    printf("Nome: ");
                    fgets(cliente[numeroDeClientes].nome, 50, stdin);
                    printf("Agencia: ");
                    scanf("%d", & cliente[numeroDeClientes].agencia);
                    scanf("%c");
                    printf("Conta corrente: ");
                    fgets(cliente[numeroDeClientes].contaCorrente, 50, stdin);
                    printf("Saldo atual: ");
                    scanf("%f", & cliente[numeroDeClientes].saldoAtual);
                    numeroDeClientes = numeroDeClientes + 1;
                    system("cls");
                    printf("\n| 1. Cadastrar outro............|");
                    printf("\n| 2. Voltar...............|");
                    printf("\n| Escolha uma alternativa |\n");
                    scanf("%d", & caseAlternativa);
                    system("cls");
                } while (caseAlternativa != 2);
                alternativa = 0;
                conta = cliente[clienteAtual].nome;
                showName = mostrarNome(conta);
                printf("\n -> Cliente: %s \n",showName);
                printf(mostrarMenu());
            break;
            case 5: // transferencia
                    if (numeroDeClientes == 0) {
                    printf("\nVoce nao possui clientes cadastrados ");
                    printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                } else {
                    do {
                        for (int i = 0; i < numeroDeClientes; i++)
                        {
                            printf("----------------------------------\n");
                            printf(" ~Codigo: %d ~Nome: %s\n", cliente[i].codigo, cliente[i].nome);
                            printf(" ~Agencia: %d ~Conta: %s\n", cliente[i].agencia, cliente[i].contaCorrente);
                            printf("  ~~~~ Saldo: %.2f ~~~~\n", cliente[i].saldoAtual);
                            printf("----------------------------------\n");
                        }
                        printf("\nInforme para quem deseja transferir (Obs: digite o codigo da conta) ");
                        scanf("%d",& contaCredora);
                        system("cls");
                        contaCredora = contaCredora - 1;
                        printf("Quanto deseja transferir para a conta do(a) %s:", cliente[contaCredora].nome);
                        scanf("%f",& transferencia);
                        if (cliente[clienteAtual].saldoAtual < transferencia) {
                            printf("\nVoce nao possui saldo suficiente para realizar a transferencia");
                            printf("\nSaldo atual: R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\nPressione enter para continuar....");
                            scanf("%c");
                            scanf("%c");
                            system("cls");
                            printf("\n| 1. Transferir..............|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        } else {
                            cliente[clienteAtual].saldoAtual = cliente[clienteAtual].saldoAtual - transferencia;
                            cliente[contaCredora].saldoAtual = cliente[contaCredora].saldoAtual + transferencia;
                            printf("\nVoce efetuou uma transferencia de R$ %.2f para a conta do(a) %s", transferencia, cliente[contaCredora].nome);
                            printf("\nSaldo atual da conta R$ %.2f\n", cliente[clienteAtual].saldoAtual);
                            printf("\nPressione enter para continuar.....");
                            scanf("%c");
                            scanf("%c");
                            system("cls");
                            printf("\n| 1. Transferir............|");
                            printf("\n| 2. Voltar...............|");
                            printf("\n| Escolha uma alternativa |\n");
                            scanf("%d", & caseAlternativa);
                            system("cls");
                        }
                } while (caseAlternativa != 2);
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                }
            break;
            case 6: // Consultar saldo
                if (numeroDeClientes == 0) {
                printf("\nVoce nao possui clientes cadastrados ");
                printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                scanf("%c");
                scanf("%c");
                system("cls");
                alternativa = 0;
                conta = cliente[clienteAtual].nome;
                showName = mostrarNome(conta);
                printf("\n -> Cliente: %s \n",showName);
                printf(mostrarMenu());
                } else {
                    if(numeroDeClientes == 0){
                        printf("Voce nao possui contas para verificar o saldo\n");
                        printf("Pressione enter para voltar ao menu inicial e cadastre uma conta.......");
                        scanf("%c");
                        scanf("%c");
                        system("cls");
                        alternativa = 0;
                        conta = cliente[clienteAtual].nome;
                        showName = mostrarNome(conta);
                        printf("\n -> Cliente: %s \n",showName);
                        printf(mostrarMenu());
                    } else {
                        printf("\n| CONSULTANDO SALDO |\n");
                        printf("\nNome: %s", cliente[clienteAtual].nome);
                        printf("Agencia: %d\n", cliente[clienteAtual].agencia);
                        printf("Conta corrente: %s", cliente[clienteAtual].contaCorrente);
                        printf("SALDO: %.2f \n", cliente[clienteAtual].saldoAtual);
                        printf("\nPressione enter para voltar ao inicio....");
                        scanf("%c");
                        scanf("%c");
                        system("cls");
                        alternativa = 0;
                        conta = cliente[clienteAtual].nome;
                        showName = mostrarNome(conta);
                        printf("\n -> Cliente: %s \n",showName);
                        printf(mostrarMenu());
                    }
                }
            break;
            case 7: // ver clientes e mudar cliente
                if (numeroDeClientes == 0) {
                    printf("\nVoce nao possui clientes cadastrados ");
                    printf("\nPressione enter para voltar ao menu e cadastre um cliente...");
                    scanf("%c");
                    scanf("%c");
                    system("cls");
                    alternativa = 0;
                    conta = cliente[clienteAtual].nome;
                    showName = mostrarNome(conta);
                    printf("\n -> Cliente: %s \n",showName);
                    printf(mostrarMenu());
                } else {
                    do {
                        for (int i = 0; i < numeroDeClientes; i++)
                        {
                            printf("----------------------------------\n");
                            printf(" ~Codigo: %d ~Nome: %s\n", cliente[i].codigo, cliente[i].nome);
                            printf(" ~Agencia: %d ~Conta: %s\n", cliente[i].agencia, cliente[i].contaCorrente);
                            printf("  ~~~~ Saldo: %.2f ~~~~\n", cliente[i].saldoAtual);
                            printf("----------------------------------\n");
                        }
                        printf("\nInforme o cliente que deseja fazer uma operacao: (obs: codigo do cliente)");
                        scanf("%d", & clienteAtual);
                        clienteAtual = clienteAtual - 1;
                        system("cls");
                        printf("\n| 1. Ver e mudar novamente............|\n");
                        printf("\n| 2. Voltar pro inicio...............|\n");
                        printf("\n| Escolha uma alternativa |\n");
                        scanf("%d", & caseAlternativa);
                    } while (caseAlternativa != 2);
                        system("cls");
                        alternativa = 0;
                        conta = cliente[clienteAtual].nome;
                        showName = mostrarNome(conta);
                        printf("\n -> Cliente: %s \n",showName);
                        printf(mostrarMenu());
                }
            break;
            case 8: // sair
                printf("\nObrigado por usar!\nby: devMRNGN\n");
                break;
        }
    } while (alternativa < 1 || alternativa > 8);

    return 0;
}
