// -------------- HEADER do TAD --------------

#define TAM 10

// Define o tipo de elemento dos vetores
typedef int elem;

// Define a estrutura basica da TAD
typedef struct{
    elem *elementos; // vetor de dados
    elem *copia; // lista auxiliar para usar na ordenacao merge
    long tamanho; // tamanho atual
    int ordenado;
} lista;

// Funcao que gera vetores de acordo com o modo escolhido
long *gera_vetor(long modo, long tam);

// Funcao que cria lista
void cria(lista *l);

// Funcao que desaloca lista
void destroi(lista *l);

// Funcao que insere elemento na lista
int insere(lista *l, elem x);

// Funcao que imprime a lista
void imprime(lista *l);

// -------------- Metodos de ordenacao -------------- //

// Bubble Sort Normal 
void ordena_bubble_sort(lista *l);

// Bubble Sort Aprimorado
void ordenacao_bubble_sort_aprimorado(lista *l);

// Quick Sort
void quick_sort_semduplicatas(int vet[], long tam);

// Radix Sort
void radix_sort(int vet[], int tam);