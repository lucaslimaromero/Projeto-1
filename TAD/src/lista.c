/*

Lucas Lima Romero 13676325
Luciano Gonçalves Lopes Filho 13676520
Marco Antonio Gaspar Garcia 11833581

*/

// Implementação do TAD

#include "lista.h" // arquivo source

long *gera_vetor(long modo, long tam){

    long *vetor = (long*) malloc(sizeof(long) * tam);
    
    if (modo == 1){ // modo aleatorio 

        srand(time(NULL));

        for(long i = 0; i < tam; i++)
            vetor[i] = rand() % 100000;
    }

    else if (modo == 2){ // ordenado
        for(long i = 0; i < tam; i++)
            vetor[i] = i+1;
    }

    else if (modo == 3){ // decrescente
        for(long i = 0; i < tam; i++)
            vetor[i] = tam-i;
    }

    return vetor;
}

double media(double A[], int n){

    double media = 0;

    for (int i = 0; i < n; i++)
        media += (double) A[i];

    return media/n;
}

double desvio_padrao(double A[], int n, double media){

    double soma = 0;
    
    for (int i = 0; i < n; i++)
        soma += pow((media - (double)A[i]), 2);
    
    return sqrt(soma/n);
}

void cria(lista *l){
    l->tamanho = 0;
    l->elementos = malloc(sizeof(elem)*TAM);
    return;
}

void destroi(lista *l){
    free(l->elementos);
    l->tamanho = 0;
}

long insere(lista *l, elem x){
    if(l->tamanho == TAM){
        return 1; // erro, lista cheia
    }
    l->elementos[l->tamanho] = x;
    l->tamanho++;
    return 0; // sucesso
}

void imprime(lista *l){
    long i = 0;
    if(l->tamanho == 0)
        printf("( )\n"); // caso a lista estiver vazia
    else{
        printf("(");
        for(i = 0; i < l->tamanho - 1; i++)
            printf("%ld, ", l->elementos[i]);
        printf("%ld)\n",  l->elementos[i]);
    } 
}

void ordena_bubble_sort(lista *l){
    elem aux;

    for(long i = 0; i < l->tamanho - 1; i++){
        for(long j = 0; j < l->tamanho - 1; j++){

            if(l->elementos[j] > l->elementos[j + 1]){
                // faz a troca
                aux = l->elementos[j];
                l->elementos[j] = l->elementos[j+1];
                l->elementos[j+1] = aux;
            }
        }
    }
}

void ordena_bubble_sort_aprimorado(lista *l){

    long continua = 1, iteracao = 1;
    long aux;

    while(continua){ // se nao houve mudanca, o vetor esta ordenado, encerra execucao
    
        continua = 0; // Flag para saber se houve mudanca na passagem
        for(long j = 0; j < l->tamanho - iteracao; j++){

            if(l->elementos[j] > l->elementos[j+1]){

                aux = l->elementos[j];
                l->elementos[j] = l->elementos[j+1];
                l->elementos[j+1] = aux;
                continua = 1; // mudanca aconteceu 
            }
        }
        iteracao++;
    }
}

void ordena_quick_sort_recursivo(elem A[], long ini, long fim) {
    // quick sort com particionamento de Lomuto (permite duplicatas)
    // pivô fica sempre no final, l->elementos[fim]
    long i, j;
    elem aux;
    
    if (ini >= fim)
        return; // caso trivial, vetor nulo ou unitario
    
    // particiona vetor
    i = ini;
    for (j = ini; j < fim; j++)
        if (A[j] < A[fim]) { // testa se o elemento da j-esima posicao eh menor do que o pivo
            // troca A[i] com A[j]
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            
            i++; // novo elemento menor do que o pivo foi encontrado
        }
    
    // coloca o pivo no lugar correto
    // basta trocar A[i] com A[fim]
    aux = A[i];
    A[i] = A[fim];
    A[fim] = aux;
    
    ordena_quick_sort_recursivo(A, ini, i - 1); // metade inferior
    ordena_quick_sort_recursivo(A, i + 1, fim); // metade superior
}

void ordena_quick_sort(lista *l) {
    ordena_quick_sort_recursivo(l->elementos, 0, l->tamanho - 1); // inicia recursividade
}
 
void counting_sort(elem A[], long posicao, long tam){

    // codigo escrito com base no pseudocodigo apresentado pelo professor

    long B[10] = {0};
    long key;

    for (long i = 0; i <= tam-1; i++){

        key = A[i] / posicao;
        key = key % 10;
        B[key] += 1;
    }
    
    for (long i = 1; i < 10; i++)
        B[i] += B[i-1];

    long *C = (long*) malloc(sizeof(long)*tam);

    for (long i = tam-1; i >= 0; i--){

        key = A[i]/posicao;
        key = key % 10;
        B[key] -= 1;
        C[B[key]] = A[i];
    }

    for (long i = 0; i <= tam-1; i++){

        A[i] = C[i];
    }

    free(C);
}

void ordena_radix_sort(lista *l){

    long maior = l->elementos[0]; //detectando o maior elemento do array
    for (long i = 1; i <= l->tamanho - 1; i++)
        if(l->elementos[i] > maior) maior = l->elementos[i];

    // A funcao counting_sort eh chamada D vezes, sendo D o numero 
    //de digitos do maior elemento presente no array
    for (long posicao = 1; maior / posicao > 0; posicao *= 10)
        counting_sort(l->elementos, posicao, l->tamanho);
    
}

void heapify(elem A[], long n, long i){

    // codigo escrito com base no pseudocodigo apresentado pelo professor

    long maior = i;
    long esquerda = (2 * i) + 1;
    long direita = (2 * i) + 2;

    if(esquerda < n && A[esquerda] > A[maior]){
        maior = esquerda;
    }

    if(direita < n && A[direita] > A[maior]){
        maior = direita;
    }
    
    if(maior != i){
        //swap(A[i],l->[maior]);
        long aux = A[i];
        A[i] = A[maior];
        A[maior] = aux; 
        heapify(A, n, maior);
    }
}

void ordena_heap_sort(lista *l){

    for (long i = (l->tamanho / 2) - 1; i >= 0; i--){
        heapify(l->elementos, l->tamanho, i);
    }

    for (long i = l->tamanho - 1; i >= 0; i--){
        //swap(l->elementos[0],l->elementos[i]);
        long temp = l->elementos[0];
        l->elementos[0] = l->elementos[i];
        l->elementos[i] = temp;
        heapify(l->elementos, i, 0);
    }
}