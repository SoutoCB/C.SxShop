/*
UFRN - Universidade Federal do Rio Grande do Norte
CERES - Centro de Ensino Superior do Seridó
BSI - Bacharelado em Sistemas de Informação
Developed by @SoutoCB - since august,2023
DCT1106 - Programação - Flavius Gorgônio
----------------------------------------
Referencias;
-Slides e Github de Flavius Gorgônio, @FlaviusGorgonio
-Chat GPT, https://chat.openai.com/
-Outras referencias, serão referenciadas no próprio codigo
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




//Assinaturas das funções
void tela_menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);


//Parte principal do programa

int main()
{
    /* code */
    ///Função para permitir caracteres especiais
    setlocale(LC_ALL,"Portuguese_Brazil");
    tela_menu_principal();
    tela_sobre();
    tela_equipe();

    return 0;
}



//Funções do sistema
void tela_menu_principal(void) {
    printf("Menu Principal\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gestão do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|            1. Menu Cliente                                                    |\n");
    printf("|            2. Menu Funcionarios                                               |\n");
    printf("|            3. Menu Gestão de Produtos                                         |\n");
    printf("|            4. Menu Vendas e pedidos                                           |\n");
    printf("|            5. Menu Relatórios                                                 |\n");
    printf("|            6. Sobre                                                           |\n");
    printf("|            0. Sair                                                            |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opção desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");

}

void tela_sobre(void) {
    printf("Menu Sobre\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gestão do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|Esse projeto tem como objetivo a conclusão de DCT1106 - Programação, ministrada|\n");
    printf("|por Flavius Gorgônio, @FlaviusGorgonio. Se trata de um sistema de gestão para  |\n");
    printf("|um SexShop, que visa conter todos os requisitos necessários para ser avaliado. |\n");
    printf("|Desenvolvido por @SoutoCB, discente em Bacharelado em Sistemas de informação - |\n");
    printf("|UFRN CERES. Base utilizada para desenvolver o projeto está localizada em:      |\n"); 
    printf("|https://github.com/FlaviusGorgonio/LinguaSolta.git                             |\n");
    printf("|===============================================================================|\n\n");



}

void tela_equipe(void) {
    printf("Menu equipe\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gestão do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|Esse projeto foi desenvolvido por;                                             |\n");
    printf("|Discente: Bruno Costa Souto                                                    |\n");
    printf("|GitHub: @SoutoCB                                                               |\n");
    printf("|Endereço: https://github.com/SoutoCB/C.SxShop.git                              |\n");
    printf("|===============================================================================|\n\n");

}

