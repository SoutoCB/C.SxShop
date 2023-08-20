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
void tela_sobre(void);
void tela_equipe(void);


//Parte principal do programa

int main()
{
    /* code */
    ///Fun��o para permitir caracteres especiais
    setlocale(LC_ALL,"Portuguese_Brazil");
    tela_menu_principal();
    tela_sobre();
    tela_equipe();

    return 0;
}



//Fun��es do sistema
void tela_menu_principal(void) {
    printf("Menu Principal\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Gest�o do SexShop = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Modulo Cliente                                            ///\n");
    printf("///            2. M�dulo Funcionarios                                       ///\n");
    printf("///            3. M�dulo Gest�o de Produtos                                 ///\n");
    printf("///            4. M�dulo Vendas e pedidos                                   ///\n");
    printf("///            5. M�dulo Relat�rios                                         ///\n");
    printf("///            6. Sobre                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a op��o desejada: \n");

}

void tela_sobre(void) {
    printf("Menu Sobre\n");
    printf("                          -Sistema de Gest�o de um SexShop-\n");
    printf("Esse projeto tem como objetivo a conclus�o de DCT1106 - Programa��o, ministrada por Flavius Gorg�nio\n");
    printf("se trata de um sistema de gest�o para um sexshop, que visa conter todos os requisitos necessarios para ser avaliado\n");
    printf("desenvolvido por @SoutoCB, discente em Bacharelado em Sistemas de Informa��o - UFRN CERES.\n"); 
    printf("base utilizada para desenvolver o projeto est� localizada nesse endere�o github: https://github.com/FlaviusGorgonio/LinguaSolta.git\n ");



}

void tela_equipe(void) {
    printf("Menu equipe\n");
    printf("Esse projeto foi desenvolvido por;\n");
    printf("Discente: Bruno Costa Souto\n");
    printf("GitHub: @SoutoCB\n");
    printf("Endere�o: https://github.com/SoutoCB/C.SxShop.git\n ");

}

