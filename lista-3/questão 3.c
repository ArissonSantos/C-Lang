
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Aluno {
    char nome[50];
    int matricula;
    char telefone[15];
    char sexo;
    int frequencia;
    float notaA1;
    float notaA2;
    float mediaFinal;
    char mensagem[20];
};

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	
	int i;
    struct Aluno alunos[5];
    float maiorMedia = 0.0, menorMedia = 10.0;
    int indiceMaiorMedia = 0;
    int aprovados = 0, reprovados = 0, reprovadosFrequencia = 0;

  
    for (i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("N mero da matr cula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Telefone: ");
        scanf("%s", alunos[i].telefone);

        printf("Sexo (M/F): ");
        scanf(" %c", &alunos[i].sexo);

        printf("Frequ ncia: ");
        scanf("%d", &alunos[i].frequencia);

        printf("Nota A1: ");
        scanf("%f", &alunos[i].notaA1);

        printf("Nota A2: ");
        scanf("%f", &alunos[i].notaA2);

   
        alunos[i].mediaFinal = (alunos[i].notaA1 + alunos[i].notaA2) / 2.0;


        if (alunos[i].mediaFinal >= 6.0 && alunos[i].frequencia >= 60) {
            printf("Aprovado\n");
            aprovados++;
        } else {
            printf("Reprovado\n");
            reprovados++;

            if (alunos[i].frequencia < 60) {
                reprovadosFrequencia++;
            }
        }

        if (alunos[i].mediaFinal > maiorMedia) {
            maiorMedia = alunos[i].mediaFinal;
        }

        if (alunos[i].mediaFinal < menorMedia) {
            menorMedia = alunos[i].mediaFinal;
        }

        if (alunos[i].mediaFinal > alunos[indiceMaiorMedia].mediaFinal) {
            indiceMaiorMedia = i;
        }
    }

    printf("\nRESULTADOS:\n");

    for (i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("N mero da matr cula: %d\n", alunos[i].matricula);
        printf("Frequ ncia: %d\n", alunos[i].frequencia);
        printf("M dia final: %.2f\n", alunos[i].mediaFinal);
        printf("Mensagem: %s\n", alunos[i].mensagem);
    }

    printf("\nMAIOR E MENOR M DIA FINAL:\n");
    printf("Maior m dia final: %.2f\n", maiorMedia);
    printf("Menor m dia final: %.2f\n", menorMedia);

    printf("\nALUNO COM A MAIOR M DIA:\n");
    printf("Nome: %s\n", alunos[indiceMaiorMedia].nome);
    printf("N mero da matr cula: %d\n", alunos[indiceMaiorMedia].matricula);
    printf("M dia final: %.2f\n", alunos[indiceMaiorMedia].mediaFinal);

    printf("\nTOTAL DE APROVADOS E REPROVADOS:\n");
    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);

    printf("\nPERCENTAGEM DE ALUNOS REPROVADOS POR FREQU NCIA:\n");
    float percentualReprovadosFrequencia = (reprovadosFrequencia / 5.0) * 100.0;
    printf("%.2f%% dos alunos foram reprovados por frequ ncia.\n", percentualReprovadosFrequencia);

    return 0;
}
