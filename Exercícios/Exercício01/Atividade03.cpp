/* 3 - Centro meteorógico

Um centro meteorológico distribuiu dispositivos para
registrar índices pluviométricos em um conjunto de 7
cidades de uma região (identificadas por códigos numéricos
de 1 a 7) durante 6 meses(Jan a Jun), onde, para cada mês
foi registrado um valor real que corresponde ao índice
pluviométrico total do mês.

Escreva um programa que leia os 6 índices pluviométricos
de cada uma das sete cidades e imprima:
a) O índice de pluviosidade médio mensal de cada cidade;
b) O índice de pluviosidade média de cada mês na região. */

#include <stdio.h>
#include <conio.h>

int main()
{
    //[mes][cidade][valorIndice]
    // int cidades[6][7][6];
    float cidades[2][2][2];
    int valorIndice = 0;
    int cidade = 0, indice = 0, mes = 0;

    float mediaCidade = 0, mediaMes = 0, somaIndiceCidade = 0, armazenaSoma = 0;

    int repeticaoMes = 3, repeticaoCidade = 2, repeticaoIndice = 2;

    for (mes = 0; mes < repeticaoMes; mes++)
    { // quantidade de tabelas - colocar 6 em quantidade de repetições
        printf("\n============ MES %d ============= \n", mes + 1);

        for (cidade = 0; cidade < repeticaoCidade; cidade++)
        { // quantidade de linhas - colocar 7 em quantidade de repetições
            printf("\n------------- CIDADE %d ---------- \n", cidade + 1);

            for (indice = 0, indice = 0; indice < repeticaoIndice; indice++)
            { // quantidade de colunas - colocar 6 em quantidade de repetições
                printf("Digite o indice de pluviosidade:");
                scanf("%f", &cidades[mes][cidade][valorIndice]);

                somaIndiceCidade += cidades[mes][cidade][valorIndice];
                //printf("%.2f\n", somaIndiceCidade);
            }
            mediaCidade = somaIndiceCidade / repeticaoIndice;
            armazenaSoma += somaIndiceCidade; // recebe todas as somas de cada cidade
            printf("Soma armazenada: %.2f\n", armazenaSoma);
            printf("\n--MEDIA DA CIDADE: %.2f \n", mediaCidade);
            somaIndiceCidade = 0; // reseta a somatória de cada cidade

        }
        mediaMes = armazenaSoma / repeticaoMes;
        printf("\n--MEDIA DO MES: %.2f \n", mediaMes);
        armazenaSoma = 0;
    }

    return 0;
}

