//Nesse exerc�cio, voc� deve fazer um programa que calcula o n-�simo termo da sequ�ncia de Fibonacci. O programa l� o valor de n e calcula o valor de f(n). O valor de n deve ser inteiro positivo e o programa deve validar a entrada. Casos em que n = 0 ou n = 1 devem ser tratados.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  //declarando vari�veis
  int n=0,qnt;
  long long int fb=0,fb2=1;
   
  //recebendo valores
  printf("Digite um n�mero inteiro pra saber qual o valor de sua posi��o na sequ�ncia de fibonacci: ");
  scanf("%d", &qnt);

  //tela
  printf("0\n");
  while (n<qnt){
    fb= fb+fb2;
    fb2 = fb - fb2;
    printf("%lld\n", fb);
    n++;
  }

  return 0;
}
