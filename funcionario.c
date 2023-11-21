#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "utilits.h"
#include <string.h>


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
        printf("|            5. Pesquisar Funcionario                                               |\n");
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
            case '5':
                pesquisa_funcionario();
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
    func->codigof = proximo_codigof();
    printf("|      CPF      =                                                               |\n");
    do{le_cpf(func->cpff);}while(!verifica_cpff(func->cpff));
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
void pesquisa_funcionario(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Funcionario* func;
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Pesquisar = = =                                                    |\n");
    printf("|     Insira o CPF do funcionario:                                               |\n");
    printf("|     CPF   =                                                                |\n"); //Pensar sobre esse codigo
    char cpf[12];
    le_cpf(cpf);
    printf("|===============================================================================|\n");
    func = busca_funcionariocpf(cpf);
    exibir_funcionario(func);
    free(func);
}

int verifica_cpff(char*cpf){
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if ((strcmp(cpf, func->cpff) == 0) && func->status != 'x') {
            printf("CPF ja cadastrado, digite novamente = \n");
            fclose(fp);
            free(func);
            return 0;
        }
    } 
    fclose(fp);
    free(func);
    return 1;
}

Funcionario* busca_funcionario(int* cod){
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    char tem = 'x';
    int codv = *cod;
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if ((codv == func->codigof)) {
            tem = 's';
            fclose(fp);
            return func;
        }
    }
    if (tem != 's') {
            printf("Nenhum funcionario encontrado, com esse codigo.\n");
    }
    fclose(fp);
    return NULL;
}

Funcionario* busca_funcionariocpf(char* cpf){
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    char tem = 'x';
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if ((strcmp(cpf, func->cpff) == 0) && func->status != 'x') {
            tem = 's';
            fclose(fp);
            return func;
        }
    }
    if (tem != 's') {
            printf("Nenhum funcionario encontrado, com esse CPF.\n");
    }
    fclose(fp);
    return NULL;
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
        printf("|        Codigo   = %d                                                            \n", func->codigof);
        printf("| 1.     CPF      = %s                                                            \n", func->cpff);
        printf("| 2.     Nome     = %s                                                            \n", func->nomef);
        printf("| 3.     Data nascimento = %s                                                     \n", func->data_nascimentof);
        printf("| 4.     Telefone = %s                                                            \n", func->telefonef);
        printf("| 5.     Funcao   = %s                                                            \n", func->funcao);
        printf("| 6.     Salario  = %.2f                                                          \n", func->salario);
        if (func->status == 'a') {
        strcpy(situacao, "Ativo");
        } else {
        strcpy(situacao, "Nao informada");
        }
        printf("|        Situacao do funcionario = %s\n", situacao);
        printf("|===============================================================================|\n\n");
    }
     // Buscar forma para exibir funcionario por funcionario
}

void exibir_funcionariort(Funcionario*func) {
    char situacao[20];
    if (func == NULL) {
        printf("\n= = = Funcionario Inexistente = = =\n");
    }else{
        if (func->status == 'a') {
        strcpy(situacao, "Ativo");
        } else {
        strcpy(situacao, "Nao informada");
        }
        printf("| %-10d| %-10s| %-29s| %-22s|\n", func->codigof, func->cpff, func->nomef, situacao);
        printf("|===============================================================================|\n");
    }    
}

void edit_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Funcionario* func;
    printf("|\033[1;36m = Editar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    //Adcionar coleta de dado
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    func = busca_funcionario(&cod);
    exibir_funcionario(func);
    if (func != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja editar esse funcionario? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        
        if (resposta == 's' || resposta == 'S') {
            printf("Qual informacao deseja alterar? (1-6).\n");
            scanf(" %c", &resposta);
            getchar();
            if(resposta == '1'){
                printf("CPF atual = %s\n", func->cpff);
                printf("Novo CPF = ");
                le_cpf(func->cpff);
            } else if (resposta == '2'){
                printf("Nome atual = %s\n", func->nomef);
                printf("Novo Nome = ");
                le_nome(func->nomef);
            } else if (resposta =='3'){
                printf("Data de nascimento atual = %s\n", func->data_nascimentof);
                printf("Nova Data de nascimento = ");
                le_data_nascimento(func->data_nascimentof);
            } else if (resposta == '4'){
                printf("Telefone atual = %s\n", func->telefonef);
                printf("Novo telefone = ");
                le_telefone(func->telefonef);
            } else if (resposta == '5'){
                printf("Funcao atual = %s\n", func->funcao);
                printf("Nova funcao = ");
                le_texto(func->funcao, 50);
            } else if (resposta == '6'){
                printf("Salario atual = %.2f\n", func->salario);
                printf("Novo salario = ");
                le_valor(&func->salario);
            } else {
                printf("Resposta invalida! (responda de 1-4)\n");
            }
            regravar_funcionario(func);
        
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }

    free(func);
}

void delet_funcionario(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Funcionario* func;
    printf("|\033[1;36m = Deletar funcionario = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|     Insira o codigo do funcionario:                                           |\n");
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    func = busca_funcionario(&cod);
    exibir_funcionario(func);
    if (func != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja excluir esse funcionario? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        if (resposta == 's' || resposta == 'S') {
            printf("Voce respondeu 'sim'.\n");
            func->status = 'x';
            regravar_funcionario(func);
            printf("Cliente deletado.\n");
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }
    free(func);
    //Posso colocar um passo de confirmação se realmente quer deletar 
    //Um frase tipo
    // prinf(" Você realmente desejar deletar (nome) do cpf (cpf)?")


}

void regravar_funcionario(Funcionario* func) {
	int achou;
	FILE* fp;
	Funcionario* funLido;

	funLido = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionarios.dat", "r+b");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
	}
	achou = 0;
	while(fread(funLido, sizeof(Funcionario), 1, fp) && achou==0) {
		if (funLido->codigof == func->codigof) {
			achou = 1;
			fseek(fp, -1L*sizeof(Funcionario), SEEK_CUR);
        	fwrite(func, sizeof(Funcionario), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(funLido);
}

int proximo_codigof(void){
    int codigo = 1; 
    Funcionario temp;
    FILE* fp;
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
	}
    fseek(fp, 0, SEEK_SET); // Volta para o inicio do arquivo
    
    while (fread(&temp, sizeof(Funcionario), 1, fp) == 1) {
        if (temp.codigof >= codigo) {
            codigo = temp.codigof + 1;
        }
    }
    fclose(fp);   
    return codigo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////