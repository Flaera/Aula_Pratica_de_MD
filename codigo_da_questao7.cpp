#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define DEBUG1 if(0) //to inputs
#define DEBUG2 if(0) //to process and outputs

using namespace std;


int MDCEuclides(int n, int d)
{
    if (d==0) {return n;}
    return MDCEuclides(d, n%d);
}


int SearchAB(int n, int d, int coef[])
{
    int mdc;
    if (d==0)
    {
        return n;
    }
    int q;
    coef[0] = 0;
    coef[1] = 1;
    if (n%d!=0){q = n/d;}
    else {q=1;}
    mdc = SearchAB(d, n%d, coef);

    DEBUG2{printf("init - q: %d, coefs: %d, %d\n", q, coef[0], coef[1]);}
    if (n%d!=0)
    {
        int old = coef[1];
        coef[1] = (coef[1] * q) + coef[0];
        coef[0] = old;
    }
    // if ((n%d)!=0){coef[1] = (coef[1] * q) + coef[0];}
    // else {coef[1]=1;}
    DEBUG2{printf("q: %d, coefs: %d, %d\n--\n", q, coef[0], coef[1]);}

    return mdc;
}


/* talvez eu tenha que fazer uma funcao para identificar o maior
It code too is answer to question in TheHuxley site, after i can submite 
*/
int main()
{
    int x, y;

    printf("Determinação do inverso de a mod b.\n");
    printf("Digite \"a\" e \"b\" para a expresão: \"a mod b\".\n");
    scanf("%d %d", &x, &y);
    int mdc = MDCEuclides(x, y);
    DEBUG1{cout << "MDC: " << mdc << endl;}

    if (mdc == 1)
    {
        int coef[2];
        SearchAB(x, y, coef);
        if ((coef[0]*-1*x) + (coef[1]*y) == 1) {coef[0]*=-1;}
        else if ((coef[0]*x) - (coef[1]*y) == 1) {coef[1]*=-1;}
        printf("O inverso de %d mod %d é %d.\n", x, y, coef[0]);
        
        printf("Outros inversos de %d mod %d por meio de %d mod %d:\n",
         x, y, coef[0], y);
        for (int i=1; i<y; i+=1)
        {
            printf("%d, %d mod %d\n", coef[0]+y*i, coef[0]+y*i, y);
        }
    }
    else {printf("Sem solução! MDC de %d e %d não é igual a 1.\n", x, y);}

    return 0;
}