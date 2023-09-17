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





//Assinaturas das funcoes principais
char tela_menu_principal();



void tela_menu_vendas_pedidos();
    void make_venda(void);
    void exibir_pedido(void);
    void edit_pedido(void);
    void cancel_pedido(void);

void tela_menu_relatorios();
    void relat_clientes(void);
    void relat_funcionarios(void);
    void relat_produtos(void);
    void relat_vendas(void);

void tela_sobre(void);

void tela_equipe(void);




//Parte principal do programa

int main() {
    ///Funcao para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    setlocale(LC_ALL,"Portuguese_Brazil");
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
                tela_menu_vendas_pedidos();          
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
    printf("Menu Principal\n");
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
    printf("|            4. Menu Vendas e pedidos                                           |\n");
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

void tela_menu_relatorios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("Menu Relatorios\n");
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


void tela_sobre(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Menu sobre\n");
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
    printf("Equipe Responsavel\n");
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



