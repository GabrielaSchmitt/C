//Fa�a um programa que leia os lados de um tri�ngulo e informe qual o seu tipo: equil�tero, is�celes ou escaleno. Os lados devem ser n�meros inteiros, sem sinal.

#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");
    printf("--Analisador de Tri�ngulos--\n ");
    
    // declare as vari�veis que ser�o utilizadas
    float r1, r2, r3;
    
    //recebendo valores
    printf("Informe o Primeiro seguimento: ");
    scanf("%f", &r1);
    
    printf("Informe o Segundo seguimento: ");
    scanf("%f", &r2);
    
    printf("Informe o Terceiro seguimento: ");
    scanf("%f", &r3);

   //L�gica do programa
    if (r1 < r2 + r3 && r2 < r1 + r3 && r3 < r1 + r2)
    {
        printf("Os seguimentos informados podem formar um tri�ngulo, ");
    if (r1 == r2  && r1 == r3){
            printf("Este � um tri�ngulo Equil�tero.");
    }
    else if (r1 != r2 && r2 != r3 && r1 != r3) {
            printf("Este tri�ngulo � Escaleno.");
    }
    else if ((r1 == r2 && r1 != r3) || (r1 == r3 && r1 != r2) || (r2 == r3 && r2 != r1)){
        printf("Este tri�ngulo � Is�sceles.");
    }
    }
    else{ 
        printf("Os seguimentos informados N�O podem formar um tri�ngulo.");
    }
    return 0;
}
