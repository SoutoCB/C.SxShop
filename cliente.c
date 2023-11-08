//Criar a biblioteca para as funções de cliente
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "utilits.h"
#include <string.h>


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
        printf("|            5. Pesquisar Cliente                                               |\n");
        printf("|            6. Recuperar Cliente                                               |\n");
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
                lista_cliente();
                break;
            case '3':
                edit_cliente();
                break;
            case '4':
                delet_cliente();
                break;
            case '5':
                pesquisa_cliente();
                break;
            case '6':
                recupera_cliente();
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
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente)); 
    fp = fopen("clientes.dat","ab");
    if (fp == NULL) {
        fp = fopen("clientes.dat","wb");
        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(cliente);
            exit(1);
        }         
    }
    printf("|\033[1;36m = Cadastrar cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    cliente->codigoc = proximo_codigoc();
    printf("|      CPF      =                                                               |\n");
    le_cpf(cliente->cpfc);
    printf("|      Nome     =                                                               |\n");
    le_nome(cliente->nomec);
    printf("|      Data nascimento =                                                        |\n");
    le_data_nascimento(cliente->data_nascimentoc);
    printf("|      Telefone =                                                               |\n");
    le_telefone(cliente->telefonec);
    printf("|===============================================================================|\n\n");
    cliente->status = 'a';
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cliente);
    //Colocar estrutura de coleta de dados
}  

void pesquisa_cliente(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Cliente* cliente;
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Pesquisar = = =                                                    |\n");
    printf("|     Insira o codigo do cliente:                                               |\n");
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    cliente = busca_cliente(&cod);
    exibir_cliente(cliente);
    free(cliente);
}

Cliente* busca_cliente(int* cod){
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    char tem = 'x';
    int codv = *cod;
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((codv == cliente->codigoc)) {
            tem = 's';
            fclose(fp);
            return cliente;
        }
    }
    if (tem != 's') {
            printf("Nenhum cliente encontrado, com esse codigo.\n");
    }
    fclose(fp);
    return NULL;
}

void lista_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status != 'x') {
            exibir_cliente(cliente);
        }
    }
    free(cliente);
    fclose(fp);
}

void exibir_cliente(Cliente*cliente) {
    char situacao[20];
    if ((cliente == NULL) || (cliente->status == 'x')) {
        printf("\n= = = Cliente Inexistente = = =\n");
    }else{
        printf("|      = = = Cliente = = =                                                      |\n");
        printf("|        Codigo   = %d                                                            \n", cliente->codigoc); //Pensar sobre esse codigo
        printf("| 1.     CPF      = %s                                                            \n", cliente->cpfc);
        printf("| 2.     Nome     = %s                                                            \n", cliente->nomec);
        printf("| 3.     Data nascimento = %s                                                     \n", cliente->data_nascimentoc);
        printf("| 4.     Telefone = %s                                                            \n", cliente->telefonec); 
        // Buscar forma para exibir cliente por cliente
        if (cliente->status == 'a') {
        strcpy(situacao, "Ativo");
        } else {
        strcpy(situacao, "Nao informada");
        }
        printf("|         Situacao do cliente = %s\n", situacao);
        printf("|===============================================================================|\n\n");
    }    
}

void edit_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Cliente* cliente;
    printf("|\033[1;36m = Editar cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do cliente:                                               |\n");
    printf("|     Codigo   =                                                                |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    cliente = busca_cliente(&cod);
    exibir_cliente(cliente);
    if (cliente != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja editar esse cliente? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        
        if (resposta == 's' || resposta == 'S') {
            printf("Qual informacao deseja alterar? (1-4).\n");
            scanf(" %c", &resposta);
            getchar();
            if(resposta == '1'){
                printf("CPF atual = %s\n", cliente->cpfc);
                printf("Novo CPF = ");
                le_cpf(cliente->cpfc);
            } else if (resposta == '2'){
                printf("Nome atual = %s\n", cliente->nomec);
                printf("Novo Nome = ");
                le_nome(cliente->nomec);
            } else if (resposta =='3'){
                printf("Data de nascimento atual = %s\n", cliente->data_nascimentoc);
                printf("Nova Data de nascimento = ");
                le_data_nascimento(cliente->data_nascimentoc);
            } else if (resposta == '4'){
                printf("Telefone atual = %s\n", cliente->telefonec);
                printf("Novo telefone = ");
                le_telefone(cliente->telefonec);
            } else {
                printf("Resposta invalida! (responda de 1-4)\n");
            }
            regravar_cliente(cliente);
        
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }

    free(cliente);
}

void delet_cliente(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Cliente* cliente;
    printf("|\033[1;36m = Excluir cliente = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|      Insira o codigo do cliente:                                              |\n");
    printf("|      Codigo   =                                                               |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    cliente = busca_cliente(&cod);
    exibir_cliente(cliente);
    if (cliente != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja excluir esse cliente? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        if (resposta == 's' || resposta == 'S') {
            printf("Voce respondeu 'sim'.\n");
            cliente->status = 'x';
            regravar_cliente(cliente);
            printf("Cliente deletado.\n");
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }
    free(cliente);
}


void regravar_cliente(Cliente* cliente) {
	int achou;
	FILE* fp;
	Cliente* cliLido;

	cliLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("clientes.dat", "r+b");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
	}
	// while(!feof(fp)) {
	achou = 0;
	while(fread(cliLido, sizeof(Cliente), 1, fp) && achou==0) {
		//fread(alnLido, sizeof(Aluno), 1, fp);
		if (cliLido->codigoc == cliente->codigoc) {
			achou = 1;
			fseek(fp, -1L*sizeof(Cliente), SEEK_CUR);
        	fwrite(cliente, sizeof(Cliente), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(cliLido);
}

void recupera_cliente(void){
    printf("oi");
}


int proximo_codigoc(void){
    int codigo = 1; 
    Cliente temp;
    FILE* fp;
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
	}
    fseek(fp, 0, SEEK_SET); // Volta para o inicio do arquivo
    
    while (fread(&temp, sizeof(Cliente), 1, fp) == 1) {
        if (temp.codigoc >= codigo) {
            codigo = temp.codigoc + 1;
        }
    }
    fclose(fp);   
    return codigo;
}