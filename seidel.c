#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 50

int main (void){
	int n; 		// tamanho da matriz
	int rep;	//Numero de repetcoes do metodo iterativo

	//Matrizes e vetores
	float **a;	//Matriz de entrada
	float **c;	//Matriz processada

	//Vetores
	float *b;	//Vetor de entrada, resultado das eq.
	float *g;	//Vetor de entrada processado
	float *x0;	//Vetor x0
	float *x1;	//Vetor x1

	//Erros
	float ep; 	//epsilon
	float erro;	//Erro durante a execucao
	float *e;	//Vetor do erro atual

	//Contadores
	int i = 0;	//Linhas
	int j = 0;	//Colunas
	int k = 0;	//Aux

	puts("Este programa calcula uma aproximacao por jacobi");
	puts("Qual tamanho de sua matriz?");
	scanf("%d", &n);

	puts("Qual valor do erro:");
	scanf("%f", &ep);

	printf("\nSua matriz eh: %d x %d", n, n+1);

	//Alocacao dinamica de memoria
	a = malloc( n * sizeof(float*));
	c = malloc( n * sizeof(float*));
	for(i = 0; i < n; i++){
		a[i] = malloc( n * sizeof(float));
		c[i] = malloc( n * sizeof(float));
	}

	e = malloc( n * sizeof(float));

	b = malloc( n * sizeof(float));
	g = malloc( n * sizeof(float));
	x0 = malloc( n * sizeof(float));
	x1 = malloc( n * sizeof(float));

	//Receber a matriz do usuario
	for(i = 0; i < n; i++){
		for(j = 0; j <= n; j++){
			printf("\nA[%d][%d] = ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}
		b[i] = a[i][j-1];
	}

	//Print da matriz inserida pelo usuario
	for(i = 0; i < n; i++) {
		printf("[  ");
		for(j = 0; j < n; j++) {
			printf("%5.4f ", a[i][j]);
		}
		printf("]");
		printf("[ %5.4f ]\n", b[i]);
	}

	//Inicio do processamento
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			c[i][j] = -a[i][j]/a[i][i]; 
		}
		c[i][i] = 0;
		g[i] = b[i]/a[i][i];
	}

	erro = 2*ep;

	//Processo iterativo
	while(erro > ep && k < max){
		for(i = 0; i < n; i++){
			x1[i] = g[i];
			for(j = i;  j < n; j++ ){
				x1[i] = x1[i] + (c[i][j] * x0[j]);
			}
			for(j = 0 ;  j < i; j++ ){
				x1[i] = x1[i] + (c[i][j] * x1[j]);
			}
			e[i] = fabs(x1[i] - x0[i])/fabs(x1[i]);
		}

		erro = e[i];
		for (i = 1; i < n; i++){
			if( e[i]>erro) {
				erro = e[i];
			} 
		}

		printf("iteracao: %d\n", k);
		for(i = 0; i < n; i++) {
			x0[i]= x1[i];
			printf("[ %.4f ]\n", x1[i]);
		}
		k++;
	}

	puts("\nO valor de x1 eh:");
	for(i = 0; i < n; i++){
		printf("[ %.4f ]\n", x1[i]);
	}
	printf("\nForam feitas %d iteracoes nesse processo.", k);

	puts("\nFIM DO PROCESSO");

	return 0;
}

