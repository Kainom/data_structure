#include <stdio.h>
#include <stdlib.h>

const int SIZE = 100;
typedef struct
{
  int keys[SIZE];
  int n;
} Heap;

Heap *heap;
int insereHeap(int valor); // insert the value in heap
void maiorHeap();          // print the grreatest value in heap
void tresMaiores();
void removeHeap();         // remove the greatest value in heap
void lerArquivo();
void removeHeap();
int fatherOfIndex(int i);
int leftChildOfIndex(int i);
int rightChildOfIndex(int i);
int stay_heap(int index, int n, int keys[]);
void swap(int *children, int *parent);
void print();

int main()
{
  heap = (Heap *)malloc(sizeof(Heap));
  heap->n = 0;
  lerArquivo();
  print();
  tresMaiores();
  return 0;
}

void lerArquivo()
{

  FILE *arquivo;
  int numero;
  arquivo = fopen("numeros.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  int full = 0;
  while (fscanf(arquivo, "%d", &numero) != EOF)
  {
    full = insereHeap(numero);
    if (full)
      break;
  }
  fclose(arquivo);
}

int insereHeap(int value)
{
  if (heap->n == SIZE - 1)
  {
    printf("Heap Full.\n");
    return 1;
  }
  heap->n++;
  int i = heap->n;
  // heap->n++;
  heap->keys[i] = value;
  while (i > 1)
  { // in the first element is no necessary the looping
    int parent = fatherOfIndex(i);
    // check if  value is greater than parent
    if (heap->keys[i] > heap->keys[parent]) // 10 12 i=1 n=2
    {
      // if the value is greate,swap the parent with the children
      swap(&(heap->keys[i]), &(heap->keys[parent]));
      // 12 10
    }
    else
    // instead,just break out of looping
    {
      break;
    }
    // the index receives the parent, as it will be inserted again, to fix the heap
    i = parent;
  }
  return 0;
}

void removeHeap()
{

  if (heap->n == 0)
  {
    printf("Heap is empty.\n");
    return;
  }
  // the last element of the heap is moved to the root
  int high = heap->keys[1];
  heap->keys[1] = heap->keys[heap->n];
  heap->n--;
  stay_heap(1, heap->n, heap->keys);
}

int stay_heap(int index, int n, int keys[])
{
  int high = index;
  int left;
  int right;

  left = leftChildOfIndex(index);
  right = rightChildOfIndex(index);

  if (left <= n && keys[left] > keys[high])
    high = left;


//if the value right is greater than high(or the parent),so the it also is greater than left,because i checked the left first than right
  if (right <= n && keys[right] > keys[high])
    high = right;

//the base case occurs when the  high value  doesn't change,it is our stopping condition
  if (high != index)
  {
    swap(&keys[index], &keys[high]);
    stay_heap(high, n, keys);
  }
  return 0;
}

void maiorHeap()
{
  if (heap->n == 0)
  {
    printf("Heap is empty.\n");
    return;
  }
  printf("Highest value: %d\n", heap->keys[1]);
}
void tresMaiores(){
  if (heap->n < 3)
  {
    printf("Heap has less than 3 values.\n");
    return;
  }
  printf("The three highest values:\n");
  for (int i = 1; i <= 3; i++){
    printf("%d ", heap->keys[i]);
  }
}
int fatherOfIndex(int i)
{
  // return (i - 1) / 2;
  return i / 2;
}

int leftChildOfIndex(int i) { return 2 * i; }

int rightChildOfIndex(int i) { return 2 * i + 1; }

void swap(int *children, int *parent)
{
  int aux = *children;
  *children = *parent;
  *parent = aux;
}

void print()
{
  for (int i = 1; i <= heap->n; i++)
  {
    printf("%d ", heap->keys[i]);
  }
  printf("\n");
}
