#include <stdio.h>
#include <stdlib.h>

void removeDequeue(struct no **start, struct no **end, struct no **previousLast, int lado);
void insertDequeue(struct no **start, struct no **end, struct no **previousLast, int value, int lado);
void initialDequeue(struct no **start, struct no **end);
void finalDequeue(struct no **end);
void print(struct no **start, struct no **end);

int removed = 0;
struct no
{
    int data;
    struct no *next;
};

int main()
{

    struct no *end = NULL;
    struct no *start = NULL;
    struct no *previousLast = NULL;

    insertDequeue(&start, &end, &previousLast, 2, 0);
    insertDequeue(&start, &end, &previousLast, 3, 0);
    insertDequeue(&start, &end, &previousLast, 4, 0);
    insertDequeue(&start, &end, &previousLast, 5, 1);
    initialDequeue(&start, &end);
    insertDequeue(&start, &end, &previousLast, 6, 1);
    insertDequeue(&start, &end, &previousLast, 7, 0);

    print(&start, &end);
    printf("\nAfter removing ");
    removeDequeue(&start, &end, &previousLast, 0);
    removeDequeue(&start, &end, &previousLast, 0);
    removeDequeue(&start, &end, &previousLast, 1);
    printf("%d elements\n", removed);
    print(&start, &end);
    finalDequeue(&end);
    initialDequeue(&start,&end);

    return 0;
}

void insertDequeue(struct no **start, struct no **end, struct no **previousLast, int value, int lado)
{
    struct no *newNo = (struct no *)malloc(sizeof(struct no));
    struct no *aux;
    newNo->data = value;
    (*newNo).next = NULL;
    if (*start == NULL) // start and end they are same
    {
        *start = newNo;
        *end = newNo;
        return;
    }
    if (lado)
    {
        *previousLast = *end;
        *end = newNo;
        (**previousLast).next = *end;
        return;
    }

    aux = *start; // 1 -> 0-> null
    *start = newNo;
    (*start)->next = aux;
}

void removeDequeue(struct no **start, struct no **end, struct no **previousLast, int lado)
{
    struct no *remove;
    if (*start == NULL)
    {
        printf("Was not  possible add in the list, it is  empty.\n");
        return;
    }
    removed++;

    if (lado && *start != *end)
    {
        free((*previousLast)->next);
        *end = *previousLast;
        (*end)->next = NULL;
        return;
    }
    remove = *start;
    *start = (**start).next;
    free(remove);
}

void print(struct no **start, struct no **end)
{
    struct no *aux = *start;
    printf("List elements: ");
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void finalDequeue(struct no **end)
{
    if (*end == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("The value of final is: %d\n", (*end)->data);
}

void initialDequeue(struct no **start, struct no **end)
{
    if (*start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("The valuez' of initial is: %d\n", (*start)->data);
}
