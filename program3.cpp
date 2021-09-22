// Fa�a um programa que leia as notas N1, N2 e N3 de um aluno e calcule a m�dia M. As notas s�o n�meros de 0 a 10. O programa tamb�m deve ler a frequ�ncia F do estudante, que pode ser de 0 a 100. Nesse exerc�cio, os n�meros podem ser decimais. No final, o programa deve mostrar a m�dia, a frequ�ncia e a situa��o do estudante, conforme a regra abaixo:
// M maior que 7 e frequencia maior que 75: APROVADO.
// M menor que 7 e maior que 4 e frequ�ncia maior que 75: RECUPERA��O.
// M menor que 4 ou frequ�ncia menor que 75: REPROVADO.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "Portuguese");

  // declara��es
  float n1, n2, n3, media, fqc;

  //recebendo valores
  
  printf("Informe a 1� nota: ");
  scanf("%f", &n1);

  printf("Informe a 2� nota: ");
  scanf("%f", &n2);
   
  printf("Informe a 3� nota: ");
  scanf("%f", &n3);
   
  printf("Informe a frequencia do estudante (0-100): ");
  scanf("%f", &fqc);

  //l�gica do programa
  media = ((n1 + n2 + n3 ) / 3);

  printf("Com media %.1f , e frequencia %.1f o aluno", media, fqc);

  if (media >= 7 && fqc >= 75){
    printf(" foi APROVADO. ");
  }		else if (media >= 4 && media < 7 && fqc > 75){
    		printf(" ficou de RECUPERA��O. ");
  }			else if (media < 4 && fqc <= 75){
   				 printf(" foi REPROVADO. ");
   			}
   				 else{
					printf(" foi REPROVADO. "); //situa��o onde +75 fqc por�m nota baixa
  }
  return 0;
}
