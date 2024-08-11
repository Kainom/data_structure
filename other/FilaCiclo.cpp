#include <iostream>
using namespace std;
const int TAM = 6;
int inicio=-1,fim=-1,Fila[TAM],element=0,cont=-1,*contador=&cont;


void Enqueue(int valor){

			
	fim++;
	*contador+=1;
	if(cont==TAM){
		cout<<"FILHA CHEIA";
		exit(0);
	}
	
	
	
	fim = (fim==TAM)? 0 : fim;
	Fila[fim] = valor; 
	element++;
}

void Dequeue(){
	inicio++;
	inicio = (inicio==TAM-1) ? 0 : inicio;
	*contador-=1;
	element--;
}

void Elementos(){
	if(element==0){
		cout<<"Sem elementos";
		return;
	}
	cout<<element<<"\n";
			
}

void Inicio(){
	cout<<Fila[inicio]<<" <<<< INICIO\n";
}
void Fim(){
	cout<<Fila[fim]<<" <<<< FIM \n";
}



int main(){
	Enqueue(5);
	Enqueue(7);
	Enqueue(8);
	Enqueue(2);
	Enqueue(3);
	Dequeue();
	Dequeue()
	Fim();
	Inicio();
	
return 0;
}
