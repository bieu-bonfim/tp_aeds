#include "Compromisso.h"

typedef struct CCelula* CApontador;

// Define um tipo de estrutura "CCelula"
typedef struct CCelula {
    Compromisso compromisso;
    struct CCelula* prox;
} CCelula;

// Define um tipo de estrutura "ListaCompromissos"
typedef struct {
    CApontador primeiro;
    CApontador ultimo;
} ListaCompromissos;

// Função para limpar a memória alocada na Listade Compromissos
void CompEmptyList(ListaCompromissos* lista);

// Função para inserir um compromisso numa lista de compromissos
void CompListInsert(ListaCompromissos* lista, Compromisso* compromisso);

// Função para printar uma lista de compromissos
void CompListPrint(ListaCompromissos* lista);

// Função para encontrar um compromisso por seu id único
Compromisso* FindCompById(ListaCompromissos *listaCompromissos, int id);

// Verificar se o compromisso com esse ID existe
int CheckCompId(ListaCompromissos *listaCompromissos, int id);

// Remove um compromisso de uma lista de compromissos por seu id único
void RemoveComp(ListaCompromissos *listaCompromissos, int id);

// Imprime todos os compromissos de uma agenda ordenados por prioridade
// 5 ao 1
void PrintByPriority(ListaCompromissos *lista);

// Retorna a quantidade de compromissos dentro de uma agenda
int ReturnNCompromissos(ListaCompromissos *lista);
