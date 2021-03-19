#include "Perfil.h"
#include "string.h"
#include "stdio.h"

// Inicializa um perfil
void InicializarPerfil(Perfil *perfil, char email[80], int ano, int mes, int dia, Endereco endereco) {
    strcpy((*perfil).email, email);
    (*perfil).ano = ano;
    (*perfil).mes = mes;
    (*perfil).dia = dia;
    (*perfil).endereco = endereco;
}

// Printa os dados do perfil
void PrintPerfil(Perfil perfil) {
    printf("Perfil\n");
    printf("Email: %s\n", perfil.email);
    printf("Aniversario: %d/%d/%d\n", perfil.dia, perfil.mes, perfil.ano);
    PrintEndereco(perfil.endereco);
}

// Altera o Email de um perfil
void SetEmail(Perfil *perfil, char email[80]) {
    strcpy((*perfil).email, email);
}

// Altera a data de um perfil
void SetAniversario(Perfil *perfil, int ano, int mes, int dia) {
    perfil->ano = ano;
    perfil->mes = mes;
    perfil->dia = dia;
}