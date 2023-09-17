#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"


void tela_menu_funcionarios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
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
        
        switch (op) {
            case '1':
                cadast_funcionario();
                break;
            case '2':
                exibir_funcionario();
                break;
            case '3':
                edit_funcionario();
                break;
            case '4':
                delet_funcionario();
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
    } while (op !='0');
}

void cadast_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("Cadastrar funcionario\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
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
    printf("|      Funcao  -                                                                |\n");
    printf("|      Carga Horaria  -                                                         |\n");
    printf("|      Salario -                                                                |\n");
    printf("|      Data de inicio -                                                         |\n"); 
    printf("|      Carteira assinada -                                                      |\n");
    printf("|      Telefone para emergencia -                                               |\n");
    printf("|===============================================================================|\n\n");
    //Colocar estrutura de coleta de dados
}



void exibir_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("exibir cliente\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Funcionario = = =                                                  |\n");
    printf("|      CPF      -                                                               |\n");
    printf("|      Nome     -                                                               |\n");
    printf("|      Idade    -                                                               |\n");
    printf("|      Telefone -                                                               |\n");
    printf("|      E-mail   -                                                               |\n");
    printf("|      Endereco -                                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Funcao  -                                                                |\n");
    printf("|      Carga Horaria  -                                                         |\n");
    printf("|      Salario -                                                                |\n");
    printf("|      Data de inicio -                                                         |\n"); 
    printf("|      Carteira assinada -                                                      |\n");
    printf("|      Telefone para emergencia -                                               |\n");
    printf("|===============================================================================|\n\n");
     // Buscar forma para exibir funcionario por funcionario

}

void edit_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("editar funcionario\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   -                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}

void delet_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("deletar funcionario\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   -                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////