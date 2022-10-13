/* Faça um programa que jogue par ou ímpar com o usuário. O programa pede para o 
jogador escolher a opção "P - Par" ou "I - Impar" e digitar um número de 1 a 5. 
Depois, o programa sorteia um número de 1 a 5. Caso a soma dos números corresponda 
a opção selecionada, o jogador ganha, caso contrário, o jogador perde. Ao término de 
cada partida, o programa pergunta ao jogador "S-Sim" ou "N-Nao" se ele quer jogar
 outra vez e mostra um placar (Computador: N pontos x Humano: M pontos). 
Caso o jogador opte pela opção "N-Nao", o programa termina.

Obs.: validar o número digitados pelo jogador, ou seja, deve ser entre 1 e 5. */

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

int main() {
	//setbuf(stdout,NULL); 
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// declarações
	int numUser, numMaquina, soma, computador, humano;
	char poui, again;
	
	computador = 0;
	humano = 0;
	again = 'S';
	
	while (again == 'S' || again == 's'){
	
		// recebendo valores
		printf("JOGO DO PAR OU ÍMPAR! \nEscolha [P] - PAR ou [I] - ÍMPAR: ");
		scanf(" %c", &poui);
		
		numUser = 0;
		while (numUser < 1 || numUser > 5){
			printf("Digite um número de 1 à 5: ");
			scanf(" %d", &numUser);
		}
		 
		numMaquina = 1 + rand() % 5; // recebendo valor da máquina
		printf("Computador: %d", numMaquina);
		
		// lógica do programa
		soma = numMaquina + numUser;
		printf("\nSoma: %d", soma);
		
		if (soma % 2 == 0) {
			if(poui == 'P' || poui == 'p'){
				printf("\nParabéns! Você ganhou.");
				humano++;
			} else {
				printf("\nVish! Você perdeu.");
				computador++;			
			}
		} else {
			if(poui == 'I' || poui == 'i'){
				printf("\nParabéns! Você ganhou.");
				humano++;
			} else {
				printf("\nVish! Você perdeu.");
				computador++;			
			}		
		}
		
		printf("\nPLACAR: \nComputador: %d pontos x Humano: %d pontos.", computador, humano);
		printf("\nGostaria de jogar novamente? [S] - sim, [N] - não: ");
		scanf(" %c", &again);
	}
	
	return 0;
}	
