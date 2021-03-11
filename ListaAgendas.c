#include "ListaAgendas.h"
#include <stdlib.h>
#include "stdio.h"

int FindById(ListaAgendas *lista, Agenda *agenda, char id[10]) {
    AApontador aux;
    aux = lista->primeiro;
    while (aux != NULL)
    {
        if(id[10] == *aux->agenda.id) {
            agenda = &aux->agenda;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int CheckId(ListaAgendas *lista, char id[10]) {

    AApontador aux;
    aux = lista->primeiro;

    while (aux != NULL)
    {

        if(id == aux->agenda.id) {
            return 1;
        }

        aux = aux->prox;

    }
    return 0;
}

void AgendaListInsert(ListaAgendas * lista, Agenda * agenda) {
    if (lista->ultimo == NULL) {
        lista->ultimo = (AApontador) malloc(sizeof (ACelula));
        lista->primeiro = lista->ultimo;
    } else {
        lista->ultimo->prox = (AApontador) malloc(sizeof (ACelula));
        lista->ultimo = lista->ultimo->prox;
    }
    lista->ultimo->agenda = *agenda;
    lista->ultimo->prox = NULL;
}

void AgendaListPrint(ListaAgendas* lista)
{
    AApontador aux;
    aux = lista->primeiro;
    while (aux != NULL)
    {
        PrintAgenda(aux->agenda);
        aux = aux->prox;
    }
}