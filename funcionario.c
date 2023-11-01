#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "utilits.h"
#include <string.h>

char codigof[10];
char cpff[12];
char nomef[50];
char data_nascimentof[11];
char telefonef[12];
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
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        
        switch (op) {
            case '1':
                cadast_funcionario();
                break;
            case '2':
                lista_funcionario();
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
    } while (op !='0');
}

void cadast_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario)); 
    fp = fopen("funcionarios.dat","ab");
    if (fp == NULL) {
        fp = fopen("funcionarios.dat","wb");
        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(func);
            exit(1);
        }         
    }
    printf("|\033[1;36m = Cadastrar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo   =                                                               |\n"); //Pensar sobre esse codigo
    le_codigo(func->codigof);
    printf("|      CPF      =                                                               |\n");
    le_cpf(func->cpff);
    printf("|      Nome     =                                                               |\n");
    le_nome(func->nomef);
    printf("|      Data nascimento =                                                        |\n");
    le_data_nascimento(func->data_nascimentof);
    printf("|      Telefone =                                                               |\n");
    le_telefone(func->telefonef);
    printf("|      Funcao   =                                                               |\n");
    le_texto(func->funcao, 50);
    printf("|      Salario  =                                                               |\n");
    le_valor(&func->salario);
    printf("|===============================================================================|\n\n");
    func->status = 'a';
    fwrite(func, sizeof(Funcionario), 1, fp);
    fclose(fp);
    free(func);
    //Colocar estrutura de coleta de dados
}

void lista_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    printf("|\033[1;36m = Exibir funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if (func->status != 'x') {
            exibir_funcionario(func);
        }
    }
    free(func);
    fclose(fp);
}


void exibir_funcionario(Funcionario*func) {
    char situacao[20];
    if ((func == NULL) || (func->status == 'x')) {
        printf("\n= = = Funcionario Inexistente = = =\n");
    }else{
        printf("|      = = = Funcionario = = =                                                  |\n");
        printf("|      CPF      = %s                                                            \n", func->cpff);
        printf("|      Codigo   = %s                                                            \n", func->codigof);
        printf("|      Nome     = %s                                                            \n", func->nomef);
        printf("|      Data nascimento = %s                                                     \n", func->data_nascimentof);
        printf("|      Telefone = %s                                                            \n", func->telefonef);
        printf("|      Funcao   = %s                                                            \n", func->funcao);
        printf("|      Salario  = %.2f                                                          \n", func->salario);
        if (func->status == 'a') {
        strcpy(situacao, "Ativo");
        } else {
        strcpy(situacao, "Nao informada");
        }
        printf("|      Situacao do cliente = %s\n", situacao);
        printf("|===============================================================================|\n\n");
    }
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