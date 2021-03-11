#include "Compromisso.h"
#include "string.h"
#include "math.h"
#include "stdio.h"

int InicializarCompromisso(Compromisso* compromisso, int id, int prioridade,
                           int dia, int mes, int ano, int hora,
                           int duracao, char descricao[100]) {

    compromisso->prioridade = prioridade;
    compromisso->dia = dia;
    compromisso->mes = mes;
    compromisso->ano = ano;
    compromisso->hora = hora;
    compromisso->duracao = duracao;
    strcpy(compromisso->descricao, descricao);
    compromisso->id = id;

    return compromisso->id;
}

void SetPrioridade(Compromisso* compromisso, int prioridade) {
    compromisso->prioridade = prioridade;
}

void GetPrioridade(Compromisso compromisso, int *prioridade) {
    (*prioridade) = compromisso.prioridade;
}

int CheckConflict(Compromisso compromisso1, Compromisso compromisso2) {
    int inicio1, inicio2, fim1, fim2;
    if (compromisso1.ano == compromisso2.ano && compromisso1.mes == compromisso2.mes && compromisso1.dia == compromisso2.dia) {
        inicio1 = compromisso1.hora * 60;
        inicio2 = compromisso2.hora * 60;
        fim1 = inicio1 + compromisso1.duracao;
        fim2 = inicio2 + compromisso2.duracao;
        if (inicio1 > inicio2 && inicio1 < fim2) {
            return 1;
        }
        if (inicio2 > inicio1 && inicio2 < fim1) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void PrintCompromisso(Compromisso compromisso) {
    printf("\nId: %d\n", compromisso.id);
    printf("Prioridade: %d\n", compromisso.prioridade);
    printf("Data: %d/%d/%d\n", compromisso.dia, compromisso.mes, compromisso.ano);
    printf("Hora: %d\n", compromisso.hora);
    printf("Duracao: %d\n", compromisso.duracao);
    printf("Descricao: %s\n", compromisso.descricao);
}