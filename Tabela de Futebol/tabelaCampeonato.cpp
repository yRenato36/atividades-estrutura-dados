#include <stdio.h>

#define LINHA 10
#define COLUNA 9
/* Colunas
PONTOS 	JOGOS	VITORIAS	EMPATES 	DERROTAS 	GOLS 	GOLS		SALDO DE 	APROVEITAMENTO
GANHOS												PROS	CONTRAS		GOLS
*/

// inicializando variaveis
float matriz[LINHA][COLUNA] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}};
float golsM = 0, golsS = 0;

float primeiro = matriz[0][0];
float segundo = matriz[0][0];
float terceiro = matriz[0][0];
float ultimo = matriz[0][0];
float penultimo = matriz[0][0];
float antepenultimo = matriz[0][0];

float maior = 0, menor = 0;

int indicePrimeiro = 0, indiceSegundo = 0, indiceTerceiro = 0;
int indiceUltimo = 0, indicePenultimo = 0, indiceAntepenultimo = 0;

// recebe a quantidade de gols em cada jogo
void recebeValores(int i)
{
	printf("Digite a quantidade de gols marcados no jogo %i: ", i + 1);
	scanf("%f", &golsM);
	matriz[i][5] = golsM; // atribui valor a coluna GM

	printf("Digite a quantidade de gols sofridos no jogo %i: ", i + 1);
	scanf("%f", &golsS);
	matriz[i][6] = golsS; // atribui valor a coluna GC

	printf("\n");
	matriz[i][1] = matriz[i][1] + 1; // qtd de jogos
}

// verifica colocacao e printa a tabela de jogos
void colocacaoTabela()
{
	printf("       | PG  |  J  |  V  |  E  |  D  |  GP |  GC | SG  |  A  |");
	for (int i = 0; i < LINHA; i++)
	{
		printf("\n");
		printf("Time %d ", i + 1);
		for (int j = 0; j < COLUNA; j++)
		{
			printf("| %.1f ", matriz[i][j]);
		}
		printf("|");

		if (matriz[i][0] > primeiro)
		{							 // procura o primeiro lugar
			terceiro = segundo;		 // 0 = 0
			segundo = primeiro;		 // 0 = 0
			primeiro = matriz[i][0]; // primeiro lugar 0 = valor da matriz
			indicePrimeiro = i;
		}
		else if (matriz[i][0] > segundo)
		{							// procura o segundo lugar
			terceiro = segundo;		// 0 = 0
			segundo = matriz[i][0]; // segundo lugar 0 = valor da matriz
			indiceSegundo = i;
		}
		else if (matriz[i][0] >= terceiro)
		{							 // procura o terceiro lugar
			terceiro = matriz[i][0]; // terceiro lugar 0 = valor da matriz
			indiceTerceiro = i;
		}
	}
}

// atribui Vitorias Derrotas e Empates a suas respectivas colunas
void vitoriasDerrotasEmpates()
{
	for (int i = 0; i < LINHA; i++)
	{
		recebeValores(i); // chama function que recebe os valores

		if (matriz[i][5] > matriz[i][6]) // atribui vitorias
		{
			matriz[i][2] = matriz[i][2] + 1; // atribui +1 VITORIA na coluna VITORIA
			matriz[i][0] = matriz[i][0] + 3; // atribui +3 pontos a coluna PG - pontos ganhos
		}
		else if (matriz[i][5] < matriz[i][6]) // atribui derrotas
		{
			matriz[i][4] = matriz[i][4] + 1; // atribui +1 DERROTA a coluna DERROTA
		}
		else // atribui empates
		{
			matriz[i][3] = matriz[i][3] + 1; // atribui +1 EMPATE a coluna EMPATE
			matriz[i][0] = matriz[i][0] + 1; // atribui +1 ponto a coluna PG - pontos ganhos
		}

		matriz[i][7] = matriz[i][5] - matriz[i][6];					  // atribui os gols excedentes a coluna SG - saldo de gol
		matriz[i][8] = (matriz[i][0] / (matriz[i][1] * LINHA) * 100); // calculo da parcentagem de aproveitamento ((PG / JOGOS * QTD JOGOS) * 100)
	}
}

// indica a colocacao dos melhores times na matriz
void indicaMelhoresColocados()
{
	printf("\n");
	printf("\nTime %d em primeiro lugar com %.1f pontos\n", indicePrimeiro + 1, primeiro);
	printf("\nTime %d em segundo lugar com %.1f pontos\n", indiceSegundo + 1, segundo);
	printf("\nTime %d em terceiro lugar com %.1f pontos\n", indiceTerceiro + 1, terceiro);
}

// indica a colocacao dos piores times na matriz
void indicaPioresColocados()
{
	ultimo = terceiro; // recebe o ultimo colocado do podio, isso vai ajudar a seguir na contagem de onde parou
	for (int i = 0; i < LINHA; i++)
	{
		if (matriz[i][0] < ultimo)
		{							   // procura o ultimo lugar
			antepenultimo = penultimo; // 0 = 0
			penultimo = ultimo;		   // 0 = 0
			ultimo = matriz[i][0];	   // ultimo lugar 0 = valor da matriz
			printf("ultimo lugar: %.2f", ultimo);
			indiceUltimo = i;

			/* LOGICA CORRETA
				ultimo = matriz[i][0];
				printf("ultimo lugar: %.2f", ultimo);
				indiceUltimo = i;
			*/
		}
		else if (matriz[i][0] < penultimo)
		{							   // procura o penultimo lugar
			antepenultimo = penultimo; // 0 = 0
			penultimo = matriz[i][0];  // penultimo lugar 0 = valor da matriz
			printf("penultimo lugar: %.2f", penultimo);
			indicePenultimo = i;
		}
		else if (matriz[i][0] < antepenultimo)
		{								  // procura o antepenultimo lugar
			antepenultimo = matriz[i][0]; // antepenultimo lugar 0 = valor da matriz
			printf("antepenultimo lugar: %.2f", antepenultimo);
			indiceAntepenultimo = i;
		}
	}
	printf("\n");
	printf("\nTime %d em ultimo lugar com %.1f pontos\n", indiceUltimo + 1, ultimo);
	printf("\nTime %d em penultimo lugar com %.1f pontos\n", indicePenultimo + 1, penultimo);
	printf("\nTime %d em antepenultimo lugar com %.1f pontos\n", indiceAntepenultimo + 1, antepenultimo);
}

// function principal
int main()
{
	vitoriasDerrotasEmpates();
	colocacaoTabela();
	indicaMelhoresColocados();
	indicaPioresColocados();
}
