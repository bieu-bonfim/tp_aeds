#include "Endereco.h"

typedef struct {
    char email[80];
    int ano, mes, dia;
    Endereco endereco;
} Perfil;

// Função que inicializa um perfil
void InicializarPerfil(Perfil *perfil, char email[80], int ano, int mes, int dia, Endereco endereco);

// Função que printa um perfil
void PrintPerfil(Perfil perfil);

// Função para mudar o email de um perfil
void SetEmail(Perfil *perfil, char email[80]);

// Função para mudar o aniversário de um perfil
void SetAniversario(Perfil *perfil, int ano, int mes, int dia);

