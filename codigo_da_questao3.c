#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#define ulli unsigned long long int

ulli primo(ulli number){
    if(number == 1 || number == 0) return 0;
    for(ulli i=2; i<number; i++){
        if(number%i == 0) return 0;
    }
    return 1;
}

void fatorarPrimos(ulli number){
    for(ulli i=2; i<=number; i++){
        if(i!=2 && i%2 == 0) continue;
        //printf("Numero atual: %lld i: %d\n", number, i);
        if(number == 1) return;

        if(number%i == 0){
            if(primo(i)){
                number = number/i;
                printf("%d ", i);
                i = 1;
            }
        }
    }
}

int main(){
    ulli number;
    scanf("%llu", &number);
    fatorarPrimos(number);
	return 0;
}