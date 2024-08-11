#include <stdio.h>
#include <stdlib.h>
#define N 100

// Esta função devolve 1 se a string s contém uma
// sequência bem-formada de parênteses e colchetes
// e devolve 0 se a sequência é malformada.

int main () {
   char	s[9] = "()";
   char pilha[N]; int t; 
   int i;
   printf("%c",s[0]);

   t = 0;
   for (i = 0; s[i] != '\0'; ++i) {
      // pilha[0..t-1] é uma pilha de '(' e '['
      switch (s[i]) {
         case ')': if (t == 0) return 0;
                   if (pilha[--t] != '(') return 0; 
                   break;
         case ']': if (t == 0) return 0;
                   if (pilha[--t] != '[') return 0; 
                   break;
         default:  pilha[t++] = s[i];
      }
   }
		if(t == 0 ){
			int b = t;
			printf("%d opa",t);
		} else{
			printf("%d",t);
		}
   return t == 0;
}



