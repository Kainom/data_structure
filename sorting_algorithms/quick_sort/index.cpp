#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vetor[TAM];

void selection();
int intercala(int low, int high);
void troca(int *a, int *b);

void merge(int low, int high);

int main() {
  clock_t t1, t2;
  geraRandom();

  t1 = clock();

  desordenado();

  t2 = clock();

  double tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no desordenado: %.6f segundos\n", tempo);

  t1 = clock();
  merge(0, TAM - 1);
  t2 = clock();

  tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no ordenado: %.6f segundos\n", tempo);
  return 0;
}

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void merge(int low, int high) {

  if (low < high) {
    int pivot = intercala(low, high);

    merge(low, (pivot - 1));
    merge((pivot + 1), high);
  }
}

int intercala(int low, int high) {
  int pivot = vetor[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (vetor[j] <= pivot) { //  91 92 89    90
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }
  troca(&vetor[i + 1], &vetor[high]);
  return (i + 1);
}