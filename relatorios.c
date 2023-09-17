#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"


void tela_menu_relatorios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("Menu Relatorios\n");
        printf("\033[1;36mSEX\033[0m \033[1;35mSHOP\033[0m\n");
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
        scanf(" %c",&op);
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
        getchar(); // Aguarda a entrada de uma tecla
    }while(op!='0');
}

void relat_clientes(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Relatorios clientes\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Clientes = = =                                       |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo   -                                                               |\n"); //Pensar sobre esse codigo
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}

void relat_funcionarios(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Relatorios funcionarios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Funcionarios = = =                                   |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo   -                                                               |\n"); //Pensar sobre esse codigo
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      Cargo    -                                                               |\n");
    printf("|      Salario  -                                                               |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}

void relat_produtos(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Relatorios Produtos\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Produtos = = =                                       |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo -                                                                 |\n"); //Pensar sobre esse codigo
    printf("|      Nome   -                                                                 |\n");
    printf("|      Preco  -                                                                 |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}

void relat_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Relatorios Vendas\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Relatorios = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Relatorios de Vendas = = =                                         |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo do pedido  -                                                      |\n"); //Pensar sobre esse codigo
    printf("|      Codigo do cliente -                                                      |\n");
    printf("|      Valor total       -                                                      |\n");
    // funcao de mostrar um por um (for dentro de for)
    // dados temporarios de exibicao
    printf("|===============================================================================|\n\n");
    
}



///////////////////////////////////////////////////////////////////////////////////////////////////