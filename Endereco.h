typedef struct {
    char rua[30];
    int numero;
    int cep;
    char bairro[30];
    char cidade[30];
} Endereco;

// Função de criar endereço do professor
void InicializarEndereco(Endereco* endereco, char rua[30], int num, int cep, char bairro[30], char cidade[30]);

// Imprime o endereço
void PrintEndereco(Endereco endereco);


