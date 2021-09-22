/* Fa�a um programa que calcule os valores de uma fun��o bivariada dada pela express�o: f(x,y) = x^2 + y^2 
 Os par�metros devem variar x: 0 <= x < 100, incrementando 2,5 a cada intera��o.
 							y: -100 < y <= 0, incrementando 5 a cada intera��o. */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
setbuf(stdout,NULL);

	//declara��es
	float n1, n2, resultado;
	
	//recebendo valores
	printf("Digite o primeiro n�mero a ser calculado de acordo com a fun��o: \n");
	scanf("%f",&n1);
	
	printf("Digite o segundo n�mero a ser calculado de acordo com a fun��o: \n");
	scanf("%f",&n2);
	
	//l�gica do programa
	while( !(( 0 <= n1 && n1 < 100 ) && ( -100 < n2 && n2 <= 0)) ){
		printf("O n�mero deve ser entre os intervalos delimitados! Tente novamente \n");
		scanf("%f%f",&n1,&n2);
	}
	int aux = n2;
	while( (( 0 <= n1 && n1 < 100 ) && ( -100 < n2 && n2 <= 0)) ){
		while( (( 0 <= n1 && n1 < 100 ) && ( -100 < n2 && n2 <= 0)) ){
			resultado = (pow(n2,2) + pow(n1,2));
			printf("f(%.2f,%.2f) = %.2f\n",n1 ,n2,resultado);
			n2+=5;
		}
		n1+=2.5;
		n2 = aux;
		printf("\n");
	}

return 0;
}


