#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    int idade;
    char sexo;
    float notaA1;
    float notaA2;
    int frequencia;
} Aluno;


bool verificarSexo(char sexo) {
    return sexo == 'M' || sexo == 'F';
}


float calcularMedia(float notaA1, float notaA2) {
    return (notaA1 + notaA2) / 2;
}


bool verificarAprovacao(float media, int frequencia) {
    return media >= 6.0 && frequencia >= 60;
}

float encontrarMaiorMedia(Aluno alunos[], int numAlunos) {
    float maiorMedia = 0.0;
    for (int i = 0; i < numAlunos; i++) {
        float media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
        if (media > maiorMedia) {
            maiorMedia = media;
        }
    }
    return maiorMedia;
}

float calcularPercentualReprovados(Aluno alunos[], int numAlunos) {
    int numReprovados = 0;
    for (int i = 0; i < numAlunos; i++) {
        float media = calcularMedia(alunos[i].notaA1, alunos[i].notaA2);
        int frequencia = alunos[i].frequencia;
        if (!verificarAprovacao(media, frequencia)) {
            numReprovados++;
        }
    }
    return (float)numReprovados / numAlunos * 100.0;
}

void exibirDadosCalculados(Aluno alunos[], int numAlunos) {
    float maiorMedia = encontrarMaiorMedia(alunos, numAlunos);
    float percentualReprovados = calcularPercentualReprovados(alunos, numAlunos);

    printf("Maior média: %.2f\n", maiorMedia);
    printf("Percentual de alunos reprovados: %.2f%%\n", percentualReprovados);
}

void cadastrarAluno(Aluno alunos[], int* numAlunos) {
    if (*numAlunos >= MAX_ALUNOS) {
        printf("Limite máximo de alunos atingido.\n");
        return;
    }

    Aluno novoAluno;

    printf("Nome: ");
    scanf(" %[^\n]s", novoAluno.nome);

    printf("Matrícula: ");
    scanf("%d", &novoAluno.matricula);

    printf("Idade: ");
    scanf("%d", &novoAluno.idade);

    do {
        printf("Sexo (M/F): ");
        scanf(" %c", &novoAluno.sexo);
    } while (!verificarSexo(novoAluno.sexo));

    printf("Nota A1: ");
    scanf("%f", &novoAluno.notaA1);

    printf("Nota A2: ");
    scanf("%f", &novoAluno.notaA2);

    printf("Frequência: ");
    scanf("%d", &novoAluno.frequencia);

    alunos[*numAlunos] = novoAluno;
    (*numAlunos)++;

    printf("Aluno cadastrado com sucesso!\n");
}

void consultarPorMatricula(Aluno alunos[], int numAlunos) {
    int matricula;
    printf("Digite o número da matrícula: ");
    scanf("%d", &matricula);

    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Aluno encontrado:\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequência: %d\n", alunos[i].frequencia);
            return;
        }
    }

    printf("Aluno não encontrado.\n");
}

void consultarPorNome(Aluno alunos[], int numAlunos) {
    char nome[MAX_NOME];
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", nome);

    for (int i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            printf("Aluno encontrado:\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequência: %d\n", alunos[i].frequencia);
            return;
        }
    }

    printf("Aluno não encontrado.\n");
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcaoPrincipal, opcaoConsulta;

    do {
        printf("\nMENU PRINCIPAL\n\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Consultar dados dos alunos\n");
        printf("3 - Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                cadastrarAluno(alunos, &numAlunos);
                break;
            case 2:
                do {
                    printf("\nCONSULTAR DADOS DOS ALUNOS\n\n");
                    printf("1 - Consultar aluno pelo número da matrícula\n");
                    printf("2 - Consultar aluno pelo nome\n");
                    printf("3 - Retornar ao menu principal\n");

                    printf("Escolha uma opção: ");
                    scanf("%d", &opcaoConsulta);

                    switch (opcaoConsulta) {
                        case 1:
                            consultarPorMatricula(alunos, numAlunos);
                            break;
                        case 2:
                            consultarPorNome(alunos, numAlunos);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (opcaoConsulta != 3);
                break;
            case 3:
                exibirDadosCalculados(alunos, numAlunos);
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcaoPrincipal != 3);

    return 0;
}
