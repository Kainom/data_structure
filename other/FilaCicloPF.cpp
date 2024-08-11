#include <iostream>

using namespace std;

const int TAM = 4;

int Fila[TAM];

int inicio = 0;
int fim = 0;
int contador = 0;

void Enqueue(int valor){
	if(contador == TAM){
		cout<<"Fila Cheia ";	                  //Nem sempre essa condicional é  utilizada,pois poder acabar sobrecarregando o sistema //
	 	return;					  				//Então nem todos os sistemas utilizam o mesmo modo //
   	}
    contador++;
    Fila[fim] = valor;                        // Poderia ser feito com apenas TAM,mas nesse o escopo seria diferente //                
   	if(fim==TAM-1){
   		fim=0;
	}
	else {
		fim++;
	}

}
void Dequeue(){
	if(contador==0){
		cout<<"Fila vazia";
		return;
	}
	contador--;
	if(inicio==TAM-1){
		inicio=0;
	}
	else {
		inicio++;	
	}
}

void Frente(){
	if(contador==0){
		cout<<"Fila vazia";
		return;
	}
cout<<"Frente da fila eh"<<Fila[inicio]<<endl;

}
void Imprime(){
	int i =0;
	int j =0;
		if(contador==0){
			cout<<"Fila vazia"<<endl;
			return;
		}
	j=inicio;
	while(i<contador){
		cout<<Fila[j]<<" ";
		if(j==TAM-1){
			j=0;	
		}
		else{
			j++;
		}
		i++;
		cout<<endl;
	}
}

int main(){
	Enqueue(8);
	Enqueue(8);
	Enqueue(8);
	Enqueue(8);
	Dequeue();
	Imprime();

	
}
