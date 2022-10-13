//Faça um programa que calcule o fatorial de um número inteiro informado pelo usuário. Validar a entrada pois o número precisa ser positivo.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	//declarando variáveis
	int num, fato;
	
	//recebendo valores
	num = -6;
	
	while (num < 0){
		printf("Digite um número inteiro pra saber sua fatorial: ");
		scanf(" %d", &num);
	}
	
	//lógica do programa
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
