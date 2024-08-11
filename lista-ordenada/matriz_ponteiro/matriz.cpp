#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size);
void teste();
void teste2();

int value = 2;
int c0[] = {value, 10, 4, 6};
int c1[] = {5, 7, 8, 9};
int c2[] = {4, 1, 2, 3};
int c3[] = {5, 7, 9, 11};

int main()
{
    // teste();
    teste2();
    return 0;
}

void teste()
{
    printf("Teste1:\n");

    int *matriz[] = {c0, c1, c2, c3};
    printf("%p %p %p \n", *matriz, c0, &value);
    printf("%p %p \n", *(matriz + 1), c1);

    for (int i = 0, j = 0; i < 4; j++)
    {
        printf("%d ", matriz[i][j]);
        if (j == 3)
            printf("\n");
        i = (j == 3) ? ++i : i;
        j = (j == 3) ? -1 : j;
    }
}

void teste2()
{
    float matrx[50][50];
    float *p;
    int count;
    p = matrx[0];
    int *matriz[] = {c0, c1, c2, c3};
    
    int v = 5;
    int *p1 = &v;
    int **pp = &p1;

    // printf("%p: %p %p %p\n", *pp, pp, &pp,&v);  ***

    for (count = 0; count < 2500; count++)
    {
        *p = 0.0;
        p++;
    }
    int ** algo;
    algo = (int **) malloc(2* sizeof (int *));
    //&p p *p **p
    // printf("%p  %p\n", matrx,matrx[0]);
    // printf("0:%p %p\n", matrx[0], *matrx);
    // printf("0:%p  %p \n", matriz[0], matriz);
    printf("%d: %p %p %p\n", *(*matriz+8), matriz, &matriz,matriz[0]);
    // printf("0:%p %p\n", *matriz + 4, matriz[1]);
    // printf("0:%p %p\n", *matriz, matriz[0]);

    //o valor que a matriz armazena e seu proprio endereço

}
