#include "Agenda.h"
#include "string.h"
#include "stdio.h"

void InicializarAgenda(Agenda* agenda, ListaCompromissos* lista, char id_prof[10], char nome[80], int ano) {
    agenda->ano = ano;
    strcpy(agenda->id, id_prof);
    strcpy(agenda->nome, nome);
    agenda->compromissos = *lista;
}

void PrintAgenda(Agenda agenda) {
    printf("\n\nID: %s\n", agenda.id);
    printf("Professor: %s\n", agenda.nome);
    printf("Ano: %d\n", agenda.ano);
}

void NFromData(Agenda *agenda, int ano, int mes, int dia) {
    CApontador aux;
    aux = agenda->compromissos.primeiro->prox;
    PrintAgenda(*agenda);
    int cont = 0;
    while (aux != NULL) {

        if (aux->compromisso.ano >= ano && aux->compromisso.mes >= mes && aux->compromisso.dia >= dia) {
            cont++;
        }

        aux = aux->prox;
    }
    printf("\nNumero de compromissos apos %d/%d/%d: %d", dia, mes, ano, cont);
}

void CreatePerfil(Agenda *agenda, Perfil perfil) {
    agenda->perfil = perfil;
}
