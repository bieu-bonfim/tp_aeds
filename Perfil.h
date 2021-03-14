#include "Endereco.h"

typedef struct {
    char email[80];
    int ano, mes, dia;
    Endereco endereco;
} Perfil;

void InicializarPerfil(Perfil *perfil, char email[80], int ano, int mes, int dia, Endereco endereco);

void PrintPerfil(Perfil perfil);

void SetEmail(Perfil *perfil, char email[80]);

void SetAniversario(Perfil *perfil, int ano, int mes, int dia);

