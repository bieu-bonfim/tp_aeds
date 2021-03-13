#include "Agenda.h"
typedef struct ACelula* AApontador;
typedef struct ACelula {
    Agenda agenda;
    struct ACelula* prox;
} ACelula;

typedef struct {
    AApontador primeiro;
    AApontador ultimo;
} ListaAgendas;

void AgendaEmptyList(ListaAgendas * lista);

Agenda FindById(ListaAgendas *lista, char id[10]);

int CheckId(ListaAgendas *lista, char id[10]);

void AgendaListInsert(ListaAgendas * lista, Agenda * agenda);

void AgendaListPrint(ListaAgendas * lista);
