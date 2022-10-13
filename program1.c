//Faça um programa que leia os lados de um triângulo e informe qual o seu tipo: equilátero, isóceles ou escaleno. Os lados devem ser números inteiros, sem sinal.

#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");
    printf("--Analisador de Triângulos--\n ");
    
    // declare as variáveis que serão utilizadas
    float r1, r2, r3;
    
    //recebendo valores
    printf("Informe o Primeiro seguimento: ");
    scanf("%f", &r1);
    
    printf("Informe o Segundo seguimento: ");
    scanf("%f", &r2);
    
    printf("Informe o Terceiro seguimento: ");
    scanf("%f", &r3);

   //Lógica do programa
    if (r1 < r2 + r3 && r2 < r1 + r3 && r3 < r1 + r2)
    {
        printf("Os seguimentos informados podem formar um triângulo, ");
    if (r1 == r2  && r1 == r3){
            printf("Este é um triângulo Equilátero.");
    }
    else if (r1 != r2 && r2 != r3 && r1 != r3) {
            printf("Este triângulo é Escaleno.");
    }
    else if ((r1 == r2 && r1 != r3) || (r1 == r3 && r1 != r2) || (r2 == r3 && r2 != r1)){
        printf("Este triângulo é Isósceles.");
    }
    }
    else{ 
        printf("Os seguimentos informados NÃO podem formar um triângulo.");
    }
    return 0;
}
