#include <stdio.h>

#define LINHA 3
#define COLUNA 9
/*
Colunas

PONTOS 	JOGOS	VIT�RIAS	EMPATES 	DERROTAS 	GOLS 	GOLS		SALDO DE 	APROVEITAMENTO
GANHOS												PR�S	CONTRAS		GOLS

*/
int main(){
	// inicializando vari�veis
	float matriz[3][9] = {{0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0}};
	float golsM = 0, golsS = 0;
	float primeiro = matriz[0][0];
  	float segundo = matriz[0][0];
  	float terceiro = matriz[0][0];
	float maior = 0, menor = 0;
	int indicePrimeiro = 0, indiceSegundo = 0, indiceTerceiro = 0;
	
	// recebendo e atribuindo valores � tabela
	for(int i = 0; i < LINHA; i++){
		
		printf("Digite a quantidade de gols marcados no jogo %i: ",i+1);
		scanf("%f", &golsM);
		matriz[i][5] = golsM; // atribui valor a coluna GM
		
		printf("Digite a quantidade de gols sofridos no jogo %i: ",i+1);
		scanf("%f", &golsS);
		matriz[i][6] = golsS; // atribui valor a coluna GC
		
		printf("\n");
		matriz[i][1] = matriz[i][1] + 1; // qtd de jogos
		
		if(matriz[i][5] > matriz[i][6]){ 
			matriz[i][2] = matriz[i][2] + 1; //atribui valor a coluna VIT�RIA
			matriz[i][0] = matriz[i][0] + 3; //atribui valor a coluna PG
		}
		else if(matriz[i][5] < matriz[i][6]){ 
			matriz[i][4] = matriz[i][4] + 1; // atribui valor a coluna DERROTA
		}
		else{
			matriz[i][3] = matriz[i][3] + 1; // atribui valor a coluna EMPATE
			matriz[i][0] = matriz[i][0] + 1; // atribui valor a coluna PG
		}
		
		matriz[i][7] = matriz[i][5] - matriz[i][6]; // atribui valor a coluna SG
		matriz[i][8] = (matriz[i][0]/(matriz[i][1]*3)*100); // c�lculo da parcentagem de aproveitamento
	}
	
	// printa a tabela de jogos
	printf("       | PG  |  J  |  V  |  E  |  D  |  GP |  GC | SG  |  A  |");
		for(int i = 0; i<LINHA; i++){
			printf("\n");
			
			printf("Time %d ", i+1);
				for(int j = 0; j<COLUNA; j++){
					printf("| %.1f ", matriz[i][j]);
				}
			printf("|");

			if (matriz[i][0] > primeiro) {
				//procura o primeiro lugar
			      terceiro = segundo; //0 = 0
				  segundo = primeiro; //0 = 0
				  primeiro = matriz[i][0]; // primeiro lugar 0 = valor da matriz
				  indicePrimeiro = i;
				  
		    	} 
			else if (matriz[i][0] > segundo) {
	    		//procura o segundo lugar
		        terceiro = segundo; //0 = 0
			    segundo = matriz[i][0]; //segundo lugar 0 = valor da matriz
				indiceSegundo = i;

			}
			else if (matriz[i][0] >= terceiro) {
		    	//procura o terceiro lugar
			    terceiro = matriz[i][0]; //terceiro lugar 0 = valor da matriz
				indiceTerceiro = i;
			}
		}		
		
		printf("\n");
  		printf("\nTime %d em primeiro lugar com %.1f pontos\n", indicePrimeiro+1, primeiro);
		printf("\nTime %d em segundo lugar com %.1f pontos\n", indiceSegundo+1, segundo);
		printf("\nTime %d em terceiro lugar com %.1f pontos\n", indiceTerceiro+1, terceiro);
		
}

