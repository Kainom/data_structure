#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;

typedef struct Node {
  int data;
  struct Node *next;
} node;

Node *hash[SIZE];

int insere(int key);
int espalha(int key);

void imprime();

void busca(int key);

int main() {

  int keys[] = {20, 35, 40, 55, 60, 75, 80, 90, 100, 110};
  int i;
  for (i = 0; i < 10; i++)
    int value = insere(keys[i]);

  insere(1);
  insere(110);
  insere(110);
  insere(110);
  insere(11);
  insere(76);

  imprime();
  busca(11);
  return 0;
}

int espalha(int key) { return key % SIZE; }

void imprime() {
  for (int i = 0; i < SIZE; i++) {
    node *aux = hash[i];
    if (aux != NULL)
      printf("Chave %d:", i);
    while (aux != NULL) {
      printf(" -> %d", aux->data);
      aux = aux->next;
      if (aux == NULL)
        printf("\n");
    }
  }
}

int insere(int key) {
  int hashKey = espalha(key);
  if (hash[hashKey] == NULL) {
    hash[hashKey] = (node *)malloc(sizeof(node));
    hash[hashKey]->data = key;
    hash[hashKey]->next = NULL;
  } else {
    Node *aux = hash[hashKey];
    while (aux->next != NULL) {
      if (aux->data == key || aux->next->data == key) {
        printf("Valor %d já existe na hash!\n", key);
        return 0;
      }
      aux = aux->next;
    }
    Node *novo = (node *)malloc(sizeof(node));
    novo->data = key;
    novo->next = NULL;
    aux->next = novo;
  }

  return 0;
}

void busca(int key) {
  int hashKey = espalha(key);
  if (hash[hashKey] == NULL) {
    printf("Valor %d não existe na hash!\n", key);
  } else {
    for (node *aux = hash[hashKey]; aux = aux->next; aux != NULL){
        if(aux->data == key){
            printf("Valor %d foi encontrado na hash!\n", key);
            return;
        }
    }
    printf("Valor %d não foi encontrado na hash!\n", key);
  }
}
