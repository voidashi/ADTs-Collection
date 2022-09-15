#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "abb.h"

int main(void) {
	arvore_t *a = criar();
	
	inserir(&a->raiz, 5);
	inserir(&a->raiz, 3);
	inserir(&a->raiz, 7);
	inserir(&a->raiz, 9);
	inserir(&a->raiz, 8);
	inserir(&a->raiz, 2);
	
	imprimir(a->raiz);
	printf("\n");

	remover(&a->raiz, 5);
	imprimir(a->raiz);
	printf("\n");

	
	return 0;
}