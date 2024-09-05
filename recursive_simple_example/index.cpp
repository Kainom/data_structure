#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int recursive(int n);

int main(){
	int result = recursive(4);
	printf("Result: %d",result);
        return 0;
}


int recursive(int n){
	if(n == 0) return 0;

	return recursive(n-1) + pow(n,3);
}
