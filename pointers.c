#include <stdio.h>


int main(void)
{
    int *ponteiro, **ponteiroDoPonteiro, valor;
    valor = 50;
    ponteiro = &valor;
    ponteiroDoPonteiro = &ponteiro;

    printf("\n\n Valor: %d", valor);
    printf("\n &Valor: %p", &valor);
    printf("\n\n*Ponteiro: %d", *ponteiro);
    printf("\n &Ponteiro: %p", &ponteiro);
    printf("\n  Ponteiro: %p",  ponteiro);
    printf("\n\n**ponteiroDoPonteiro: %d", **ponteiroDoPonteiro);
    printf("\n *ponteiroDoPonteiro: %p", *ponteiroDoPonteiro);
    printf("\n &ponteiroDoPonteiro: %p", &ponteiroDoPonteiro);
    printf("\n  ponteiroDoPonteiro: %p", ponteiroDoPonteiro);
    return 0;
}