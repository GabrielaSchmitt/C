//Fa�a um jogo de adivinha��o em que programa sorteia um n�mero inteiro positivo de 0 a 100 e o jogador tem 10 tentativas (vidas) para acertar. Em cada tentativa, l� o n�mero digitado pelo jogador e mostra uma dica. Essa dica consiste em informar se o n�mero digitado � maior ou menor que o n�mero sorteado. Caso o jogador acerte, o jogo termina informando que o jogador venceu, caso as vidas acabem, o jogo termina informando que o jogador perdeu. O programa deve validar o n�mero digitado pois o valor precisa ser entre 0 e 100.

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//setbuf(stdout,NULL);
	setlocale(LC_ALL, "Portuguese");

  	// declare as vari�veis do sistema
  	int vidas, num, chute;

  	printf("Bem vindo ao jogo da adivinha��o, voc� possui 10 vidas. O jogo consiste em adivinhar o n�mero aleat�rio de 0-100 que o programa selecionou, a cada chute ele te dar� dicas. Boa sorte!\n");

  	// recebendo valores
  	vidas = 10;
  	srand(time(NULL));
  	num = 1 + rand() %101;

  	// l�gica do programa
  	while(vidas != 0){
    	printf("Vidas: %d\n", vidas);
    	printf("Digite um n�mero entre 0 a 100: ");
    	scanf(" %d", &chute);
    	if(chute > 0 && chute < 100){
    		if(chute == num){
      			printf("\nParab�ns voc� acertou!\n");
			      printf("Total de vidas: %d", vidas);
			      break;
    }
    else if (chute < num){
      printf("O n�mero digitado � menor que o que esta procurando, tente um valor maior.");
      vidas = vidas -1;
    }
    else if (chute > num){
      printf("O n�mero digitado � maior que o que esta procurando, tente um valor menor.");
      vidas = vidas -1;
    }
    }else{
      printf("Digite um n�mero v�lido. Entre 0 e 100.\n");
    }
  }

	if (vidas = 0){
		printf("Que pena! Suas vidas acabaram, tente novamente!");
		printf("O n�mero aleat�rio era %d", num);
	}

  return 0;
}
