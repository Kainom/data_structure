#include "./utils.h"
#include <stdio.h>
#include <stdlib.h>

extern int collisionTotal;

void fill(int hashArray[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    hashArray[i] = -1;
  }
}  

void imprime(int hashArray[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", hashArray[i]);
  }
  printf("\n");
}

int espalha(int key) { return key % SIZE; }

int reespalha(int index) { return (index +1) % SIZE; }
