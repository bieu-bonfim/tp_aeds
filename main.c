#include <stdio.h>
#include <stdlib.h>
#include "ListaAgendas.h"

// Variável usada para criação do ID de compromissos
int tam = 0;

void ReadFile();

// --- Cabeçalhos das Funções Menu Interativo --- //

// Primeiro Menu do sistema
// Escolha de tipo de interação
void MenuInicial(ListaAgendas *listaAgendas);

// Primeira fase do Menu Interativo
// Login ou criação de agenda
void MenuInterativo(ListaAgendas *listaAgendas);

// Menu de Login dos professores
void MenuLogin (ListaAgendas *listaAgendas);

// Menu de criação de Agendas
void MenuCreateAgenda (ListaAgendas *listaAgendas);

// Menu Principal do Sistema
// Oferece todas as opções para um usuário logado
void MenuPrincipal(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de inserção de compromissos
void MenuInserirComp(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de remoção de compromissos por ID
void MenuRemoverComp(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de alteração de prioridades de compromissos
void MenuAlterarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de retorno de prioridade
void MenuRetornarPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de impressão de compromissos
void MenuPrintarComp(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de impressão de agenda de acordo com as datas
void MenuPrintAgendaData(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu que imprime todos os compromissos de uma agenda por ordem de prioridade
void MenuPrintarAgendaPrioridade(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu que imprime a quantidade de compromissos
void MenuPrintQntCompromissos(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu para verificar se há conflito entre dois compromissos
void MenuChecarConflito(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu para informações de perfil do professor
void MenuPerfil(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu para informações de perfil do professor
void MenuCreatePerfil(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de alteração do email do professor
void MenuAlterarEmail(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de alteração do aniversário do professor
void MenuAlterarAniversario(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de alteração do endereço do professor
void MenuAlterarEndereco(Agenda *agenda, ListaAgendas *listaAgendas);

// Menu de impressão do endereço do professor
void MenuPrintarEndereco(Agenda *agenda, ListaAgendas *listaAgendas);

// ------------------------------------------------------------------------ //

// --- Implementação dos Menus --- //

void ReadFile (ListaAgendas *listaAgendas) {

    FILE *pfile;
    char nome_arquivo[30], conteudo[50];
    int contProf = 0, contComp = 0, contDadosProf = 3, contDadosComp = 8, inter1 = 0, inter2 = 0;

    char id[10], nome[80];
    int anoAgenda;

    int prioridade, dia, mes, ano, hora, minuto, duracao;
    char descricao[100];

    int opcao;

    Agenda *agenda = (Agenda*) malloc(sizeof (Agenda));


    printf("\n---------------------------------");
    printf("\n------ Leitura de Arquivo -------");
    printf("\n---------------------------------");

    printf("\n\nDigite o nome do arquivo, caso esteja na mesma pasta q o arquivo main.c, coloque ../ antes do nome: ");
//    scanf("%s", nome_arquivo);

    pfile = fopen("../teste.txt", "r");

    while(1==1) {
        printf("\nPROF: %d\nCOMPRO: %d\nINTER: %d\n", contProf, contComp, inter1);

        if (contProf == 0 && contComp == 0 && inter1 == 1) {
            break;
        }
        if (contProf == 0 && contComp == 0 && inter1 == 0) {
            fscanf(pfile, "%d", &contProf);
            printf("%d", contProf);
            inter1++;
            continue;
        }
        if (contComp == 0) {
            fscanf(pfile, "%d", &contComp);
            printf("%d", contComp);
            if (inter2 == 1) {
                contProf--;
                contDadosProf = 3;
                inter2 = 0;
                continue;
            }
            inter2++;
            continue;
        }
        if (contProf > 0) {

            if (contDadosProf == 3) {
                printf("\nprof %d\n", contProf);
                fscanf(pfile, "%s", id);
                printf("%s", id);
                contDadosProf--;
                continue;
            } else if (contDadosProf == 2) {
                fscanf(pfile, "%s", nome);
                printf("%s", nome);
                contDadosProf--;
                continue;
            } else if (contDadosProf == 1) {
                ListaCompromissos lista;
                CompEmptyList(&lista);
                fscanf(pfile, "%d", &anoAgenda);
                printf("%d", anoAgenda);
                contDadosProf--;
                InicializarAgenda(agenda, &lista, id, nome, anoAgenda);
                AgendaListInsert(listaAgendas, agenda);
                continue;
            }
            if (contComp > 0) {
                if (contDadosComp == 8) {
                    printf("\ncompromisso numero %d do prof %d\n", contComp, contProf);
                    fscanf(pfile, "%d", &prioridade);
                    printf("%d", prioridade);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 7) {
                    fscanf(pfile, "%d", &dia);
                    printf("%d", dia);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 6) {
                    fscanf(pfile, "%d", &mes);
                    printf("%d", mes);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 5) {
                    fscanf(pfile, "%d", &ano);
                    printf("%d", ano);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 4) {
                    fscanf(pfile, "%d", &hora);
                    printf("%d", hora);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 3) {
                    fscanf(pfile, "%d", &minuto);
                    printf("%d", minuto);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 2) {
                    fscanf(pfile, "%d", &duracao);
                    printf("%d", duracao);
                    contDadosComp--;
                    continue;
                } else if (contDadosComp == 1) {
                    Compromisso compromisso;
                    fscanf(pfile, "%s", descricao);
                    printf("%s", descricao);
                    tam++;
                    InicializarCompromisso(&compromisso, tam, prioridade, dia, mes, ano, hora, minuto, duracao, descricao);
                    PrintCompromisso(compromisso);
                    CompListInsert(&agenda->compromissos, &compromisso);
                    PrintAgenda(*agenda);
                    contComp--;
                    contDadosComp = 8;
                }
            }
        }



    }

    printf("Insercoes:\n");
    AgendaListPrint(listaAgendas);

    printf("\n\nArquivo lido e insercao completa. ");
    printf("\nDigite 1 para ler outro arquivo");
    printf("\nDigite 0 para voltar ao menu inicial");

    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        ReadFile(listaAgendas);
    } else if (opcao == 0) {
        MenuInicial(listaAgendas);
    }


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
        ReadFile(listaAgendas);
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
    Perfil perfil;
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
    printf("\n-> Printar Quantidade de Compromissos Apos Data (Digite 6)");
    printf("\n-> Printar Agenda por Prioridade (Digite 7)");
    printf("\n-> Printar Quantidade de Compromissos (Digite 8)");
    printf("\n-> Checar Conflito Entre Compromissos (Digite 9)");
    printf("\n-> Visualizar Perfil de Professor (Digite 10)");
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

        case 10:
            MenuPerfil(agenda, listaAgendas);
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

    NFromData(agenda, ano, mes, dia);

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

    int prioridade, ano, mes, dia, hora, minuto, duracao;
    char descricao[100];

    int result, opcao;

    printf("\n---------------------------------");
    printf("\n------ Inserir Compromisso ------");
    printf("\n---------------------------------");

    printf("\n\nDigite a descricao:  ");
    scanf("%s", descricao);
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
    printf("\nDigite a minuto:  ");
    scanf("%d", &minuto);
    printf("\nDigite a duracao:  ");
    scanf("%d", &duracao);

    int check_hora;

    check_hora = (hora*60)+duracao+minuto;

    if (check_hora <= 1439) {
        tam++;
        result = InicializarCompromisso(&compromisso, tam, prioridade, dia, mes, ano, hora, minuto, duracao, descricao);
        CompListInsert(&agenda->compromissos, &compromisso);
        printf("\n\nCompromisso inserido com sucesso!");
        printf("\nO ID do compromisso eh: %d\n", result);
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

void MenuPerfil(Agenda *agenda, ListaAgendas *listaAgendas) {
    int opcao;
    printf("\n\n---------------------------------");
    printf("\n---------- Seu  Perfil ----------");
    printf("\n---------------------------------");



    printf("\n\nEscolha uma das seguintes opcoes:");
    if (!agenda->perfil.ano) {
        printf("\n\n-> Criar Perfil (Digite 9)");
    } else {
        printf("\n");
        PrintPerfil(agenda->perfil);
        printf("\n\n-> Alterar Email (Digite 1)");
        printf("\n-> Alterar Aniversario (Digite 2)");
        printf("\n-> Alterar Endereco (Digite 3)");
        printf("\n-> Imprimir Endereco (Digite 4)");
    }
    printf("\n-> Voltar (Digite 0)");

    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 9) {
        MenuCreatePerfil(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPrincipal(agenda, listaAgendas);
    } else if (opcao == 1) {
        MenuAlterarEmail(agenda, listaAgendas);
    } else if (opcao == 2) {
        MenuAlterarAniversario(agenda, listaAgendas);
    } else if (opcao == 3) {
        MenuAlterarEndereco(agenda, listaAgendas);
    } else if (opcao == 4) {
        MenuPrintarEndereco(agenda, listaAgendas);
    }
}

void MenuCreatePerfil(Agenda *agenda, ListaAgendas *listaAgendas) {
    int opcao, ano, mes, dia, numero, cep;
    char email[80], rua[30], bairro[30], cidade[30];

    Perfil perfil;
    Endereco endereco;

    printf("\n\n---------------------------------");
    printf("\n--------- Criar  Perfil ---------");
    printf("\n---------------------------------");

    printf("\n\nDigite o email:  ");
    scanf("%s", email);
    printf("\nDigite o ano de nascimento:  ");
    scanf("%d", &ano);
    printf("\nDigite o mes de nascimento:  ");
    scanf("%d", &mes);
    printf("\nDigite o dia de nascimento:  ");
    scanf("%d", &dia);
    printf("\nDigite o rua:  ");
    scanf("%s", rua);
    printf("\nDigite o numero:  ");
    scanf("%d", &numero);
    printf("\nDigite o bairro:  ");
    scanf("%s", bairro);
    printf("\nDigite a cidade:  ");
    scanf("%s", cidade);
    printf("\nDigite o cep:  ");
    scanf("%d", &cep);

    InicializarEndereco(&endereco, rua, numero, cep, bairro, cidade);
    InicializarPerfil(&perfil, email, ano, mes, dia, endereco);
    CreatePerfil(agenda, perfil);

    printf("\n\nPerfil criado com sucesso!\n");

    PrintPerfil(agenda->perfil);
    UpdateAgenda(listaAgendas, agenda, agenda->id);

    printf("\n\nDigite 0 para voltar ao menu de perfil");
    printf("\n\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 0) {
        MenuPerfil(agenda, listaAgendas);
    }
}

void MenuAlterarEmail(Agenda *agenda, ListaAgendas *listaAgendas) {
    int opcao;
    char email[80];

    Compromisso *compromisso;

    printf("\n---------------------------------");
    printf("\n--------- Alterar Email ---------");
    printf("\n---------------------------------");

    printf("\n\nDigite o novo email do seu perfil: ");
    scanf("%s", email);

    PrintPerfil(agenda->perfil);
    SetEmail(&agenda->perfil, email);
    PrintPerfil(agenda->perfil);

    printf("\nEmail alterado com sucesso!");
    printf("\nSe quiser alterar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuAlterarEmail(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPerfil(agenda, listaAgendas);
    }
}

void MenuAlterarAniversario(Agenda *agenda, ListaAgendas *listaAgendas) {
    int ano, mes, dia, opcao, prioridade;

    Compromisso *compromisso;

    printf("\n---------------------------------");
    printf("\n------ Alterar Aniversario ------");
    printf("\n---------------------------------");

    printf("\nDigite o ano:  ");
    scanf("%d", &ano);
    printf("\nDigite o mes:  ");
    scanf("%d", &mes);
    printf("\nDigite o dia:  ");
    scanf("%d", &dia);

    SetAniversario(&agenda->perfil, ano, mes, dia);

    printf("\nAniversario alterado com sucesso!");
    printf("\nSe quiser alterar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuAlterarEmail(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPerfil(agenda, listaAgendas);
    }
}

void MenuAlterarEndereco(Agenda *agenda, ListaAgendas *listaAgendas){
    int opcao, numero, cep;
    char rua[30], bairro[30], cidade[30];

    Endereco endereco;

    printf("\n---------------------------------");
    printf("\n------- Alterar  Endereco -------");
    printf("\n---------------------------------");

    printf("\nDigite o rua:  ");
    scanf("%s", rua);
    printf("\nDigite o numero:  ");
    scanf("%d", &numero);
    printf("\nDigite o bairro:  ");
    scanf("%s", bairro);
    printf("\nDigite a cidade:  ");
    scanf("%s", cidade);
    printf("\nDigite o cep:  ");
    scanf("%d", &cep);

    InicializarEndereco(&endereco, rua, numero, cep, bairro, cidade);
    agenda->perfil.endereco = endereco;
    UpdateAgenda(listaAgendas, agenda, agenda->id);

    printf("\n\nEndereco alterado com sucesso");
    printf("\n\nSe quiser alterar novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuAlterarEndereco(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPerfil(agenda, listaAgendas);
    }
}

void MenuPrintarEndereco(Agenda *agenda, ListaAgendas *listaAgendas){
    int opcao;

    printf("\n---------------------------------");
    printf("\n------- Imprimir Endereco -------");
    printf("\n---------------------------------\n");

    PrintEndereco(agenda->perfil.endereco);

    printf("\nSe quiser imprimir novamente, digite 1");
    printf("\nCaso deseje voltar ao menu principal, digite 0");
    printf("\nOpcao escolhida: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        MenuPrintarEndereco(agenda, listaAgendas);
    } else if (opcao == 0) {
        MenuPerfil(agenda, listaAgendas);
    }
}

int main() {

    ListaAgendas *listaAgendas;

    listaAgendas = (ListaAgendas*) malloc(sizeof (ListaAgendas));
    AgendaEmptyList(listaAgendas);

    MenuInicial(listaAgendas);

    return 0;
}