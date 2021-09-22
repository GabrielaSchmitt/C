/* Faça um programa que simule um jogo da memória. O programa sorteia 10 números inteiros de 1 a 10,
mostra a sequência sorteada para o jogador durante 3 segundos e apaga a tela. O jogador tenta escrever
a sequência de números conforme foi mostrada. O programa compara as duas sequências e a cada acerto de
um número da sequência, o jogador ganha um ponto. No final, o programa mostra a sequência sorteada, a
sequência digitada pelo jogador e a pontuação final. Caso o jogador tenha feito 10 pontos, mostrar uma
mensagem de parabéns! 
Obs.: validar os números digitados pelo jogador, ou seja, deve ser entre 1 e 10. */

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
	int jogo[10], i, j, teste, v, guess[10], acerto;
	acerto = 0;
	
	
	// lógica do programa 
	for (i = 0; i < 10; i++){     // sorteia 10 números de 1 - 10 que não se repetem
		if(i == 0){                        
			jogo[i] = 1 + rand() % 10;     
		}else {                            
		teste = 0;
			while(teste == 0){            
			teste++;
			v = 1 + rand() %10;           
	           	for (j = 0; j < i; j++) {  
					if (v == jogo[j]) { 
	                teste = 0;              
					}			     
				}
			}
		jogo[i] = v;                    
		}
	}
	
	// tela
	printf("\MEMORIZE OS NÚMEROS A SEGUIR: ");
	Sleep(3000);       // Sleep 3 segundos
	system("cls");     // Limpa tela

	printf("\nJogo: "); 
	for (int m = 0; m < 10; m++){
		printf(" %d", jogo[m]);
	}

	Sleep(3000);      // Sleep 3 segundos
	system("cls");    // limpa a tela
	
	// recebendo valores
	printf("\Digite a sequência memorizada: ");
	scanf(" %d %d %d %d %d %d %d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3], &guess[4], &guess[5], &guess[6], &guess[7], &guess[8], &guess[9]);
	for(int n = 0; n < 10; n++){
	if (guess[n] > 10 || guess[n] < 1){
		printf("Só são aceitos números de 1 à 10! \nDigite novamente o %d° número da sequência: ", n+1);
		scanf(" %d", &guess[n]);
		Sleep(3000);      // Sleep 3 segundos
	}
	}
	
	// comparando
	for (int e = 0; e < 10; e++){
		if (guess[e] == jogo[e]){
		acerto++; 
		} 	
	}
	
	// mostrando a sequencia do jogo e de chute
	printf("\n     Jogo: ");
	for (int m = 0; m < 10; m++){
		printf(" %d", jogo[m]);
	}
	
	printf("\nSequência: ");
	for (int m = 0; m < 10; m++){
		printf(" %d", guess[m]);
	}
	
	// mensagem de acerto
	if (acerto == 10){
	printf("\nParabéns você acertou! ");	
	} else {
	printf("\nVocê acertou %d números.", acerto);
	}	

	return 0;
}
