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
void MenuPrincipal(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuInserirComp(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuRemoverComp(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuAlterarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuRetornarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuPrintarComp(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuPrintAgendaData(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuPrintarAgendaPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuPrintQntCompromissos(Agenda *agenda, ListaAgendas *listaAgendas);
void MenuChecarConflito(Agenda *agenda, ListaAgendas *listaAgendas);

// ------------------------------------------------------------------------ //

void ReadFile () {

}

void MenuInicial(ListaAgendas *listaAgendas) {
    int metodo;

    printf("\n--------- Bem vinde ao ----------");
    printf("\nSistema de Gerenciamento de Tempo");
    printf("\n---------------------------------");

    printf("\n\nEscolha o metodo de entrada que deseja utilizar: ");
    printf("\n\n-> Interativo (Digite 1)");
    printf("\n-> Arquivo (Digite 2)");
    printf("\n-> Sair do Sistema (Digite 0)");

    printf("\n\nMetodo de entrada escolhido: ");
    scanf("%d", &metodo);

    if (metodo == 1) {
        MenuInterativo(listaAgendas);
    } else if (metodo == 2) {
        ReadFile();
    } else if (metodo == 0) {
        system("PAUSE");
    }

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
    int opcao;
    Agenda agenda;

    printf("\n---------------------------------");
    printf("\n- Voce escolheu o Menu de Login -");
    printf("\n---------------------------------");

    printf("\n\nDigite o seu ID de Professor:");

    printf("\n\nID: ");
    scanf("%s", id);

    if (CheckId(listaAgendas, id)) {
        agenda = FindById(listaAgendas, id);
        MenuPrincipal(&agenda, listaAgendas);
    } else {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu interativo");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuLogin(listaAgendas);
        } else if (opcao == 0) {
            MenuInterativo(listaAgendas);
        }
    }
}

void MenuCreateAgenda (ListaAgendas *listaAgendas) {
    char id[10], nome[80];
    int ano, opcao;

    ListaCompromissos lista;
    CompEmptyList(&lista);
    Agenda agenda;

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

        printf("\nOpção escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuCreateAgenda(listaAgendas);
        } else if (opcao == 0) {
            MenuInterativo(listaAgendas);
        }
    }

    InicializarAgenda(&agenda, &lista, id, nome, ano);
    AgendaListInsert(listaAgendas, &agenda);

    printf("\n\nLembre-se, seu ID e: %s", id);
    PrintAgenda(agenda);

    MenuLogin(listaAgendas);

}

void MenuPrincipal(Agenda *agenda, ListaAgendas *listaAgendas) {

    int opcao;

    printf("\n--------- Bem vinde ao ----------");
    printf("\n-------- Menu Principal ---------");
    printf("\n---------------------------------");
    printf("\nAgenda de %s do ano %d\n", agenda->nome, agenda->ano);

    printf("\n\nEscolha uma das seguintes opcoes:");

    printf("\n\n-> Inserir Compromisso (Digite 1)");
    printf("\n-> Remover Compromisso (Digite 2)");
    printf("\n-> Alterar Prioridade (Digite 3)");
    printf("\n-> Retornar Prioridade (Digite 4)");
    printf("\n-> Printar Compromisso pelo ID (Digite 5)");
    printf("\n-> Printar Agenda a Partir de Data (Digite 6)");
    printf("\n-> Printar Agenda por Prioridade (Digite 7)");
    printf("\n-> Printar Quantidade de Compromissos (Digite 8)");
    printf("\n-> Checar Conflito Entre Compromissos (Digite 9)");
    printf("\n-> Fazer Logoff (Digite 0)");

    printf("\n\nOpcao escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            MenuInserirComp(agenda, listaAgendas);
            break;

        case 2:
            MenuRemoverComp(agenda, listaAgendas);
            break;

        case 3:
            MenuAlterarPrioridade(agenda, listaAgendas);
            break;

        case 4:
            MenuRetornarPrioridade(agenda, listaAgendas);
            break;

        case 5:
            MenuPrintarComp(agenda, listaAgendas);
            break;

        case 6:
            MenuPrintAgendaData(agenda, listaAgendas);
            break;

        case 7:
            MenuPrintarAgendaPrioridade(agenda, listaAgendas);
            break;

        case 8:
            MenuPrintQntCompromissos(agenda, listaAgendas);
            break;

        case 9:
            MenuChecarConflito(agenda, listaAgendas);
            break;

        case 0:
            MenuInterativo(listaAgendas);
            break;

        default:
            break;

    }

}

void MenuChecarConflito(Agenda *agenda, ListaAgendas *listaAgendas) {
    int id1, id2, opcao;
    Compromisso *compromisso1, *compromisso2;


    printf("\n-------- Checar Conflito --------");
    printf("\n------ Entre  Compromissos ------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ID do primeiro compromisso: ");
    scanf("%d", &id1);

    if(!CheckCompId(&agenda->compromissos, id1)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuChecarConflito(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    compromisso1 = FindCompById(&agenda->compromissos, id1);

    printf("\n\nDigite o ID do segundo compromisso: ");
    scanf("%d", &id2);


    if(!CheckCompId(&agenda->compromissos, id2)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuChecarConflito(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    compromisso2 = FindCompById(&agenda->compromissos, id2);

    if (CheckConflict(*compromisso1, *compromisso2)) {
        printf("\n\nHa conflito entre os dois compromissos.");
    } else {
        printf("\n\nNao ha conflito entre os dois compromissos.");
    }


    printf("\n\nSe quiser checar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuChecarConflito(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuRemoverComp(Agenda *agenda, ListaAgendas *listaAgendas) {
    int id, opcao;

    printf("\n---------------------------------");
    printf("\n------ Remover Compromisso ------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ID do compromisso que deseja remover: ");
    scanf("%d", &id);

    if(!CheckCompId(&agenda->compromissos, id)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuRemoverComp(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    RemoveComp(&agenda->compromissos, id);

    printf("\nCompromisso removido com sucesso!");
    printf("\nSe quiser remover outro, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuRemoverComp(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuAlterarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas) {
    int id, opcao, prioridade;

    Compromisso *compromisso;

    printf("\n---------------------------------");
    printf("\n------ Alterar  Prioridade ------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ID do compromisso do qual deseja alterar a prioridade: ");
    scanf("%d", &id);

    if(!CheckCompId(&agenda->compromissos, id)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuAlterarPrioridade(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    compromisso = FindCompById(&agenda->compromissos, id);

    printf("\n\nDigite a nova prioridade do compromisso: ");
    scanf("%d", &prioridade);

    SetPrioridade(compromisso, prioridade);

    printf("\nPrioridade alterada com sucesso!");
    printf("\nSe quiser alterar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuAlterarPrioridade(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuRetornarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas) {
    int id, opcao, prioridade;

    Compromisso compromisso;

    printf("\n---------------------------------");
    printf("\n------ Retornar Prioridade ------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ID do compromisso do qual deseja verificar a prioridade: ");
    scanf("%d", &id);

    if(!CheckCompId(&agenda->compromissos, id)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuAlterarPrioridade(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    compromisso = *FindCompById(&agenda->compromissos, id);
    GetPrioridade(compromisso, &prioridade);

    printf("\n\nA prioridade do compromisso e: %d", prioridade);

    printf("\n\nSe quiser alterar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuRetornarPrioridade(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuPrintAgendaData(Agenda *agenda, ListaAgendas *listaAgendas) {
    int ano, mes, dia, opcao;

    printf("\n-------- Imprimir Agenda --------");
    printf("\n------- A Partir  da Data -------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ano:  ");
    scanf("%d", &ano);
    printf("\nDigite o mes:  ");
    scanf("%d", &mes);
    printf("\nDigite o dia:  ");
    scanf("%d", &dia);

    PrintByData(&agenda->compromissos, ano, mes, dia);

    printf("\n\nSe quiser printar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuPrintAgendaData(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuPrintarAgendaPrioridade(Agenda *agenda, ListaAgendas *listaAgendas) {
    int opcao;

    printf("\n-------- Imprimir Agenda --------");
    printf("\n-------- Por  Prioridade --------");
    printf("\n---------------------------------");

    printf("\n");

    PrintByPriority(&agenda->compromissos);

    printf("\n\nSe quiser printar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuPrintarAgendaPrioridade(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }

}

void MenuPrintQntCompromissos(Agenda *agenda, ListaAgendas *listaAgendas) {
    int opcao, qnt;

    printf("\n------ Imprimir Quantidade ------");
    printf("\n-------- De Compromissos --------");
    printf("\n---------------------------------");

    qnt = ReturnNCompromissos(&agenda->compromissos);

    printf("\n\nA quantidade de compromissos em sua agenda e: %d", qnt);

    printf("\n\nSe quiser verificar a quantidade novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuPrintQntCompromissos(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }
}

void MenuPrintarComp(Agenda *agenda, ListaAgendas *listaAgendas) {
    int id, opcao;
    Compromisso compromisso;
    printf("\n----- Imprimir  Compromisso -----");
    printf("\n------------ Por  ID ------------");
    printf("\n---------------------------------");

    printf("\n\nDigite o ID do compromisso que deseja:  ");
    scanf("%d", &id);

    if(!CheckCompId(&agenda->compromissos, id)) {
        printf("\n\nO ID informado nao existe ");
        printf("\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuPrintarComp(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }

    compromisso = *FindCompById(&agenda->compromissos, id);
    PrintCompromisso(compromisso);
    printf("\nSe quiser imprimir outro compromisso, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuPrintarComp(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    }

}

void MenuInserirComp(Agenda *agenda, ListaAgendas *listaAgendas) {
    Compromisso compromisso;

    int prioridade, ano, mes, dia, hora, duracao;
    char descricao[100];

    int result, opcao;

    printf("\n---------------------------------");
    printf("\n------ Inserir Compromisso ------");
    printf("\n---------------------------------");

    printf("\n\nDigite a descricao:  ");
    scanf("%s", descricao);
//    scanf("%[^\n]%*c", descricao);
    printf("\nDigite a prioridade:  ");
    scanf("%d", &prioridade);
    printf("\nDigite o ano:  ");
    scanf("%d", &ano);
    printf("\nDigite o mes:  ");
    scanf("%d", &mes);
    printf("\nDigite o dia:  ");
    scanf("%d", &dia);
    printf("\nDigite a hora:  ");
    scanf("%d", &hora);
    printf("\nDigite a duracao:  ");
    scanf("%d", &duracao);

    int check_hora;

    check_hora = (hora*60)+duracao;

    if (check_hora <= 1439) {
        tam++;
        result = InicializarCompromisso(&compromisso, tam, prioridade, dia, mes, ano, hora, duracao, descricao);
        CompListInsert(&agenda->compromissos, &compromisso);
        printf("\n\nCompromisso inserido com sucesso!");
        printf("\nO ID do compromisso eh: %d", result);
        MenuPrincipal(agenda, listaAgendas);
    }else{
        printf("\n\nA duracao do compromisso excede o dia \npara o qual esta sendo marcado.");
        printf("\n\nDigite 1 para tentar novamente");
        printf("\nDigite 0 para voltar ao menu principal");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            MenuInserirComp(agenda, listaAgendas);
        } else if (opcao == 0) {
            MenuPrincipal(agenda, listaAgendas);
        }
    }
}



int main() {

    ListaAgendas *listaAgendas;

    listaAgendas = (ListaAgendas*) malloc(sizeof (ListaAgendas));
    AgendaEmptyList(listaAgendas);

    MenuInicial(listaAgendas);

    return 0;
}

