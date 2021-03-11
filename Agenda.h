#include "ListaCompromissos.h"

typedef struct {
    ListaCompromissos compromissos;
    char id[10];
    char nome[80];
    int ano;
} Agenda;

void InicializarAgenda(Agenda* agenda, ListaCompromissos* lista, char id[10], char nome[80], int ano);

void RetrieveAgenda(Agenda agenda, int ano, int mes, int dia);

void InsertCompromisso(Agenda* agenda, int prioridade, int ano, int mes, int dia,
                       int hora, int duracao, char descricao[100]);

void RemoveCompromisso(long id_compromisso);

void PrintAgenda(Agenda agenda);

int ReturnNCompromissos(Agenda agenda);

