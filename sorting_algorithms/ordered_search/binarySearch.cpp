#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int SIZE = 10;
int vetor[SIZE];

void geraRandomAndOrders();
int binary(int key);
void geraRandomAndOrders() {
  srand(time(NULL)); // Inicializa o gerador de números aleatórios.
  for (int i = 0; i < SIZE; i++) {
    vetor[i] = rand() % 10;
  }
  // Ordena o vetor

  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - 1 - i; j++) {
      if (vetor[j] > vetor[j + 1]) {
        int aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux; // 2 5
      }
    }
  }
}

int main() {
  geraRandomAndOrders();
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  int key = 5;
  int value = binary(key);
  if (value == -1) {
    printf("Elemento nao encontrado!\n");

  } else {
    printf("Elemento %d encontrado na posicao %d.\n", key, value);
  }
  return 0;
}

int binary(int key) {
  int inicio = 0;
  int fim = SIZE - 1;
  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    if (vetor[meio] == key)
      return meio;
    if (vetor[meio] < key)
      inicio = meio +1;
    if (vetor[meio] > key)
      fim = meio - 1;
  }
      return -1;

}
