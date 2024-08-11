
#include <stdio.h>
#include <stdlib.h>
#define  TAM 6

char vetor[TAM];
char pilha[TAM];
int top = -1;
int itera = 0;

int vazia();
int verificarExpressao();
void push(int valor);
void pop();


int main(){
	int sucess = 1;
	printf("Digite os parênteses: ");
	for(int i = 0; i < TAM; i++){
		scanf("%c",&vetor[i]);
		fflush(stdin);
	}


	 for(int i = 0; i< TAM; i++){
		 if(verificarExpressao() == 0){ 
			printf("Parentêses não corretamente balanceados1");
			exit(0);
	    }
	} 

       
	if(vazia()){
	  printf("Parentêses corretamente balanceados");
   	  return 0;
    }
	
	printf("Parentêses não corretamente balanceados");
	return 0;

}


void push(int valor){
     if(top == (TAM-1))return;
	 pilha[++top] = valor;
	 itera++;
}



int vazia(){
	if(top == -1) return 1;
	return 0;
}



void pop(){
	top--;
	itera++;
}

int verificarExpressao(){
	  switch(vetor[itera]){
		  case ')':
			    if(vazia()) return 0;
				if(pilha[top] == '('){
					pop();
					return 1; 
				}
			 	return 0;	
		default:
		   push(vetor[itera]);	
	 	   return 1;
	  }
	return 1;      
}

