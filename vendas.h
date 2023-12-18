
struct vendas{
    int codigov;//Codigo da venda
    char cpf_cliente[10];//Cpf do cliente
    int codigo_funcionario;//Codigo do funcionario
    float valor_total;//Valor total
    char descricao[1000];//Descricao da venda
    char status;// a = ativa / x = excluida
};

typedef struct vendas Vendas;

struct produtovendido{
    int codigopdv;//Codigo do produto vendido
    int codigov;//Codigo da venda
    int codigop;//Codigo do produto
    int quantidade;//Quantidade do produto vendido
    char status;//a = ativa / x = excluida
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


   