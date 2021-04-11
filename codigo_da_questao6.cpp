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


int ModuleAbs(int number)
{
    if (number<0) {return number*-1;}
    return number;
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

    scanf("%d %d", &x, &y);
    int mdc = MDCEuclides(x, y);
    DEBUG1{cout << "MDC: " << mdc << endl;}

    int coef[2]; //last and current
    
    SearchAB(x, y, coef);
    if ((-1*coef[0]*x) + (coef[1]*y) == mdc)
    {coef[0] = coef[0]*-1;}
    else if ((coef[0]*x) - (coef[1]*y) == mdc) {coef[1]=coef[1]*-1;}
    printf("MDC: %d = (%d)*%d + (%d)*%d\n", mdc, coef[0], x, coef[1], y);

    return 0;
}