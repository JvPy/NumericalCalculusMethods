#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Fx (float x){
	float eq;

	eq = x*x + x - 6;

	return eq;
}

float fx (float x){
	float dev;

	dev = 2*x + 1;

	return dev;
}

int main(void){

	float x0;
	float x1;
	float ep = 0.000001;
	float erro;
	int k = 0;

	printf("Digite o valor de x0:  ");
	scanf("%f", &x0);

	erro = ep * 2;

	puts("\nProcessando...");

	while(erro > ep){
		x1 = x0 - (Fx(x0)/fx(x0));
		erro = fabs((x1-x0)/x1);
		x0 = x1;
		k++;
		printf("\nValor no ponto %f eh %f", x1, Fx(x1));
	}
	puts("");
	printf("\nO valor que em que a funcao eh zero: %f", x1);
	printf("\nO valor de f(x0) eh: %f", Fx(x0));
	printf("\nForam feitas %d iteracoes.", k);

	puts("\n\nFIM DO PROCESSO\n");
	return 0;
}