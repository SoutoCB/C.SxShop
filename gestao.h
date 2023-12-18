
struct gestao{
    int codigop;//Codigo do produto
    char nomep[50];//Nome do produto
    float valor;//Valor do produto
    char descricaop[1000];//Descricao do produto
    int quantidade;//Quantidade de produto
    char status;// a = Em estoque / x = Sem estoque
};

typedef struct gestao Gestao;  //Poderia ter usado outra nomeclatura para essa struct, porem percebi tarde, preferi deixar assim mesmo, mas se refere a gestao de produtos




void tela_menu_gestao_produtos();
    void cadast_produto(void);
    void lista_produto(void);
    void exibir_produto(Gestao*);
    void exibir_produtort(Gestao*);
    void edit_produto(void);
    void delet_produto(void);
    void pesquisa_produto(void);
    Gestao* busca_produto(int*);
    void regravar_produto(Gestao*);
    int proximo_codigop(void);
    void exibir_produtort_nvc(Gestao*, int);

