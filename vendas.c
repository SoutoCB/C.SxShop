#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"
#include "utilits.h"
#include <string.h>
#include "cliente.h"
#include "funcionario.h"

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
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                make_vendas();
                break;
            case '2':
                lista_vendas();
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
    }while(op!='0');
}

void make_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas)); 
    fp = fopen("vendas.dat","ab");
    if (fp == NULL) {
        fp = fopen("vendas.dat","wb");
        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(vend);
            exit(1);
        }         
    }
    printf("|\033[1;36m = Realizar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Realizar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Numero da venda   =                                                      |\n"); //Pensar sobre esse codigo
    le_codigo(vend->numero_venda);
    printf("|      CPF do cliente =                                                         |\n");
    le_cpf(vend->cpf_cliente);
    printf("|      Codigo do funcionario =                                                  |\n");
    le_codigo(vend->codigo_funcionario);
    printf("|      Valor total     =                                                        |\n");
    le_valor(&vend->valor_total);
    printf("|      Descricao       =                                                        |\n");
    le_texto(vend->descricao, 1000);
    // Possivel adicao de novos dados para coletar
    //Possivel adicao de uma coleta de codigo de protudo para diminuir sua quantidade no estoque
    // Salva a quantida de compras feitas pelo cliente
    // Salva a quantida de compras feitas pelo funcionario
    printf("|===============================================================================|\n\n");
    fwrite(vend, sizeof(Vendas), 1, fp);
    fclose(fp);
    free(vend);
}
 
                      //VER QUESTAO DA FUNCAO PEDIDO DEPOIS
void lista_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Listar Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
            exibir_vendas(vend);
    }
    free(vend);
    fclose(fp);
}
void exibir_vendas(Vendas*vend) {
    if(vend == NULL) {
        printf("\n= = = Venda Inexistente = = =\n");
    }else{
        printf("|      = = = Venda = = =                                                        |\n");
        printf("|                                                                               |\n");
        printf("|      Numero da Venda   = %s                                                   \n", vend->numero_venda); //Pensar sobre esse codigo
        printf("|      CPF do cliente = %s                                                      \n", vend->cpf_cliente);
        printf("|      Codigo do funcionario = %s                                               \n", vend->codigo_funcionario);
        printf("|      Valor total     = %.2f                                                   \n", vend->valor_total);
        printf("|      Descricao       = %s                                                     \n", vend->descricao);
        printf("|===============================================================================|\n\n");
    }
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