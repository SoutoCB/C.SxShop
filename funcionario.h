
struct funcionario{
    int codigof;//Codigo do funcionario
    char cpff[12];//Cpf do funcionario
    char nomef[50];//Nome do funcionario
    char data_nascimentof[11];//DD/MM/AAAA Data de nascimento do funcionario
    char telefonef[12];//Telefone do funcionario
    char funcao[50];//Funcao do funcionario
    float salario;//Salario do funcionario
    char status;// a = Ativo / x = Inativo
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
