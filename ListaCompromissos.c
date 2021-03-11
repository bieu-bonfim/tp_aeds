#include "ListaCompromissos.h"
#include <stdlib.h>

void EmptyList(ListaCompromissos* lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

int IsListEmpty(ListaCompromissos* lista)
{
    return (lista->ultimo == NULL);
}

void ListInsert(ListaCompromissos* lista, Compromisso* compromisso)
{
    if (lista->ultimo == NULL) {
        lista->ultimo = (CApontador) malloc(sizeof (CCelula));
        lista->primeiro = lista->ultimo;
    } else {
        lista->ultimo->prox = (CApontador) malloc(sizeof (CCelula));
        lista->ultimo = lista->ultimo->prox;
    }
    lista->ultimo->compromisso = *compromisso;
    lista->ultimo->prox = NULL;
}

int ListRetrieve(ListaCompromissos* lista, Compromisso* compromisso)
{
    CCelula* pAux;
    if (IsListEmpty(lista))
        return 0;
    *compromisso = lista->primeiro->compromisso;
    pAux = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    free(pAux);
    if (lista->primeiro == NULL)
        lista->ultimo = NULL;
    return 1;
}

void ListPrint(ListaCompromissos* lista)
{
    CApontador aux;
    aux = lista->primeiro;
    while (aux != NULL)
    {
        PrintCompromisso(aux->compromisso);
        aux = aux->prox;
    }
}