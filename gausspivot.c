//Metodo de Gauss

/*
	Este programa recebe ou gera uma matriz quadrada e aplica o metodo de Gauss para escalonar
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	//Adicionar funcoes deixando o programa mais limpo;

int main (void) {
	//Variveis
	int tamanhoMatriz;

	//Vetores
	float *aux;
	float *matrizResultado;
	float **matriz;
	float **m;

	//Auxiliares
	float comparador;

	//Contadores
	int i; //linhas
	int j; //colunas
	int k; //numeroDeOperacoes

	puts("Este programa recebe uma matriz quadrada N x (N+1) e aplica o metodo de gauss\nSendo N+1 a parte do resultado");
	puts("Qual a medida de sua matriz:");

	scanf("%d", &tamanhoMatriz);

	printf("\nSua matriz eh: %d x %d\n",tamanhoMatriz, tamanhoMatriz+1);

	matrizResultado = malloc( tamanhoMatriz * sizeof(float));
	aux = malloc( tamanhoMatriz * sizeof(float));
	matriz = malloc( tamanhoMatriz * sizeof(float*));
	m = malloc( tamanhoMatriz * sizeof(float*));

	for(i=0; i<tamanhoMatriz; ++i){
		matriz[i] = malloc(tamanhoMatriz * sizeof(float));
		m[i] = malloc(tamanhoMatriz * sizeof(float));
	}

	//Preencher a matriz
	for(i = 0; i < tamanhoMatriz; i++){
		for(j = 0; j <= tamanhoMatriz; j++){
			printf("\nA[%d][%d] = ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
		}
		matrizResultado[i] = matriz[i][j-1];
	}

	puts("\n");

	//Print da matriz
	for(i = 0; i < tamanhoMatriz; i++) {
		printf("[  ");
		for(j = 0; j < tamanhoMatriz; j++) {
			printf("%5.2f ", matriz[i][j]);
		}
		printf("]");
		printf("[ %5.2f ]\n", matrizResultado[i]);
	}

	//Escalonamento
	for (k = 0; k < tamanhoMatriz - 1; k++) {
		comparador = fabs(matriz[k][k]);
		linha = k;
		for (i = k + 1; i < tamanhoMatriz; i++) {
			if(fabs(matriz[i][k]) > comparador){
				comparador = fabs(matriz[i][k]);
				linha = i;
			}
			//outro for
			for (j = k; j < tamanhoMatriz; j++) {

				m[i][k]= -(matriz[i][k]/matriz[k][k]);
				matriz[i][j] = matriz[i][j] + (m[i][k] * matriz[k][j]);
			}

			matrizResultado[i] = matrizResultado[i] + (m[i][k] * matrizResultado[k]);
		}

	}

	puts("\n\n");
	
	//Print da matriz escolanda
	for(i = 0; i < tamanhoMatriz; i++) {
		printf("[  ");
		for(j = 0; j < tamanhoMatriz; j++) {
			printf("%5.2f ", matriz[i][j]);
		}
		printf("]");
		printf("[ %5.2f ]\n", matrizResultado[i]);
	}

	puts("\nFIM DO PROCESSO");
	return 0;
}