//Destinada a futuras adicoes
                                    // Semana 10 slides Flavius
//struct cliente{
//  char codigoc[10];
//  char cpfc[12]; 
//  char nomec[50];
//  char data_nascimentoc[11]; // "dd/mm/aaaa"
//  char telefonec[12];
//};
//Exemplo de uso          // *Posso utilizar essa parte abaixo como um ponteiro, para o uso de malloc
//struct cliente (codigo do cliente ou nome, alguma coisa que represente o cliente) {
//  char codigoc[10];  //Ex: 123
//  char cpfc[12];     //Ex: 000.111.222-33
//  char nomec[50];    //Ex: Fulano
//  char data_nascimentoc[11]; // "dd/mm/aaaa"
//  char telefonec[12]; //Ex: 84888223344
//};

//typedef struct cliente Cliente;    //Para facilita o uso da struct

//Cliente.fulando
//fulando.codigoc
//fulando.cpfc
//fulano.nomec     
//fulano.data_nascimentoc
//fulano.telefone

//typedef struct funcionario Funcionario;

//Funcionario.fulando
//fulano.codigof
//fulano.cpff
//fulano.nomef     
//fulano.data_nascimentof
//fulano.telefonef
//fulando.funcao
//fulano.salario




//Pesquisar para ver se posso usar os mesmos nomes das variaveis dentro do struct, em outro struct 

//Uso de malloc, para otimizacao de espaco
                            

                                  // Semana 9 slides Flavius
// Tabela ASCII

//Algumas funções da biblioteca <string.h>
// Copia o conteúdo da string2 na string1
//char *strcpy (char *dest, const char *src);

// Copia os n primeiros caracteres da string2 na string1
//char *strncpy(char *string1, const char *string2, size_t n);

// Concatena a string2 no final da string1
//char *strcat(char *string1, const char *string2);

// Concatena n caracteres da string2 no final da string1
//char *strncat(char *string1, const char *string2, size_t n);

// Compara duas strings e determina a ordem (alfabética) das duas
//int strcmp(const char *string1, const char *string2);

// Compara os n primeiros caracteres de duas strings
//int strncmp(const char *string1, char *string2, size_t n);

// Retorna o tamanho de uma string
//int strlen(const char *string);