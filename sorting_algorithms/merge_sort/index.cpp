#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vetor[TAM];

void selection();
void intercala(int l, int m, int r);

void merge(int l, int r);

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

void merge(int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge(l, m);
    merge((m + 1), r);
    intercala(l, m, r);
  }
}

void intercala(int l, int m, int r) {
  int vetorLeftInicio = l;
  int vetorRightInicio = m + 1;
  int posFree = l;
  int aux[TAM];

  while (vetorLeftInicio <= m && vetorRightInicio <= r) {
    if (vetor[vetorLeftInicio] <= vetor[vetorRightInicio]) {
      aux[posFree] = vetor[vetorLeftInicio];
      vetorLeftInicio++;
    } else {
      aux[posFree] = vetor[vetorRightInicio];
      vetorRightInicio++;
    }
      posFree++;
  }

  for (int i = vetorLeftInicio; i <= m; i++) {
    aux[posFree] = vetor[i];
    posFree++;
  }
  for (int j = vetorRightInicio; j <= r; j++) {
    aux[posFree] = vetor[j];
    posFree++;
  }

  int inicio = l;
  while (inicio <=r) {
    vetor[inicio] = aux[inicio];
    inicio++;
  }
}