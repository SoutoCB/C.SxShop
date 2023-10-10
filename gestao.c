#include <stdio.h>
#include <stdlib.h>
#include "gestao.h"
#include "utilits.h"

char codigop[10];
char nomep[50];
float valor;
char descricaop[1000];
float quantidade;


void tela_menu_gestao_produtos() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Gestao de Produtos = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Gestao de Produtos = = = = =                        |\n");
        printf("|                                                                               |\n");
        printf("|            1. Cadastrar Produto                                               |\n");
        printf("|            2. Listar Produtos                                                 |\n");
        printf("|            3. Editar Produto                                                  |\n");
        printf("|            4. Excluir Produto                                                 |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        // IDEIA, FAZER UM SISTEMA DE AVISO PARA QUANDO O ESTOQUE DE ALGUM PRODUTO ESTIVER BAIXO
        // função for (para ver todos os itens)
        //    printf("O produto (nome do produto) está com baixo estoque"\n)
        //#Pode colocar a frase em vermelho
        switch (op) {
            case '1':
                cadast_produto();
                break;
            case '2':
                exibir_produto();
                break;
            case '3':
                edit_produto();
                break;
            case '4':
                delet_produto();
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
    }while (op!='0');
}

void cadast_produto(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Cadastrar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo     =                                                             |\n"); //Pensar sobre esse codigo
    le_codigo(codigop);
    printf("|      Nome       =                                                             |\n");
    le_nome(nomep);
    printf("|      Valor      =                                                             |\n");
    le_valor(&valor);
    printf("|      Descricao  =                                                             |\n");
    le_texto(descricaop, 1000);
    printf("|      Quantidade =                                                             |\n");
    le_valor(&quantidade);
    // Pensar sobre o estoque de produto
    printf("|===============================================================================|\n\n");
    //Colocar estrutura de coleta de dados
}

void exibir_produto(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Exibir produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Produto = = =                                                      |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo     =  %s                                                         \n", codigop); 
    printf("|      Nome       =  %s                                                         \n", nomep);
    printf("|      Valor      =  %.2f                                                       \n", valor);
    printf("|      Descricao  =  %s                                                         \n", descricaop);
    printf("|      Quantidade =  %.0f                                                       \n", quantidade);
    // Forma para exibir produto por produto
    printf("|===============================================================================|\n\n");
}

void edit_produto(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Editar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do produto:                                               |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}

void delet_produto(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Deletar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|     Insira o codigo do produto:                                               |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");
    //Posso colocar um passo de confirmação se realmente quer deletar 
    //Um frase tipo
    // prinf(" Você realmente desejar deletar (nome do produto)?")


}

////////////////////////////////////////////////////////////////////////////////////////////////////////
