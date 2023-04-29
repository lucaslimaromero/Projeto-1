#define REP 1 // numero de vezes que vou rodar meu codigo pra pegar um tempo medio

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // para medir o tempo de cada execucao de ordenacao, para fazer medicao de tempo usaremos os ciclos do nosso processador
#include "lista.h"

int main(){
    // clock_t é um long long que vai medir quantos clocks / ciclos q o processador faz por segundo. Ex.: 2,5GHz
    lista l;
    clock_t tempo_ini, soma_tempos; // guarda em certos momentos quantos ciclos do processador ocorreram desde que liguei a máquina

    // Considera listas de tamanho cada vez maiores
    for(long ordem = 3; pow(10, ordem) <= TAM; ordem++) // Número de elementos do vetor será no máximo o tamanho max estipulado (TAM)
    {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for(long i = 0; i < REP; i++)
        {
            // nova lista
            cria(&l);

            // insere elementos aleatorios
            for(long j = 0; j < pow(10, ordem); j++)
                insere(&l, rand() % TAM);

            //imprime(&l); // imprime antes de ordenar

            // ordena e guarda o tempo gasto numa soma
            tempo_ini = clock(); // Guarda tempo atual
            // chama funcao que ordena
            soma_tempos += clock() - tempo_ini; // guarda tempo decorrido desta rodada adicionando-o à soma

            //imprime(&l); // imprime apos ordenar
            destroi(&l);
        }
        printf("Tamanho da entrada: %0.0f\tTempo medio: %0.10f\n", pow(10, ordem), ((float) soma_tempos / REP) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC é uma constante que diz a razão clock por segundo
    }

    return 0;
}