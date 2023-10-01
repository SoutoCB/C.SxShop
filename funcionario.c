#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int codigo;
char cpf[12];
char nome[50];
char data_nascimento[11];
char telefone[15];
char funcao[50];
float salario;

void tela_menu_funcionarios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Funcionarios = \033[0m|\n");
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
    printf("|\033[1;36m = Cadastrar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo   =                                                               |\n"); //Pensar sobre esse codigo
    scanf("%d", &codigo);
    printf("|      CPF      =                                                               |\n");
    scanf("%s", cpf);
    printf("|      Nome     =                                                               |\n");
    scanf(" %s", nome);
    printf("|      Data nascimento =                                                        |\n");
    scanf("%s", data_nascimento);
    printf("|      Telefone =                                                               |\n");
    scanf("%s", telefone);
    printf("|      Funcao   =                                                               |\n");
    scanf("%s", funcao);
    printf("|      Salario  =                                                               |\n");
    scanf("%f", &salario);
    printf("|===============================================================================|\n\n");
    //Colocar estrutura de coleta de dados
}



void exibir_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Exibir funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Funcionario = = =                                                  |\n");
    printf("|      CPF      = %d                                                            |\n", codigo);
    printf("|      Nome     = %s                                                            |\n", nome);
    printf("|      Data nascimento = %s                                                     |\n", data_nascimento);
    printf("|      Telefone = %s                                                            |\n", telefone);
    printf("|      Funcao   = %s                                                            |\n", funcao);
    printf("|      Salario  = %.2f                                                          |\n", salario);
    printf("|===============================================================================|\n\n");
     // Buscar forma para exibir funcionario por funcionario

}

void edit_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Editar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");

}

void delet_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    printf("|\033[1;36m = Deletar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    printf("|===============================================================================|\n");
    //Posso colocar um passo de confirmação se realmente quer deletar 
    //Um frase tipo
    // prinf(" Você realmente desejar deletar (nome) do cpf (cpf)?")


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////