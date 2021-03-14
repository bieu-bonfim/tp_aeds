#include "ListaCompromissos.h"

typedef struct {
    ListaCompromissos compromissos;
    char id[10];
    char nome[80];
    int ano;
} Agenda;

void InicializarAgenda(Agenda* agenda, ListaCompromissos* lista, char id[10], char nome[80], int ano);

void PrintAgenda(Agenda agenda);


