// Fa�a um programa que leia 3 n�meros inteiros A, B e C, com sinal, e mostre-os em ordem crescente ou decrescente, conforme a op��o do usu�rio. Por exemplo:
// Digite A: 5
// Digite B: -10
// Digite C: 1
// Qual ordem? (C - crescente; D - decrescente): D
// Ordem decrescente: 5, 1 e -10.

#include <stdio.h>
#include <stdlib.h>

int main() {
    // declare as vari�veis que ser�o utilizadas
    float n1, n2, n3;
    char ordem;
    
    //recebendo valores
    printf("Informe o 1� n�mero: ");
    scanf("%f", &n1);
    
    printf("Informe o 2� n�mero: ");
    scanf("%f", &n2);
    
    printf("Informe o 3� n�mero: ");
    scanf("%f", &n3);
    
    printf("Informe a ordem desejada, digite \n[D] para decrescente e \n[C] para crescente: ");
    scanf(" %c", &ordem);

    //L�gica do programa e tela
    
    //se todos s�o iguais
    if (n1 == n2 && n2 == n3){ 
    	printf("A ordem possui apenas numeros iguais: %.1f %.1f %.1f", n3, n2, n1);
	}
    
    //se crescente
    if (ordem == 'C' || ordem == 'c')
    {
    if (n1 > n2 && n1 > n3 && n2 > n3){
      printf("A ordem crescente: %.1f %.1f %.1f", n3, n2, n1);
   }
    if (n1 > n2 && n1 > n3 && n2 < n3){
      printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n3, n1);
   }
   
    if (n2 > n1 && n2 > n3 && n1 > n3){
      printf("A ordem crescente: %.1f %.1f %.1f\n", n3, n1, n2);
   }
    if (n2 > n1 && n2 > n3 && n1 < n3){
      printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n3, n2);
   }
   
    if (n3 > n2 && n3 > n1 && n2 > n1){
      printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n2, n3);
   }
    if (n3 > n2 && n3 > n1 && n2 < n1){
      printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n1, n3);
   }
    if (n1 == n2 && n1 < n3){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n2, n3);	
	}
	if (n1 == n2 && n1 > n3){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n3, n1, n2);	
	}
	if (n1 == n3 && n1 < n2){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n3, n2);	
	}
	if (n1 == n3 && n1 > n2){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n1, n3);	
	}
	if (n2 == n3 && n2 < n1){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n3, n1);	
	}
	if (n2 == n3 && n2 > n1){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n2, n3);	
	}
   //se decrescente
   } else if (ordem == 'D' || ordem == 'd'){
    if (n1 < n2 && n1 < n3 && n2 < n3){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n3, n2, n1);
   }
    if (n1 < n2 && n1 < n3 && n2 > n3){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n2, n3, n1);
   }
    if (n2 < n1 && n2 < n3 && n1 < n3){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n3, n1, n2);
   }
    if (n2 < n1 && n2 < n3 && n1 > n3){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n1, n3, n2);
   }
    if (n3 < n2 && n3 < n1 && n2 < n1){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n1, n2, n3);
   }
    if (n3 < n2 && n3 < n1 && n2 > n1){
      printf("A ordem decrescente: %.1f %.1f %.1f\n", n2, n1, n3); 
   }
    if (n1 == n2 && n1 < n3){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n3, n1, n2);	
	}
	if (n1 == n2 && n1 > n3){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n2, n3);	
	}
	if (n1 == n3 && n1 < n2){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n1, n3);	
	}
	if (n1 == n3 && n1 > n2){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n3, n2);	
	}
	if (n2 == n3 && n2 < n1){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n1, n2, n3);	
	}
	if (n2 == n3 && n2 > n1){
     printf("A ordem crescente: %.1f %.1f %.1f\n", n2, n3, n1);	
	}
   }
   return 0;
}
