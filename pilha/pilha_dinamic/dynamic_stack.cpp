#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int data;
    struct no *next;
    /* data */
} No;

void push(int value, No **inicio);
void pop(no **pilha);
void imprime(no **pilha);
int main()
{
    No *pilha = NULL;

    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    imprime(&pilha);
    pop(&pilha);
    printf("\n");
    imprime(&pilha);

}

void push(int value, No **pilha)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->data = value;
    novo->next = *pilha;
    *pilha = novo;
}

void pop(no **pilha) // pilha -> *pilha -> **pilha -> struct no (bloco de memoria ou endereços consecutivos)  // *stack != *stack when  one the stack is  pointer for pointer
{
    if (*pilha == NULL)
    {
        printf("Pilha vazia.\n");
        return;
    }

    no *aux = *pilha;
    *pilha = (**pilha).next;
    // *pilha = (*pilha)->next;
    free(aux);
}

void imprime(no **pilha)
{
    No *aux = *pilha;

    while (aux != NULL)
    {
        printf("data: %d\n", aux->data);
        aux = aux->next;
    }
}
