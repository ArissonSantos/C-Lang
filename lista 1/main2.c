#include <stdio.h>
#include <stdlib.h>


int main()
{

  float AC = 1.5, AZ = 1.1;
  int CC = 2, CZ = 3;
  int anos = 0, idade;

  while (1)
  {
    printf("Digite a idade (-1 para sair): ");
    scanf("%d", &idade);
    if (idade < 0)
    {
      break;
    }

    AC += CC * idade / 100.0;
    AZ += CZ * idade / 100.0;
    if (AZ > AC)
    {
      printf("Altura de Ze ultrapassou a de Chico em %d anos.\n", anos);
      anos = 0;
    }
    else
    {
      anos += idade;
    }

    if (anos >= 100)
    {
      printf("Imposs�vel Ze ultrapassar Chico em 100 anos.\n");
      break;
    }
  }

  return 0;
}

