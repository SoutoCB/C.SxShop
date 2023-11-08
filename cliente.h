

struct cliente{
    int codigoc;
    char cpfc[12]; 
    char nomec[50];
    char data_nascimentoc[11]; // "dd/mm/aaaa"
    char telefonec[12];
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
    void recupera_cliente(void);
    int proximo_codigoc(void);
    int verifica_cpfc(char*);
