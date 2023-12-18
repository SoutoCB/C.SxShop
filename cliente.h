

struct cliente{
    int codigoc; //Codigo do cliente
    char cpfc[12]; //Cpf do cliente
    char nomec[50];//Nome do cliente
    char data_nascimentoc[11]; // "dd/mm/aaaa"
    char telefonec[12];//Telefone do cliente
    char status;  // x = deletado / a = ativo
};

typedef struct cliente Cliente;


//Assinaturas modulo clientes
void tela_menu_cliente();
    void cadast_cliente(void);
    void exibir_cliente(Cliente*);
    void edit_cliente(void);
    void delet_cliente(void);
    void lista_cliente(void);
    void pesquisa_cliente(void);
    Cliente* busca_cliente(int*);
    Cliente* busca_clientecpf(char*);
    void regravar_cliente(Cliente*);
    int proximo_codigoc(void);
    int verifica_cpfc(char*);
    int verifica_cpfc_existe(char*);
    void exibir_clientert(Cliente*);
    void exibir_clientert_ncc(Cliente*, int);