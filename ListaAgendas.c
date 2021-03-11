#include "ListaAgendas.h"
#include <stdlib.h>
#include "stdio.h"

int FindById(ListaAgendas *lista, Agenda *agenda, char id[10]) {
    AApontador aux;
    aux = lista->primeiro;
    while (aux != NULL)
    {
        if(id == aux->agenda.id_prof) {
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

        if(id == aux->agenda.id_prof) {
            return 1;
        }

        aux = aux->prox;

    }
    return 0;
}