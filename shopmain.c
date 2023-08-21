/*
UFRN - Universidade Federal do Rio Grande do Norte
CERES - Centro de Ensino Superior do Serid�
BSI - Bacharelado em Sistemas de Informa��o
Developed by @SoutoCB - since august,2023
DCT1106 - Programa��o - Flavius Gorg�nio
----------------------------------------
Referencias;
-Slides e Github de Flavius Gorg�nio, @FlaviusGorgonio
-Chat GPT, https://chat.openai.com/
-Outras referencias, ser�o referenciadas no pr�prio codigo
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




//Assinaturas das fun��es
void tela_menu_principal(void);
void tela_menu_cliente(void);
void tela_menu_funcionarios(void);
void tela_menu_gestao_produtos(void);
void tela_menu_vendas_pedidos(void);
void tela_menu_relatorios(void);
void tela_sobre(void);
void tela_equipe(void);



//Parte principal do programa

int main()
{
    /* code */
    ///Fun��o para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    setlocale(LC_ALL,"Portuguese_Brazil");
    tela_menu_principal();
    tela_menu_cliente();
    tela_menu_funcionarios();
    tela_menu_gestao_produtos();
    tela_menu_vendas_pedidos();
    tela_menu_relatorios();
    tela_sobre();
    tela_equipe();
    printf("Pressione uma tecla para continuar...\n");
    getchar(); // Aguarda a entrada de uma tecla

    return 0;
}



//Fun��es do sistema
void tela_menu_principal(void) {
    printf("Menu Principal\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gest�o do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|            1. Menu Cliente                                                    |\n");
    printf("|            2. Menu Funcionarios                                               |\n");
    printf("|            3. Menu Gest�o de Produtos                                         |\n");
    printf("|            4. Menu Vendas e pedidos                                           |\n");
    printf("|            5. Menu Relat�rios                                                 |\n");
    printf("|            6. Sobre                                                           |\n");
    printf("|            0. Sair                                                            |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");

}
void tela_menu_cliente(void) {
    printf("Menu Cliente\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Cliente = = = = =                                   |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Cliente                                               |\n");
    printf("|            2. Listar Clientes                                                 |\n");
    printf("|            3. Editar Cliente                                                  |\n");
    printf("|            4. Excluir Cliente                                                 |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_funcionarios(void) {
    printf("Menu Funcion�rios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Funcion�rios = = = = =                              |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Funcion�rio                                           |\n");
    printf("|            2. Listar Funcion�rios                                             |\n");
    printf("|            3. Editar Funcion�rio                                              |\n");
    printf("|            4. Excluir Funcion�rio                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_gestao_produtos(void) {
    printf("Menu Gest�o de Produtos\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Gest�o de Produtos = = = = =                        |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Produto                                               |\n");
    printf("|            2. Listar Produtos                                                 |\n");
    printf("|            3. Editar Produto                                                  |\n");
    printf("|            4. Excluir Produto                                                 |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_vendas_pedidos(void) {
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
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_relatorios(void) {
    printf("Menu Relat�rios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relat�rios = = = = =                                |\n");
    printf("|                                                                               |\n");
    printf("|            1. Relat�rio de Clientes                                           |\n");
    printf("|            2. Relat�rio de Funcion�rios                                       |\n");
    printf("|            3. Relat�rio de Produtos                                           |\n");
    printf("|            4. Relat�rio de Vendas                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}


void tela_sobre(void) {
    printf("Menu Sobre\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gest�o do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|Esse projeto tem como objetivo a conclus�o de DCT1106 - Programa��o, ministrada|\n");
    printf("|por Flavius Gorg�nio, @FlaviusGorgonio. Se trata de um sistema de gest�o para  |\n");
    printf("|um SexShop, que visa conter todos os requisitos necess�rios para ser avaliado. |\n");
    printf("|Desenvolvido por @SoutoCB, discente em Bacharelado em Sistemas de informa��o - |\n");
    printf("|UFRN CERES. Base utilizada para desenvolver o projeto est� localizada em:      |\n"); 
    printf("|https://github.com/FlaviusGorgonio/LinguaSolta.git                             |\n");
    printf("|===============================================================================|\n\n");



}

void tela_equipe(void) {
    printf("Menu equipe\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gest�o do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|Esse projeto foi desenvolvido por;                                             |\n");
    printf("|Discente: Bruno Costa Souto                                                    |\n");
    printf("|GitHub: @SoutoCB                                                               |\n");
    printf("|Endere�o: https://github.com/SoutoCB/C.SxShop.git                              |\n");
    printf("|===============================================================================|\n\n");

}

