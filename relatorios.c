#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"
#include "utilits.h"
#include "cliente.h"
#include "funcionario.h"
#include "gestao.h"
#include "vendas.h"
#include <string.h>

void tela_menu_relatorios() {
    char op;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Menu Relatorios = \033[0m|\n");
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
        scanf(" %c",&op); getchar();
        printf("|===============================================================================|\n\n");
        switch (op) {
            case '1':
                relat_clientes();
                break;
            case '2':
                relat_funcionarios();
                break;
            case '3':
                relat_produtos();
                break;
            case '4':
                relat_vendas();
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

void relat_clientes(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios clientes = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|                 = = = = = Menu Relatorios de Clientes = = = = =               |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Clientes = = =                                       |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Clientes por situacao                                                 |\n");
        printf("|      3. Quantidade de compras por cliente                                     |\n");
        printf("|      4. Clientes ordenados por nome                                           |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_clientert();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                cliente_p_situacao();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                numero_c_cliente();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                ordenados_clientes();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');
}
    
void lista_clientert(void) {//RELATORIO DE EXIBIR TODOS OS CLIENTES
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status != 'x') {
            exibir_clientert(cliente);
        }
    }
    free(cliente);
    fclose(fp);
}

void cliente_p_situacao(void) {//RELATORIO PARA EXIBIR OS CLIENTES POR SITUACAO, Ativo e inativo
    char op;
    printf(" 1 - Clientes ativos\n");
    printf(" 2 - Cliente inativos\n ");
    printf("Digite sua opcao: ");
    scanf(" %c",&op); getchar();
    if(op == '1' || op == '2'){
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        FILE* fp;
        Cliente* cliente;
        cliente = (Cliente*) malloc(sizeof(Cliente));
        printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
        printf("|                                                                               |\n");
        printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
        printf("|-------------------------------------------------------------------------------|\n");
        fp = fopen("clientes.dat", "rb");
        if (fp == NULL) {
            printf("Erro na abertura do arquivo.\n");
            printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
            exit(1);
        }
        if (op == '1'){
            while(fread(cliente, sizeof(Cliente), 1, fp)) {
                if (cliente->status == 'a') {
                    exibir_clientert(cliente);
                }
            }
        } else if (op == '2'){
            while(fread(cliente, sizeof(Cliente), 1, fp)) {
                if (cliente->status == 'x') {
                    exibir_clientert(cliente);
                }
            }
        }
        free(cliente);
        fclose(fp);
    } else{
        printf("Opcao invalida.\n");
    }
}


void numero_c_cliente(void) {//RELATORIO PARA EXIBIR O NUMERO DE COMPRAS POR CLIENTE
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    FILE* vp;
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    Vendas* venda;
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("clientes.dat", "rb"); 
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }
    vp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |     COMPRAS FEITAS    |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    while(fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente->status == 'a') {
            fseek(vp, 0, SEEK_SET);
            int q = 0;
            while(fread(venda, sizeof(Vendas), 1, vp)) {
                if((strcmp(cliente->cpfc, venda->cpf_cliente) == 0)&&(venda->status !='x')){
                    q += 1;
                }
            }
            exibir_clientert_ncc(cliente, q);
        }
    }

free(cliente);
fclose(fp);
free(venda);
fclose(vp);
}

int compararClientes(const void *a, const void *b) { //Apoio do GPT
    return strcmp(((Cliente *)a)->nomec, ((Cliente *)b)->nomec);
}

void ordenados_clientes(){ //Apoio do GPT //RELATORIO PARA EXIBIR OS CLIENTE ORDENADOS POR NOME
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE *arquivoClientes;

    // Abrir o arquivo para leitura binaria
    if ((arquivoClientes = fopen("clientes.dat", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem clientes cadastrados...\n");
        exit(1);
    }

    // Determinar o numero de clientes no arquivo
    fseek(arquivoClientes, 0, SEEK_END);
    size_t numClientes = ftell(arquivoClientes) / sizeof(Cliente);
    rewind(arquivoClientes);

    // Alocar espaço para armazenar os clientes
    Cliente *clientes = (Cliente *)malloc(numClientes * sizeof(Cliente));

    // Ler os clientes do arquivo para o array
    fread(clientes, sizeof(Cliente), numClientes, arquivoClientes);

    // Fechar o arquivo
    fclose(arquivoClientes);

    // Ordenar os clientes pelo nome
    qsort(clientes, numClientes, sizeof(Cliente), compararClientes);

    // Exibir os clientes ordenados
    printf("|\033[1;36m = Lista de clientes = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Cliente = = = = =                         |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      TELEFONE         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    
    for (size_t i = 0; i < numClientes; i++) {
        if(clientes[i].status != 'x'){  
            printf("| %-10d| %-10s| %-29s| %-22s|\n", clientes[i].codigoc, clientes[i].cpfc, clientes[i].nomec, clientes[i].telefonec);
            printf("|===============================================================================|\n");
        }
    }

    // Liberar a memória alocada para os clientes
    free(clientes);

}


void relat_funcionarios(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios funcionarios = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|              = = = = = Menu Relatorios de Funcionarios = = = = =              |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Funcionarios = = =                                   |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Funcionarios por situacao                                             |\n");
        printf("|      3. Quantidade de vendas por funcionario                                  |\n");
        printf("|      4. Funcionarios ordenados por nome                                       |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_funcionariort();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                funcionario_p_situacao();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                numero_v_funcionario();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                ordenados_funcionarios();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
}

void lista_funcionariort(void) {//RELATORIO PARA EXIBIR TODOS OS FUNCIONARIOS
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    printf("|\033[1;36m = Lista de funcionarios = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Funcionarios = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if (func->status != 'x') {
            exibir_funcionariort(func);
        }
    }
    free(func);
    fclose(fp);
}

void funcionario_p_situacao(void) {;//RELATORIO PARA EXIBIR OS FUNCIONARIOS POR SITUACAO, ATIVOS E INATIVOS
    char op;
    printf(" 1 - Funcionarios ativos\n");
    printf(" 2 - Funcionarios inativos\n ");
    printf("Digite sua opcao: ");
    scanf(" %c",&op); getchar();
    if(op == '1' || op == '2'){
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        FILE* fp;
        Funcionario* func;
        func = (Funcionario*) malloc(sizeof(Funcionario));
        printf("|\033[1;36m = Lista de funcionarios = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Relatorios de Funcionarios = = = = =                |\n");
        printf("|                                                                               |\n");
        printf("|   CODIGO  |    CPF     |              NOME            |      SITUACAO         |\n");            
        printf("|-------------------------------------------------------------------------------|\n");
        fp = fopen("funcionarios.dat", "rb");
        if (fp == NULL) {
            printf("Erro na abertura do arquivo.\n");
            printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
            exit(1);
        }
        if(op =='1'){
            while(fread(func, sizeof(Funcionario), 1, fp)) {
                if (func->status == 'a') {
                    exibir_funcionariort(func);
                }
            }
        } else if(op=='2'){
            while(fread(func, sizeof(Funcionario), 1, fp)) {
                if (func->status == 'x') {
                    exibir_funcionariort(func);
                }
            }
        }
        free(func);
        fclose(fp);
    } else{
        printf("Opcao invalida.\n");
    }
}

void numero_v_funcionario(void) {//RELATORIO PARA EXIBIR O NUMERO DE VENDAS POR FUNCIONARIO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    FILE* vp;
    Funcionario* func;
    func = (Funcionario*) malloc(sizeof(Funcionario));
    Vendas* venda;
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("funcionarios.dat", "rb"); 
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }
    vp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    printf("|\033[1;36m = Lista de funcionarios = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Funcionarios = = = = =                |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |     VENDAS FEITAS     |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    while(fread(func, sizeof(Funcionario), 1, fp)) {
        if (func->status == 'a') {
            fseek(vp, 0, SEEK_SET);
            int q = 0;
            while(fread(venda, sizeof(Vendas), 1, vp)) {
                if((func->codigof == venda->codigo_funcionario)&&(venda->status !='x')){
                    q += 1;
                }
            }
            exibir_funcionariort_nvc(func, q);
        }
    }

free(func);
fclose(fp);
free(venda);
fclose(vp);
}

int compararFuncionarios(const void *a, const void *b) { //Apoio do GPT
    return strcmp(((Funcionario *)a)->nomef, ((Funcionario *)b)->nomef);
}

void ordenados_funcionarios(){ //Apoio do GPT //RELATORIO PARA EXIBIR OS FUNCIONARIOS ORDENADOS PELO NOME
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE *fp;

    // Abrir o arquivo para leitura binaria
    if ((fp = fopen("funcionarios.dat", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem funcionarios cadastrados...\n");
        exit(1);
    }

    // Determinar o numero de funcionarios no arquivo
    fseek(fp, 0, SEEK_END);
    size_t numFunc = ftell(fp) / sizeof(Funcionario);
    rewind(fp);

    // Alocar espaço para armazenar os clientes
    Funcionario *func = (Funcionario *)malloc(numFunc * sizeof(Funcionario));

    // Ler os funcionarios do arquivo para o array
    fread(func, sizeof(Funcionario), numFunc, fp);

    // Fechar o arquivo
    fclose(fp);

    // Ordenar os funcionarios pelo nome
    qsort(func, numFunc, sizeof(Funcionario), compararFuncionarios);

    // Exibir os funcionarios ordenados
    printf("|\033[1;36m = Lista de funcionarios = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|                      = = = = = Menu Funcionario = = = = =                     |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  |    CPF     |              NOME            |      TELEFONE         |\n");            
    printf("|-------------------------------------------------------------------------------|\n");
    
    for (size_t i = 0; i < numFunc; i++) {
        if(func[i].status != 'x'){  
            printf("| %-10d| %-10s| %-29s| %-22s|\n", func[i].codigof, func[i].cpff, func[i].nomef, func[i].telefonef);
            printf("|===============================================================================|\n");
        }
    }

    // Liberar a memória alocada para os funcionarios
    free(func);

}



void relat_produtos(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios Produtos = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|              = = = = = Menu Relatorios de Produtos = = = = =                  |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Produtos = = =                                       |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Produtos por situacao                                                 |\n");
        printf("|      3. Quantidade de vendas por produto                                      |\n");
        printf("|      4. Produtos ordenados por nome                                           |\n");
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_produtort();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                produto_p_situacao();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                numero_v_produto();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                ordenados_produtos();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
    
}

void produto_p_situacao(void) {//RELATORIO PARA EXIBIR OS PRODUTOS POR SITUACAO, EM ESTOQUE E ESGOTADOS
    char op;
    printf(" 1 - Produtos em estoque\n");
    printf(" 2 - Produtos esgotados\n ");
    printf("Digite sua opcao: ");
    scanf(" %c",&op); getchar();
    if(op == '1' || op == '2'){
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        FILE* fp;
        Gestao* gest;
        gest = (Gestao*) malloc(sizeof(Gestao));
        printf("|\033[1;36m = Lista de Produtos = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|            = = = = = Menu Relatorios de Produtos = = = = =                    |\n");
        printf("|                                                                               |\n");            
        printf("|   CODIGO  | QUANTIDADE|              NOME            |      SITUACAO          |\n");
        printf("|-------------------------------------------------------------------------------|\n");
        fp = fopen("produtos.dat", "rb");
        if (fp == NULL) {
            printf("Erro na abertura do arquivo.\n");
            printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
            exit(1);
        }
        if (op =='1'){
            while(fread(gest, sizeof(Gestao), 1, fp)) {
                if ((gest->status == 'a')&&(gest->quantidade > 0)){
                    exibir_produtort(gest);
                }
            }
        } else if (op =='2'){
            while(fread(gest, sizeof(Gestao), 1, fp)) {
                if (gest->quantidade <= 0) {
                    exibir_produtort(gest);
                }
            }
        }
        free(gest);
        fclose(fp);
    } else{
        printf("Opcao invalida.\n");
    }
}

void lista_produtort(void) {//RELATORIO PARA EXIBIR TODOS OS PRODUTOS
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));
    printf("|\033[1;36m = Lista de Produtos = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Produtos = = = = =                    |\n");
    printf("|                                                                               |\n");            
    printf("|   CODIGO  | QUANTIDADE|              NOME            |      SITUACAO          |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        if (gest->status != 'x') {
            exibir_produtort(gest);
        }
    }
    free(gest);
    fclose(fp);
}

void numero_v_produto(void) {//RELATORIO PARA EXIBIR O NUMERO DE VENDAS POR PRODUTO
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Gestao* gest;
    gest = (Gestao*) malloc(sizeof(Gestao));

    FILE* fv;
    Prodv* prodv;
    prodv = (Prodv*) malloc(sizeof(Prodv));
    
    printf("|\033[1;36m = Lista de Produtos = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Produtos = = = = =                    |\n");
    printf("|                                                                               |\n");            
    printf("|   CODIGO  |              NOME            |   VALOR   |        VENDAS          |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }
    fv = fopen("produtosvendidos.dat", "rb");
    if (fv == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos vendidos cadastrados...\n");
        exit(1);
    }
    while(fread(gest, sizeof(Gestao), 1, fp)) {
        int q = 0;
        fseek(fv, 0, SEEK_SET);
        while(fread(prodv, sizeof(Prodv), 1, fv)) {
            if((gest->codigop==prodv->codigop)&&(prodv->status!='x')){
                q+=prodv->quantidade;      
            }
        }
        exibir_produtort_nvc(gest, q);
    }
    free(prodv);
    fclose(fv);
    free(gest);
    fclose(fp);
}

int compararProdutos(const void *a, const void *b) { //Apoio do GPT
    return strcmp(((Gestao *)a)->nomep, ((Gestao *)b)->nomep);
}

void ordenados_produtos(){ //Apoio do GPT //RELATORIO PARA EXIBIR O NOME DOS PRODUTOS ORDENADOS
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE *fp;

    // Abrir o arquivo para leitura binaria
    if ((fp = fopen("produtos.dat", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos cadastrados...\n");
        exit(1);
    }

    // Determinar o numero de produtos no arquivo
    fseek(fp, 0, SEEK_END);
    size_t numGest = ftell(fp) / sizeof(Gestao);
    rewind(fp);

    // Alocar espaço para armazenar os clientes
    Gestao *gest = (Gestao *)malloc(numGest * sizeof(Gestao));

    // Ler os produtos do arquivo para o array
    fread(gest, sizeof(Gestao), numGest, fp);

    // Fechar o arquivo
    fclose(fp);

    // Ordenar os produtos pelo nome
    qsort(gest, numGest, sizeof(Gestao), compararProdutos);

    // Exibir os produtos ordenados
    printf("|\033[1;36m = Lista de Produtos = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Produtos = = = = =                    |\n");
    printf("|                                                                               |\n");            
    printf("|   CODIGO  |              NOME            |   VALOR   |     QUANTIDADE         |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    
    for (size_t i = 0; i < numGest; i++) {
        if(gest[i].status != 'x'){  
            printf("| %-10d| %-29s| %-10.2f| %-23d|\n", gest[i].codigop, gest[i].nomep, gest[i].valor, gest[i].quantidade);
            printf("|===============================================================================|\n");
        }
    }

    // Liberar a memória alocada para os produtos
    free(gest);

}


void relat_vendas(void) {
    char op1;
    do{
        system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
        printf("|\033[1;36m = Relatorios Vendas = \033[0m|\n");
        printf("|===============================================================================|\n");
        printf("|                                                                               |\n");
        printf("|               = = = = = Menu Relatorios de Vendas = = = = =                   |\n");
        printf("|                                                                               |\n");
        printf("|      = = = Relatorios de Vendas = = =                                         |\n");
        printf("|                                                                               |\n");
        printf("|      1. Relatorio de todos                                                    |\n");
        printf("|      2. Vendas por funcionario                                                |\n");
        printf("|      3. Vendas por cliente                                                    |\n");
        printf("|      4. Vendas por produto                                                    |\n"); 
        printf("|      0. Voltar ao Menu Principal                                              |\n");
        printf("|                                                                               |\n");
        printf("|            Escolha a opcao desejada: "); 
        scanf(" %c",&op1); getchar();
        printf("|===============================================================================|\n\n");
        switch (op1) {
            case '1':
                lista_vendart();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '2':
                venda_p_funcionario();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '3':
                venda_p_cliente();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '4':
                venda_p_produto();
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
            case '0':
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                printf("Pressione uma tecla para continuar...\n");
                getchar(); // Aguarda a entrada de uma tecla
                break;
        }
    }while(op1!='0');    
}

void lista_vendart(void) {//RELATORIO PARA EXIBIR TODAS AS VENDAS
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if (vend->status != 'x') {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}

void venda_p_funcionario(void) {//RELATORIO PARA EXIBIR AS VENDAS POR FUNCIONARIO
    int cod;
    printf("Digite o codigo do funcionario: ");
    le_inte(&cod);

    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("| VENDAS DO FUNCIONARIO : %d\n", cod);
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if ((vend->codigo_funcionario == cod)&&(vend->status!='x')) {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}

void venda_p_cliente(void) {//RELATORIO PARA EXIBIR AS VENDAS POR CLIENTE
    char cpf[12];
    printf("Digite o CPF do cliente: ");
    le_cpf(cpf);

    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    FILE* fp;
    Vendas* vend;
    vend = (Vendas*) malloc(sizeof(Vendas));
    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");
    printf("| VENDAS DO CLIENTE : %s\n", cpf);
    printf("|                                                                               |\n");
    printf("|   CODIGO  | CPF CLIENTE|          VALOR TOTAL         |   CODIGO FUNCIONARIO  |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    while(fread(vend, sizeof(Vendas), 1, fp)) {
        if ((strcmp(vend->cpf_cliente, cpf) == 0)&&(vend->status!='x')) {
            exibir_vendart(vend);
        }
    }
    free(vend);
    fclose(fp);
}

void venda_p_produto(void) {//RELATORIO PARA EXIBIR AS VENDAS POR PRODUTO
    int cod = 0;
    printf("Digite o codigo: ");
    do{le_inte(&cod);}while(!tem_codigop(&cod));
    system("clear || cls");  // Tenta "clear" no Linux/macOS, se falhar, tenta "cls" no Windows
    
    FILE* fv;
    Prodv* prodv;
    prodv = (Prodv*) malloc(sizeof(Prodv));
    fv = fopen("produtosvendidos.dat", "rb");
    if (fv == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem produtos vendidos cadastrados...\n");
        exit(1);
    }

    FILE* fp;
    Vendas* venda;
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        printf("Nao e possivel continuar, provavelmente nao tem vendas cadastrados...\n");
        exit(1);
    }
    

    Gestao* gest;
    gest = busca_produto(&cod);

    printf("|\033[1;36m = Lista de Vendas = \033[0m|\n");
    printf("|===============================================================================|\n");
    printf("|                                                                               |\n");
    printf("|            = = = = = Menu Relatorios de Vendas = = = = =                      |\n");
    printf("|                                                                               |\n");  
    printf("|   PRODUTO: %-10s             CODIGO: %-10d                                     \n", gest->nomep, gest->codigop);
    printf("|                                                                               |\n");          
    printf("|   CODIGO DA VENDA   |     CPF CLIENTE      |  QUANTIDADE  |       VALOR       |\n");
    printf("|-------------------------------------------------------------------------------|\n");

     while(fread(prodv, sizeof(Prodv), 1, fv)) {
        if (prodv->codigop == gest->codigop) {
            fseek(fp, 0, SEEK_SET);
            while(fread(venda, sizeof(Vendas), 1, fp)) {
                if (venda->codigov == prodv->codigov) {
                    float v = 0;
                    v = gest->valor * prodv->quantidade;
                    if(prodv->quantidade!=0){
                        exibir_v_produtort(prodv, venda->cpf_cliente, v);
                    }
                }
            }
        }
    }

free(gest);
free(prodv);
free(venda);
fclose(fp);
fclose(fv);
}





///////////////////////////////////////////////////////////////////////////////////////////////////