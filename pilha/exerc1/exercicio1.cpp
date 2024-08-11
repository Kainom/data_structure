#include <stdio.h>
#include <stdlib.h>

#define  TAM 4
int vetor[TAM];
int top = -1;
int itera = 0;

void push(int valor);
int vazia();
void pop();
void topoPilha();
void imprime();

int main(){
   push(1);
   push(2);
   push(3);
   push(4);
   push(5);
  topoPilha();
   pop();
   pop(); 
   pop();
   pop(); 
  imprime();


	return 0;
}


void push(int valor){
	if(top == (TAM-1))return;

	vetor[++top] = valor;

}

int vazia(){
	if(top == -1) return 1;
	return 0;
}

void imprime(){
	if(vazia()) {
		printf("Pilha Vazia \n");
		return;
	}
	for(int i =0;i<=top;i++){
		printf("%d ",vetor[i]);
	}
}

void  topoPilha(){
	if(vazia()){
		printf("Pilha Vazia \n");
		return;
	}
	printf("Valor no topo: %d \n",vetor[top]);
}

void pop(){
	if(vazia()) return;
	top--;
}

	
