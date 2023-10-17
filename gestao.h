void tela_menu_gestao_produtos();
    void cadast_produto(void);
    void exibir_produto(void);
    void edit_produto(void);
    void delet_produto(void);

struct gestao{
    char codigop[10];
    char nomep[50];
    float valor;
    char descricaop[1000];
    float quantidade;
};

typedef struct gestao Gestao;
