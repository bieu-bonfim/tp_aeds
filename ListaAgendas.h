#include "Agenda.h"
// Define-se um tipo de estrutura ACelula (Célula que contém uma agenda)
typedef struct ACelula* AApontador;
typedef struct ACelula {
    Agenda agenda;
    struct ACelula* prox;
} ACelula;

// Define-se uma estrutura do tipo ListaAgendas (lista encadeada de agendas)
typedef struct {
    AApontador primeiro;
    AApontador ultimo;
} ListaAgendas;

// Função para limpar a memória alocada na lista de Agendas
void AgendaEmptyList(ListaAgendas * lista);

// Função para encontrar a agenda do professor pelo id
Agenda FindById(ListaAgendas *lista, char id[10]);

// Função para checar se o novo id inserido já existe para outro professor
int CheckId(ListaAgendas *lista, char id[10]);

// Função para inserir uma nova agenda na Lista de Agendas
void AgendaListInsert(ListaAgendas * lista, Agenda * agenda);

// Função para printar a lista de agendas (testes)
void AgendaListPrint(ListaAgendas * lista);

// Update na agenda para adicionar perfil
void UpdateAgenda(ListaAgendas *listaAgendas, Agenda *agenda, char id[10]);

