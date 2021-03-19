#include "ListaCompromissos.h"
#include "Perfil.h"

// Define-se um tipo de estrutura "Agenda"
typedef struct {
    ListaCompromissos compromissos;
    char id[10];
    char nome[80];
    Perfil perfil;
    int ano;
} Agenda;

// Inicializa uma agenda e a insere na lista de agendas
void InicializarAgenda(Agenda* agenda, ListaCompromissos* lista, char id[10], char nome[80], int ano);

// Imprime os dados da Agenda
void PrintAgenda(Agenda agenda);

// Retorna os dados da agenda e quantos compromissos há
// após a data informada
void NFromData(Agenda *agenda, int ano, int mes, int dia);

// Cria um perfil para o professor
void CreatePerfil(Agenda *agenda, Perfil perfil);