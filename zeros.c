/*
	Este progrma localiza zeros reais em funcoes reais
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float equacao(float x){
	float eq;

	eq = x * log10(x) - 1;

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

	int k;


	puts("Este programa encontra zeros reais em funcoes reais");

	puts("Digite seu valor minimo");
	scanf("%f", &mim);
	puts("Digite seu valor maximo");
	scanf("%f", &max);


	atual = (mim+max)/2;

	while( fabs(equacao(atual)) > erro ){
		eqMim = equacao(mim);
		eqMax = equacao(max);
		eqAtual = equacao(atual);

		sinalMim = equacao(mim) * equacao(atual);
		sinalMax = equacao(max) * equacao(atual);

		if(sinalMim < 0){
			max = atual;
			atual = (mim+max)/2;
			eqMax = eqAtual;
			eqAtual = equacao(atual);
		} else {
			mim = atual;
			atual = (mim+max)/2;
			eqMim = eqAtual;
			eqAtual = equacao(atual);
		}
		k++;
	}
	printf("\nf(x%d) = %f",k, eqAtual );
	printf("\nNumero de iteracoes: %d", k);
	printf("\nA funcao chega no zero no valor: %5.5f", atual);
	puts("\n\nFIM DO PROCESSO.\n");
	return 0;
}