#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"





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

void geraRandom() {
  for (int i = 0; i < TAM; i++) {
    vetor[i] = rand() % 100000;
  }
}
