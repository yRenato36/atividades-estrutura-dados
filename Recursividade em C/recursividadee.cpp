#include <stdio.h>

int somatoria(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somatoria(n-1);
    }
}

int main() {
    int n, resultado;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    resultado = somatoria(n);

    printf("A somatoria dos numeros de 1 a %d eh %d\n", n, resultado);

    return 0;
}
