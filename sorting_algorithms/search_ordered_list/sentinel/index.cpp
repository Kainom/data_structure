#include "../util_search.h"
#include <stdio.h>

int vetor[TAM];

int sentinel(int key);
int sentinelRecursive(int key, int i);

int main() {
  int value = 0, key = 53;
  geraRandom(10000);
  //    value = sentinel(key);
  value = sentinelRecursive(key, 0);
  if (value == TAM - 1) {
    printf("Elemento nao encontrado!\n");
  } else {
    printf("Elemento %d encontrado na posicao %d.\n", key, value);
  }
  return 0;
}

int sentinelRecursive(int key, int i) {
  if (vetor[i] != key) {
    return sentinelRecursive(key, ++i);
  }
  return i;
}

int sentinel(int key) {
  int i = 0, lastElement = vetor[TAM - 1];
  vetor[TAM - 1] = key;

  for (; key != vetor[i]; i++)
    ;
  vetor[TAM - 1] = lastElement;
  return i;
}
