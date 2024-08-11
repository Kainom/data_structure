#include <iostream>

// Para o computador esse processo é mais lento //
using namespace std; // comando que permite a utilização das entradas e saidas em c++ // // define todas as funções da biblioteca padrão //
const int TAM = 6;
int Fila[TAM];
int denfi=-1,enfi=-1,*enfi1 = &enfi,inici=0,element=0,fim=0;

void Dequeue();

void Enqueue(int valor){
	*enfi1=*enfi1+1;
	Fila[enfi] = valor;	
	element++;
	if(enfi == TAM){
	  cout<<"Fila cheia \n";
	  exit(0);
	}
 inici = Fila[0];	
	
}

void Dequeue(){
	static int t;
	if(enfi== 0){
		cout<<"Fila vazia";
		exit(0);
	}
	
	denfi++;
	inici=denfi;
	for(denfi=0;denfi<=element-1;denfi++){
		Fila[denfi] = Fila[denfi+1];
		if(denfi == 0){
			inici = Fila[denfi];
		}
	}
	element--;
	*enfi1=*enfi1-1;
	
}

void Imprima(){
	int i = 0;
	
	
		for(i=0;i<=element-1;i++){
		printf("%d",Fila[i]);
	}
	
	printf("  <----- FILA");
	
	fim=Fila[element-1];

	
	
	printf("\nInicio %d\n",inici);
	printf("Elementos %d\n",element);
	printf("fim %d\n ",fim);



		
	
}

int main(){
 	
	Enqueue(8);
	Enqueue(2);
	Enqueue(6);
	Enqueue(4);	
	Enqueue(8);
	Enqueue(9);
	Dequeue();
	
	Imprima();
	return 0;
}

