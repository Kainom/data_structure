#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char data;
    struct no *next;
    char *p;
    /* data */
} No;

void push(int value, No **inicio);
void pushString(char value, No **inicio);

void pop(no **pilha);
void imprime(no **pilha);
void inverteOnlyValue(char string[], no **pilha);
void inverteArray(char string[], no **pilha);
void invertePilha(no **pilha);

// No *temp = NULL;
// No *current = *pilha;
// No *prev = NULL;

// while (current!= NULL)
// {
//     temp = current->next;
//     current->next = prev;
//     prev = current;
//     current = temp;
// }
// *pilha = prev;

int main()
{
    No *pilha = NULL;

    // char string[] = "abcd";
    // inverteOnlyValue(string, &pilha);
    // imprime(&pilha);
    // inverteArray(string, &pilha);

    pushString('a', &pilha);
    pushString('b', &pilha);
    pushString('c', &pilha);
    pushString('d', &pilha);
    pushString('e', &pilha);
    imprime(&pilha);
    invertePilha(&pilha);
    imprime(&pilha);

    return 0;
}

void push(int value, No **pilha)
{
    No *novo = (No *)malloc(sizeof(No));

    novo->data = value;
    novo->next = *pilha;
    *pilha = novo;
}

void pushString(char value, No **pilha)
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
        printf("data: %c ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void inverteOnlyValue(char string[], No **pilha)
{
    int tam = 0;
    for (tam; string[tam] != '\0'; tam++)
        for (int i = 0; i < tam; i++)
        {
            push(string[i], pilha);
        }
}

void inverteArray(char string[], No **pilha)
{
    int tam = 0;
    for (tam; string[tam] != '\0'; tam++)
        ;
    for (int i = tam - 1; i >= 0; i--)
    {
        push(string[i], pilha);
    }
}

void invertePilha(No **pilha)
{
    no *prox = NULL;
    no *anterior = NULL;
    no *atual = *pilha;

    while (atual != NULL)
    {
        prox = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = prox;
    }
    *pilha = anterior; // troca o ponteiro do topo da pilha para o novo topo invertido
}