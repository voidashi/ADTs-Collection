#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "treap.h"

// TODO: Busca em largura
int main(void) {

	int n;
	char modo[10];
	int chave, prioridade;
	char modoPrint[10];
	
	arvore_t *a = criar();

	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%s", modo);

		if(!strcmp(modo, "insercao")) {
			scanf("%d %d", &chave, &prioridade);
			inserir(&a->raiz, chave, prioridade);
		}
		else if(!strcmp(modo, "remocao")) {
			scanf("%d", &chave);
			remover(&a->raiz, chave);
		}
		else if(!strcmp(modo, "buscar")) {
			scanf("%d", &chave);
			printf("%d\n", busca_bool(a->raiz, chave));
		}
		else if(!strcmp(modo, "impressao")) {
			scanf("%s", modoPrint);
			
			if(!strcmp(modoPrint, "ordem")) {
				em_ordem(a->raiz);
				printf("\n");
			}
			else if(!strcmp(modoPrint, "preordem")) {
				pre_ordem(a->raiz);
				printf("\n");
			}
			else if(!strcmp(modoPrint, "posordem")) {
				pos_ordem(a->raiz);
				printf("\n");
			}
			else if(!strcmp(modoPrint, "largura")) {
				//TODO
			}
		}
	}
	
	return 0;
}




















/*

*/
