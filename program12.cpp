/* Fa�a um programa que jogue par ou �mpar com o usu�rio. O programa pede para o 
jogador escolher a op��o "P - Par" ou "I - Impar" e digitar um n�mero de 1 a 5. 
Depois, o programa sorteia um n�mero de 1 a 5. Caso a soma dos n�meros corresponda 
a op��o selecionada, o jogador ganha, caso contr�rio, o jogador perde. Ao t�rmino de 
cada partida, o programa pergunta ao jogador "S-Sim" ou "N-Nao" se ele quer jogar
 outra vez e mostra um placar (Computador: N pontos x Humano: M pontos). 
Caso o jogador opte pela op��o "N-Nao", o programa termina.

Obs.: validar o n�mero digitados pelo jogador, ou seja, deve ser entre 1 e 5. */

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
	
	// declara��es
	int numUser, numMaquina, soma, computador, humano;
	char poui, again;
	
	computador = 0;
	humano = 0;
	again = 'S';
	
	while (again == 'S' || again == 's'){
	
		// recebendo valores
		printf("JOGO DO PAR OU �MPAR! \nEscolha [P] - PAR ou [I] - �MPAR: ");
		scanf(" %c", &poui);
		
		numUser = 0;
		while (numUser < 1 || numUser > 5){
			printf("Digite um n�mero de 1 � 5: ");
			scanf(" %d", &numUser);
		}
		 
		numMaquina = 1 + rand() % 5; // recebendo valor da m�quina
		printf("Computador: %d", numMaquina);
		
		// l�gica do programa
		soma = numMaquina + numUser;
		printf("\nSoma: %d", soma);
		
		if (soma % 2 == 0) {
			if(poui == 'P' || poui == 'p'){
				printf("\nParab�ns! Voc� ganhou.");
				humano++;
			} else {
				printf("\nVish! Voc� perdeu.");
				computador++;			
			}
		} else {
			if(poui == 'I' || poui == 'i'){
				printf("\nParab�ns! Voc� ganhou.");
				humano++;
			} else {
				printf("\nVish! Voc� perdeu.");
				computador++;			
			}		
		}
		
		printf("\nPLACAR: \nComputador: %d pontos x Humano: %d pontos.", computador, humano);
		printf("\nGostaria de jogar novamente? [S] - sim, [N] - n�o: ");
		scanf(" %c", &again);
	}
	
	return 0;
}	
