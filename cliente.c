//Criar a biblioteca para as funções de cliente
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"





void tela_menu_cliente() {
    char op;
    do {
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Cliente = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
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
        switch (op) {
            case '1':
                cadast_cliente();
                break;
            case '2':                        
                exibir_cliente();
                break;
            case '3':
                edit_cliente();
                break;
            case '4':
                delet_cliente();
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

void cadast_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Cadastrar cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo   -                                                               |\n"); //Pensar sobre esse codigo
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Idade    -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      E-mail   -                                                               |\n");
    printf("|      Endereco -                                                               |\n");
    printf("|      Envio de promocoes/novos produtos - (Nao aceita / Aceita)                |\n"); 
    printf("|===============================================================================|\n\n");
    //Colocar estrutura de coleta de dados
}

void exibir_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Exibir cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cliente = = =                                                      |\n");
    printf("|      Codigo   -                                                               |\n"); //Pensar sobre esse codigo
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Idade    -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      E-mail   -                                                               |\n");
    printf("|      Endereco -                                                               |\n");
    printf("|      Envio de promocoes/novos produtos - (Nao aceita / Aceita)                |\n"); 
    printf("|===============================================================================|\n\n");
    // Buscar forma para exibir cliente por cliente

}

void edit_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Editar cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do cliente:                                               |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   -                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}

void delet_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Excluir cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|      Insira o codigo do cliente:                                              |\n");
    //Adcionar coleta de dado
    printf("|      Codigo   -                                                               |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}