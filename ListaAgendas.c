#include "ListaAgendas.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

void AgendaEmptyList(ListaAgendas * lista)
{
    lista->primeiro = (AApontador) malloc(sizeof (ACelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

Agenda FindById(ListaAgendas *lista, char id[10]) {
    AApontador aux;
    Agenda agenda;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if(!strcmp(aux->agenda.id, id)) {
            agenda = aux->agenda;
            return agenda;
        }
        aux = aux->prox;
    }
}

int CheckId(ListaAgendas *lista, char id[10]) {
    AApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL) {

        if (!strcmp(aux->agenda.id, id)) {
            return 1;
        }

        aux = aux->prox;
    }
    return 0;
}

void AgendaListInsert(ListaAgendas * lista, Agenda * agenda) {
    lista->ultimo->prox = (AApontador) malloc(sizeof(ACelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->agenda = *agenda;
    lista->ultimo->prox = NULL;
}

void AgendaListPrint(ListaAgendas* lista)
{
    AApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        PrintAgenda(aux->agenda);
        aux = aux->prox;
    }
}