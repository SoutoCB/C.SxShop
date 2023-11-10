
struct gestao{
    int codigop;
    char nomep[50];
    float valor;
    char descricaop[1000];
    int quantidade;
    char status;
};

typedef struct gestao Gestao;




void tela_menu_gestao_produtos();
    void cadast_produto(void);
    void lista_produto(void);
    void exibir_produto(Gestao*);
    void edit_produto(void);
    void delet_produto(void);
    void pesquisa_produto(void);
    Gestao* busca_produto(int*);
    void regravar_produto(Gestao*);
    int proximo_codigop(void);


