/*
2 - Notas da turma
Fazer um programa para ler as notas de 4 provas para 5 alunos de uma turma e calcular a média do aluno e média da turma */

#include <stdio.h>

int main()
{   
    //[linhas][colunas]
    float matriz[5][4];
    float soma = 0, somaAluno = 0, mediaAluno = 0, mediaSala = 0;
    int alunos = 0, notas = 0;
    
    for(alunos = 0; alunos < 5; alunos++) { //linhas
        printf("Aluno %d\n", alunos);
        
        for(notas = 1; notas <= 4; notas++){ //colunas
            printf("Digite a Nota %d:\n", notas);
            scanf("%f", &matriz[alunos][notas]);
            
            somaAluno += matriz[alunos][notas]; // soma todas as notas do aluno
            mediaAluno = somaAluno/4; // média das notas do aluno
      
        }
        printf("Media do aluno %d = %.2f\n", alunos, mediaAluno);
        soma = soma + somaAluno; // armazena a somatoria de notas e incrementa várias somatórias
        somaAluno = 0; //reseta a soma das notas do aluno
        printf("\n"); 
    }
    mediaSala = soma/20;
    printf("Media da Sala: %.2f", mediaSala);
}   