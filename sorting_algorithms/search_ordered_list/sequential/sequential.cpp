#include "../util_search.h"
#include <stdio.h>
#include <time.h>

int vetor[TAM];

int sentinel(int key, int i);

int main() {
  int key = 53;
  geraRandom(10000);
  int value = sentinel(key, 0);
  if (value == -1) {
    printf("Elemento nao encontrado!\n");
  } else {
    printf("Elemento %d encontrado na posicao %d.\n", key, value);
  }
  return 0;
}

int sentinel(int key, int i) {
  if (i != TAM) {
    if (vetor[i] == key) {
      return i;
    }
    return sentinel(key, ++i);
  }
  return -1;
}
