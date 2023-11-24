//Destinada a futuras adicoes

//Uso de malloc, para otimizacao de espaco

//Lembrar de sempre testar no ambiente linux, Replit.
//replit:
//gcc -Wall *.h -c
//gcc -Wall *.c -c 
//gcc -Wall *.c -o testec
//./testec

//Colocar para exibir o cadastros excluidos ou inativos, principalmente nos relatorios.
//Opcao, caso o cpf já tenha sido cadastrado antes, de poder recuperar cadastro
//Exibir os produtos esgotados no menu de gestão, como um aviso
//Reajusta quando escreve as resposta, para responder do lado da pergunta
//Filtro envolvendo 3 modulos
//Colocar filtro de ordem alfabetica

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