#ifndef UTILS_SEARCH_H
#define UTILS_SEARCH_H

typedef struct Node {
  int value;
  Node *next;
} Node;

const int TAM = 20000;
const int SIZE = 1000;
extern int vetor[TAM];
extern int vetor2[SIZE];

void geraRandom(int tam);
void gerarRandomDynamic(Node **inicio, int tam);
void printArray();
void desordenado();

#endif
