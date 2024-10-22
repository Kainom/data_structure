#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vetor[TAM];

void selection();

int main() {
  clock_t t1, t2;
  geraRandom();

  t1 = clock();

  desordenado();

  t2 = clock();

  double tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no desordenado: %.6f segundos\n", tempo);

  t1 = clock();
  selection();
  t2 = clock();

  tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no ordenado: %.6f segundos\n", tempo);
}

void selection() {
  int pivo = 0;
  int j, menor;

  for (int  i= 0; i < TAM; i++) {
    pivo = i;

    j = i + 1;
    while (j <= (TAM - 1)) {
      if (vetor[pivo] > vetor[j]) {
        pivo = j;
      }
      j++;
    }
    menor = vetor[pivo];
    vetor[pivo] = vetor[i];
    vetor[i] = menor;
  }
}
