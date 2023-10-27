

struct cliente{
    char codigoc[10];
    char cpfc[12]; 
    char nomec[50];
    char data_nascimentoc[11]; // "dd/mm/aaaa"
    char telefonec[12];
};

typedef struct cliente Cliente;


//Assinaturas modulo clientes
void tela_menu_cliente();
    void cadast_cliente(Cliente*);
    void exibir_cliente(Cliente*);
    void edit_cliente(void);
    void delet_cliente(void);
