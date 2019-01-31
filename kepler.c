#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Fx (float x, float e, float m){
	float eq;

	eq = x-e*sin(x)-m;

	return eq;
}

float fx (float x, float e){
	float dev;

	dev = 1-e*cos(x);

	return dev;
}

int main(void){

	float x0;
	float x1;
	float m;
	float e;
	float ep = 0.001;
	float erro;
	int k = 0;

	printf("Digite o valor de x0:  ");
	scanf("%f", &x0);
	printf("Digite o valor de m:  ");
	scanf("%f", &m);
	printf("Digite o valor de e:  ");
	scanf("%f", &e);

	erro = ep * 2;

	puts("\nProcessando...");

	while(erro > ep){
		x1 = x0 - (Fx(x0,e,m)/fx(x0,e));
		erro = fabs((x1-x0)/x1);
		x0 = x1;
		k++;
		printf("\nValor no ponto %f eh %f", x1, Fx(x1,e,m));
	}
	puts("");
	printf("\nO valor que em que a funcao eh zero: %f", x1);
	printf("\nO valor de f(x0) eh: %f", Fx(x0,e,m));
	printf("\nForam feitas %d iteracoes.", k);

	puts("\n\nFIM DO PROCESSO\n");
	return 0;
}
