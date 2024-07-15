#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "racionais.h"

int main() {
	srand(time(NULL)); /*inicializa a semente randômica uma única vez*/

	int n;
	int max;
	printf("N: ");
	scanf("%d", &n);
	printf("MAX: ");
	scanf("%d", &max);

	for (int i = 1; i <= n; i++)
	{
		printf("%d: ", i);

	/*sorteia dois racionais r1 e r2*/
		struct racional r1 = sorteia_r(max);
		struct racional r2 = sorteia_r(max);

	/*imprime r1 e r2 na mesma linha*/
		imprime_r(r1);
		printf(" ");
		imprime_r(r2);

	/*verifica se r1 ou r2 são inválidos*/
	if (!valido_r(r1) || !valido_r(r2)) 
	{
		printf("NUMERO INVALIDO\n");
		return 1;
        }

	/*realiza as operações*/
		struct racional soma = soma_r(r1, r2);
		struct racional subtracao = subtrai_r(r1, r2);
		struct racional multiplicacao = multiplica_r(r1, r2);
		struct racional divisao = divide_r(r1, r2);

	/*verifica se a divisão é inválida*/
	if (!valido_r(divisao)) 
	{
		printf("DIVISAO INVALIDA\n");
		return 1;
	}

	/* Imprime os resultados */
	printf(" ");
	imprime_r(soma);
	printf(" ");
	imprime_r(subtracao);
	printf(" ");
	imprime_r(multiplicacao);
	printf(" ");
	imprime_r(divisao);

	printf("\n");
		}
return 0;
}
