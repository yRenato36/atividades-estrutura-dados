#include <stdio.h>
#include <stdlib.h>

// matriz que comporta todo os 9 valores do jogo da velha
char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void fazerTabuleiro();
int verificaVitoria();
void movimentoJogador(int jogador);

// objeto principal
int main() {
    int jogador = 1;
    int movimentos = 0;
    int row, col;

    printf("Jogo da Velha\n");

    while (movimentos < 9) {
        fazerTabuleiro();
        movimentoJogador(jogador);
        if (verificaVitoria()) {
            printf("Jogador %d ganhou!\n", jogador);
            return 0;
        }
        jogador = (jogador == 1) ? 2 : 1;
        movimentos++;
    }

    printf("Empate!\n");
    return 0;
}

// monta o tabuleiro do jogo
void fazerTabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int verificaVitoria() {
    // verifica as linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1;
        }
    }
    // verificas as colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1;
        }
    }
    // verifica as diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1;
    }
    return 0;
}

// objeto para o movimento do jogador
void movimentoJogador(int jogador) {
    int row, col;
    do {
        printf("Jogador %d, digite a linha (1-3) e coluna (1-3) que deseja jogar: ", jogador);
        scanf("%d %d", &row, &col);
        row--;
        col--;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || tabuleiro[row][col] != ' ');

    tabuleiro[row][col] = (jogador == 1) ? 'X' : 'O';
}
