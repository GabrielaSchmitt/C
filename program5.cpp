//Faça um jogo de adivinhação em que programa sorteia um número inteiro positivo de 0 a 100 e o jogador tem 10 tentativas (vidas) para acertar. Em cada tentativa, lê o número digitado pelo jogador e mostra uma dica. Essa dica consiste em informar se o número digitado é maior ou menor que o número sorteado. Caso o jogador acerte, o jogo termina informando que o jogador venceu, caso as vidas acabem, o jogo termina informando que o jogador perdeu. O programa deve validar o número digitado pois o valor precisa ser entre 0 e 100.

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	//setbuf(stdout,NULL);
	setlocale(LC_ALL, "Portuguese");

  	// declare as variáveis do sistema
  	int vidas, num, chute;

  	printf("Bem vindo ao jogo da adivinhação, você possui 10 vidas. O jogo consiste em adivinhar o número aleatório de 0-100 que o programa selecionou, a cada chute ele te dará dicas. Boa sorte!\n");

  	// recebendo valores
  	vidas = 10;
  	srand(time(NULL));
  	num = 1 + rand() %101;

  	// lógica do programa
  	while(vidas != 0){
    	printf("Vidas: %d\n", vidas);
    	printf("Digite um número entre 0 a 100: ");
    	scanf(" %d", &chute);
    	if(chute > 0 && chute < 100){
    		if(chute == num){
      			printf("\nParabéns você acertou!\n");
			      printf("Total de vidas: %d", vidas);
			      break;
    }
    else if (chute < num){
      printf("O número digitado é menor que o que esta procurando, tente um valor maior.");
      vidas = vidas -1;
    }
    else if (chute > num){
      printf("O número digitado é maior que o que esta procurando, tente um valor menor.");
      vidas = vidas -1;
    }
    }else{
      printf("Digite um número válido. Entre 0 e 100.\n");
    }
  }

	if (vidas = 0){
		printf("Que pena! Suas vidas acabaram, tente novamente!");
		printf("O número aleatório era %d", num);
	}

  return 0;
}
