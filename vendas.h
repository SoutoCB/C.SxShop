
struct vendas{
    int codigov;
    char cpf_cliente[10];
    int codigo_funcionario;
    float valor_total;
    char descricao[1000];
    char status;
};

typedef struct vendas Vendas;

struct produtovendido{
    int codigopdv;
    int codigov;
    int codigop;
    int quantidade;
    char status;
};

typedef struct produtovendido Prodv;




void tela_menu_vendas();
    void make_vendas(void);
    void lista_vendas(void);
    void exibir_vendas(Vendas*);
    void exibir_vendart(Vendas*);
    void exibir_v_produtort(Prodv*, char*, float);
    void cancel_vendas(void);
    void pesquisa_vendas(void);
    Vendas* busca_vendas(int*);
    void regravar_vendas(Vendas*);
    int proximo_codigov(void);
    int tem_cpfc(char*);
    int tem_codigof(int*);
    int proximo_codigopdv(void);

    int tem_codigop(int*);
    int tem_quant(int*, int*);
    float produto_vendido(int*);

    void volta_quant(int*);
    void regravar_prodv(Prodv*);


   