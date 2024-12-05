#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vetor[100];

int collisionTotal = 0;

void busca(int key);

void insere(int key);

int main() {
  fill(vetor);
  int i = 0;
  printf("Vetor inicial:\n");
  imprime(vetor);
  srand(time(NULL));
  for (; i < SIZE; i++) {
    int key = rand() % SIZE; 
    insere(key);
  }
  float average = ((float) collisionTotal / i);
  printf("\nVetor final:\n");
  imprime(vetor);
  printf("Number os collisions: %d\n", collisionTotal);

  printf("Average of collisions: %.2f\n", average);
  return 0;
}

void busca(int key) {
  int hashKey = espalha(key);
  int collision = 0;
  for (; vetor[hashKey] != -1 && vetor[hashKey] != key;) {
    collision++;
    hashKey = reespalha(hashKey);

    if (collision == SIZE) {
      printf("the value was not found\n");
      collisionTotal += collision;
      return;
    }
  }

  if (vetor[hashKey] == -1) {
    printf("the value was not found\n");
    return;
  } // Valor não encontrado.

  printf("the value was found at position %d\n", hashKey);
  collisionTotal += collision;
}

void insere(int key) {
  int hashKey = espalha(key);
  int collision = 0;

  while (vetor[hashKey] != -1) {
    collision++;
  
    if (collision == SIZE) {
      // printf("the value cannot be entered,Hash full\n");
      collisionTotal += collision;
      return;
    } // Repetição máxima de colisões atingida.

    hashKey = reespalha(hashKey);
  }

  vetor[hashKey] = key;
  collisionTotal += collision;
}
