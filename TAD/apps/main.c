#define REP 5 // numero de vezes que vou rodar meu codigo pra pegar um tempo medio

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // para medir o tempo de cada execucao de ordenacao, para fazer medicao de tempo usaremos os ciclos do nosso processador
#include "lista.h"

void bubble_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, soma_tempos; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_bubble_sort(l);// chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10fs\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void bubble_sort_aprimorado(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

     clock_t tempo_ini, soma_tempos;

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_bubble_sort_aprimorado(l);// chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10fs\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");

}

void quick_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, soma_tempos; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= 100000; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_quick_sort(l);// chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10fs\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");

}

void radix_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, soma_tempos; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= TAM; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_radix_sort(l);// chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10fs\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");
}

void heap_sort(lista *l, int modo){

    printf("\t--- Modo %d ---\n", modo);

    clock_t tempo_ini, soma_tempos; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    for (long ordem = 3; pow(10, ordem) <= TAM; ordem++) // Numero de elementos do vetor, de 1000 ate TAM
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(l);

            // insere elementos aleatorios
            l->elementos = gera_vetor(modo, pow(10, ordem));
            l->tamanho = pow(10, ordem);
            //imprime(l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            ordena_heap_sort(l);// chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            
            //imprime(l); // imprime apos ordenar
            destroi(l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10fs\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }
    puts("");

}

int main(){
    
    lista *l;

    
    printf("\tBubble Sort\n\n");
    for (int i = 1; i <= 3; i++)
        bubble_sort(l, i);

    printf("\n\tBubble Sort Aprimorado\n\n");
    for (int i = 1; i <= 3; i++)
        bubble_sort_aprimorado(l, i);
    
    printf("\n\tQuick Sort\n\n");
    for (int i = 1; i <= 3; i++)
        quick_sort(l, i);
    
    printf("\n\tRadix Sort\n\n");
    for (int i = 1; i <= 3; i++)
        radix_sort(l, i);

    printf("\n\tHeap Sort\n\n");
    for (int i = 1; i <= 3; i++)
        heap_sort(l, i);

    return 0;
}