#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct{
	
	char nome[50];
	int matricula;
	float nota1;
	float nota2;
	
} Aluno;

	void calcularMedia(Aluno *aluno){
		
		float media = (aluno -> nota1 + aluno ->nota2) / 2.0;
		
			printf("Matr�cula: %d\n", aluno -> matricula);
			printf("Nome: %s\n", aluno -> nome);
			printf("M�dia: %.2f\n", media);
			printf("\n");
			
	}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
		int numAlunos = 0;
		Aluno *alunos = NULL;
		
		char opcao;
		
			do{
				numAlunos++;
					alunos = realloc(alunos, numAlunos * sizeof(Aluno));
					if(alunos == NULL){
						printf("Erro.\n");
						return 1;
					}
				
				printf("Aluno %d\n", numAlunos);
				
				printf("Digite o nome: ");
				scanf(" %[^\n]", alunos[numAlunos - 1].nome);
				
				printf("Digite a matr�cula: ");
				scanf(" %d[^\n]", &alunos[numAlunos - 1].matricula);
				
				printf("Digite a primeira nota: ");
				scanf("%f", &alunos[numAlunos - 1].nota1);
				
				printf("Digite a segunda nota: ");
				scanf("%f", &alunos[numAlunos - 1].nota2);
				
				printf("\n");
				
					calcularMedia(&alunos[numAlunos - 1]);
					
						printf("Deseja cadastrar mais alunos? (S/N):");
						scanf(" %c", &opcao);
			
				}while (opcao == 'S' || opcao == 's');
				
				free(alunos);
				
					return 0;
						
			
	
}
