#include <stdio.h>
#include <stdlib.h>
#define LLI long long int

LLI mdcEuclides(LLI a, LLI b){
    if(a>b) return a%b == 0 ? b : mdcEuclides(b, a%b);
    else return b%a == 0 ? a : mdcEuclides(a, b%a);
}

LLI inversoModular(LLI a, LLI m){
    if(mdcEuclides(a, m) != 1) return 0;
    for(int i=0; i<m-1; i++) if((a*i)%m == 1) return i;
    return a;
}

void prodModulos(LLI m[], LLI mLinha[], LLI mLinhaInverso[], LLI prod[], int tamanho){
    LLI produto = 1;
    for(int i=0; i<tamanho; i++){
        produto *= m[i];
        prod[i] = m[i];
    }
    for(int i=0; i<tamanho; i++){
        prod[i] = produto/prod[i]; //Calcula o produto individual de cada modulo
        mLinha[i] = prod[i]%m[i]; //Calcula o resultado do produto pelo modulo
        mLinhaInverso[i] = inversoModular(mLinha[i], m[i]); //Calcula o inverso do produto pelo modulo
    }
    return;
}

void produtosFinais(LLI b[], LLI m[], LLI prod[], LLI mLinhaInverso[], int tamanho){
    LLI produtoFinal = 0;
    LLI produtoModulos = 1;

    for(int i=0; i<tamanho; i++){
        produtoModulos *= m[i];
        produtoFinal += b[i] * prod[i] * mLinhaInverso[i]; 
    } 

    printf("Produtos: %lld = %lld mod %lld\n", produtoFinal, produtoFinal%produtoModulos, produtoModulos);
    printf("Solucao: N = %lld*k + %lld\n", produtoModulos, produtoFinal%produtoModulos);
    return;
}

int main(){
    LLI nCongruencias;
    printf("Insira o numero de congruencias: ");
    scanf("%lld", &nCongruencias);

    LLI b[nCongruencias];
    LLI m[nCongruencias];
    LLI mLinha[nCongruencias];
    LLI mLinhaInverso[nCongruencias];
    LLI prod[nCongruencias];

    printf("Formato da equacao: Ax congruente b (mod m)\n");
    printf("Voce deve inserir os valores correspondentes para: b e m\n");

    for(int i=0; i<nCongruencias; i++){
        printf("b%d m%d: ", i+1, i+1);
        scanf("%lld %lld", &b[i], &m[i]);
    }

    prodModulos(m, mLinha, mLinhaInverso, prod, nCongruencias);
    produtosFinais(b, m, prod, mLinhaInverso, nCongruencias);
    return 0;
}