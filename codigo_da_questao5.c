#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int mdcEuclides(int n1, int n2){
    if(n1%n2 == 0) return n2;
    else return mdcEuclides(n2, n1%n2);
}

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", mdcEuclides(n1, n2));
	return 0;
}