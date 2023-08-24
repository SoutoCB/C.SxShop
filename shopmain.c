/*
UFRN - Universidade Federal do Rio Grande do Norte
CERES - Centro de Ensino Superior do Seridó
BSI - Bacharelado em Sistemas de Informação
Developed by @SoutoCB - since august,2023
DCT1106 - Programação - Flavius Gorgônio
----------------------------------------
Referencias;
-Slides e Github de Flavius Gorgônio, @FlaviusGorgonio
-ChatGPT, um modelo de linguagem da OpenAI, https://chat.openai.com/
-Outras referencias, serão referenciadas no próprio codigo
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




//Assinaturas das funções
char tela_menu_principal();
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
    ///Função para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    setlocale(LC_ALL,"Portuguese_Brazil");
    char op1; op1 = tela_menu_principal();
    if (op1 == '1'){
        tela_menu_cliente();     
    }else if (op1 =='2') {
        tela_menu_funcionarios();
    }else if (op1 =='3') {
        tela_menu_gestao_produtos();
    }else if (op1 =='4') {
        tela_menu_vendas_pedidos();
    }else if (op1 =='5') {
        tela_menu_relatorios();
    }else if (op1 =='6') {
        tela_sobre();
    }else if (op1 =='0') {
        printf("Obrigaod por utilizar no sistema.\n");
        printf("Saindo.\n\n");
    }else{
        printf("Opção invalida.\n\n");
    }
    tela_equipe();
    printf("Pressione uma tecla para continuar...\n");
    getchar(); // Aguarda a entrada de uma tecla

    return 0;
}



//Funções do sistema
char tela_menu_principal() {
    char op;
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
    printf("|            Escolha a opção desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;

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
    printf("|            Escolha a opção desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_funcionarios(void) {
    printf("Menu Funcionários\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Funcionários = = = = =                              |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Funcionário                                           |\n");
    printf("|            2. Listar Funcionários                                             |\n");
    printf("|            3. Editar Funcionário                                              |\n");
    printf("|            4. Excluir Funcionário                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opção desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_gestao_produtos(void) {
    printf("Menu Gestão de Produtos\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Gestão de Produtos = = = = =                        |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Produto                                               |\n");
    printf("|            2. Listar Produtos                                                 |\n");
    printf("|            3. Editar Produto                                                  |\n");
    printf("|            4. Excluir Produto                                                 |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opção desejada:                                          |\n"); 
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
    printf("|            Escolha a opção desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}

void tela_menu_relatorios(void) {
    printf("Menu Relatórios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatórios = = = = =                                |\n");
    printf("|                                                                               |\n");
    printf("|            1. Relatório de Clientes                                           |\n");
    printf("|            2. Relatório de Funcionários                                       |\n");
    printf("|            3. Relatório de Produtos                                           |\n");
    printf("|            4. Relatório de Vendas                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opção desejada:                                          |\n"); 
    printf("|===============================================================================|\n\n");
}


void tela_sobre(void) {
    printf("Menu sobre\n");
    printf("|==================================================================================|\n");
    printf("|                                                                                  |\n");
    printf("|           = = = = = Sistema de Gestão para Estabelecimento Sensual = = = = =     |\n");
    printf("|                                                                                  |\n");
    printf("| Este projeto tem como propósito a conclusão do curso DCT1106 - Programação,      |\n");
    printf("| ministrado pelo Professor Flavius Gorgônio (@FlaviusGorgonio). O projeto         |\n");
    printf("| consiste em um sistema de gestão para um estabelecimento voltado ao público      |\n");
    printf("| adulto, visando a incorporação integral dos requisitos essenciais para avaliação.|\n");
    printf("| Desenvolvido por @SoutoCB, estudante do Bacharelado em Sistemas de Informação    |\n");
    printf("| na UFRN CERES. A base utilizada para o desenvolvimento do projeto pode ser       |\n");
    printf("| encontrada em:                                                                   |\n");
    printf("| https://github.com/FlaviusGorgonio/LinguaSolta.git                               |\n");
    printf("|==================================================================================|\n\n");


}

void tela_equipe(void) {
    printf("Equipe Responsável\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|          = = = = = Sistema de Gestão para Estabelecimento Sensual = = = = =   |\n");
    printf("|                                                                               |\n");
    printf("| Este projeto foi desenvolvido pela seguinte equipe:                           |\n");
    printf("|                                                                               |\n");
    printf("| ** Bruno Costa Souto **                                                       |\n");
    printf("|                                                                               |\n");
    printf("| GitHub: [@SoutoCB](https://github.com/SoutoCB)                                |\n");
    printf("| Repositório: [C.SxShop](https://github.com/SoutoCB/C.SxShop.git)              |\n");
    printf("|                                                                               |\n");
    printf("|===============================================================================|\n\n");

}

