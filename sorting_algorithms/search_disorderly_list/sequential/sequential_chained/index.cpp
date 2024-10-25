#include "../../util_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int vetor2[SIZE];
int vetor[TAM];

int sequential(Node **inicio);

int main() {

  Node *inicio = NULL;
  gerarRandomDynamic(&inicio, 10000);
  int value = sequential(&inicio);
  printf("Number of comparison: %d\n", value);
  return 0;
}

int sequential(Node **inicio) {
  int comparison = 0, i = 0;

  srand(time(NULL)); // Inicializa o gerador de números aleatórios.
  while (i != 1000) {
    int key = rand() % 10000;
    for (Node *aux = *inicio; aux != NULL; aux = aux->next) {
      if (aux->value == key) {
        comparison++;
        break;
      }
      comparison++;
    }
    i++;
  }
  return comparison;
}
