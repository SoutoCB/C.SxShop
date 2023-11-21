#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "utilits.h"
#include "cliente.h"
#include "funcionario.h"
#include "gestao.h"
#include "vendas.h"
#include <string.h>

void tela_menu_relatorios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Relatorios = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Relatorios = = = = =                                |\n");
        printf("|                                                                               |\n");
        printf("|            1. Relatorios de Clientes                                          |\n");
        printf("|            2. Relatorios de Funcionarios                                      |\n");
        printf("|            3. Relatorio de Produtos                                           |\n");
        printf("|            4. Relatorio de Vendas                                             |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                relat_clientes();
                break;
            case '2':
                relat_funcionarios();
                break;
            case '3':
                relat_produtos();
                break;
            case '4':
                relat_vendas();
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        printf("Pressione uma tecla para continuar...\n");
        getchar(); // Aguarda a entrada de uma tecla
    }while(op!='0');
}

void relat_clientes(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios clientes = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|                 = = = = = Menu Relatorios de Clientes = = = = =               |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Clientes = = =                                       |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Relatorio por ...                                                     |\n");
        printf("|      3. Relatorio por ...                                                     |\n");
        printf("|      4. Relatorio por ...                                                     |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_clientert();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');
}
    
void lista_clientert(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status != 'x') {
            exibir_clientert(cliente);
        }
    }
    free(cliente);
    fclose(fp);
}


void relat_funcionarios(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios funcionarios = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|              = = = = = Menu Relatorios de Funcionarios = = = = =              |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Funcionarios = = =                                   |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Relatorio por ...                                                     |\n");
        printf("|      3. Relatorio por ...                                                     |\n");
        printf("|      4. Relatorio por ...                                                     |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_funcionariort();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
}

void lista_funcionariort(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    printf("|\033[1;36m = Lista de funcionarios = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Funcionarios = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if (func->status != 'x') {
            exibir_funcionariort(func);
        }
    }
    free(func);
    fclose(fp);
}


void relat_produtos(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios Produtos = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|              = = = = = Menu Relatorios de Produtos = = = = =                  |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Produtos = = =                                       |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Relatorio por ...                                                     |\n");
        printf("|      3. Relatorio por ...                                                     |\n");
        printf("|      4. Relatorio por ...                                                     |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_produtort();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                printf("Relatorio por...\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
    
}

void lista_produtort(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    printf("|\033[1;36m = Lista de Produtos = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Produtos = = = = =                    |\n");
    printf("|                                                                               |\n");            
    printf("|   CODIGO  | QUANTIDADE|              NOME            |      SITUACAO          |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if (gest->status != 'x') {
            exibir_produtort(gest);
        }
    }
    free(gest);
    fclose(fp);
}



void relat_vendas(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios Vendas = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|               = = = = = Menu Relatorios de Vendas = = = = =                   |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Vendas = = =                                         |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Vendas por funcionario                                                |\n");
        printf("|      3. Vendas por cliente                                                    |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_vendart();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                venda_p_funcionario();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                venda_p_cliente();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
}

void lista_vendart(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if (vend->status != 'x') {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}

void venda_p_funcionario(void) {
    int cod;
    printf("Digite o codigo do funcionario: ");
    le_inte(&cod);

    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("| VENDAS DO FUNCIONARIO : %d\n", cod);
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if ((vend->codigo_funcionario == cod)&&(vend->status!='x')) {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}

void venda_p_cliente(void) {
    char cpf[12];
    printf("Digite o CPF do cliente: ");
    le_cpf(cpf);

    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("| VENDAS DO CLIENTE : %s\n", cpf);
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if ((strcmp(vend->cpf_cliente, cpf) == 0)&&(vend->status!='x')) {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}




///////////////////////////////////////////////////////////////////////////////////////////////////