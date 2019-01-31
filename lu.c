//Metodo de Gauss

/*
	Este programa recebe ou gera uma matriz quadrada e aplica o metodo de Gauss para escalonar
*/

#include <stdio.h>
#include <stdlib.h>

	//Adicionar funcoes deixando o programa mais limpo;

int main (void) {
	
	//Variveis
	int tamanhoMatriz;

	//Vetores
	float *matrizY;
	float *matrizX;
	float *matrizResultado;
	float **matriz;
	float **m;

	//Contadores
	int i; //linhas
	int j; //colunas
	int k; //numeroDeOperacoes

	puts("Este programa recebe uma matriz quadrada Nx(N+1) e aplica o metodo de guaus\nSendo N+1 a parte do resultado");
	puts("Qual a medida de sua matriz:");

	scanf("%d", &tamanhoMatriz);

	printf("\nSua matriz eh: %d x %d\n",tamanhoMatriz, tamanhoMatriz+1);

	matriz = malloc( tamanhoMatriz * sizeof(float*));
	matrizResultado = malloc( tamanhoMatriz * sizeof(float));
	m = malloc( tamanhoMatriz * sizeof(float*));
	matrizY = malloc( tamanhoMatriz * sizeof(float*));

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

	//Prencher a matriz M com zeros, para ter um print correto no final
	for(i = 0; i < tamanhoMatriz; i++){
		for(j = 0; j <= tamanhoMatriz; j++){
			if(i == j){
				m[i][j] = 1;
			} else {
			m[i][j] = 0;
			}
		}
	}

	//Preencher matriz X e Y com 0
	for(i = 0; i < tamanhoMatriz; i++){
		matrizY[i] = 0;
		matrizX[i] = 0;
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

	for (k = 0; k < tamanhoMatriz - 1; k++) {
		for (i = k + 1; i < tamanhoMatriz; i++) {
			m[i][k]= - (matriz[i][k]/matriz[k][k]);

			for (j = k; j < tamanhoMatriz; j++) {
				matriz[i][j] = matriz[i][j] + (m[i][k] * matriz[k][j]);
			}
		}
	}

	puts("\nAplicando transformacao L.U...\n");
	
	//Print da matriz upper
	puts("Matriz U:");
	for(i = 0; i < tamanhoMatriz; i++) {
		printf("[  ");
		for(j = 0; j < tamanhoMatriz; j++) {
			printf("%5.2f ", matriz[i][j]);
		}
		printf(" ]\n");
	}

	//Print da matriz lower
	puts("\nMatriz L:");
	for(k = 0; k < tamanhoMatriz; k++){
		printf("[  ");		
		for(i = 0; i < tamanhoMatriz; i++){
			printf("%5.2f ", m[k][i]);
		}
		printf(" ]\n");
	}

	//Print da matriz b
	puts("\nMatriz B:");
	for(i = 0; i < tamanhoMatriz; i++){
		printf("[ %5.2f ]\n", matrizResultado[i]);
	}

	//Multiplicar L.y = b
	for(i = 0; i < tamanhoMatriz; i++){
		matrizY[i] = matrizResultado[i];
		for(j = i+1; j < tamanhoMatriz; j++){
			matrizY[i] = matrizY[i] - (m[i][j] * matrizY[j]);
		}
	}
	//Print da matriz Y
	puts("\nMatriz Y:");
	for(i = 0; i < tamanhoMatriz; i++){
		printf("[%5.2f]\n", matrizY[i]);
	}

	//Multiplicar U.x = y
	for(i = 0; i < tamanhoMatriz; i++){
		matrizX[i] = matrizResultado[i];
		for(j = i+1; j < tamanhoMatriz; j++){
			matrizX[i] = matrizX[i] - (m[i][j] * matrizX[j]);
		}
	}
	//Print da matriz X
	puts("\nMatriz X:");
	for(i = 0; i < tamanhoMatriz; i++){
		printf("[%5.2f]\n", matrizX[i]);
	}

	puts("\nFIM DO PROCESSO");
	return 0;
}