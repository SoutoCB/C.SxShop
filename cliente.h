

struct cliente{
    char codigoc[10];
    char cpfc[12]; 
    char nomec[50];
    char data_nascimentoc[11]; // "dd/mm/aaaa"
    char telefonec[12];
    char status;
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
