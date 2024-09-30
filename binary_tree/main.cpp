#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *right;
  struct Node *left;
} Node;

void insert(Node **raiz, int value);
int isEmpty(Node **raiz);
int searchValue(Node *raiz, int value);
void inOrdem(Node *raiz);
void preOrder(Node *raiz);
void postOrder(Node *raiz);

int main() {
  Node *raiz = NULL;
  insert(&raiz, 6);
  insert(&raiz, 4);
  insert(&raiz, 3);
  insert(&raiz, 5);
  insert(&raiz, 8);
  insert(&raiz, 7);
  insert(&raiz, 9);

  if (searchValue(raiz, 9))
    printf("The value was found\n");

  inOrdem(raiz);
  printf("\n");
  preOrder(raiz);
  printf("\n");
  postOrder(raiz);
  return 0;
}

void insert(Node **raiz, int value) {
  struct Node *aux = (Node *)malloc(sizeof(Node));
  struct Node *aux2 = (Node *)malloc(sizeof(Node));

  aux->data = value;
  aux->right = NULL;
  aux->left = NULL;

  if (*raiz ==
      NULL) // that means tree is empty.So,you must give tje first address;
  {
    *raiz = aux;
    return;
  }

  // always the new element must be a leaf

  aux2 = *raiz;
  while (1) {
    if (aux2->data == aux->data) {
      printf("Valor Repetido\n");
    }

    if (aux->data <
        aux2->data) // you must consideration that value < always to go for the
    {
      if (aux2->left == NULL) {
        aux2->left = aux;
        return;
      } else {
        aux2 = aux2->left;
      }
    } else {
      if (aux2->right == NULL) {
        aux2->right = aux;
        return;
      }
      aux2 = aux2->right;
    }
  }
}

int isEmpty(Node **root) {
  if (*root == NULL) {
    printf("The tree is empty\n");
    return 1;
  }
  return 0;
}

int searchValue(Node *root, int value) {
  Node *aux = root;

  if (isEmpty(&aux))
    return 0;
  if (aux->data == value)
    return 1;

  if (value > aux->data)
    return searchValue(aux->right, value);

  else
    return searchValue(aux->left, value);
}

void inOrdem(Node *root) {
  if (root != NULL) {
    inOrdem(root->left);
    printf("%d ", root->data);
    inOrdem(root->right);
  }
  return;
}

void preOrder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
     preOrder(root->left);
     preOrder(root->right);
  }
  return;
}

void postOrder(Node *root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}