#include <stdio.h>
#include <stdlib.h>

void remove(struct no **start);
void insert(struct no **start, struct no **end, int value);
void print(struct no **start, struct no **end);

struct no
{
    int data;
    struct no *next;
};

int main()
{

    struct no *end = NULL;
    struct no *start = NULL;
    struct no *teste;

    if (teste != NULL)
    {
        printf("Its' true\n");
        return 0;
    }

    insert(&start, &end, 10);
    insert(&start, &end, 20);
    insert(&start, &end, 30);
    print(&start, &end);
    remove(&start);
    remove(&start);
    remove(&start);
    remove(&start);
    printf("\nAfter removing\n");
    print(&start, &end);

    return 0;
}

void insert(struct no **start, struct no **end, int value)
{
    struct no *newNo = (struct no *)malloc(sizeof(struct no));
    newNo->data = value;
    (*newNo).next = NULL;
    if (*start == NULL)
    {
        *start = newNo;
        *end = newNo;
        return;
    }
    (**end).next = newNo;
    *end = newNo; // o fim esta apontando para Null implicitamente,vide ser um endereço inválido
}

void remove(struct no **start)
{
    if (*start == NULL)
    {
        printf("Was not  possible add in the list, it is  empty.\n");
        return;
    }

    struct no *aux = (*start)->next;
    free(*start);
    *start = aux;
}

void print(struct no **start, struct no **end)
{
    struct no *aux = *start;
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
}