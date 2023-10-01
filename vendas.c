#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

int numero_venda;
int codigo_cliente;
int codigo_funcionario;
float valor_total;
char descricao[100];

void tela_menu_vendas() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Vendas = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Vendas = = = = =                                    |\n");
        printf("|                                                                               |\n");
        printf("|            1. Realizar Venda                                                  |\n");
        printf("|            2. Listar Vendas                                                   |\n");
        printf("|            3. Editar Venda                                                    |\n");
        printf("|            4. Cancelar Venda                                                  |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op);
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                make_vendas();
                break;
            case '2':
                exibir_vendas();
                break;
            case '3':
                edit_vendas();
                break;
            case '4':
                cancel_vendas();
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

void make_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Realizar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Realizar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Numero da venda   =                                                      |\n"); //Pensar sobre esse codigo
    scanf("%d", &numero_venda);
    printf("|      Codigo do cliente =                                                      |\n");
    scanf("%d", &codigo_cliente);
    printf("|      Codigo do funcionario =                                                  |\n");
    scanf("%d", &codigo_cliente);
    printf("|      Valor total     =                                                        |\n");
    scanf("%f", &valor_total);
    printf("|      Descricao       =                                                        |\n");
    scanf("%s", descricao);
    // Possivel adicao de novos dados para coletar
    //Possivel adicao de uma coleta de codigo de protudo para diminuir sua quantidade no estoque
    // Salva a quantida de compras feitas pelo cliente
    // Salva a quantida de compras feitas pelo funcionario
    printf("|===============================================================================|\n\n");
}
 
                      //VER QUESTAO DA FUNCAO PEDIDO DEPOIS

void exibir_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Listar Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Lista de Vendas = = =                                              |\n");
    printf("|                                                                               |\n");
    printf("|      Numero da Venda   = %d                                                   |\n", numero_venda); //Pensar sobre esse codigo
    printf("|      Codigo do cliente = %d                                                   |\n", codigo_cliente);
    printf("|      Codigo do funcionario = %d                                               |\n", codigo_funcionario);
    printf("|      Valor total     = %.2f                                                   |\n", valor_total);
    printf("|      Descricao       = %s                                                     |\n", descricao);
    // Possivel adicao de novos dados para coletar
    // funcao para mostrar os pedido um por um
    printf("|===============================================================================|\n\n");
}

void edit_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Editar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar Venda = = =                                                 |\n");
    printf("|                                                                               |\n");
    printf("|      Numero da Venda =                                                        |\n"); //Pensar sobre esse codigo
          //funcao de coleta de dado
          //possiveis alteracoes
    printf("|===============================================================================|\n\n");
}

void cancel_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Cancelar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cancelar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Numero da Venda =                                                        |\n"); //Pensar sobre esse codigo
          //funcao de coleta de dado
          //possiveis alteracoes
    printf("|===============================================================================|\n\n");
}


///////////////////////////////////////////////////////////////////////////////////////////////////