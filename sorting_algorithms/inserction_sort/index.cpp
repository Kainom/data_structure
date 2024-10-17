#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../utils.h"

int vetor[TAM];

void inserction();


int main() {
  clock_t t1, t2;
  geraRandom();

  t1 = clock();

  desordenado();

  t2 = clock();

  double tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no desordenado: %.6f segundos\n", tempo);

  t1 = clock();
  inserction();
  t2 = clock();

  tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no ordenado: %.6f segundos\n", tempo);
}




void inserction() {
  int trocaPivo = 0, aux, i, j, pivo;

  for (i = 1; i < TAM; i++) {
    pivo = vetor[i];
    trocaPivo = 0;
    for (j = (i - 1); j >= 0 && trocaPivo != 1; j--) {
      if (vetor[j] > pivo) {
        aux = vetor[j + 1];
        vetor[j + 1] = vetor[j];
        vetor[j] = aux;
      } else { // When the'pivo' is  bigger than the value,he is a ususeless,so
               // we get out
        trocaPivo = 1;
      }
    }
  }
}
