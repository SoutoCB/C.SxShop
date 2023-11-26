
struct funcionario{
    int codigof;
    char cpff[12];
    char nomef[50];
    char data_nascimentof[11];
    char telefonef[12];
    char funcao[50];
    float salario;
    char status;
};

typedef struct funcionario Funcionario;




void tela_menu_funcionarios();
    void lista_funcionario(void);
    void cadast_funcionario(void);
    void exibir_funcionario(Funcionario*);
    void exibir_funcionariort(Funcionario*);
    void exibir_funcionariort_nvc(Funcionario*, int);
    void edit_funcionario(void);
    void delet_funcionario(void);
    void pesquisa_funcionario(void);
    Funcionario* busca_funcionario(int*);
    Funcionario* busca_funcionariocpf(char*);
    void regravar_funcionario(Funcionario*);
    int proximo_codigof(void);
    int verifica_cpff(char*);
