#include <stdio.h>
#include <iostream>
#include <math.h>
#define DEBUG1 if(0)
#define DEBUG2 if(0)

using namespace std;


int IsPrimo(int number)
{
    int end = sqrt(number);
    // DEBUG1{printf("raiz de n: %d\n", end);}
    if ((number < 2) && (number > -2))
    {
        //DEBUG1{printf("Is here?\n");}
        return 0;
    }
    for (int i=2; i<=end; ++i)
    {
        if (number%i==0)
        {
            // DEBUG1{printf("i: %d\n", i);}
            return 0;
        }
    }
    return 1;
}


int NextPrimo(int number)
{
    // It's return the next after of number in parameter.
    if (IsPrimo(number+1)==1)
    {return number+1;}
    else {return NextPrimo(number+1);}
    return 0;
}


int TheGreater(int x, int y)
{
    //It forever return the greater number into at two paremeters inserteds
    if (x>y) {return x;}
    else if (x<y) {return y;}
    return x; // If two values are equals
}
int TheLower(int x, int y)
{
    //It return the the minor value into two values in parameters
    if (x>y) {return y;}
    else if (x<y) {return x;}
    return x; //if values are equals!!
}


void InitVecOnes(int len, int array[][2])
{
    for (int i=0; i<len; ++i)
    {
        array[i][0]=1;
        array[i][1]=1;
    }
    return;
}


int IsAllOne(int len, int array[])
{
    //DEPRECATED!!!
    for (int i=0; i<len; ++i)
    {
        if (array[i]!=1) {return 0;}
    }
    return 1;
}


int RunDividing(int a, int b, int lenght, int factors[][2])
{
    //It make the factorization of elements in each step
    int divisor = 2; //first primo
    // int is_all_one = IsAllOne(lenght, factors);
    int have_div = 0;
    int i = 0;
    while (a!=1 || b!=1)
    {
        // for (int i=0; i<lenght; ++i)
        // {
            if (a%divisor==0)
            {
                factors[i][0] *= divisor;
                a /= divisor;
                have_div = 1;
            }
            if (b%divisor==0)
            {
                factors[i][1] *= divisor;
                b /= divisor;
                have_div = 1;
            }
        // }
        if (have_div==0)
        {
            i += 1;
            divisor = NextPrimo(divisor);
        }
        have_div = 0;
    }
    return 0;
}


int main()
{
    int a, b;

    printf("Digite dois números inteiros (a e b): ");
    scanf("%d %d", &a, &b);
    int len = TheGreater(a, b);
    int factors[len][2];
    InitVecOnes(len, factors);
    printf("\n");
    DEBUG1{cout << "Próximo primo de a: " << NextPrimo(a) << endl;}
    DEBUG1{printf("Quem é maior? a ou b? %d\n", TheGreater(a, b));}   
    
    RunDividing(a, b, len, factors);
    int mmc, mdc;
    mmc = mdc = 1;
    for (int i=0; i<len; ++i)
    {
        DEBUG2{printf("factors: %d-%d\n", factors[i][0], factors[i][1]);}
        mmc *= TheGreater(factors[i][0], factors[i][1]);
        mdc *= TheLower(factors[i][0], factors[i][1]);
    }
    cout << "MDC: " << mdc << endl << "MMC: " << mmc << endl;

    return 0;
}
