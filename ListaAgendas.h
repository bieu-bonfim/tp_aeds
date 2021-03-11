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

int FindById(ListaAgendas *lista, Agenda *agenda, char id[10]);

int CheckId(ListaAgendas *lista, char id[10]);