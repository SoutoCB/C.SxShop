//Destinado as funções de validações
#include <stdio.h>
#include <stdlib.h>
#include "utilits.h"
#include <ctype.h>
#include <string.h>
// Apoio do ChatGPT, um modelo de linguagem da OpenAI, https://chat.openai.com/
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

///////////////////////////////////////////////////////
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

    if (codigo[0] == '\0') {
        printf("Codigo invalido.\n");
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


int valida_cpf(char *cpf){                //GRANDE PARTE RETIRADA DE https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
    
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF invalido.1\n");
            printf("Digite novamente: \n");
            return 0;
        }
    }

    if (isspace(cpf[0]) || isspace(cpf[strlen(cpf) - 1])) {
        printf("CPF invalido, iniciou ou terminou com espaco.\n");
        printf("Digite novamente: \n");
        return 0;
    }

    if (cpf[0] == '\0') {
        printf("CPF invalido.2\n");
        printf("Digite novamente: \n");
        return 0;
    }

    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11){
        printf("CPF invalido.3\n");
        printf("Digite novamente: \n");
        return 0;
    }
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0)) {
        printf("CPF invalido.4");
        printf("Digite novamente: \n");
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    }
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1){
            printf("CPF invalido.1\n");
            printf("Digite novamente: \n");
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        }
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2){
            printf("CPF invalido.1\n");
            printf("Digite novamente: \n");
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
        }
    }
    
    return 1;
    
}
