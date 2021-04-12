#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

void geraPrimos(long long int numero){
    for(int i=3; i<sqrt(numero)+1; i++) if(numero%i == 0) return;
    cout<<numero<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    time_t start_t; //Criando variável pra guardar o tempo inicial do programa
    time(&start_t); //Aqui marca o tempo inicial do programa
    cout<<"2"<<" "; //Imprimindo o dois para evitar fazer a verificação de numeros pares

    long long int number = 3;
    while(difftime(time(NULL), start_t) < 60){
        geraPrimos(number);
        number = number+2;
    }

    cout<<"\nTempo de execucao = "<<difftime(time(NULL), start_t);
    return 0;
}