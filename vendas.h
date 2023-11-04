
struct vendas{
    char numero_venda[10];
    char codigo_cliente[10];
    char codigo_funcionario[10];
    float valor_total;
    char descricao[1000];
};

typedef struct vendas Vendas;



void tela_menu_vendas();
    void make_vendas(void);
    void lista_vendas(void);
    void exibir_vendas(Vendas*);
    void edit_vendas(void);
    void cancel_vendas(void);

