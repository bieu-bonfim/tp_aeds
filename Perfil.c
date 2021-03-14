#include "Perfil.h"
#include "string.h"
#include "stdio.h"

void InicializarPerfil(Perfil *perfil, char email[80], int ano, int mes, int dia, Endereco endereco) {
    strcpy((*perfil).email, email);
    (*perfil).ano = ano;
    (*perfil).mes = mes;
    (*perfil).dia = dia;
    (*perfil).endereco = endereco;
}

void PrintPerfil(Perfil perfil) {
    printf("Perfil\n");
    printf("Email: %s\n", perfil.email);
    printf("Aniversario: %d/%d/%d\n", perfil.dia, perfil.mes, perfil.ano);
    PrintEndereco(perfil.endereco);
}

void SetEmail(Perfil *perfil, char email[80]) {
    strcpy((*perfil).email, email);
}

void SetAniversario(Perfil *perfil, int ano, int mes, int dia) {
    perfil->ano = ano;
    perfil->mes = mes;
    perfil->dia = dia;
}