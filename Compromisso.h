typedef struct {
    int id;
    int prioridade;
    int dia, mes, ano;
    int hora, duracao;
    char descricao[100];
} Compromisso;

int InicializarCompromisso(Compromisso* compromisso, int id, int prioridade,
                            int dia, int mes, int ano, int hora,
                            int duracao, char descricao[100]);

void SetPrioridade(Compromisso* compromisso, int prioridade);

void GetPrioridade(Compromisso compromisso, int *prioridade);

int CheckConflict(Compromisso compromisso1, Compromisso compromisso2);

void PrintCompromisso(Compromisso compromisso);
