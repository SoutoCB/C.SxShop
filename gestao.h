
struct gestao{
    char codigop[10];
    char nomep[50];
    float valor;
    char descricaop[1000];
    float quantidade;
    char status;
};

typedef struct gestao Gestao;




void tela_menu_gestao_produtos();
    void cadast_produto(void);
    void lista_produto(void);
    void exibir_produto(Gestao*);
    void edit_produto(void);
    void delet_produto(void);


