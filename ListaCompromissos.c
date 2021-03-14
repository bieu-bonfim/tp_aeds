#include "ListaCompromissos.h"
#include <stdlib.h>

void CompEmptyList(ListaCompromissos* lista)
{
    lista->primeiro = (CApontador) malloc(sizeof (CCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

void CompListInsert(ListaCompromissos* lista, Compromisso* compromisso)
{
    lista->ultimo->prox = (CApontador) malloc(sizeof(CCelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->compromisso = *compromisso;
    lista->ultimo->prox = NULL;
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

void PrintByData(ListaCompromissos *lista, int ano, int mes, int dia) {
    CApontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL) {

        if (aux->compromisso.ano >= ano && aux->compromisso.mes >= mes && aux->compromisso.dia >= dia) {
            PrintCompromisso(aux->compromisso);
        }

        aux = aux->prox;
    }
}

void PrintByPriority(ListaCompromissos *lista) {
    CApontador aux;
    Compromisso p1[30], p2[30], p3[30], p4[30], p5[30];
    int cont1 = -1, cont2 = -1, cont3 = -1, cont4 = -1, cont5 = -1;
    aux = lista->primeiro->prox;
    while (aux != NULL) {

        if (aux->compromisso.prioridade == 1) {
            cont1++;
            p1[cont1] = aux->compromisso;
        } else if (aux->compromisso.prioridade == 2) {
            cont2++;
            p2[cont2] = aux->compromisso;
        } else if (aux->compromisso.prioridade == 3) {
            cont3++;
            p3[cont3] = aux->compromisso;
        } else if (aux->compromisso.prioridade == 4) {
            cont4++;
            p4[cont4] = aux->compromisso;
        } else if (aux->compromisso.prioridade == 5) {
            cont5++;
            p5[cont5] = aux->compromisso;
        }

        aux = aux->prox;
    }
    while (cont5 >= 0) {
        PrintCompromisso(p5[cont5]);
        cont5--;
    }
    while (cont4 >= 0) {
        PrintCompromisso(p4[cont4]);
        cont4--;
    }
    while (cont3 >= 0) {
        PrintCompromisso(p3[cont3]);
        cont3--;
    }
    while (cont2 >= 0) {
        PrintCompromisso(p2[cont2]);
        cont2--;
    }
    while (cont1 >= 0) {
        PrintCompromisso(p1[cont1]);
        cont1--;
    }
}

int ReturnNCompromissos(ListaCompromissos *lista) {
    CApontador aux;
    aux = lista->primeiro->prox;
    int cont = 0;
    while (aux != NULL) {

        cont++;

        aux = aux->prox;
    }
    return cont;
}