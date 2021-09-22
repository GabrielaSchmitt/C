/* Fa�a um programa que sorteie 20 n�meros inteiros de 1 a 100 e mostre-os em ordem crescente.
Obs.: os n�meros sorteados n�o podem ter repeti��o.
Usei o bubble sort o qual se baseia do seguinte modo: imagine que h� bolhas embaixo da �gua e que as 
maiores sobem mais r�pido � superf�cie mas nesse caso n�o podem ocupar a mesma camada, deste modo a 
maior bolha ficaria mais pr�xima do topo e assim por diante. Esta � a teoria de ordem do bubble sort. */ 

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) // fun��o para fazer a troca de lugar dos valores
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
	//setbuf(stdout,NULL); 
	setlocale(LC_ALL, "Portuguese");
	
	// declara��es
	int vetor[20], i, v, teste, j;
	srand(time(NULL));
	
	// recebendo valores randomicos que n�o se repetem
	for(i = 0; i < 20; i++){               // valores dos vetores
		if(i == 0){                        // se for o primeiro vetor
			vetor[i] = 1 + rand() %101;    // apenas atribui valor a ele
		}else {                            // sen�o
		teste = 0;
			while(teste == 0){            
			teste++;
			v = 1 + rand() %101;           // randomiza n�mero p variavel v
	           	for (j = 0; j < i; j++) {  // percorre vetores j� preenchidos
					if (v == vetor[j]) {   // se o valor randomizado j� foi atribuido a um vetor
	                teste = 0;             // permanece dentro do while 
					}			     
				}
			}
		vetor[i] = v;                      // se o valor randomizado � unico perante aos vetores j� preenchidos, atribua-o
		}
	}
	
	// ordenando valores 
	int n = sizeof(vetor)/sizeof(vetor[0]);
    int k, l;
    for (k = 0; k < n-1; k++){ 
       for (l = 0; l < n-k-1; l++){
           if (vetor[l] > vetor[l+1]){
              swap(&vetor[l], &vetor[l+1]);
	}	}	}
              
	// tela de resposta ao usu�rio 
	printf("Sorted array: \n");
	for (int y=0; y < n; y++){
        printf("%d ", vetor[y]);
    	printf("\n");
	}
    	
    	return 0;
}
