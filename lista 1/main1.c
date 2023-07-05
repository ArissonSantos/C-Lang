#include <stdio.h>
#include <stdlib.h>


int main() {
    float sal, s_sal = 0, med_sal, m_sal = 0;
    int NF, SF = 0, Npessoas = 0, N100 = 0;
    
    
    while (1) {
        printf("Digite o salario (digite um numero negativo para finalizar): ");
        scanf("%f", &sal);
        if (sal < 0) {
            break;
        }
        printf("Digite o numero de filhos: ");
        scanf("%d", &NF);
        
        s_sal += sal;
        SF += NF;
        Npessoas+1;
        
        if (sal> m_sal) {
            m_sal = sal;
        }
        
        if (sal <= 100) {
            N100++;
        }
    }
    
    med_sal = s_sal / Npessoas;
    float media_filhos = (float)SF / Npessoas;
    
    float percentual_ate_100 = ((float)N100 / Npessoas) * 100;
    
    printf("Media salarial da populacao: %.2f\n", med_sal);
    printf("Media do numero de filhos: %.2f\n", media_filhos);
    printf("Maior salario: %.2f\n", m_sal);
    printf("Percentual de pessoas com salario ate R$ 100,00: %.2f%%\n", percentual_ate_100);
    
    return 0;
}

