#include <stdio.h>

void loopSolucoes(int mdc, int x, int m, int cnt) {
    if (cnt == mdc) return;
    else {
        printf("Solução %d: %d\n", cnt + 1, x + (m * cnt));
        loopSolucoes(mdc, x, m, cnt + 1);
    }
}

int valorInicial(int a, int m, int cnt) {
    if ((a * cnt) % m == 1 && cnt < m) return cnt;
    else return valorInicial(a, m, cnt + 1);
}

int MDCEuclides(int n, int d) { 
    if (d==0) return n;
    return MDCEuclides(d, n % d);
}


void verificadora() {
    int a, b, m, mdc, x;
    scanf("%d %d %d", &a, &b, &m);
    mdc = MDCEuclides(a, m);
    if (b % MDCEuclides(a, m) == 0) {
        if (mdc == 1) {
            x = (valorInicial(a, m, 0) * b) % m;
            printf("\nTemos UMA solução para x, sendo x > 0 e x < m\nX = %d \n", x);
        }
        else {
            a /= mdc;
            b /= mdc;
            m /= mdc;
            x = (valorInicial(a, m, 0) * b) % m;
            printf("\nTemos %d soluções para x.\n", mdc);
            loopSolucoes(mdc, x, m, 0);
        }
    }
    else printf("\n%dx ≡ %d mod %d não tem solução\n", a, b, m);
    return;
}

int main() {
    printf("Digite \"a\", \"b\" e \"m\" para a expresão: \"a.x ≡ b mod m\".\n");    
    verificadora();
    return 0;
}
