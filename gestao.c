#include <stdio.h>
#include <stdlib.h>
#include "gestao.h"
#include "utilits.h"
#include <string.h>


void tela_menu_gestao_produtos() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Gestao de Produtos = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Gestao de Produtos = = = = =                        |\n");
        printf("|                                                                               |\n");
        printf("|            1. Cadastrar Produto                                               |\n");
        printf("|            2. Listar Produtos                                                 |\n");
        printf("|            3. Editar Produto                                                  |\n");
        printf("|            4. Excluir Produto                                                 |\n");
        printf("|            5. Pesquisar Produto                                               |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                cadast_produto();
                break;
            case '2':
                lista_produto();
                break;
            case '3':
                edit_produto();
                break;
            case '4':
                delet_produto();
                break;
            case '5':
                pesquisa_produto();
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
    }while (op!='0');
}

void cadast_produto(void) {//FUNCAO PARA CADASTRAR PRODUTO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao)); 
    fp = fopen("produtos.dat","ab");
    if (fp == NULL) {
        fp = fopen("produtos.dat","wb");
        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(gest);
            exit(1);
        }         
    }
    printf("|\033[1;36m = Cadastrar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cadastro = = =                                                     |\n");
    printf("|                                                                               |\n");
    gest->codigop = proximo_codigop();
    printf("|      Codigo do produto = %d                                                    \n", gest->codigop);
    printf("|      Nome       = ");
    le_nome(gest->nomep);
    printf("|      Valor      = ");
    le_valor(&gest->valor);
    printf("|      Descricao  = ");
    le_texto(gest->descricaop, 1000);
    printf("|      Quantidade = ");
    le_inte(&gest->quantidade);
    printf("|===============================================================================|\n\n");
    gest->status = 'a';
    fwrite(gest, sizeof(Gestao), 1, fp);
    fclose(fp);
    free(gest);
}

void pesquisa_produto(void){//FUNCAO PARA PESQUISAR PRODUTO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Gestao* gest;
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Gestao = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Pesquisar = = =                                                    |\n");
    printf("|     Insira o codigo do produto:                                               |\n");
    printf("|     Codigo   = "); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    gest = busca_produto(&cod);
    exibir_produto(gest);
    free(gest);
}

Gestao* busca_produto(int* cod){//FUNCAO PARA BUSCAR PRODUTO PELO CODIGO
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    char tem = 'x';
    int codv = *cod;
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((codv == gest->codigop)) {
            tem = 's';
            fclose(fp);
            return gest;
        }
    }
    if (tem != 's') {
            printf("Nenhum produto encontrado, com esse codigo.\n");
    }
    fclose(fp);
    return NULL;
}

void lista_produto(void){//FUNCAO PARA LISTAR TODOS OS PRODUTOS
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    printf("|\033[1;36m = Exibir produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if (gest->status != 'x') {
            exibir_produto(gest);
        }
    }
    free(gest);
    fclose(fp);
}
void exibir_produto(Gestao*gest) {//FUNCAO PARA EXIBIR OS DADOS DO PRODUTO
    char situacao[20];
    if ((gest == NULL) || (gest->status == 'x')) {
        printf("\n= = = Produto Inexistente = = =\n");
    }else{
        printf("|      = = = Produto = = =                                                      |\n");
        printf("|                                                                               |\n");
        printf("|        Codigo     =  %d                                                         \n", gest->codigop); 
        printf("| 1.     Nome       =  %s                                                         \n", gest->nomep);
        printf("| 2.     Valor      =  %.2f                                                       \n", gest->valor);
        printf("| 3.     Descricao  =  %s                                                         \n", gest->descricaop);
        printf("| 4.     Quantidade =  %d                                                         \n", gest->quantidade);
        if (gest->status == 'a') {
        strcpy(situacao, "Em estoque");
        } else {
        strcpy(situacao, "Esgotado");
        }
        printf("|        Situacao do produto = %s\n", situacao);
        printf("|===============================================================================|\n\n");
    }    
    
}

void exibir_produtort(Gestao*gest) {//FUNCAO PARA EXIBIR O PRODUTO DE FORMA TABELADA
    char situacao[20];
    if (gest == NULL) {
        printf("\n= = = Produto Inexistente = = =\n");
    }else{
        if (gest->status == 'a') {
        strcpy(situacao, "Em estoque");
        } else {
        strcpy(situacao, "Esgotado");
        }
        if (gest->quantidade <= 0){
            strcpy(situacao, "Esgotado");
        }
        printf("| %-10d| %-10d| %-29s| %-23s|\n", gest->codigop, gest->quantidade, gest->nomep, situacao);
        printf("|===============================================================================|\n");
    }    
}

void exibir_produtort_nvc(Gestao*gest, int q) {//FUNCAO PARA EXIBIR TABELADAMENTE O PRODUTO, USADA PARA O RELATORIO DE VENDAS POR PRODUTO
    if (gest == NULL) {
        printf("\n= = = Produto Inexistente = = =\n");
    }else{
        printf("| %-10d| %-29s| %-10.2f| %-23d|\n", gest->codigop, gest->nomep, gest->valor, q);
        printf("|===============================================================================|\n");
    }    
}

void edit_produto(void) {//FUNCAO PARA EDITAR PRODUTO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Gestao* gest;
    printf("|\033[1;36m = Editar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Editar = = =                                                       |\n");
    printf("|     Insira o codigo do produto:                                               |\n");
    printf("|     Codigo   = ");
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    gest = busca_produto(&cod);
    exibir_produto(gest);
    if (gest != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja editar esse produto? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        
        if (resposta == 's' || resposta == 'S') {
            printf("Qual informacao deseja alterar? (1-4).\n");
            scanf(" %c", &resposta);
            getchar();
            if (resposta == '1'){
                printf("Nome atual = %s\n", gest->nomep);
                printf("Novo Nome = ");
                le_nome(gest->nomep);
            } else if (resposta =='2'){
                printf("Valor atual = %.2f\n", gest->valor);
                printf("Novo valor = ");
                le_valor(&gest->valor);
            } else if (resposta == '3'){
                printf("Descricao atual = %s\n", gest->descricaop);
                printf("Nova descricao = ");
                le_texto(gest->descricaop, 1000);
            } else if (resposta == '4'){
                printf("Quantidade atual = %d\n", gest->quantidade);
                printf("Nova quantidade = ");
                le_inte(&gest->quantidade);
            } else {
                printf("Resposta invalida! (responda de 1-4)\n");
            }
            regravar_produto(gest);
        
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }

    free(gest);
}

void delet_produto(void) {//FUNCAO PARA DELETAR PRODUTO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Gestao* gest;
    printf("|\033[1;36m = Deletar produto = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Produto = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Deletar = = =                                                      |\n");
    printf("|     Insira o codigo do produto:                                               |\n");
    printf("|     Codigo   = "); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    gest = busca_produto(&cod);
    exibir_produto(gest);
    if (gest != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja excluir esse produto? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        if (resposta == 's' || resposta == 'S') {
            printf("Voce respondeu 'sim'.\n");
            gest->status = 'x';
            regravar_produto(gest);
            printf("Produto deletado.\n");
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }
    free(gest);
}

void regravar_produto(Gestao* gest) {//FUNCAO PARA REGRAVAR O PRODUTO NO ARQUIVO EXTERNO BINARIO
	int achou;
	FILE* fp;
	Gestao* gesLido;

	gesLido = (Gestao*) malloc(sizeof(Gestao));
	fp = fopen("produtos.dat", "r+b");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
	}
	achou = 0;
	while(fread(gesLido, sizeof(Gestao), 1, fp) && achou==0) {
		if (gesLido->codigop == gest->codigop) {
			achou = 1;
			fseek(fp, -1L*sizeof(Gestao), SEEK_CUR);
        	fwrite(gest, sizeof(Gestao), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(gesLido);
}

int proximo_codigop(void){//FUNCAO PARA COLOCAR O CODIGO DO PRODUTO 
    int codigo = 1; 
    Gestao temp;
    FILE* fp;
    fp = fopen("produtos.dat", "r+b");
    if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
	}
    fseek(fp, 0, SEEK_SET); // Volta para o inicio do arquivo
    
    while (fread(&temp, sizeof(Gestao), 1, fp) == 1) {
        if (temp.codigop >= codigo) {
            codigo = temp.codigop + 1;
        }
    }
    fclose(fp);   
    return codigo;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
