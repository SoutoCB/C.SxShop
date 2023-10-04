//Destinado as funções de validações
#include <stdio.h>
#include <stdlib.h>
#include "utilits.h"
#include <ctype.h>
#include <string.h>
// Apoio do ChatGPT, um modelo de linguagem da OpenAI, https://chat.openai.com/
void le_nome(char *nome){
    do{
        fgets(nome, 50, stdin);
        if (nome[strlen(nome) - 1] == '\n') {
        nome[strlen(nome) - 1] = '\0';
        }
   }while(!valida_nome(nome));
}


int valida_nome(char *nome){
    char letras_acentuadas[] = "áéíóúàèìòùãõâêîôûç";
    if (strlen(nome)<2){
        printf("Nome invalido.\n");
        printf("Digite novamente: \n");
        return 0;
    }
    if (nome[0] == '\0') {
        printf("Nome invalido.\n");
        printf("Digite novamente: \n");
        return 0;
    }
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '\n' && nome[i] != '\r' && nome[i] != '\t'
            && strchr(letras_acentuadas, nome[i]) == NULL) {
            printf("Nome invalido.\n");
            printf("Digite novamente: \n");
            return 0;
        }
    }
    if (isspace(nome[0]) || isspace(nome[strlen(nome) - 1])) {
        printf("Nome invalido, iniciou ou terminou com espaco.\n");
        printf("Digite novamente: \n");
        return 0;
    }
    return 1;
}

///////////////////////////////////////////////////////////////////////////////////////
void le_codigo(char *codigo){
    do{
        fgets(codigo, 10, stdin);
        if (codigo[strlen(codigo) - 1] == '\n') {
        codigo[strlen(codigo) - 1] = '\0';
        }
   }while(!valida_codigo(codigo));
}


int valida_codigo(char *codigo){
    for (int i = 0; codigo[i] != '\0'; i++) {
        if (!isdigit(codigo[i])) {
            printf("Codigo invalido\n");
            printf("Digite novamente: \n");
            return 0;
        }
    }

    if (isspace(codigo[0]) || isspace(codigo[strlen(codigo) - 1])) {
        printf("Codigo invalido, iniciou ou terminou com espaco.\n");
        printf("Digite novamente: \n");
        return 0;
    }

    return 1;
}

//////////////////////////////////////////////////////////////////////////////
void le_cpf(char *cpf){
    do{
        fgets(cpf, 12, stdin);
        if (cpf[strlen(cpf) - 1] == '\n') {
        cpf[strlen(cpf) - 1] = '\0';
        }
   }while(!valida_cpf(cpf));
}


int valida_cpf(char *cpf){
    
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF invalido.2\n");
            printf("Digite novamente: \n");
            return 0;
        }
    }

    if (isspace(cpf[0]) || isspace(cpf[strlen(cpf) - 1])) {
        printf("CPF invalido, iniciou ou terminou com espaco.\n");
        printf("Digite novamente: \n");
        return 0;
    }

    return 1;
    
}
