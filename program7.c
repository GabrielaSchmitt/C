//Nesse exercício, você deve fazer um programa que calcula o n-ésimo termo da sequência de Fibonacci. O programa lê o valor de n e calcula o valor de f(n). O valor de n deve ser inteiro positivo e o programa deve validar a entrada. Casos em que n = 0 ou n = 1 devem ser tratados.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  //declarando variáveis
  int n=0,qnt;
  long long int fb=0,fb2=1;
   
  //recebendo valores
  printf("Digite um número inteiro pra saber qual o valor de sua posição na sequência de fibonacci: ");
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
