#include <stdio.h>
#include <stdlib.h>

const int TAM = 3;

int fila[TAM];
int inicio = 0;
int fim = 0;
int elemento = 0;
void insereFila(int valor);
void removeFila();
void inicioFila();
void imprime();


int main(){
		removeFila();

		insereFila(10);
		insereFila(8);
		imprime();

		insereFila(12);
		insereFila(14);
		imprime();

		removeFila();
		imprime();

		insereFila(14);
		imprime();
		//printf("%d inicio\n",inicio);
		//printf("%d\n",fila[fim]);
		inicioFila();
		insereFila(16);
		removeFila();
		removeFila();
		removeFila();
		imprime();
		return 0;
}

void insereFila(int valor){
	if(elemento == TAM){
	printf("\nFila cheia\n");
		return;
	}

	if(fim == TAM ){
		fim = 0;	
 	} 
	   
	
	elemento++;
	fila[fim] = valor; 
	printf("%d\n",elemento);
	fim++;

}

void removeFila(){
	if(elemento == 0){ 
		imprime();
		return;
	}

	elemento--;

	if(inicio == TAM){
		inicio = 0;
		return;
	}

	inicio++;
  

}


void inicioFila(){
	if(elemento == 0) return;
	printf("%d\n",fila[inicio]);
}



void imprime(){
	if(elemento == 0){
		printf("Fila Vazia\n");
		return;
	}



	
     if(fim >inicio){
	    for(int i = inicio; i < fim; i++){
                printf("%d ",fila[i]);
         }
		printf("\n");
		return;
    }

		for(int i = inicio; i < TAM; i++){
			printf("%d ",fila[i]);
		}

			printf("%d",fila[fim-1]);
	
   printf("\n");	
}

