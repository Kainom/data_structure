#include <cstddef>
#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} Celula;

Celula *criaNo(int valor)
{                                                    // cria um no e retorna esse mesmo
    Celula *novo = (Celula *)malloc(sizeof(Celula)); // aloca espaço para um ponteiro de estrutc  // #int == 0 and #ponteiro == 1
    novo->dado = valor;                              // 10
    novo->prox = NULL;
    return novo;
}

void insereNoInicio(Celula **inicio, int valor)
{
    Celula *novo = criaNo(valor);
    novo->prox = *inicio;   // 1 == null
    (*novo).prox = *inicio; // novo.prox
    *inicio = novo;         // recebe endereço do novo struc alocado dinamicamente
}

void imprimeFila(Celula *inicio)
{
    Celula *aux = inicio; // === igual ao # do struct com o dado == 30
    while (aux != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void remove(Celula **inicio)
{
    Celula *aux = *inicio;
    if (aux != NULL)
    {
        // *inicio = aux->prox;
        // *inicio = (*inicio)->prox;
        // *inicio = (**inicio).prox; // pp -> p -> structc;
        *inicio = (*inicio)->prox;

        free(aux); // libera a memoria da celula que foi removida
    }
    else
    {
        printf("Fila vazia.\n"); // caso a fila seja vazia, não há nada para remover
    }
}

void remove(Celula **inicio, int value)
{

    Celula *ant = *inicio; // pasando o valor que o ponteiro inicio armazena,nesse caso endereço do struct
    Celula *aux = *inicio;

    if (*inicio == NULL)
    {
        printf("\nFila vazia.\n"); // caso a fila seja vazia, não há nada para remover
        return;                    // não precisa verificar se aux == NULL, pois a função remove se encarrega de verificar
    }

    if ((*inicio)->prox == NULL && aux->dado == value)
    {
        *inicio = NULL;
        free(aux);
        return;
    }

    while (ant->prox != NULL) // null  <- 10  _<-20   <- 30
    {
        printf("Ok ");
        if (aux->dado == value)
        {

            if (ant == aux)
            {
                *inicio = aux->prox;

                free(aux);
                // *inicio = NULL; // caso seja o primeiro elemento da fila
                return;
            }

            ant->prox = aux->prox; // remove a celula
            // free(aux->prox); // libera a memoria da celula que foi removida
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
    printf(" Valor não encontrado.\n");
}

int main()
{
    Celula inicio2;
    Celula *inicio = NULL;

    int teste = 5;
    int *ip1 = &teste;
    int *(*ipp) = &ip1;
    *ipp = &teste;

    printf("%d ", **ipp); // *ipp
    printf("%d ", teste);
    printf("%d \n", *ip1);

    insereNoInicio(&inicio, 10); // passa o endereço de inicio para manipução fora do main
    insereNoInicio(&inicio, 20);
    insereNoInicio(&inicio, 30);
    imprimeFila(inicio);
    remove(&inicio, 10);
    remove(&inicio, 20);
    remove(&inicio, 30);

    remove(&inicio);
    // remove(&inicio);
    // remove(&inicio);

    imprimeFila(inicio);
    



    return 0;
}
