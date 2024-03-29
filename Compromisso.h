// Define um tipo de estrutura "Compromisso"
typedef struct {
    int id;
    int prioridade;
    int dia, mes, ano;
    int hora, minuto, duracao;
    char descricao[100];
} Compromisso;

// Função que inicializa um compromisso
int InicializarCompromisso(Compromisso* compromisso, int id, int prioridade,
                            int dia, int mes, int ano, int hora, int minuto,
                            int duracao, char descricao[100]);

// Altera a prioridade de um compromisso
void SetPrioridade(Compromisso* compromisso, int prioridade);

// Retorna a prioridade de um compromisso
void GetPrioridade(Compromisso compromisso, int *prioridade);

// Função que verifica se o compromisso tem conflito
int CheckConflict(Compromisso compromisso1, Compromisso compromisso2);

// Função que imprime o compromisso
void PrintCompromisso(Compromisso compromisso);
