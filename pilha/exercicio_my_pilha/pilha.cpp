#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void empilhar(int *top, char pilha[], char valor);
void desempilhar(int *top, char pilha[]);
void input();
int operation(char valores[]);

int main()
{

  input();

  return 1;
}

void input()
{
  int escolha;
//  char initial[] = {'{', '(', '[', ']', ')', '}'};
   //char initial[] = {'(', ')'};
   char initial[] = {'(','('};
  do
  {
    int vazio = operation(initial);
    printf("\nTam: %d", vazio);
    printf("\n");
    printf("Escolha uma operacao: ");
    escolha = 0;
    scanf("%d", &escolha);
  } while (escolha != -1);
}

int operation(char valores[])
{
  int top = -1;
  int iterar = 0;
  char pilha[6];
  do
  {
    switch (pilha[top])
    {
    case '(':
      if (valores[iterar] == '(' || valores[iterar] == '{' || valores[iterar] == '[')
      {

        empilhar(&top, pilha, valores[iterar]);
        iterar++;
      }
      else if (valores[iterar] == ')')
      {
        desempilhar(&top, pilha);
        iterar++;
      }
      else
      {
        printf("%c", pilha[0]);
        printf("%c", pilha[1]);
        printf("%c", pilha[2]);
        printf("Parenteses não balanceados!\n");
        return -1;
      }
      break;

    case '[':
      if (valores[iterar] == '(' || valores[iterar] == '{' || valores[iterar] == '[')
      {
        empilhar(&top, pilha, valores[iterar]);
        iterar++;
      }
      else if (valores[iterar] == ']')
      {
        desempilhar(&top, pilha);
        iterar++;
      }
      else
      {
        printf("Parenteses não balanceados!\n");
        return -1;
      }
      break;

    case '{':
      if (valores[iterar] == '(' || valores[iterar] == '{' || valores[iterar] == '[')
      {
        empilhar(&top, pilha, valores[iterar]);
        iterar++;
      }
      else if (valores[iterar] == '}')
      {
        desempilhar(&top, pilha);
        iterar++;
      }
      else
      {
        printf("Parenteses não balanceados!\n");
        return -1;
      }
      break;

    default:
      if (iterar == 0 && top == -1)
        empilhar(&top, pilha, valores[iterar]);
      iterar++;
      break;
    }
  } while (top != -1);

  for (int i = 0; i < 6; i++)
  {
    printf("%c", pilha[i]);
  }

  return top;
}

void empilhar(int *top, char pilha[], char valor)
{
  (*top)++;
  pilha[*top] = valor;
}

void desempilhar(int *top, char pilha[])
{
  // pilha[*top] = ' ';

  --(*top);
}
