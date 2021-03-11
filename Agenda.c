#include "Agenda.h"
#include "string.h"
#include "stdio.h"

void InicializarAgenda(Agenda* agenda, ListaCompromissos* lista, char id_prof[10], char nome[80], int ano) {
    agenda->ano = ano;
    strcpy(agenda->id_prof, id_prof);
    strcpy(agenda->nome, nome);
    agenda->lista = *lista;
}

void PrintAgenda(Agenda agenda) {
    printf("ID: %s\n", agenda.id_prof);
    printf("Professor: %s\n", agenda.nome);
    printf("Ano: %d\n", agenda.ano);
    CompListPrint(&agenda.lista);
}