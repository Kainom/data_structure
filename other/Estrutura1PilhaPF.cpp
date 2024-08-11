#include <iostream> // biblioteca de entrada e saida em c++ //

using namespace std;
const int TAM = 8;
      int pilha[TAM];
      int topo=-1; // significa que a pilha se encontra vazia //
      
 void push(int valor){	;
	static int c;
	c++;
     if(topo == TAM-1){
        cout << "Pilha cheia \n ";
        return;         
     }
     topo++;
     pilha[topo] = valor ;
     cout <<c<<"Sucesso em dar push na pilha \n\n " ;      
}

void pop(){
  if(topo == -1){
    cout << "Pilha vazia\n ";
    return; 
  }
  topo = topo-1; // o topo  anterior vai existir,contudo,será ignorado //
  cout <<"Sucesso em dar pop na pilha \n\n";
}

void topo_pilha(){
     if(topo == -1){
         cout <<"Pilha vazia\n";
         return;            
     }
     cout << "Topo da pilha: " << pilha[topo] <<"\n\n";     
     
} 
void imprime(){
	int i = 0;
	int t = 0;
     if(topo == -1){
        cout <<"pilha vazia\n ";           
     }
     cout <<"Pilha total\n";
     for(i=topo;i>=0;i--){
     	t = pilha[i];
     	cout <<t << "\n";   
     }  
}     
     
     
  
int main(){
  push(10);
  push(5);
  push(15);
  pop();
  topo_pilha();
  imprime();
    
}
