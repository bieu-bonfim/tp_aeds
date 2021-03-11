#include <stdio.h>
#include <stdlib.h>
#include "ListaAgendas.h"

int tam = 0;

void TesteCompromisso();

void ReadFile();
void MenuInicial(ListaAgendas *listaAgendas);
void MenuInterativo(ListaAgendas *listaAgendas);
void MenuLogin (ListaAgendas *listaAgendas);
void MenuCreateAgenda (ListaAgendas *listaAgendas);

void TestCompromisso() {
    Compromisso *compromisso1;

    compromisso1 = (Compromisso*) malloc(sizeof(Compromisso));

    int prioridade, ano, mes, dia, hora, duracao;
    char descricao[100];

    ListaCompromissos *lista1;

    lista1 = (ListaCompromissos*) malloc(sizeof(ListaCompromissos));

    printf("\nDigite uma descricao:  ");
    scanf("%[^\n]%*c", descricao);
    printf("\nDigite uma prioridade:  ");
    scanf("%d", &prioridade);
    printf("\nDigite uma ano:  ");
    scanf("%d", &ano);
    printf("\nDigite uma mes:  ");
    scanf("%d", &mes);
    printf("\nDigite uma dia:  ");
    scanf("%d", &dia);
    printf("\nDigite uma hora:  ");
    scanf("%d", &hora);
    printf("\nDigite uma duracao:  ");
    scanf("%d", &duracao);

    tam++;
    InicializarCompromisso(compromisso1, tam, prioridade, dia, mes, ano, hora, duracao, descricao);
    ListInsert(lista1, compromisso1);

    ListPrint(lista1);

    int *prioridade_teste;
    int new_prioridade;

    printf("\nDigite a nova prioridade: ");
    scanf("%i", &new_prioridade);

    prioridade_teste = (int*) malloc(sizeof(int));

    GetPrioridade(*compromisso1, prioridade_teste);

    printf("Prioridade antiga: %d\n", *prioridade_teste);

    SetPrioridade(compromisso1, new_prioridade);

    GetPrioridade(*compromisso1, prioridade_teste);

    printf("Prioridade nova: %d\n", *prioridade_teste);
}

void TestAgenda() {
    Agenda *agenda1;

    agenda1 = (Agenda*) malloc(sizeof(Agenda));

    int prioridade, ano, mes, dia, hora, duracao;
    char descricao[100];

    ListaAgendas *lista1;

    lista1 = (ListaAgendas*) malloc(sizeof(ListaAgendas));

    printf("\nDigite uma descricao:  ");
    scanf("%[^\n]%*c", descricao);
    printf("\nDigite uma prioridade:  ");
    scanf("%d", &prioridade);
    printf("\nDigite uma ano:  ");
    scanf("%d", &ano);
    printf("\nDigite uma mes:  ");
    scanf("%d", &mes);
    printf("\nDigite uma dia:  ");
    scanf("%d", &dia);
    printf("\nDigite uma hora:  ");
    scanf("%d", &hora);
    printf("\nDigite uma duracao:  ");
    scanf("%d", &duracao);

    tam++;
    InicializarCompromisso(compromisso1, tam, prioridade, dia, mes, ano, hora, duracao, descricao);
    ListInsert(lista1, compromisso1);

    ListPrint(lista1);

    int *prioridade_teste;
    int new_prioridade;

    printf("\nDigite a nova prioridade: ");
    scanf("%i", &new_prioridade);

    prioridade_teste = (int*) malloc(sizeof(int));

    GetPrioridade(*compromisso1, prioridade_teste);

    printf("Prioridade antiga: %d\n", *prioridade_teste);

    SetPrioridade(compromisso1, new_prioridade);

    GetPrioridade(*compromisso1, prioridade_teste);

    printf("Prioridade nova: %d\n", *prioridade_teste);
}

void ReadFile () {

}

void MenuInterativo (ListaAgendas *listaAgendas) {
    int opcao;
    printf("\n---------------------------------");
    printf("\n-Voce escolheu o Menu Interativo-");
    printf("\n---------------------------------");

    printf("\n\nEscolha uma das seguintes opcoes:");

    printf("\n\n-> Fazer Login (Digite 1)");
    printf("\n-> Criar Agenda (Digite 2)");
    printf("\n-> Voltar (Digite 0)");

    printf("\n\nOpcao escolhida: ");
    scanf("%d", &opcao);

    if(opcao == 1) {
        MenuLogin(listaAgendas);
    } else if (opcao == 2) {
        MenuCreateAgenda(listaAgendas);
    } else if (opcao == 0) {
        MenuInicial(listaAgendas);
    }
}

void MenuLogin (ListaAgendas *listaAgendas) {
    char id[10];

    Agenda *agenda = (Agenda*) malloc(sizeof (Agenda));

    printf("\n---------------------------------");
    printf("\n- Voce escolheu o Menu de Login -");
    printf("\n---------------------------------");

    printf("\n\nDigite o seu ID de Professor:");

    printf("\n\nID: ");
    scanf("%s", id);

    if (FindById(listaAgendas, agenda, id)) {

    }
}

void MenuCreateAgenda (ListaAgendas *listaAgendas) {
    char id[10], nome[80];
    int ano, opcao;

    Agenda *agenda = (Agenda*) malloc(sizeof (Agenda));
    ListaCompromissos *lista = (ListaCompromissos*) malloc(sizeof (ListaCompromissos));

    printf("\n---------------------------------");
    printf("\n-- Voce escolheu  Criar Agenda --");
    printf("\n---------------------------------");

    printf("\n\nDigite qual sera seu identificador unico: ");
    scanf("%s", id);

    printf("\n\nAgora, digite seu nome: ");
    scanf("%s", nome);

    printf("\n\nAno da agenda: ");
    scanf("%d", &ano);

    if (CheckId(listaAgendas, id)) {
        printf("\n\nO ID informado ja existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu interativo");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuCreateAgenda(listaAgendas);
        } else if (opcao == 0) {
            MenuInterativo(listaAgendas);
        }
    }

    InicializarAgenda(agenda, lista, id, nome, ano);

    printf("\n\nLembre-se, seu ID é: %s", id);

    MenuLogin(listaAgendas);

}

void MenuInicial(ListaAgendas *listaAgendas) {
    int metodo;

    printf("\n-------- Bem vindo(a) ao --------");
    printf("\nSistema de Gerenciamento de Tempo");
    printf("\n---------------------------------");

    printf("\n\nEscolha o metodo de entrada que deseja utilizar: ");
    printf("\n\n-> Interativo (Digite 1)");
    printf("\n-> Arquivo (Digite 2)");

    printf("\n\nMetodo de entrada escolhido: ");
    scanf("%d", &metodo);

    if (metodo == 1) {
        MenuInterativo(listaAgendas);
    } else if (metodo == 2) {
        ReadFile();
    }

}

int main() {

//    ListaAgendas *listaAgendas;
//
//    listaAgendas = (ListaAgendas*) malloc(sizeof (ListaAgendas));
//
//    MenuInicial(listaAgendas);

    TestCompromisso();











    return 0;
}

