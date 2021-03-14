#include "Compromisso.h"
typedef struct CCelula* CApontador;
typedef struct CCelula {
    Compromisso compromisso;
    struct CCelula* prox;
} CCelula;

typedef struct {
    CApontador primeiro;
    CApontador ultimo;
} ListaCompromissos;

void CompEmptyList(ListaCompromissos* lista);

int CompIsListEmpty(ListaCompromissos* lista);

void CompListInsert(ListaCompromissos* lista, Compromisso* compromisso);

int CompListRetrieve(ListaCompromissos* lista, Compromisso* compromisso);

void CompListPrint(ListaCompromissos* lista);

void FindCompById(int id);
