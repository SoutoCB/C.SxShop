
//Assinaturas modulo clientes
struct cliente{
    char codigoc[10];
    char cpfc[12]; 
    char nomec[50];
    char data_nascimentoc[11]; // "dd/mm/aaaa"
    char telefonec[12];
};

void tela_menu_cliente();
    void cadast_cliente(void);
    void exibir_cliente(void);
    void edit_cliente(void);
    void delet_cliente(void);