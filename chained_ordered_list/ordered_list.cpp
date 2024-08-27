#include <stdio.h>
#include <stdlib.h>

struct no
{
    int data;
    struct no *next;
} typedef Node;

struct remove
{
    int data;
    struct remove *next;
} typedef Remove;

void insertQueue(int data, Node **list);
void removeValue(int data, Node **list, Remove **value, Remove **end);
void recoverValue(int data, Node **list);
void printList(Node **list);
void printRemoved(Remove **values);

int main()
{
    Node *list = NULL;
    Node *end = NULL;
    Remove *value = NULL;
    Remove *endRemove = NULL;
    printf("\nBefore removing\n");
    insertQueue(20, &list);
    insertQueue(5, &list);
    insertQueue(10, &list);
    insertQueue(30, &list);
    insertQueue(-25, &list);
    insertQueue(15, &list);
    insertQueue(15, &list);
    printList(&list);

    printf("After removing\n");

    removeValue(30, &list, &value, &endRemove);
    removeValue(-25, &list, &value, &endRemove);
    removeValue(15, &list, &value, &endRemove);

    printList(&list);
    printRemoved(&value);

    return 0;
}

void insertQueue(int data, Node **list)
{
    Node *prox = NULL;
    Node *prev = NULL;
    Node *current = *list;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    // 10  20 30    -25-
    for (; current != NULL; current = current->next)
    {
        if (newNode->data < current->data)
        {
            if (current == *list)
            {
                newNode->next = current;
                *list = newNode;
                return;
            }

            prev->next = newNode;
            newNode->next = current;

            return;
        }
        prev = current;
    }
    prev->next = newNode;
}

void removeValue(int data, Node **list, Remove **value, Remove **end)
{
    Node *prev = *list;
    Remove *removed = (Remove *)malloc(sizeof(Remove));
    removed->next = NULL;
    if (*list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    for (Node *current = *list; current != NULL; current = current->next)
    {
        if (data == current->data)
        {
            if (*end == NULL)
            {
                removed->data = current->data;
                *value = removed;
                *end = removed;
            } // 30 -25 -15
            else
            {
                removed->data = current->data;
                (*end)->next = removed;
                *end = removed;
            }

            if (current == *list){
                *list = current->next;
            } else{
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
    }
    printf("Value not found in the list\n");
}

void printRemoved(Remove **values){
    if (*values == NULL){
        printf("no values removed\n");
        return;
    }
    printf("Values removed: ");
    for (Remove *removidos = *values; removidos != NULL; removidos = removidos->next)
    {
        if (removidos->next == NULL)
        {
            printf("%d\n", removidos->data);
        }
        else
        {
            printf("%d,", removidos->data);
        }
    }
}

void printList(Node **list)
{
    if (*list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *aux = *list;
    printf("List: ");
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}
