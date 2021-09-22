// Faça um programa que leia as notas N1, N2 e N3 de um aluno e calcule a média M. As notas são números de 0 a 10. O programa também deve ler a frequência F do estudante, que pode ser de 0 a 100. Nesse exercício, os números podem ser decimais. No final, o programa deve mostrar a média, a frequência e a situação do estudante, conforme a regra abaixo:
// M maior que 7 e frequencia maior que 75: APROVADO.
// M menor que 7 e maior que 4 e frequência maior que 75: RECUPERAÇÃO.
// M menor que 4 ou frequência menor que 75: REPROVADO.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

  // declarações
  float n1, n2, n3, media, fqc;

  //recebendo valores
  
  printf("Informe a 1° nota: ");
  scanf("%f", &n1);

  printf("Informe a 2° nota: ");
  scanf("%f", &n2);
   
  printf("Informe a 3° nota: ");
  scanf("%f", &n3);
   
  printf("Informe a frequencia do estudante (0-100): ");
  scanf("%f", &fqc);

  //lógica do programa
  media = ((n1 + n2 + n3 ) / 3);

  printf("Com media %.1f , e frequencia %.1f o aluno", media, fqc);

  if (media >= 7 && fqc >= 75){
    printf(" foi APROVADO. ");
  }		else if (media >= 4 && media < 7 && fqc > 75){
    		printf(" ficou de RECUPERAÇÃO. ");
  }			else if (media < 4 && fqc <= 75){
   				 printf(" foi REPROVADO. ");
   			}
   				 else{
					printf(" foi REPROVADO. "); //situação onde +75 fqc porém nota baixa
  }
  return 0;
}
