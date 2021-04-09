#include <stdio.h>
#include <iostream>
#include <math.h>
#define DEBUG1 if(0)
#define DEBUG2 if(0)

using namespace std;


int IsPrimo(int number)
{
    int end = sqrt(number);
    DEBUG1{printf("raiz de n: %d\n", end);}
    if ((number < 2) && (number > -2))
    {DEBUG1{printf("Is here?\n");}return 0;}
    for (int i=2; i<=end; ++i)
    {
        if (number%i==0)
        {
            DEBUG1{printf("i: %d\n", i);}
            return 0;
        }
    }
    return 1;
}


int main()
{
    int n;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    printf("\n");

    int is_primo = IsPrimo(n);
    if (is_primo == 1)
    {printf("%d é um número primo.\n", n);}
    else {printf("%d não é número primo.\n", n);}

    return 0;
}