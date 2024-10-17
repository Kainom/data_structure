#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int TAM = 19999;
int vetor[TAM];

void geraRandom();
void printArray();
void bubbleSort();
void bubbleSort2();

void bubbleSort3();

void desordenado();

int main() {
  clock_t t1, t2;
  geraRandom();

  t1 = clock();

  desordenado();

  t2 = clock();

  double tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no ordenado: %.6f segundos\n", tempo);

  t1 = clock();

  bubbleSort2();
  t2 = clock();

  tempo = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
  printf("Tempo gasto no desordenado: %.6f segundos\n", tempo);
}

void geraRandom() {
  for (int i = 0; i < TAM; i++) {
    vetor[i] = rand() % 100000;
  }
}

void printArray() {
  for (int i = 0; i < TAM; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

void desordenado() {
  for (int i = 0; i < TAM; i++) {
  }
}

void bubbleSort() {
  int i, j, troca, aux;

  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
        troca = 1;
      }
    }
    if (troca == 0)
      break;
  }
}

void bubbleSort2() {
  int i, j, troca, aux;
  // the difference between this and the first is the iteration size

  // how the max value always will be put in the last position,we can avoid this
  // is position,because there is nothing forward

  // Then, on  each iteration, the process 'cut' the  iteration size

  // The 'troca' avoids the full iterarion of first loop,because,he is check if is necessary  keep the looping

  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM - i - 1; j++) {
      troca = 0;
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
        troca = 1;
      }
    }
    if (troca == 0)
      break;
  }
}

void bubbleSort3() { // 5 9 8 2
  int i, j, troca, aux;
  for (i = 1; i < TAM; i++) {
    for (j = (TAM - 1); j >=i; j--) {
      if (vetor[j] > vetor[j - 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j - 1];
        vetor[j-1] = aux;
        troca = 1;
      }
    }
    if (troca == 0)
      break;
  }
}
