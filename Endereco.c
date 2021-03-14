#include "string.h"
#include "stdio.h"
#include "Endereco.h"

void InicializarEndereco(Endereco* endereco, char rua[30], int num, int cep, char bairro[30], char cidade[30]) {
    strcpy((*endereco).bairro, bairro);
    strcpy((*endereco).cidade, cidade);
    strcpy((*endereco).rua, rua);
    (*endereco).numero = num;
    (*endereco).cep = cep;
}

void PrintEndereco(Endereco endereco) {
    printf("Endereco\n");
    printf("Rua: %s\n", endereco.rua);
    printf("Numero: %d\n", endereco.numero);
    printf("CEP: %d\n", endereco.cep);
    printf("Bairro: %s\n", endereco.bairro);
    printf("Cidade: %s\n", endereco.cidade);
}