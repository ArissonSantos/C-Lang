#include <stdio.h>
#include <stdlib.h>

/*Elabore um programa que fa�a o sorteio de v�rios n�meros e ao final mostra:
a) A quantidade de n�meros sorteados;
b) O Maior numero sorteado;
c) Quantos n�meros pares foram sorteados;
Observa��o: O programa deve finalizar quando for sorteado o valor 0 (zero)e utilizar no
m�ximo 3 vari�veis n�o utilizar vetores ou matrizes.*/

int main()
{
  int quantidade = 0, maior = 0, pares = 0, numero;

  while (1)
  {
    printf("Digite um n�mero (0 para sair): ");
    scanf("%d", &numero);
    if (numero == 0)
    {
      break;
    }

    quantidade++;

    if (numero > maior)
    {
      maior = numero;
    }

    if (numero % 2 == 0)
    {
      pares++;
    }
  }

  printf("Quantidade de numeros sorteados: %d\n", quantidade);
  printf("Maior n�mero sorteado: %d\n", maior);
  printf("Quantidade de numeros pares: %d\n", pares);

  return 0;
}

