/* Fa�a um jogo de loteria! O programa sorteia 6 n�meros (chamadas dezenas) de 1 a 60 e pede
para o jogador escolher 6 n�meros de 1 a 60. O programa compara os n�meros escolhidos com os 
n�meros sorteados, mostra as dezenas sorteadas, as dezenas escolhidas pelo jogador e mostra o 
pr�mio conforme abaixo:
	6 acertos: R$ 1.000.000,00
	5 acertos: R$ 250.000,00
	4 acertos: R$ 50.000,00
	3 acertos: nada.
	2 acertos: nada.
	1 acerto: nada.
Obs.: validar os n�meros digitados pelo jogador, devem ser entre 1 e 60. */

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//setbuf(stdout,NULL); 
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// declara��es
	int loteria[6], i, teste, v, j, k, acerto;
	int aposta[6];  // n�meros apostados
	
	// recebendo valores
	
	for (i = 0; i < 6; i++){     // sorteia 6 n�meros de 1 - 60 que n�o se repetem
		if(i == 0){                        
			loteria[i] = 1 + rand() %60;     
		}else {                            
		teste = 0;
			while(teste == 0){            
			teste++;
			v = 1 + rand() %60;           
	           	for (j = 0; j < i; j++) {  
					if (v == loteria[j]) { 
	                teste = 0;              
					}			     
				}
			}
		loteria[i] = v;                    
		}
	}
		
	for(k =0; k < 6; k++){
	teste = 0;
		while(teste == 0){
		printf("Digite o %d� n�mero de 1 � 60 para apostar na loteria: ", k+1);
		scanf(" %d", &aposta[k]);
			if (aposta[k] > 0 && aposta [k] < 61){
				teste = 1;
				break;
			}else {
				printf("O n�mero deve estar entre 1 e 60!\n");
				teste = 0;
			}
		}
	}
	
	// compara��o:
	acerto = 0;
	
	for (int m = 0; m < 6; m++){
		for (int n = 0; n < 6; n++){
			if (loteria[m] == aposta[n]){
				acerto++;
			} 
		}
	} 
	
	// resposta de tela
	printf("\nLoteria: ");
	for (int m = 0; m < 6; m++){
		printf(" %d", loteria[m]);
	}
	
	printf("\nApostas: ");
	for (int m = 0; m < 6; m++){
		printf(" %d", aposta[m]);
	}

	if(acerto == 1 || acerto == 2 || acerto == 3){
		printf("\nAcertos: %d", acerto);
		printf("\nPr�mio: nada.");
	} else if (acerto == 4){
		printf("\n4 acertos: R$ 50.000,00");
	} else if (acerto == 5){
		printf("\n5 acertos: R$ 250.000,00"); 
	} else if (acerto == 6){
		printf("\n6 acertos: R$ 1.000.000,00");
	} else {
		printf("\nBoa sorte na pr�xima vez!");	
	}
	
	return 0;
}	
