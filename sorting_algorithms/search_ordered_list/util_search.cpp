#include "util_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void geraRandom(int tam) {
  srand(time(NULL)); // Inicializa o gerador de números aleatórios.
  for (int i = 0; i < tam; i++) {
    vetor[i] = rand() % tam;
  }
}

void gerarRandomDynamic(Node **inicio, int tam) {
  *inicio = (Node *)malloc(sizeof(Node));

  Node *aux = *inicio; //

  *inicio = aux;
  srand(time(NULL)); // Inicializa o gerador de números aleatórios.

  aux->value = rand() % tam;

  for (int i = 0; i < SIZE; i++) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->value = rand() % tam;
    novo->next = NULL;
    aux->next = novo;
    aux = novo;
  }
}
