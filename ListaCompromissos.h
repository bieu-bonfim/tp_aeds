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

void CompListInsert(ListaCompromissos* lista, Compromisso* compromisso);

void CompListPrint(ListaCompromissos* lista);

Compromisso* FindCompById(ListaCompromissos *listaCompromissos, int id);

int CheckCompId(ListaCompromissos *listaCompromissos, int id);

void RemoveComp(ListaCompromissos *listaCompromissos, int id);

void PrintByData(ListaCompromissos *lista, int ano, int mes, int dia);

void PrintByPriority(ListaCompromissos *lista);

int ReturnNCompromissos(ListaCompromissos *lista);
