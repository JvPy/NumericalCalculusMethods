#include <stdio.h>
#include <stdlib.h>

int main(void){

	float *dvf;
	float *x;

	int tamanho;
	int i;

	for (i = n; i >= 0; i--){
		dvf[i] = f(x[i]);
	}

	for (k = 1; k < n; k++){
		for(i = n; i > k-1; i--){
			dvf(i) = (dvf[i]-dvf[i-1])/(x[i]-x[i-k]);
		}
	}

	dvf[tamanho] = (dfv[n] - dvf[n-1])/(x[n] - x[0]);

	puts("FIM DO PROCESSO.");
	return 0;
}

/*
for (i = tamanho, i < tamanho; i++){
	dvf[i] = ((f(x[i]) - f(x[i-1])) / (x[i+1] - x[i]));
}

for (i = tamanho; i > 1
*/