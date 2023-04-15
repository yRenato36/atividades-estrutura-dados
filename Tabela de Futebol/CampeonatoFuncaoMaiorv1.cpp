#include <stdio.h>
#include <conio.h>

#define DIML 3
#define DIMC 9

void inicializamatriz(float, int, int);

void inicializamatriz(float matriz[DIML][DIMC], int linha, int coluna)
{
     for (int i = 0; i < linha; i++)
          for (int j = 0; j < coluna; j++)
               matriz[i][j] = 0;
}

void imprimematriz(float matriz[DIML][DIMC], int linha, int coluna)
{
     printf("\n        PG    J      V     E    D     GP    GC   SG    Aroveitamento");
     for (int i = 0; i < linha; i++)
     {
          printf("\nTime %d ", i);
          for (int j = 0; j < coluna; j++)
          {
               printf("%.2f  ", matriz[i][j]);
          }
     }
}

int main(void)
{
     float matriz[3][9];
     int golsmarcados, golscontra, resultado, maior, posicaomaior;

     inicializamatriz(matriz, 3, 9);
     // Imprime Matriz
     // imprimematriz(matriz, 3,9);

     // Leitura dos valores
     for (int i = 0; i < 3; i++)
     {
          printf("\nQuantos gols o time marcou?\n\n");
          scanf("%d", &golsmarcados);
          matriz[i][5] += golsmarcados;
          printf("\nQuantos gols o time sofreu?\n\n");
          scanf("%d", &golscontra);
          matriz[i][6] += golscontra;

          // Calculo dos Valores na Matriz
          // gols - Saldo de Gols
          resultado = golsmarcados - golscontra;

          // Vitoria, Empate, Derrota
          if (resultado > 0) // Vitoria - matriz[i][7]>0
          {
               matriz[i][2] = matriz[i][2] + 1;
          }
          else if (resultado == 0) // Empate -  matriz[i][7]==0
          {
               matriz[i][3] = matriz[i][3] + 1;
          }
          else
          {
               // Derrota
               matriz[i][4] = matriz[i][4] + 1;
          }
          // Jogos
          matriz[i][1] = matriz[i][1] + 1;
          // PontosGanhos
          matriz[i][0] = matriz[i][0] + (matriz[i][2] * 3 + matriz[i][3]);

          // Aproveitamento
          matriz[i][8] = (matriz[i][0] / (matriz[i][1] * 3)) * 100;
     }
     // Apresentar os resultados
     imprimematriz(matriz, 3, 9);

     // Verifica maior e menor
     maior = 0;
     posicaomaior = 0;

     for (int i = 0; i < 3; i++)
     {
          if (maior < matriz[i][0])
          {
               maior = matriz[i][0];
               posicaomaior = i;
          }
     }

     printf("\n        PG    J      V     E    D     GP    GC   SG    Aroveitamento");

     printf("\nTime %d ", posicaomaior);
     for (int j = 0; j < 9; j++)
     {
          printf("%.2f  ", matriz[posicaomaior][j]);
     }

     getch();
     return (0);
}
