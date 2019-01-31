/*
	Este progrma localiza zeros reais em funcoes reais
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float equacao(float x){
	float eq;

	eq = sin(x) + x*x - 1;

	return eq;
}

int main(void){
	
	//Limites
	float mim;
	float max;
	float atual;
	float erro=0.0000001;

	//Equacoes
	float eqMim;
	float eqMax;
	float eqAtual;
	float sinalMim;
	float sinalMax;

	//Contador de iteracoes
	int k=1;	//Inicia em 1, pois a primeira iteracao eh feita fora do while

	puts("\nEste programa encontra zeros reais em funcoes reais pelo metodo da falsa posicao");

	puts("Digite seu valor minimo");
	scanf("%f", &mim);
	puts("Digite seu valor maximo");
	scanf("%f", &max);

	eqMim = equacao(mim);
	eqMax = equacao(max);
	atual = (mim*eqMax - max*eqMim)/(eqMim - eqMax);

	while( fabs(equacao(atual)) > erro ){
		eqMim = equacao(mim);
		eqMax = equacao(max);
		eqAtual = equacao(atual);

		atual = (mim*eqMax - max*eqMim)/(eqMim - eqMax);


		k++;
	}
	printf("\nf(x%d) = %f",k, eqAtual );
	printf("\nNumero de iteracoes: %d", k);
	printf("\nA funcao chega no zero no valor: %5.5f", atual);
	puts("\n\nFIM DO PROCESSO.\n");
	return 0;
}