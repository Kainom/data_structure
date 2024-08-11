#include <stdio.h>
#include <stdlib.h>

const int TAM = 3;
int elementos = 0;
int lista[TAM];

void insereLista(int value);
void recuperaLista(int pos);
void removeValue(int val);
void removeLista(int pos);

int listaVazia();
void imprime();

int main()
{
    insereLista(1);
    insereLista(3);
    insereLista(2);
    insereLista(4);
    printf("List antes da remoção: ");
    imprime();
    // removeLista(2);
    // removeLista(0);
    // removeLista(0);
    removeValue(3);
    removeValue(3);
    removeValue(2);
    recuperaLista(0);
    printf("List após remoção: ");
    imprime();

    return 0; // Indicate successful program execution
}

// the firts rule for the  ordenated list is always put the value in the first position
void insereLista(int value)
{
    int i = 0;
    if (elementos == TAM)
    {
        printf("A lista está cheia!\n");
        return;
    }

    for (i = elementos; elementos > 0 && value < lista[i - 1]; i--) //
    {
        lista[i] = lista[i - 1];
    }

    lista[i] = value;
    elementos++;
}

void imprime()
{
    if (elementos == 0)
    {
        printf("A lista está vazia!\n");
        return;
    }

    for (int i = 0; i < elementos; i++)
    {
        printf("%d ", lista[i]);
    }
}

int listaVazia()
{
    if (elementos == 0)
    {
        printf("A lista está vazia!\n");
        return 1;
    }
    return 0;
}

void removeLista(int pos)
{
    if (listaVazia())
    {
        return;
    }
    if (pos < 0 || pos >= elementos)
    {
        printf("\nPosição inválida!\n");
        return;
    }

    for (int i = pos; i < elementos - 1; i++) // 0 1 2  1 3 2
    {
        lista[i] = lista[i + 1];
    }
    elementos--;
}

void removeValue(int value)
{
    int i = 0;
    if (listaVazia())
    {
        return;
    }

    for (i = elementos - 1; i >= 0 && value != lista[i]; i--) // 0 1   1 2 
    if (i>=0) removeLista(i); 
}


void recuperaLista(int pos){
    if(listaVazia()) return;
    if (pos < 0 || pos >= elementos)
    {
        printf("\nPosição inválida!\n");
        return;
    }
    printf("\nO elemento na posição %d é: %d\n", pos, lista[pos]);
}
