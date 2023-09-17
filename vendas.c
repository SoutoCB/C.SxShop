#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"



void tela_menu_vendas_pedidos() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("Menu Vendas e Pedidos\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Vendas e Pedidos = = = = =                          |\n");
        printf("|                                                                               |\n");
        printf("|            1. Realizar Venda                                                  |\n");
        printf("|            2. Listar Pedidos                                                  |\n");
        printf("|            3. Editar Pedido                                                   |\n");
        printf("|            4. Cancelar Pedido                                                 |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op);
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                make_venda();
                break;
            case '2':
                exibir_pedido();
                break;
            case '3':
                edit_pedido();
                break;
            case '4':
                cancel_pedido();
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

void make_venda(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Realizar Venda\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas e Pedidos = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Realizar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Numero do pedido -                                                       |\n"); //Pensar sobre esse codigo
    printf("|      Codigo do cliente -                                                      |\n");
    printf("|      Valor total     -                                                        |\n");
    printf("|      Descricao       -                                                        |\n");
    // Possivel adicao de novos dados para coletar
    printf("|===============================================================================|\n\n");
}
 
                      //VER QUESTAO DA FUNCAO PEDIDO DEPOIS

void exibir_pedido(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Listar Pedidos\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas e Pedidos = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Lista de Pedidos = = =                                             |\n");
    printf("|                                                                               |\n");
    printf("|      Numero do pedido -                                                       |\n"); //Pensar sobre esse codigo
    printf("|      Codigo do cliente -                                                      |\n");
    printf("|      Valor total     -                                                        |\n");
    printf("|      Descricao       -                                                        |\n");
    // Possivel adicao de novos dados para coletar
    // funcao para mostrar os pedido um por um
    printf("|===============================================================================|\n\n");
}

void edit_pedido(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Editar Pedido\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas e Pedidos = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar Pedidos = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Numero do pedido -                                                       |\n"); //Pensar sobre esse codigo
          //funcao de coleta de dado
          //possiveis alteracoes
    printf("|===============================================================================|\n\n");
}

void cancel_pedido(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Cancelar Pedido\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas e Pedidos = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cancelar Pedido = = =                                              |\n");
    printf("|                                                                               |\n");
    printf("|      Numero do pedido -                                                       |\n"); //Pensar sobre esse codigo
          //funcao de coleta de dado
          //possiveis alteracoes
    printf("|===============================================================================|\n\n");
}


///////////////////////////////////////////////////////////////////////////////////////////////////