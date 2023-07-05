#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void mm(int v[], int n, int* endereco_min, int* endereco_max) {
    int i;
    *endereco_min = INT_MAX;
    *endereco_max = INT_MIN;

    for (i = 0; i < n; i++) {
        if (v[i] < *endereco_min) {
            *endereco_min = v[i];
        }
        if (v[i] > *endereco_max) {
            *endereco_max = v[i];
        }
    }
}

int main() {
    
	int tamanho = 3;
    int *vetor;
    int i;
    int valor_minimo, valor_maximo;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*)malloc(tamanho * sizeof(int));

	    printf("Digite os elementos do vetor:\n");
	    for (i = 0; i < tamanho; i++) {
	        scanf("%d", &vetor[i]);
	    }

    		mm(vetor, tamanho, &valor_minimo, &valor_maximo);

			    printf("Valor minimo: %d\n", valor_minimo);
			    printf("Valor maximo: %d\n", valor_maximo);

    free(vetor);

    return 0;
}
