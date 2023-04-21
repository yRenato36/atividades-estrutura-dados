/* Faça uma rotina recursiva para calcular a somatória de todos os número de 1 a N (N será lido do teclado). 
Observação: se N é igual a 5 por exemplo, A somatória dos números será igual a 15, ou seja, 1+2+3+4+5 = 15   
*/

#include <stdio.h>

int randomNumber = 0, resultado = 0;

int recursiva(int num) {
    if(num == 1) {
        return 1;
    } else {
        return num + recursiva(num-1);
    }
}

int main() {

    printf("Digite um numero qualquer: ");
    scanf("%d", &randomNumber);

    resultado = recursiva(randomNumber);

    printf("Seu resultado: %d\n", resultado);

    return 0;
}