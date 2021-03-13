#include "ListaCompromissos.h"
#include <stdlib.h>

void CompEmptyList(ListaCompromissos* lista)
{
    lista->primeiro = (CApontador) malloc(sizeof (CCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int CompIsListEmpty(ListaCompromissos* lista)
{
    return (lista->ultimo == lista->primeiro);
}

void CompListInsert(ListaCompromissos* lista, Compromisso* compromisso)
{
    lista->ultimo->prox = (CApontador) malloc(sizeof(CCelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->compromisso = *compromisso;
    lista->ultimo->prox = NULL;
}

int CompListRetrieve(ListaCompromissos* lista, Compromisso* compromisso)
{
    CCelula* pAux;
    if (CompIsListEmpty(lista))
        return 0;
    *compromisso = lista->primeiro->prox->compromisso;
    pAux = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    free(pAux);
    return 1;
}

void CompListPrint(ListaCompromissos* lista)
{
    CApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        PrintCompromisso(aux->compromisso);
        aux = aux->prox;
    }
}