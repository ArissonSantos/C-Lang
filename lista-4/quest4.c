#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

	typedef struct{
		
		int codigo;
		char cargo[20];
		float percentual;
		
	} Cargo;
	
	typedef struct{
		
		float salario;
		Cargo cargo;
		
	} Funcionario;

void calcularNovoSalario(Funcionario *funcionario){
	
	float novoSalario;

		switch(funcionario -> cargo.codigo){
			case 101:
				novoSalario = funcionario -> salario + (funcionario -> salario * funcionario -> cargo.percentual);
			
			break;
			
			case 102:
				novoSalario = funcionario -> salario + (funcionario -> salario * funcionario -> cargo.percentual);
				
			break;
			
			case 103:
				novoSalario = funcionario -> salario + (funcionario -> salario * funcionario -> cargo.percentual);
				
			break;
		
		default:
			novoSalario = funcionario -> salario + (funcionario -> salario * 0.4);
		
			break;
			
		}	
	
	float diferenca = novoSalario - funcionario -> salario;
		
	printf("+--------------+--------------+-----------------+-------------------+------------------+\n");
    printf("| Salario ant. | Novo salario | Diferenca (R$)  | Codigo do cargo   |     Cargo        |\n");
    printf("+--------------+--------------+-----------------+-------------------+------------------+\n");
    printf("| R$ %8.2f  | R$ %8.2f  | R$ %10.2f   | %14d    |%-16s  |\n", funcionario->salario, novoSalario, diferenca, funcionario->cargo.codigo, funcionario->cargo.cargo);
    printf("+--------------+--------------+-----------------+-------------------+------------------+\n");
    
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
		char resposta[3];
		
		do {
    
	Funcionario funcionario;
	
		printf("Digite o salario do funcionario: ");
		scanf("%f", &funcionario.salario);
		
		printf("Digite o codigo do cargo: ");
		scanf("%d", &funcionario.cargo.codigo);
		
		printf("\n");
		
	switch(funcionario.cargo.codigo){
		
		case 101:
			snprintf(funcionario.cargo.cargo, sizeof(funcionario.cargo.cargo), "Gerente");
				funcionario.cargo.percentual = 0.1;
			
			break;
		
		case 102:
			snprintf(funcionario.cargo.cargo, sizeof(funcionario.cargo.cargo), "Engenheiro");
				funcionario.cargo.percentual = 0.2;
			
			break;
		
		case 103:
			snprintf(funcionario.cargo.cargo, sizeof(funcionario.cargo.cargo), "Tecnico");
				funcionario.cargo.percentual = 0.3;
			
			break;
		
		default:
			snprintf(funcionario.cargo.cargo, sizeof(funcionario.cargo.cargo), "Outro");
				funcionario.cargo.percentual = 0.4;
			
			break;
	}
	
    calcularNovoSalario(&funcionario);
   		
   	 printf("+--------------+--------------+-----------------+-------------------+------------------+\n");

        printf("Deseja fazer outra checagem? (sim/nao): ");
        scanf("%s", resposta);
        printf("\n");
        
    } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0 || strcmp(resposta, "SIM") == 0);

    	return 0;
}

