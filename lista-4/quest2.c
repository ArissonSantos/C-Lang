#include <stdio.h>
#include <limits.h>

void maximoMinimo(int *v, int n, int *maximo, int *minimo) {
	
    *maximo = INT_MIN;
    *minimo = INT_MAX;
    
    	int i;
    
    
    for (i = 0; i < n; i++) {
        *maximo = (*maximo > v[i]) ? *maximo : v[i];
        *minimo = (*minimo < v[i]) ? *minimo : v[i];
        
    }
}


int main() {
	
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
		    int vetor[tamanho];
		    
		    printf("Digite os elementos do vetor:\n");
		    
		    int i;
		    for (i = 0; i < tamanho; i++) {
		        scanf("%d", &vetor[i]);
		    }
    
   			 int valor_minimo, valor_maximo;
    
   					 maximoMinimo(vetor, tamanho, &valor_maximo, &valor_minimo);
    
   							 printf("Valor minimo: %d\n", valor_minimo);
   							 printf("Valor maximo: %d\n", valor_maximo);
    
   			 return 0;
}
