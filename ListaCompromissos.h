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

void EmptyList(ListaCompromissos* lista);

int IsListEmpty(ListaCompromissos* lista);

void ListInsert(ListaCompromissos* lista, Compromisso* compromisso);

int ListRetrieve(ListaCompromissos* lista, Compromisso* compromisso);

void ListPrint(ListaCompromissos* lista);
