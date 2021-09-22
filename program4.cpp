// Fa�a um programa que leia os coeficientes a, b e c de uma equa��o de segundo grau, calcule o valor do discriminante delta D e os valores das ra�zes quadradas X1 e X2. No t�rmino, o programa deve mostrar as ra�zes para o usu�rio.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {
	
	setlocale(LC_ALL, "Portuguese");
    // declara��es
    float a, b, c, d, x1, x2;
    
    //recebendo valores
    printf("Informe o valor de A: ");
    scanf("%f", &a);
    
    printf("Informe o valor de B: ");
    scanf("%f", &b);
    
    printf("Informe o valor de C: ");
    scanf("%f", &c);
    
    //l�gica do programa
    d =  (b*b) -4 * a * c;
    
    if (d < 0 ){
    	printf("A equa��o n�o tem ra�zes reais pois d � menor que zero. ");
	}else{
		x1 = (-b - sqrtf(d)) / (2 * a);
		x2 = (-b + sqrtf(d)) / (2 * a);
		printf("Resultado x1: %.1f \nResultado x2: %.1f", x1, x2);
	}
    
    return 0;
}
