
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  int bal; // Fator de balanceamento
  struct no *esq, *dir;
} No;

No *raiz_avl = NULL; // Raiz da árvore AVL

No *cria_no(int chave) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo != NULL) {
    novo->dado = chave;
    novo->bal = 0;
    novo->esq = novo->dir = NULL;
  }
  return novo;
}

void direita(No *x) {
  No *y = x->esq;
  x->esq = y->dir;
  y->dir = x;
  x->bal = 0;
}

void esquerda(No *x) {
  No *y = x->dir;
  x->dir = y->esq;
  y->esq = x;
  x->bal = 0;
}

void insere_bal(int chave) {
  No *pp = NULL, *p = raiz_avl, *pajovem = NULL, *ajovem = raiz_avl, *q, *filho;
  int imbal;

  if (p == NULL) {             
    raiz_avl = cria_no(chave); 
    return;
  }

  while (p != NULL) {
    if (chave < p->dado)
      q = p->esq;
    else
      q = p->dir;

    if (q != NULL)
      if (q->bal != 0) {
        pajovem = p;
        ajovem = q;
      }

    pp = p;
    p = q;
  }

  q = cria_no(chave);
  if (chave < pp->dado)
    pp->esq = q;
  else
    pp->dir = q;

  if (chave < ajovem->dado)
    filho = ajovem->esq;
  else
    filho = ajovem->dir;

  p = filho;
  while (p != q) {
    if (chave < p->dado) {
      p->bal = 1;
      p = p->esq;
    } else {
      p->bal = -1;
      p = p->dir;
    }
  }

  if (chave < ajovem->dado)
    imbal = 1;
  else
    imbal = -1;

  if (ajovem->bal == 0) { 
    ajovem->bal = imbal;
    return;
  }

  if (ajovem->bal != imbal) { 
    ajovem->bal = 0;
    return;
  }

  
  if (filho->bal == imbal) {
    p = filho;
    if (imbal == 1) 
      direita(ajovem);
    else 
      esquerda(ajovem);
    ajovem->bal = 0;
    filho->bal = 0;
  } else {
    if (imbal == 1) { 
      p = filho->dir;
      esquerda(filho);
      ajovem->esq = p;
      direita(ajovem);
    } else { 
      p = filho->esq;
      direita(filho);
      ajovem->dir = p;
      esquerda(ajovem);
    }

    if (p->bal == 0) {
      ajovem->bal = 0;
      filho->bal = 0;
    } else {
      if (p->bal == imbal) {
        ajovem->bal = -imbal;
        filho->bal = 0;
      } else {
        ajovem->bal = 0;
        filho->bal = imbal;
      }
    }
    p->bal = 0;
  }

  if (pajovem == NULL) 
    raiz_avl = p;
  else if (ajovem == pajovem->dir)
    pajovem->dir = p;
  else
    pajovem->esq = p;

  return;
}

void emOrdem(No *root) {
  if (root != NULL) {
    emOrdem(root->esq);
    printf("%d ", root->dado);
    emOrdem(root->dir);
  }
}

void posOrdem(No *root) {
  if (root != NULL) {
    posOrdem(root->esq);
    posOrdem(root->dir);
    printf("%d ", root->dado);
  }
}

void preOrdem(No *root) {
  if (root != NULL) {
    printf("%d ", root->dado);
    preOrdem(root->esq);
    preOrdem(root->dir);
  }
}

int busca(int value, No *raiz) {
  if (raiz == NULL)
    return -1;
  if (raiz->dado == value)
    return value;

  if (value < raiz->dado)
    return busca(value, raiz->esq);
  return busca(value, raiz->dir);
}

No* minimo(No* raiz) {
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

No* excluir(No* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->dado)
        raiz->esq = excluir(raiz->esq, valor);
    else if (valor > raiz->dado)
        raiz->dir = excluir(raiz->dir, valor);
    else {
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        No* temp = minimo(raiz->dir);
        raiz->dado = temp->dado;
        raiz->dir = excluir(raiz->dir, temp->dado);
    }

    return raiz;
}



int main() {
  insere_bal(30);
  insere_bal(20);
  insere_bal(10);

  printf("Em Ordem: ");
  emOrdem(raiz_avl);
  printf("\n");

  printf("Pre Ordem: ");
  preOrdem(raiz_avl);
  printf("\n");

  printf("Pos Ordem: ");
  posOrdem(raiz_avl);
  printf("\n");

  int value = 20;
  int result = busca(value, raiz_avl);
  if (result == -1) {
    printf("Elemento Nao encontrado");
  } else {
    printf("O Elemento %d foi encontrado: ", result);
  }

  raiz_avl = excluir(raiz_avl, 10);
  printf("\nEm Ordem Apos Remocao: ");
  emOrdem(raiz_avl);

  return 0;
}
