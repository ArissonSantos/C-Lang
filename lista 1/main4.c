#include <stdio.h>
#include <stdlib.h>

/*Elabore um programa que receba omo dados de entrada duas notas de vários alunos
e ao final mostra:
a) A quantidade de alunos com media maior ou igual a 7,0;
b) A Menor media da Turma;
c) A Media geral da turma;
d) Quantas vezes o programa rodou;
Observação: O programa deve finalizar quando for digitado o valor 0 (zero) e utilizar no
máximo 6 variáveis não utilizar vetores ou matrizes.*/

int main()
{
  int quantidade = 0, media_maior_ou_igual_a_7 = 0;
  float menor_media = 10.0, media_geral = 0.0;
  float nota1, nota2;

  while (1)
  {
    printf("Digite a nota 1 e a nota 2 do aluno (0 para sair): ");
    scanf("%f%f", &nota1, &nota2);
    
    if (nota1 == 0 && nota2 == 0)
    {
      break;
    }

    quantidade++;

    float media = (nota1 + nota2) / 2.0; //

    if (media >= 7.0)
    {
      media_maior_ou_igual_a_7++;
    }

    if (media < menor_media)
    {
      menor_media = media;
    }

    media_geral += media;
  }

  printf("Quantidade de alunos com média maior ou igual a 7.0: %d\n", media_maior_ou_igual_a_7);
  printf("Menor média da turma: %.2f\n", menor_media);

  if (quantidade > 0)
  { 
    media_geral /= quantidade;
  }

  printf("Média geral da turma: %.2f\n", media_geral);
  printf("Quantidade de vezes que o programa rodou: %d\n", quantidade);

  return 0;
}

