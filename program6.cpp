//Fa�a um programa que calcule o fatorial de um n�mero inteiro informado pelo usu�rio. Validar a entrada pois o n�mero precisa ser positivo.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	//declarando vari�veis
	int num, fato;
	
	//recebendo valores
	num = -6;
	
	while (num < 0){
		printf("Digite um n�mero inteiro pra saber sua fatorial: ");
		scanf(" %d", &num);
	}
	
	//l�gica do programa
	if (num > 0){
		for(fato = 1; num > 1; num--){
			fato = fato * num;
		}
		printf("\nFatorial calculado: %d", fato);
	}
	else if(num == 0){
		printf("\nFatorial calculado: 1");
	}

return 0;
}
