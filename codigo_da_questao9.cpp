#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define DEBUG1 if(0) //to inputs
#define DEBUG2 if(0) //to process and outputs
#define LEN_VEC 1000

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

    // DEBUG2{printf("init - q: %d, coefs: %d, %d\n", q, coef[0], coef[1]);}
    if (n%d!=0)
    {
        int old = coef[1];
        coef[1] = (coef[1] * q) + coef[0];
        coef[0] = old;
    }
    // if ((n%d)!=0){coef[1] = (coef[1] * q) + coef[0];}
    // else {coef[1]=1;}
    // DEBUG2{printf("q: %d, coefs: %d, %d\n--\n", q, coef[0], coef[1]);}

    return mdc;
}


int CongruSoluctions(int a, int b, int m, int mdc, int coef[], int solu[])
{
    // initiliaze the vector of soluctions with negative ones
    for (int j=0; j<LEN_VEC; ++j)
    {solu[j]=-1;}

    if (mdc == 1)
    {
        SearchAB(a, m, coef);
        if ((-1*coef[0]*a) + (coef[1]*m) == mdc)
        {coef[0] = coef[0]*-1;}
        else if ((coef[0]*a) - (coef[1]*m) == mdc) {coef[1]=coef[1]*-1;}
        DEBUG2{printf("MDC: %d = (%d)*%d + (%d)*%d\n", mdc, coef[0], a, coef[1], m);}
        DEBUG2{printf("coefs: %d, %d\n", coef[0], coef[1]);}
        // DEBUG2{printf("a,b,m: %d, %d, %d\n", a, b, m);}
        
        int x = coef[0]*b;
        while (x<0) {x+=m;}
        if (x>m) {x=x%m;}
        solu[0] = x;
        DEBUG2{{printf("Solucao unica. O conjunto solucao e S={%d}.\n", x);}}
        return 1; //With only one soluction
    }
    else if ((mdc > 1) && (b % mdc == 0))
    {
        // printf("A congruencia tem d=%d solucoes.\n", mdc);
        int a1, m1, mdc1, b1;
        int coef2[2];
        
        a1 = a/mdc;
        b1 = b/mdc;
        m1 = m/mdc;
        DEBUG2{printf("a1, m1: %d, %d\n", a1, m1);}

        mdc1 = SearchAB(a1, m1, coef2);
        DEBUG2{printf("MDC1 search: %d\n", mdc1);}
        if ((-1*coef2[0]*a1) + (coef2[1]*m1) == mdc1)
        {coef2[0] = coef2[0]*-1;}
        else if ((coef2[0]*a1) - (coef2[1]*m1) == mdc1) {coef2[1]=coef2[1]*-1;}
        DEBUG2{printf("coefs2: %d, %d\n", coef2[0], coef2[1]);}

        int x = b1 * coef2[0];
        while (x<0) {x=x+m1;} //adjust the x
        if (x>m) {x=x%m;} //adjust the x
        DEBUG2{printf("x = %d\n", x);}

        for (int i=0; i<mdc; ++i)
        {
            solu[i] = x+(m1*i);
        }
        return 2; // With multiples soluctions
    }
    else
    {
        DEBUG2{printf("A congruencia nao tem solucoes.\n");}
        return 0; //NO soluctions!!
    }
    DEBUG2{printf("Invalid output!!\n");}
    return -3; //Invalid output
}


int NCongruenciasTCR(int data_congru[][3], int lines, int great_m)
{
    /*
    It use the teorem chine of scrap to return x0 that the soluctions of system of
    congruencias
    */
    int mdc_modules = MDCEuclides(data_congru[0][2], data_congru[1][2]);
    for (int i=0; i<lines; ++i)
    {
        for (int j=0; j<lines; ++j)
        {
            if (i!=j)
            {
                mdc_modules = MDCEuclides(data_congru[i][2], data_congru[j][2]);
                if (mdc_modules!=1) {return -1;} //The modules values no are coprimos
            }
        }
    }
    
    int x0 = 0;
    int news_m[lines];
    if (mdc_modules==1)
    {
        for (int k=0; k<lines; ++k)
        {
            
            news_m[k] = great_m/data_congru[k][2];
            int soluctions[LEN_VEC];
            int coef[2]; //Only to the to stock the coeficients
            // SearchAB(news_m[k], data_congru[k][2], coef);
            // int mdc2 = MDCEuclides(news_m[k], data_congru[k][2]);
            CongruSoluctions(news_m[k], 1, data_congru[k][2],
             mdc_modules, coef, soluctions);
            // DEBUG2{printf("AQUI!!\n");}
            // DEBUG2{printf("s=%d\n", soluctions[0]);}
            // DEBUG2{printf("AQUI!!\n");}
            data_congru[k][0] = soluctions[0];
            // DEBUG2{printf("AQUI!!\n");}
            DEBUG2{printf("s=%d, new_m=%d.\n", data_congru[k][0], news_m[k]);}
            x0 = x0 + (news_m[k]*data_congru[k][0]*data_congru[k][1]);
            DEBUG2{printf("x0=%d.\n", x0);}
        }
        return x0;
    }
    // else if (mdc>1)

    return -10; //the wrong output!!
}


int main()
{
    int n = 3;
    int great_m;
    int data_congru[n][3]; 
    //It's array above contain the for each n congruencia, values: x=s, r and m.
    
    great_m = 1;
    for (int i=0; i<n; ++i)
    {
        //it get the inputs 
        printf("Digite r e m para a congruencia %d (x congruente a r mod m):\n", i);
        scanf("%d %d", &data_congru[i][1], &data_congru[i][2]);
        getchar();
        great_m *= data_congru[i][2]; //It calcule the M
        DEBUG2{printf("%d - r=%d, m=%d, M=%d.\n", i, data_congru[i][1], data_congru[i][2], great_m);}
    }

    int x = NCongruenciasTCR(data_congru, n, great_m);
    if (x > 0) {printf("A solucao do sistema é X0 = %d.\n", x);}
    else {printf("O sistema de congruencias nao possui solucao.\n");}

    return 0;
}