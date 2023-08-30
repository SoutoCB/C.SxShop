/*
UFRN - Universidade Federal do Rio Grande do Norte
CERES - Centro de Ensino Superior do Serid�
BSI - Bacharelado em Sistemas de Informa��o
Developed by @SoutoCB - since august,2023
DCT1106 - Programa��o - Flavius Gorg�nio
----------------------------------------
Referencias;
-Slides e Github de Flavius Gorg�nio, @FlaviusGorgonio
-ChatGPT, um modelo de linguagem da OpenAI, https://chat.openai.com/
-Outras referencias, ser�o referenciadas no pr�prio codigo
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




//Assinaturas das fun��es
char tela_menu_principal();
char tela_menu_cliente();
char tela_menu_funcionarios();
char tela_menu_gestao_produtos();
char tela_menu_vendas_pedidos();
char tela_menu_relatorios();
void tela_sobre(void);
void tela_equipe(void);



//Parte principal do programa

int main()
{
    /* code */
    ///Fun��o para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    setlocale(LC_ALL,"Portuguese_Brazil");
    char op1; op1 = tela_menu_principal();
    
    if (op1 == '1') {
        char op2; op2 = tela_menu_cliente();
        if (op2 =='1'){
            printf("Cadastro Cliente.\n");
        }else if (op2 =='2') {
            printf("Listar Clientes.\n");
        }else if (op2 =='3') {
            printf("Editar Clientes.\n");
        }else if (op2 =='4') {
            printf("Excluir Clientes.\n");
        }else if (op2 =='0') {
            printf("Saindo.\n");
        }else {
            printf("Op��o invalida.\n");
        }        
    }
    else if (op1 =='2') {
        char op2; op2 = tela_menu_funcionarios();
        if (op2 =='1'){
            printf("Cadastro Funcion�rio.\n");
        }else if (op2 =='2') {
            printf("Listar Funcion�rio.\n");
        }else if (op2 =='3') {
            printf("Editar Funcion�rio.\n");
        }else if (op2 =='4') {
            printf("Excluir Funcion�rio.\n");
        }else if (op2 =='0') {
            printf("Saindo.\n");
        }else {
            printf("Op��o invalida.\n");
        }
    }
    else if (op1 =='3') {
        char op2; op2 = tela_menu_gestao_produtos();
        if (op2 =='1'){
            printf("Cadastro Produto.\n");
        }else if (op2 =='2') {
            printf("Listar Produto.\n");
        }else if (op2 =='3') {
            printf("Editar Produto.\n");
        }else if (op2 =='4') {
            printf("Excluir Produto.\n");
        }else if (op2 =='0') {
            printf("Saindo.\n");
        }else {
            printf("Op��o invalida.\n");
        }
    }
    else if (op1 =='4') {
        char op2; op2 = tela_menu_vendas_pedidos();
        if (op2 =='1'){
            printf("Realizar Venda\n");
        }else if (op2 =='2') {
            printf("Listar Pedidos\n");
        }else if (op2 =='3') {
            printf("Editar Pedido\n");
        }else if (op2 =='4') {
            printf("Cancelar Pedido\n");
        }else if (op2 =='0') {
            printf("Saindo.\n");
        }else {
            printf("Op��o invalida.\n");
        }
    }
    else if (op1 =='5') {
        char op2; op2 = tela_menu_relatorios();
        if (op2 =='1'){
            printf("Relat�rios de Clientes\n");
        }else if (op2 =='2') {
            printf("Relat�rios de Funcion�rios\n");
        }else if (op2 =='3') {
            printf("Relat�rio de Produtos\n");
        }else if (op2 =='4') {
            printf("Relat�rio de Vendas\n");
        }else if (op2 =='0') {
            printf("Saindo.\n");
        }else {
            printf("Op��o invalida.\n");
        }
    }
    else if (op1 =='6') {
        tela_sobre();
        tela_equipe();
    }
    else if (op1 =='0') {
        printf("Obrigado por utilizar no sistema.\n");
        printf("Saindo.\n\n");
    }
    else{
        printf("Op��o invalida.\n\n");
    }
    printf("Pressione uma tecla para continuar....\n");
    getchar(); // Aguarda a entrada de uma tecla
    getchar(); // Aguarda a entrada de uma tecla

    return 0;
}



//Fun��es do sistema
char tela_menu_principal() {
    char op;
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
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
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;

}

char tela_menu_cliente() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
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
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_funcionarios() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
    printf("Menu Funcion�rios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Funcion�rios = = = = =                              |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Funcion�rio                                           |\n");
    printf("|            2. Listar Funcion�rio                                              |\n");
    printf("|            3. Editar Funcion�rio                                              |\n");
    printf("|            4. Excluir Funcion�rio                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_gestao_produtos() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
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
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_vendas_pedidos() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op; 
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
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_relatorios() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
    printf("Menu Relat�rios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relat�rios = = = = =                                |\n");
    printf("|                                                                               |\n");
    printf("|            1. Relat�rios de Clientes                                          |\n");
    printf("|            2. Relat�rios de Funcion�rios                                      |\n");
    printf("|            3. Relat�rio de Produtos                                           |\n");
    printf("|            4. Relat�rio de Vendas                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a op��o desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}


void tela_sobre(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Menu sobre\n");
    printf("|==================================================================================|\n");
    printf("|                                                                                  |\n");
    printf("|           = = = = = Sistema de Gest�o para Estabelecimento Sensual = = = = =     |\n");
    printf("|                                                                                  |\n");
    printf("| Este projeto tem como prop�sito a conclus�o do curso DCT1106 - Programa��o,      |\n");
    printf("| ministrado pelo Professor Flavius Gorg�nio (@FlaviusGorgonio). O projeto         |\n");
    printf("| consiste em um sistema de gest�o para um estabelecimento voltado ao p�blico      |\n");
    printf("| adulto, visando a incorpora��o integral dos requisitos essenciais para avalia��o |\n");
    printf("| Desenvolvido por @SoutoCB, estudante do Bacharelado em Sistemas de Informa��o    |\n");
    printf("| na UFRN CERES. A base utilizada para o desenvolvimento do projeto pode ser       |\n");
    printf("| encontrada em:                                                                   |\n");
    printf("| https://github.com/FlaviusGorgonio/LinguaSolta.git                               |\n");
    printf("|==================================================================================|\n\n");


}

void tela_equipe(void) {
    printf("Equipe Respons�vel\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|          = = = = = Sistema de Gest�o para Estabelecimento Sensual = = = = =   |\n");
    printf("|                                                                               |\n");
    printf("| Este projeto foi desenvolvido pela seguinte equipe:                           |\n");
    printf("|                                                                               |\n");
    printf("| ** Bruno Costa Souto **                                                       |\n");
    printf("|                                                                               |\n");
    printf("| GitHub: [@SoutoCB](https://github.com/SoutoCB)                                |\n");
    printf("| Reposit�rio: [C.SxShop](https://github.com/SoutoCB/C.SxShop.git)              |\n");
    printf("|                                                                               |\n");
    printf("|===============================================================================|\n\n");

}

