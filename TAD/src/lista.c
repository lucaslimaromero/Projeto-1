// Implementação do TAD
#include <stdio.h> // < > diretório padrão do C
#include <stdlib.h>
#include "lista.h" // "" diretório corrente que eu estou

void cria(lista *l){
    l->tamanho = 0;
    l->copia = malloc(sizeof(elem)*TAM);
    l->elementos = malloc(sizeof(elem)*TAM);
    l->ordenado = 0;
    return;
}

void destroi(lista *l){
    free(l->elementos);
    free(l->copia);
    l->tamanho = 0;
    l->ordenado = 0;
}

int insere(lista *l, elem x){
    if(l->tamanho == TAM){
        return 1; // erro, lista cheia
    }
    l->elementos[l->tamanho] = x;
    l->tamanho++;
    l->ordenado = 0;
    return 0; // sucesso
}

void imprime(lista *l){
    long i = 0;
    if(l->tamanho == 0)
        printf("( )\n"); // caso a lista estiver vazia
    else{
        printf("(");
        for(i = 0; i < l->tamanho - 1; i++)
            printf("%d, ", l->elementos[i]);
        printf("%d)\n",  l->elementos[i]);
    } 
}

void ordena_bubble_sort(lista *l){
    elem aux;
    for(long i = 0; i < l->tamanho - 1; i++){
        for(long j = 0; j < l->tamanho - i; j++){
            if(l->elementos[j] > l->elementos[j + 1]){
                // faz a troca
                aux = l->elementos[j];
                l->elementos[j] = l->elementos[j+1];
                l->elementos[j+1] = aux;
            }
        }
    }
}

void ordenacao_bubble_sort_aprimorado(lista *l){
    long continua = 1, iteracao = 1;
    int aux;

    while(continua)
    {
        continua = 0;
        for(int j = 0; j < l->tamanho - iteracao; j++)
        {
            if(l->elementos[j] > l->elementos[j+1]){
                aux = l->elementos[j];
                l->elementos[j] = l->elementos[j+1];
                l->elementos[j+1] = aux;
                continua = 1;
            }
        }
        iteracao++;
    }

    for(int i = 0; i < l->tamanho; i++)
         printf("%d ", l->elementos[i]);

}

void quick_sort_semduplicatas_recursivo(int vet[], int ini, int fim){
    int i, j, meio;
    int pivo, aux;

    if(ini < fim){
        meio = (ini+fim) / 2;
        pivo = vet[meio];

        i = ini;
        j = fim;
        while(1){
            for(; vet[i] < pivo; i++);

            for(; vet[j] > pivo; j--);

            if(i == j)
                break;

            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }

        quick_sort_semduplicatas_recursivo(vet, ini, i-1);
        quick_sort_semduplicatas_recursivo(vet, i+1, fim);
    }
}

void quick_sort_semduplicatas(int vet[], int tam){
    return quick_sort_semduplicatas_recursivo(vet, 0, tam-1);
}
 
