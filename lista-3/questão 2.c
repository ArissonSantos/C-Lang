#include <stdio.h>
#include <locale.h>

struct Professor {
    int codigo;
    char sexo;
    int horasAula;
    float salarioBruto;
    float desconto;
    float salarioLiquido;
};

int i;

float calcularDesconto(char sexo, int horasAula) {
    if (sexo == 'M') {
        return (horasAula <= 70) ? 0.10 : 0.08;
    } else {
        return (horasAula <= 70) ? 0.07 : 0.05;
    }
}

void calcularSalario(struct Professor *professor, float valorHoraAula) {
    professor->salarioBruto = professor->horasAula * valorHoraAula;
    professor->desconto = calcularDesconto(professor->sexo, professor->horasAula);
    professor->salarioLiquido = professor->salarioBruto - (professor->salarioBruto * professor->desconto);
}

void exibirListagem(const struct Professor *professores, int numProfessores) {
    printf("Listagem dos Salários dos Professores\n");
    
    printf("¦ Código ¦ Salário Bruto ¦ Desconto ¦ Salário Líquido ¦\n");
   

    for (i = 0; i < numProfessores; i++) {
        const struct Professor *professor = &professores[i];
        printf("¦ %6d ¦ %13.2f ¦ %8.2f ¦ %14.2f ¦\n", professor->codigo, professor->salarioBruto, professor->desconto, professor->salarioLiquido);
    }

   
}

float calcularMediaSalarios(const struct Professor *professores, int numProfessores, char sexo) {
    float somaSalarios = 0;
    int contador = 0;
	int i;
	
    for (i = 0; i < numProfessores; i++) {
        const struct Professor *professor = &professores[i];
        if (professor->sexo == sexo) {
            somaSalarios += professor->salarioBruto;
            contador++;
        }
    }

    return (contador > 0) ? somaSalarios / contador : 0;
}

int main() {
	
	setlocale (LC_ALL, "Portuguese");

    const int numProfessores = 5;
    const float valorHoraAula = 15.0;

    struct Professor professores[numProfessores];

    printf("Cadastro de Salários dos Professores\n\n");

    for (i = 0; i < numProfessores; i++) {
        struct Professor *professor = &professores[i];

        printf("Professor %d\n", i + 1);

        printf("Código: ");
        scanf("%d", &professor->codigo);

        printf("Sexo (M/F): ");
        scanf(" %c", &professor->sexo);

        printf("Número de horas/aula: ");
        scanf("%d", &professor->horasAula);

        calcularSalario(professor, valorHoraAula);

        printf("\n");
    }

    exibirListagem(professores, numProfessores);

    float mediaMasculino = calcularMediaSalarios(professores, numProfessores, 'M');
    float mediaFeminino = calcularMediaSalarios(professores, numProfessores, 'F');

    printf("Média dos Salários dos Professores Masculinos: %.2f\n", mediaMasculino);
    printf("Média dos Salários dos Professores Femininos: %.2f\n", mediaFeminino);

    return 0;
}


