/* Jogo da Velha. Jogo disputado por dois jogadores, com objetivo de formar uma linha horizontal,
vertical ou diagonal de três xis ou círculos, numa das nove entrelinhas de uma figura de quatro
linhas em forma de (#) cerquilha.
Nesse exercício, você deve fazer um jogo da velha. Inicialmente, o programa deve guardar e escrever
na tela um tabuleiro de jogo da velha. Depois, seu programa deve permitir que 2 jogadores humanos
possam jogar um contra o outro. Finalmente, permita que o jogador humano possa jogar contra o 
computador.? O programa também deve permitir selecionar entre jogar contra um jogador humano ou o
computador.
Dica. Faça o programa perguntar qual a linha e coluna que o jogador que marcar. Não esqueça de validar
o valor, ou seja, deve ser entre os limites da matriz. */
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

// declaraçao de constantes
#define DIM 3

void mostrar_tabuleiro(char tabuleiro[DIM][DIM]);
void carregando(); 
int verifica_ganho(char tabuleiro[DIM][DIM], int venceu, int preenchido);

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	// declarações
	char tabuleiro[DIM][DIM] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int preenchido = 0, venceu = 0, numMaquinaX, numMaquinaY, mode, coordenadaX, coordenadaY, b1, b2, b3, b4, a1, a2, a3, a4, a5, a6; 
	
	// tela inicial (menu)
	printf("Seja bem vindo ao jogo da velha!");
	Sleep(3000); // 3 segundos de pausa
	system("cls"); // limpa tela
	
	
	printf("Escolha o modo de jogo desejado:\n [1] - Jogar local, Player 1 vs Player 2.\n [2] - Jogar contra máquina. \nDigite: ");
	scanf(" %d", &mode);
	system("cls"); // limpa tela
	
	carregando(); 
	
	// recebendo valores - lógica 
	switch(mode)
	{
		case 1: // player1 vs player2
			
			do{
				a1 = 0;
			  	while (a1 == 0){
				  	a2 = 0;
				  	while(a2 == 0){
					  	printf("Você é o X.\nDigite a coordenada X da posição que deseja marcar: "); // recebe valor de coordenada X do jogador
					  	scanf(" %d", &coordenadaX);	
					  	
						if(coordenadaX >= 0 && coordenadaX < 3){          // limita a resposta da coordenada X de 0 - 2
						  	a2++;
							break;
						} else {
							printf("O número deve estar entre 0 e 2!\n");
							a2 = 0;	
						}
					}
					
					a3 = 0; 
					while(a3 == 0){
					  	printf("Digite a coordenada Y da posição que deseja marcar: ");        // recebe valor da coordenada Y do jogador
					  	scanf(" %d", &coordenadaY);	 
					  	
						if(coordenadaY >= 0 && coordenadaY < 3){          // limita a resposta da coordenada Y de 0 - 2
						  	a3++;
							break;
						} else {
							printf("O número deve estar entre 0 e 2!\n");
							a3 = 0;	
						}
					}
							
					if (tabuleiro[coordenadaX][coordenadaY] == ' '){     // verifica se a coordenada em questão esta preenchida
						tabuleiro[coordenadaX][coordenadaY] = 'X'; 
						a1++; 
					} else {
						printf("Esta coordenada já esta preenchida, tente uma válida. ");
						a1 = 0; 
					}
				}
			
				preenchido = 0; 
				for (int v = 0; v < 3; v++){          // mostra quantas casas do tabuleiro estao preenchidas
					for(int r = 0; r < 3; r++){
						if (!(tabuleiro[v][r] == ' ')){
							preenchido++; 
						}
					}
				}
			
				venceu = verifica_ganho(tabuleiro, venceu, preenchido); // verifica se o jogador venceu
				mostrar_tabuleiro(tabuleiro);	// tela
			
				if (preenchido == 9){
					if (venceu != 1){
						printf("\nEmpate!!\n"); 
					}
					venceu = 1; 
				}
			
				if (preenchido == 8 || preenchido == 9){       // se o tabuleiro não teha mais espaços saia
					continue;
				} else if (venceu == 1) {                      // caso alguém tenha ganho o jogo saia
					continue; 
				}else {
				
				a4 = 0;	
				while(a4 == 0){	
					
					a5 = 0;
				  	while(a5 == 0){
				  		
					printf("Você é o O.\nDigite a coordenada X da posição que deseja marcar: "); // recebe valor de coordenada X do jogador 2
					scanf(" %d", &coordenadaX);	
					  	
					if(coordenadaX >= 0 && coordenadaX < 3){          // limita a resposta da coordenada X de 0 - 2
						a5++;
						break;
					} else {
						printf("O número deve estar entre 0 e 2!\n");
						a5 = 0;	
					}
					}
				
					a6 = 0;
				  	while(a6 == 0){
					printf("Digite a coordenada Y da posição que deseja marcar: ");        // recebe valor da coordenada Y do jogador 2
					scanf(" %d", &coordenadaY);	 
						  	
					if(coordenadaY >= 0 && coordenadaY < 3){          // limita a resposta da coordenada Y de 0 - 2
						a6++;
						break;
					} else {
						printf("O número deve estar entre 0 e 2!\n");
						a6 = 0;	
					}	
					}
					
					if (tabuleiro[coordenadaX][coordenadaY] == ' '){    // verifica se a coordenada em questão esta preenchida
						tabuleiro[coordenadaX][coordenadaY] = 'O'; 
						a4++; 
					} else {
						printf("Esta coordenada já esta preenchida, tente uma válida. ");
						a4 = 0;
					}
				}
				}
				
			// lógica do programa
				preenchido = 0; 
				for (int v = 0; v < 3; v++){          // mostra quantas casas do tabuleiro estao preenchidas
				for(int r = 0; r < 3; r++){
					if (!(tabuleiro[v][r] == ' ')){
						preenchido++; 
					}
				}
			}
			//printf("Preenchido: %d\n", preenchido); 
			
			// tela
			mostrar_tabuleiro(tabuleiro);
			venceu = verifica_ganho(tabuleiro, venceu, preenchido);
			//printf("venceu: %d\n", venceu);
			
			}while(venceu != 1); 
			break; 

	    case 2:	// player vs maquina
			do{
				b1 = 0;
			  	while (b1 == 0){
				  	b2 = 0;
				  	while(b2 == 0){
					  	printf("Você é o X.\nDigite a coordenada X da posição que deseja marcar: "); // recebe valor de coordenada X do jogador
					  	scanf(" %d", &coordenadaX);	
					  	
						  if(coordenadaX >= 0 && coordenadaX < 3){          // limita a resposta da coordenada X de 0 - 2
						  	b2++;
							break;
						  } else {
							printf("O número deve estar entre 0 e 2!\n");
							b2 = 0;	
							}
					}
					b3 = 0; 
					while(b3 == 0){
					  	printf("\nDigite a coordenada Y da posição que deseja marcar: ");        // recebe valor da coordenada Y do jogador
					  	scanf(" %d", &coordenadaY);	 
					  	
						  if(coordenadaY >= 0 && coordenadaY < 3){          // limita a resposta da coordenada X de 0 - 2
						  	b3++;
							break;
						  } else {
							printf("O número deve estar entre 0 e 2!\n");
							b3 = 0;	
							}
					}
							
					if (tabuleiro[coordenadaX][coordenadaY] == ' '){
						tabuleiro[coordenadaX][coordenadaY] = 'X'; 
						b1++; 
					} else {
						printf("Esta coordenada já esta preenchida, tente uma válida. ");
						b1 = 0; 
				}
			}
			
			preenchido = 0; 
			for (int v = 0; v < 3; v++){          // mostra quantas casas do tabuleiro estao preenchidas
				for(int r = 0; r < 3; r++){
					if (!(tabuleiro[v][r] == ' ')){
						preenchido++; 
					}
				}
			}
			
			venceu = verifica_ganho(tabuleiro, venceu, preenchido); // verifica se o jogador venceu
			
			//printf("venceu: %d\n", venceu);
			//printf("Preenchido: %d\n", preenchido); 
			
			if (preenchido == 9){
				if (venceu != 1){
					printf("\nEmpate!!\n"); 
				}
				venceu = 1; 
			}
			
			if (preenchido == 8 || preenchido == 9){
				continue;
			} else if (venceu == 1) {
				continue; 
			}else {
			b4 = 0;	
			while(b4 == 0){
				numMaquinaX = rand() % 3; // recebendo valor X da máquina 
				numMaquinaY = rand() % 3; // recebendo valor Y da máquina
				
				if (tabuleiro[numMaquinaX][numMaquinaY] == ' '){
					tabuleiro[numMaquinaX][numMaquinaY] = 'O'; 
					b4++; 
				} else {
					b4 = 0;
				}
			}
			}
		
			// lógica do programa
				preenchido = 0; 
				for (int v = 0; v < 3; v++){          // mostra quantas casas do tabuleiro estao preenchidas
				for(int r = 0; r < 3; r++){
					if (!(tabuleiro[v][r] == ' ')){
						preenchido++; 
					}
				}
			}
			//printf("Preenchido: %d\n", preenchido); 

			venceu = verifica_ganho(tabuleiro, venceu, preenchido);
			//printf("venceu: %d\n", venceu);
			
			// tela
			mostrar_tabuleiro(tabuleiro);
			
			}while(venceu != 1); 
			break; 
	
		default:
 			printf("Digite 1 ou 2. ");
 			break;
	}
	return EXIT_SUCCESS;
}

int verifica_ganho(char tabuleiro[DIM][DIM], int venceu, int preenchido){
	// X vence:
	if ((tabuleiro[0][0] == 'X' || tabuleiro[0][0] == 'x') && (tabuleiro[1][1] == 'X' || tabuleiro[1][1] == 'x') && (tabuleiro[2][2] == 'X' || tabuleiro[2][2] == 'x')){
		printf("X venceu!\n");
		venceu = 1;
	}
	if ((tabuleiro[0][0] == 'X' || tabuleiro[0][0] == 'x') && (tabuleiro[0][1] == 'X' || tabuleiro[0][1] == 'x') && (tabuleiro[0][2] == 'X' || tabuleiro[0][2] == 'x')){
		printf("X venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][0] == 'X' || tabuleiro[0][0] == 'x') && (tabuleiro[1][0] == 'X' || tabuleiro[1][0] == 'x') && (tabuleiro[2][0] == 'X' || tabuleiro[2][0] == 'x')){
		printf("X venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][1] == 'X' || tabuleiro[0][1] == 'x') && (tabuleiro[1][1] == 'X' || tabuleiro[1][1] == 'x') && (tabuleiro[2][1] == 'X' || tabuleiro[2][1] == 'x')){
		printf("X venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][2] == 'X' || tabuleiro[0][2] == 'x') && (tabuleiro[1][2] == 'X' || tabuleiro[1][2] == 'x') && (tabuleiro[2][2] == 'X' || tabuleiro[2][2] == 'x')){
		printf("X venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][2] == 'X' || tabuleiro[0][2] == 'x') && (tabuleiro[1][1] == 'X' || tabuleiro[1][1] == 'x') && (tabuleiro[2][0] == 'X' || tabuleiro[2][0] == 'x')){
		printf("O venceu!\n");
		venceu++;
		}
	if ((tabuleiro[1][0] == 'X' || tabuleiro[1][0] == 'x') && (tabuleiro[1][1] == 'X' || tabuleiro[1][1] == 'x') && (tabuleiro[1][2] == 'X' || tabuleiro[1][2] == 'x')){
		printf("X venceu!\n");
		venceu++;
		}	
	if ((tabuleiro[2][0] == 'X' || tabuleiro[2][0] == 'x') && (tabuleiro[2][1] == 'X' || tabuleiro[2][1] == 'x') && (tabuleiro[2][2] == 'X' || tabuleiro[2][2] == 'x')){
		printf("X venceu!\n");
		venceu++;
	}
	
	// O vence:
	if ((tabuleiro[0][0] == 'O' || tabuleiro[0][0] == 'o') && (tabuleiro[1][1] == 'O' || tabuleiro[1][1] == 'o') && (tabuleiro[2][2] == 'O' || tabuleiro[2][2] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][0] == 'O' || tabuleiro[0][0] == 'o') && (tabuleiro[0][1] == 'O' || tabuleiro[0][1] == 'o') && (tabuleiro[0][2] == 'O' || tabuleiro[0][2] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][0] == 'O' || tabuleiro[0][0] == 'o') && (tabuleiro[1][0] == 'O' || tabuleiro[1][0] == 'o') && (tabuleiro[2][0] == 'O' || tabuleiro[2][0] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][1] == 'O' || tabuleiro[0][1] == 'o') && (tabuleiro[1][1] == 'O' || tabuleiro[1][1] == 'o') && (tabuleiro[2][1] == 'O' || tabuleiro[2][1] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][2] == 'O' || tabuleiro[0][2] == 'o') && (tabuleiro[1][2] == 'O' || tabuleiro[1][2] == 'o') && (tabuleiro[2][2] == 'O' || tabuleiro[2][2] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[0][2] == 'O' || tabuleiro[0][2] == 'o') && (tabuleiro[1][1] == 'O' || tabuleiro[1][1] == 'o') && (tabuleiro[2][0] == 'O' || tabuleiro[2][0] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}	
	if ((tabuleiro[1][0] == 'O' || tabuleiro[1][0] == 'o') && (tabuleiro[1][1] == 'O' || tabuleiro[1][1] == 'o') && (tabuleiro[1][2] == 'O' || tabuleiro[1][2] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}
	if ((tabuleiro[2][0] == 'O' || tabuleiro[2][0] == 'o') && (tabuleiro[2][1] == 'O' || tabuleiro[2][1] == 'o') && (tabuleiro[2][2] == 'O' || tabuleiro[2][2] == 'o')){
		printf("O venceu!\n");
		venceu++;
	}	
		
	return venceu; 
}

void mostrar_tabuleiro(char tabuleiro[DIM][DIM]){
	system("cls");
	for (int i = 0; i < DIM; i++) {
		printf("-------------------------\n|");
		for (int j = 0; j < DIM; j++) {
			printf("   %c   |", tabuleiro[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}

	void carregando(){               //animação de carregamento 
	for(int i=0; i<5; i++){
		printf("carregando\n");
		printf("~------");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");
		printf("-~-----");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");
		printf("--~----");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");
		printf("---~---");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");		
		printf("----~--");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");
		printf("-----~-");
		Sleep(100);
		system("cls"); 
		printf("carregando\n");
		printf("------~");
		Sleep(100);
		system("cls"); 
	}
	}
