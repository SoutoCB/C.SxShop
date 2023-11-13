#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "utilits.h"
#include "cliente.h"
#include "funcionario.h"
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
                printf("Relatorio por...");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                printf("Relatorio por...");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                printf("Relatorio por...");
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
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Relatorios funcionarios = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Funcionarios = = =                                   |\n");
    printf("|                                                                               |\n");
    printf("|      Numero de funcionarios =                                                 |\n"); //Pensar sobre esse codigo
    printf("|      Media de vendas por funcionario =                                        |\n");
    printf("|      Valor total de salarios =                                                |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}

void relat_produtos(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Relatorios Produtos = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Produtos = = =                                       |\n");
    printf("|                                                                               |\n");
    printf("|      Numero de produtos =                                                     |\n"); //Pensar sobre esse codigo
    printf("|      Produto mais vendido =                                                   |\n");
    printf("|      Produto menos vendido =                                                  |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}

void relat_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Relatorios Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Vendas = = =                                         |\n");
    printf("|                                                                               |\n");
    printf("|      Receita total =                                                          |\n"); //Pensar sobre esse codigo
    printf("|      Numero de vendas =                                                       |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}



///////////////////////////////////////////////////////////////////////////////////////////////////