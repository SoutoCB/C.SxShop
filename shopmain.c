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




//Assinaturas das funcoes principais
char tela_menu_principal();
char tela_menu_cliente();
char tela_menu_funcionarios();
char tela_menu_gestao_produtos();
char tela_menu_vendas_pedidos();
char tela_menu_relatorios();
void tela_sobre(void);
void tela_equipe(void);

//Funcoes de exibicao
void exibir_cliente(void);
void exibir_funcionario(void);



//Parte principal do programa

int main() {
    ///Funcao para permitir caracteres especiais. Fonte: Canal mPOV ; Video: https://www.youtube.com/watch?v=hB6KFP6luL4&list=WL&index=3
    setlocale(LC_ALL,"Portuguese_Brazil");
    char op1;
    while (op1 != '0') {
        op1 = tela_menu_principal();
        switch (op1) {
            case '1': {
                char op2;
                op2 = tela_menu_cliente();
                switch (op2) {
                    case '1':
                        printf("Cadastro Cliente.\n");
                        break;
                    case '2':
                        printf("Listar Clientes.\n");
                        break;
                    case '3':
                        printf("Editar Clientes.\n");
                        break;
                    case '4':
                        printf("Excluir Clientes.\n");
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
            }
            break;
            case '2': {
                char op2;
                op2 = tela_menu_funcionarios();
                switch (op2) {
                    case '1':
                        printf("Cadastro Funcionario.\n");
                        break;
                    case '2':
                        printf("Listar Funcionario.\n");
                        break;
                    case '3':
                        printf("Editar Funcionario.\n");
                        break;
                    case '4':
                        printf("Excluir Funcionario.\n");
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
            }
            break;
            case '3': {
                char op2;
                op2 = tela_menu_gestao_produtos();
                switch (op2) {
                    case '1':
                        printf("Cadastro Produto.\n");
                        break;
                    case '2':
                        printf("Listar Produto.\n");
                        break;
                    case '3':
                        printf("Editar Produto.\n");
                        break;
                    case '4':
                        printf("Excluir Produto.\n");
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
            }
            break;
            case '4': {
                char op2;
                op2 = tela_menu_vendas_pedidos();
                switch (op2) {
                    case '1':
                        printf("Realizar Venda\n");
                        break;
                    case '2':
                        printf("Listar Pedidos\n");
                        break;
                    case '3':
                        printf("Editar Pedido\n");
                        break;
                    case '4':
                        printf("Cancelar Pedido\n");
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
            }
            break;
            case '5': {
                char op2;
                op2 = tela_menu_relatorios();
                switch (op2) {
                    case '1':
                        printf("Relatorios de Clientes\n");
                        break;
                    case '2':
                        printf("Relatorios de Funcionarios\n");
                        break;
                    case '3':
                        printf("Relatorio de Produtos\n");
                        break;
                    case '4':
                        printf("Relatorio de Vendas\n");
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
            }
            break;
            case '6': {
                tela_sobre();
                tela_equipe();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                getchar(); // Aguarda a entrada de uma tecla
            }
            break;
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
    }
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
    printf("|            Escolha a opcao desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_funcionarios() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
    printf("Menu Funcionarios\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Funcionarios = = = = =                              |\n");
    printf("|                                                                               |\n");
    printf("|            1. Cadastrar Funcionario                                           |\n");
    printf("|            2. Listar Funcionario                                              |\n");
    printf("|            3. Editar Funcionario                                              |\n");
    printf("|            4. Excluir Funcionario                                             |\n");
    printf("|            0. Voltar ao Menu Principal                                        |\n");
    printf("|                                                                               |\n");
    printf("|            Escolha a opcao desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_gestao_produtos() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
    printf("Menu Gestao de Produtos\n");
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
    printf("|            Escolha a opcao desejada: "); 
    scanf(" %c",&op);
    printf("|===============================================================================|\n\n");
    return op;
}

char tela_menu_relatorios() {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    char op;
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
    return op;
}


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

//Funcoes de exibicao 

void exibir_cliente(void) {
    printf("exibir cliente\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Cliente = = = = =                                   |\n");
    printf("|                                                                               |\n");
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Idade    -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      E-mail   -                                                               |\n");
    printf("|      Endereco -                                                               |\n");
    printf("|      Envio de promo��es/novos produtos - (N�o aceita / Aceita)                |\n"); 
    printf("|===============================================================================|\n\n");

}

void exibir_funcionario(void) {
    printf("exibir cliente\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Funcionario = = = = =                               |\n");
    printf("|                                                                               |\n");
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Idade    -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      E-mail   -                                                               |\n");
    printf("|      Endereco -                                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Fun��o -                                                                 |\n");
    printf("|      Carga Horaria -                                                          |\n");
    printf("|      Salario -                                                                |\n");
    printf("|      Data de inicio -                                                         |\n"); 
    printf("|      Carteira assinada -                                                      |\n");
    printf("|      Telefone para emergencia -                                               |\n");
    printf("|===============================================================================|\n\n");

}
