
struct vendas{
    int codigov;
    char cpf_cliente[10];
    int codigo_funcionario;
    float valor_total;
    char descricao[1000];
    char status;
};

typedef struct vendas Vendas;



void tela_menu_vendas();
    void make_vendas(void);
    void lista_vendas(void);
    void exibir_vendas(Vendas*);
    void cancel_vendas(void);
    void pesquisa_vendas(void);
    Vendas* busca_vendas(int*);
    void regravar_vendas(Vendas*);
    int proximo_codigov(void);
    int tem_cpfc(char*);
    int tem_codigof(int*);

