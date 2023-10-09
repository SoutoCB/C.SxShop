//Criar a biblioteca para as funções de cliente
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "utilits.h"


char codigoc[10];
char cpfc[12]; 
char nomec[50];
char data_nascimentoc[11]; // "dd/mm/aaaa"
char telefonec[12];


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
        scanf(" %c",&op);getchar();
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
    printf("|      Codigo   =                                                               |\n"); //Pensar sobre esse codigo
    le_codigo(codigoc);
    printf("|      CPF      =                                                               |\n");
    le_cpf(cpfc);
    printf("|      Nome     =                                                               |\n");
    le_nome(nomec);
    printf("|      Data nascimento =                                                        |\n");
    le_data_nascimento(data_nascimentoc);
    printf("|      Telefone =                                                               |\n");
    le_telefone(telefonec);
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
    printf("|      Codigo   = %s                                                            \n", codigoc); //Pensar sobre esse codigo
    printf("|      CPF      = %s                                                            \n", cpfc);
    printf("|      Nome     = %s                                                            \n", nomec);
    printf("|      Data nascimento = %s                                                     \n", data_nascimentoc);
    printf("|      Telefone = %s                                                            \n", telefonec); 
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
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
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
    printf("|      Codigo   =                                                               |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");
    //Posso colocar um passo de confirmação se realmente quer deletar 
    //Um frase tipo
    // prinf(" Você realmente desejar deletar (nome) do cpf (cpf)?")
}
