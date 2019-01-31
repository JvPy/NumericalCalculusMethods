/************************************************************
*	Algoritimo para calcular o metodo Briot-Ruffini Honer	*			
*															*
*	Joao Victor Martinelli de Souza							*
*	jvmartinellis@gmail.com									*
*															*	
*	Este software pode ser modificado livremente			*
*															*
*	12/04/2016 -  Bug corrigido.							*
*		O vetor estava sendo verificado de forma inversa.	*
*															*
*	13/04/2016 - Alterecao no codigo						*
*		Valor no ponto e da derivada agora armazenados em	*
*		inteiros e nao mais em Vetores 						*
************************************************************/	

#include <stdlib.h>
#include <stdio.h>

#define KBLU  "\x1B[34m"
#define KNRM  "\x1B[0m"

int main (void){
	
	//Vetores
	int *a;			//Polinomio

	//Variaveis
	int c;			//Ponto a ser analisado
	int n;			//Grau do polinomio
	int q; 			//Derivada
	int p;			//Valor no ponto C
	
	//Contador
	int i;

	puts("Digite o grau do polinomio");
	scanf("%d", &n);
	puts("Digite o ponto:");
	scanf("%d", &c);

	a = malloc(n * sizeof(int));

	puts(" ");

	//Preencher o vetor a
	for(i = n; i >= 0; i--){
		printf("Digite o termo que acompanha x%d:", i);
		scanf("%d", &a[i]);
	}

	puts("\nPolinomio de entrada:");


	/* 	Formatacao do print do Polinomio 	*/
	for(i = n; i >= 0; i--){
		//Printar com sinal, caso nao seja o primeiro valor e sinal nao negativo.
		if(a[i] > 0 && i != n && i != 0){
			printf("+ %dx%d ", a[i], i);
		} else { 
			//Printar o ultimo valor sem o parametro X
			if(i-1 != 0){ 
				printf("%dx%d ", a[i], i);
			} else {
				//Caso o termo independente seja positivo, ou zero, printar com +, senao printa com o sinal que o acompanha
				if(a[i] >= 0){
					printf("+ %d ", a[i]);
				} else {
					printf("%d ", a[i]);
				}
			}
		}	
	}
	puts("= 0");

	/* Metodo */
	p = a[n];
	q = 0;
	for(i = n-1; i >= 0; i--){
		q = p + c * q;
		p = a[i] + c * p;
	}
	printf("\n[%s*%s]Valor no ponto %d eh: %d",KBLU, KNRM, c, p);
	printf("\n[%s*%s]Derivada no ponto %d eh: %d",KBLU, KNRM, c, q);

	puts("\nFIM DO PROCESSO.");
	return 0;
}