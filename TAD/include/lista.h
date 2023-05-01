// -------------- HEADER do TAD --------------
#ifndef LISTA_H
#define LISTA_H

#define TAM 1000000

#include <stdio.h>   // < > diretório padrão do C
#include <stdlib.h>  // 
#include <time.h>    // 
#include <math.h>    // 

// Define o tipo de elemento dos vetores
typedef long elem;

// Define a estrutura basica da TAD
typedef struct{
    elem *elementos; // vetor de dados
    elem *copia; // lista auxiliar para usar na ordenacao merge
    long tamanho; // tamanho atual
    long ordenado;
} lista;

// Funcao que gera vetores de acordo com o modo escolhido
long *gera_vetor(long modo, long tam);

// Funcao que calcula a media de um array
double media(double A[], int n);

// Funcao que calcula o desvio padrao de um array
double desvio_padrao(double A[], int n, double media);

// Funcao que cria lista
void cria(lista *l);

// Funcao que desaloca lista
void destroi(lista *l);

// Funcao que insere elemento na lista
long insere(lista *l, elem x);

// Funcao que imprime a lista
void imprime(lista *l);

// -------------- Metodos de ordenacao -------------- //

// Bubble Sort Normal 
void ordena_bubble_sort(lista *l);

// Bubble Sort Aprimorado
void ordena_bubble_sort_aprimorado(lista *l);

// Quick Sort
void ordena_quick_sort(lista *l);

// Radix Sort
void ordena_radix_sort(lista *l);

// Heap Sort
void ordena_heap_sort(lista *l);


#endif