//Destinado as funções de validações
#include <stdio.h>
#include <stdlib.h>
#include "utilits.h"
#include <ctype.h>
#include <string.h>

int valida_nome(char *nome){
    fgets(nome, 50, stdin);
    if (nome[strlen(nome) - 1] == '\n') {
        nome[strlen(nome) - 1] = '\0';
    }
    if (nome[0] == '\0') {
        printf("Nome invalido.\n");
        printf("Digite novamente: \n");
        return 0;
    }
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && !isspace(nome[i])) {
            printf("Nome invalido.\n");
            printf("Digite novamente: \n");
            return 0;
        }
    }
    if (isspace(nome[0]) || isspace(nome[strlen(nome) - 1])) {
        printf("Nome invalido.\n");
        printf("Digite novamente: \n");
        return 0;
    }
    return 1;
}
