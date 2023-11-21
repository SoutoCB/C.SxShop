#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"
#include "utilits.h"
#include <string.h>
#include "cliente.h"
#include "funcionario.h"
#include "gestao.h"

void tela_menu_vendas() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Vendas = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Vendas = = = = =                                    |\n");
        printf("|                                                                               |\n");
        printf("|            1. Realizar Venda                                                  |\n");
        printf("|            2. Listar Vendas                                                   |\n");
        printf("|            3. Pesquisar Vendas                                                |\n");
        printf("|            4. Cancelar Venda                                                  |\n");
        printf("|            0. Voltar ao Menu Principal                                        |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                make_vendas();
                break;
            case '2':
                lista_vendas();
                break;
            case '3':
                pesquisa_vendas();
                break;
            case '4':
                cancel_vendas();
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

void make_vendas(void) {
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas)); 
    fp = fopen("vendas.dat","ab");
    if (fp == NULL) {
        fp = fopen("vendas.dat","wb");
        if (fp == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(vend);
            exit(1);
        }         
    }
    printf("|\033[1;36m = Realizar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Realizar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    vend->codigov = proximo_codigov();
    printf("|      CPF do cliente =                                                         |\n");
    do{le_cpf(vend->cpf_cliente);}while(!tem_cpfc(vend->cpf_cliente));
    printf("|      Codigo do funcionario =                                                  |\n"); 
    do{le_inte(&vend->codigo_funcionario);}while(!tem_codigof(&vend->codigo_funcionario));
    float valor = 0;
    char resp = 'z';
    do{
        valor += produto_vendido(&vend->codigov); 
        printf("|      Adcionar mais produto(s/n)? ");
        scanf(" %c", &resp); getchar();
    }while((resp == 's')||(resp == 'S'));  
    printf("|      Valor total     = %.2f                                                   \n", valor);
    vend->valor_total = valor;
    printf("|      Descricao       =                                                        \n");
    le_texto(vend->descricao, 1000);
    vend->status = 'a';
    // Possivel adicao de novos dados para coletar
    //Possivel adicao de uma coleta de codigo de protudo para diminuir sua quantidade no estoque
    // Salva a quantida de compras feitas pelo cliente
    // Salva a quantida de compras feitas pelo funcionario
    printf("|===============================================================================|\n\n");
    fwrite(vend, sizeof(Vendas), 1, fp);
    fclose(fp);
    free(vend);
}

float produto_vendido(int* cod){
    
    int codp;
    printf("Digite o codigo do produto: ");
    do{le_inte(&codp);}while(!tem_codigop(&codp));

    int quant;
    printf("Digite a quantidade: ");
    do{le_inte(&quant);}while(!tem_quant(&quant, &codp));
    
    FILE* fp;
    Gestao* gest;
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    gest = busca_produto(&codp);
    gest->quantidade = (gest->quantidade - quant);
    float valor;
    valor = gest->valor * quant;
    regravar_produto(gest);
    
    //Adicionando a struct Prodv
    int codv = *cod;
    FILE* fv;
    Prodv* prodv;
    prodv = (Prodv*) malloc(sizeof(Prodv)); 
    fv = fopen("produtosvendidos.dat","ab");
    if (fv == NULL) {
        fv = fopen("produtosvendidos.dat","wb");
        if (fv == NULL){
            printf("Erro na criacao do arquivo\n!");
            free(prodv);
            exit(1);
        }         
    }
    prodv->codigov = codv;
    prodv->codigop = codp;
    prodv->quantidade = quant;
    prodv->status = 'a';
    fwrite(prodv, sizeof(Prodv), 1, fv);
    //

//frees
//
free(prodv);
fclose(fv);
//
free(gest);
fclose(fp);
return valor;
}

int tem_quant(int*quan, int*co){
    int cod = *co;
    int quant = *quan;
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((gest->codigop == cod) && (gest->status != 'x')){
            int temestoque;
            temestoque = (gest->quantidade - quant);
            if (temestoque >= 0) {
                fclose(fp);
                free(gest);
                return 1;
            } else if (temestoque < 0) {
                printf("Estoque atual deste produto: %d\n", gest->quantidade);
                printf("Estoque indisponivel, digite novamente = \n");
                fclose(fp);
                free(gest);
                return 0;
            }
        }
    } 
    fclose(fp);
    free(gest);
    printf("DEU B.O \n");
    return 0;
}

int tem_codigop(int*codp){
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    int codpp = *codp;
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if ((gest->codigop == codpp)  && gest->status != 'x') {
            fclose(fp);
            free(gest);
            return 1;
        }
    } 
    fclose(fp);
    free(gest);
    printf("Codigo inexistente, digite novamente = \n");
    return 0;
}

int tem_cpfc(char*cpfc){
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cpfc, cliente->cpfc) == 0)  && cliente->status != 'x') {
            fclose(fp);
            free(cliente);
            return 1;
        }
    } 
    fclose(fp);
    free(cliente);
    printf("CPF nao cadastrado, digite novamente = \n");
    return 0;
}

int tem_codigof(int*codf){
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    int codff = *codf;
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if ((func->codigof == codff)  && func->status != 'x') {
            fclose(fp);
            free(func);
            return 1;
        }
    } 
    fclose(fp);
    free(func);
    printf("Codigo inexistente, digite novamente = \n");
    return 0;
}

void pesquisa_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Vendas* vend;
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Pesquisar = = =                                                    |\n");
    printf("|     Insira o codigo da venda:                                                 |\n");
    printf("|     Codigo   =                                                                   |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n");
    vend = busca_vendas(&cod);
    exibir_vendas(vend);
    free(vend);
}

Vendas* busca_vendas(int* cod){
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    char tem = 'x';
    int codv = *cod;
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if ((codv == vend->codigov)) {
            tem = 's';
            fclose(fp);
            return vend;
        }
    }
    if (tem != 's') {
            printf("Nenhuma venda encontrado, com esse codigo.\n");
    }
    fclose(fp);
    return NULL;
}
 
                      //VER QUESTAO DA FUNCAO PEDIDO DEPOIS
void lista_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Listar Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if (vend->status != 'x'){
            exibir_vendas(vend);
        }
    }
    free(vend);
    fclose(fp);
}
void exibir_vendas(Vendas*vend) {
    if((vend == NULL) || (vend->status == 'x')) {
        printf("\n= = = Venda Inexistente = = =\n");
    }else{
        printf("|      = = = Venda = = =                                                        |\n");
        printf("|                                                                               |\n");
        printf("|      Codigo da Venda   = %d                                                   \n", vend->codigov); //Pensar sobre esse codigo
        printf("|      CPF do cliente = %s                                                      \n", vend->cpf_cliente);
        printf("|      Codigo do funcionario = %d                                               \n", vend->codigo_funcionario);
        printf("|      Valor total     = %.2f                                                   \n", vend->valor_total);
        printf("|      Descricao       = %s                                                     \n", vend->descricao);
        printf("|===============================================================================|\n\n");
    }
}

void exibir_vendart(Vendas*vend) {
    if (vend == NULL) {
        printf("\n= = = Venda Inexistente = = =\n");
    }else{
        printf("| %-10d| %-10s| R$%-27.2f| %-22d|\n", vend->codigov, vend->cpf_cliente, vend->valor_total, vend->codigo_funcionario);
        printf("|===============================================================================|\n");
    }    
}


void cancel_vendas(void){
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    Vendas* vend;
    printf("|\033[1;36m = Cancelar Venda = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Vendas = = = = =                          |\n");
    printf("|                                                                               |\n");
    printf("|      = = = Cancelar Venda = = =                                               |\n");
    printf("|                                                                               |\n");
    printf("|      Codigo da Venda =                                                        |\n"); //Pensar sobre esse codigo
    int cod;
    le_inte(&cod);
    printf("|===============================================================================|\n\n");
    vend = busca_vendas(&cod);
    exibir_vendas(vend);
    if (vend != NULL){
        char resposta;
        printf("\033[1;31mVoce realmente deseja excluir essa venda? (s/n):\033[0m ");
        scanf(" %c", &resposta);
        getchar();
        if (resposta == 's' || resposta == 'S') {
            printf("Voce respondeu 'sim'.\n");
            vend->status = 'x';
            regravar_vendas(vend);
            //
            volta_quant(&vend->codigov);
            //
            printf("Venda deletada.\n");
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Voce respondeu 'nao'.\n");
            printf("Acao cancelada.\n");
        } else {
            printf("Resposta invalida! (responda com 's' ou 'n')\n");
        }
    }
    free(vend);
}

void volta_quant(int* cod){
    int codv = *cod;
    FILE* fv;
    Prodv* prodv;
    prodv = (Prodv*) malloc(sizeof(Prodv)); 
    fv = fopen("produtosvendidos.dat", "rb");
	if (fv == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
	}
    while(fread(prodv, sizeof(Prodv), 1, fv)) {
        if ((codv == prodv->codigov)&&(prodv->status != 'x')){
            FILE* fp;
            Gestao* gest;
            fp = fopen("produtos.dat", "rb");
            if (fv == NULL) {
                printf("Erro na abertura do arquivo.\n");
                printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
                exit(1);
            }
            gest = busca_produto(&prodv->codigop);
            gest->quantidade += prodv->quantidade;
            prodv->status = 'x';
            regravar_produto(gest);
            regravar_prodv(prodv);
            free(gest);
            fclose(fp);    
        }
    }
fclose(fv);
free(prodv);
}

void regravar_prodv(Prodv* prodv) {
	int achou;
	FILE* fp;
	Prodv* venLido;

	venLido = (Prodv*) malloc(sizeof(Prodv));
	fp = fopen("produtosvendidos.dat", "r+b");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
	}
	achou = 0;
	while(fread(venLido, sizeof(Prodv), 1, fp) && achou==0) {
		if (venLido->codigov == prodv->codigov) {
			achou = 1;
			fseek(fp, -1L*sizeof(Prodv), SEEK_CUR);
        	fwrite(prodv, sizeof(Prodv), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(venLido);
}


void regravar_vendas(Vendas* vend) {
	int achou;
	FILE* fp;
	Vendas* venLido;

	venLido = (Vendas*) malloc(sizeof(Vendas));
	fp = fopen("vendas.dat", "r+b");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
	}
	achou = 0;
	while(fread(venLido, sizeof(Vendas), 1, fp) && achou==0) {
		if (venLido->codigov == vend->codigov) {
			achou = 1;
			fseek(fp, -1L*sizeof(Vendas), SEEK_CUR);
        	fwrite(vend, sizeof(Vendas), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(venLido);
}


int proximo_codigov(void){
    int codigo = 1; 
    Vendas temp;
    FILE* fp;
    fp = fopen("vendas.dat", "r+b");
    if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
	}
    fseek(fp, 0, SEEK_SET); // Volta para o inicio do arquivo
    
    while (fread(&temp, sizeof(Vendas), 1, fp) == 1) {
        if (temp.codigov >= codigo) {
            codigo = temp.codigov + 1;
        }
    }
    fclose(fp);   
    return codigo;
}



///////////////////////////////////////////////////////////////////////////////////////////////////