#include <stdio.h>
#include <stdlib.h>

/*Elabore um programa que faça o sorteio de vários números e ao final mostra:
a) A quantidade de números sorteados;
b) O Maior numero sorteado;
c) Quantos números pares foram sorteados;
Observação: O programa deve finalizar quando for sorteado o valor 0 (zero)e utilizar no
máximo 3 variáveis não utilizar vetores ou matrizes.*/

int main()
{
  int quantidade = 0, maior = 0, pares = 0, numero;

  while (1)
  {
    printf("Digite um número (0 para sair): ");
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
  printf("Maior número sorteado: %d\n", maior);
  printf("Quantidade de numeros pares: %d\n", pares);

  return 0;
}

