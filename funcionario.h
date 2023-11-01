
struct funcionario{
    char codigof[10];
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
    void edit_funcionario(void);
    void delet_funcionario(void);

