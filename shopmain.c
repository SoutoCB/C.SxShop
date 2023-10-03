/*
UFRN - Universidade Federal do Rio Grande do Norte
CERES - Centro de Ensino Superior do Serido
BSI - Bacharelado em Sistemas de Informacao
Developed by @SoutoCB - since august,2023
DCT1106 - Programacao - Flavius Gorgonio
----------------------------------------
Referencias;
-Slides e Github de Flavius Gorgonio, @FlaviusGorgonio
-ChatGPT, um modelo de linguagem da OpenAI, https://chat.openai.com/
-Outras referencias, serao referenciadas no proprio codigo 
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cliente.h"
#include "funcionario.h"
#include "gestao.h"
#include "vendas.h"
#include "relatorios.h"
#include "utilits.h"

//Assinaturas das funcoes principais
char tela_menu_principal();
void tela_sobre(void);
void tela_equipe(void);

//Parte principal do programa

int main() {
    ///Funcao para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    char op1; 
    do {
        op1 = tela_menu_principal();
        switch (op1) {
            case '1': {
                tela_menu_cliente();     
            }break;
            
            case '2': {
                tela_menu_funcionarios();        
            }break;
            
            case '3': {
               tela_menu_gestao_produtos();
            }break;
            
            case '4': {
                tela_menu_vendas();          
            }break;
            
            case '5': {
                tela_menu_relatorios();
            }break;
            
            case '6': {
                tela_sobre();
                tela_equipe();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                getchar(); // Aguarda a entrada de uma tecla
            }break;
            
            case '0':
                printf("Obrigado por utilizar o sistema.\n");
                printf("Saindo.\n\n");
                break;
            
            default:
                printf("Opcao invalida.\n\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while (op1 != '0');
    printf("Pressione uma tecla para continuar..\n");
    getchar(); // Aguarda a entrada de uma tecla
    getchar(); // Aguarda a entrada de uma tecla

    return 0;
}

//Funcoes principais do sistema
char tela_menu_principal() {
    char op;
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Menu Principal = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                 \033[1;36m SSS  EEEEE XX   XX\033[0m    \033[1;35m SSS   HH  HH   OOO   PPPP\033[0m             |\n");
    printf("|                 \033[1;36mS     E       X X \033[0m     \033[1;35mS      HH  HH  O   O  P   P\033[0m            |\n"); //Ajuda do ChatGPT
    printf("|                 \033[1;36m SSS  EEE      X \033[0m      \033[1;35m SSS   HHHHHH  O   O  PPPP\033[0m             |\n");
    printf("|                 \033[1;36m    S E       X X \033[0m     \033[1;35m    S  HH  HH  O   O  P\033[0m                |\n");
    printf("|                 \033[1;36mSSSS  EEEEE XX   XX \033[0m   \033[1;35mSSSS   HH  HH   OOO   P\033[0m                |\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Sistema de Gestao do SexShop = = = = =                   |\n");
    printf("|                                                                               |\n");
    printf("|            1. Menu Cliente                                                    |\n");
    printf("|            2. Menu Funcionarios                                               |\n");
    printf("|            3. Menu Gestao de Produtos                                         |\n");
    printf("|            4. Menu Vendas                                                     |\n");
    printf("|            5. Menu Relatorios                                                 |\n");
    printf("|            6. Sobre                                                           |\n");
    printf("|            0. Sair                                                            |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opcao desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void tela_sobre(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Sobre = \033[0m|\n");
    printf("|==================================================================================|\n");
    printf("|                                                                                  |\n");
    printf("|           = = = = = Sistema de Gestao para Estabelecimento Sensual = = = = =     |\n");
    printf("|                                                                                  |\n");
    printf("| Este projeto tem como proposito a conclusao do curso DCT1106 - Programacao,      |\n");
    printf("| ministrado pelo Professor Flavius Gorgonio (@FlaviusGorgonio). O projeto         |\n");
    printf("| consiste em um sistema de gestao para um estabelecimento voltado ao publico      |\n");
    printf("| adulto, visando a incorporacao integral dos requisitos essenciais para avalia??o |\n");
    printf("| Desenvolvido por @SoutoCB, estudante do Bacharelado em Sistemas de Informacao    |\n");
    printf("| na UFRN CERES. A base utilizada para o desenvolvimento do projeto pode ser       |\n");
    printf("| encontrada em:                                                                   |\n");
    printf("| https://github.com/FlaviusGorgonio/LinguaSolta.git                               |\n");
    printf("|==================================================================================|\n\n");
}

void tela_equipe(void) {
    printf("|\033[1;36m = Equipe responsavel = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|          = = = = = Sistema de Gestao para Estabelecimento Sensual = = = = =   |\n");
    printf("|                                                                               |\n");
    printf("| Este projeto foi desenvolvido pela seguinte equipe:                           |\n");
    printf("|                                                                               |\n");
    printf("| ** Bruno Costa Souto **                                                       |\n");
    printf("|                                                                               |\n");
    printf("| GitHub: [@SoutoCB](https://github.com/SoutoCB)                                |\n");
    printf("| Repositorio: [C.SxShop](https://github.com/SoutoCB/C.SxShop.git)              |\n");
    printf("|                                                                               |\n");
    printf("|===============================================================================|\n\n");
}