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

Compromisso* FindCompById(ListaCompromissos *listaCompromissos, int id) {
    CApontador aux;
    Compromisso *compromisso;
    aux = listaCompromissos->primeiro->prox;
    while (aux != NULL)
    {
        if(id == aux->compromisso.id) {
            compromisso = &aux->compromisso;
            return compromisso;
        }
        aux = aux->prox;
    }
}

int CheckCompId(ListaCompromissos *listaCompromissos, int id) {
    CApontador aux;
    aux = listaCompromissos->primeiro->prox;
    while (aux != NULL) {

        if (id == aux->compromisso.id) {
            return 1;
        }

        aux = aux->prox;
    }
    return 0;
}

void RemoveComp(ListaCompromissos *listaCompromissos, int id) {
    CCelula* celAux;
    CApontador apoAux;
    Compromisso *compromisso;
    int cont1 = 0, cont2 = 0;
    apoAux = listaCompromissos->primeiro->prox;

    while (apoAux != NULL) {

        if (id == apoAux->compromisso.id) {
            break;
        }
        cont1++;
        apoAux = apoAux->prox;
    }
    apoAux = listaCompromissos->primeiro;
    while (cont2 <= cont1) {
        if (cont1 == cont2) {
            if (apoAux->prox->prox == NULL) {
                celAux = apoAux->prox;
                apoAux->prox = NULL;
            } else {
                celAux = apoAux->prox;
                apoAux->prox = apoAux->prox->prox;
            }
        }
        cont2++;
        apoAux = apoAux->prox;
    }
    free(celAux);
}