#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treap.h"

struct no {
	no_t *esq, *dir;
	elem info;
	int priori;
};

arvore_t *criar() {
	arvore_t *a = (arvore_t *)malloc(sizeof(arvore_t));
	a->raiz = NULL;
	return a;
}

int esta_vazia(arvore_t *a) {
	assert(a != NULL);
	if(a->raiz == NULL)
		return 1;
	return 0;
}

void finalizar(no_t *raiz) {
	if(raiz != NULL) {
		finalizar(raiz->esq);
		finalizar(raiz->dir);
		free(raiz);
	}
}

void imprimir(no_t *raiz) {
	if(raiz != NULL) {
		printf("%d(", raiz->info);
		imprimir(raiz->esq);
		printf(",");
		imprimir(raiz->dir);
		printf(")");
	} else {
		printf("null");
	}
}

int altura(no_t *raiz) {
	if(raiz == NULL) 
		return 0;
	
	int alt_esq = 1 + altura(raiz->esq);
	int alt_dir = 1 + altura(raiz->dir);
	
	if(alt_esq > alt_dir)
		return alt_esq;
	else
		return alt_dir;
}

void pre_ordem(no_t *raiz) {
	if(raiz != NULL) {
		printf("(%d, %d) ", raiz->info, raiz->priori);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void em_ordem(no_t *raiz) {
	if(raiz != NULL) {		
		em_ordem(raiz->esq);
		printf("(%d, %d) ", raiz->info, raiz->priori);
		em_ordem(raiz->dir);
	}
}

void pos_ordem(no_t *raiz) {
	if(raiz != NULL) {		
		pos_ordem(raiz->esq);		
		pos_ordem(raiz->dir);
		printf("(%d, %d) ", raiz->info, raiz->priori);
	}
}

no_t *busca(no_t *raiz, elem x) {
	if(raiz == NULL) {
		return NULL;
	} else if(raiz->info == x) {
		return raiz;
	} else if(x < raiz->info) {
		return busca(raiz->esq, x);
	} else {
		return busca(raiz->dir, x);
	}
}

int busca_bool(no_t *raiz, elem x) {
	if(raiz == NULL) {
		return 0;
	} else if(raiz->info == x) {
		return 1;
	} else if(x < raiz->info) {
		return busca_bool(raiz->esq, x);
	} else {
		return busca_bool(raiz->dir, x);
	}
}

no_t *rotacao_EE(no_t *desb) {
	no_t *aux = desb->dir;
	desb->dir = aux->esq;
	aux->esq = desb;
	return aux;
}

no_t *rotacao_DD(no_t *desb) {
	no_t *aux = desb->esq;
	desb->esq = aux->dir;
	aux->dir = desb;
	return aux;
}

int inserir(no_t **raiz, elem x, int priori) {
	if(*raiz == NULL) {
		*raiz = (no_t *)malloc(sizeof(no_t));
		(*raiz)->info = x;
		(*raiz)->priori = priori;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		return 1;
	} else if(x == (*raiz)->info) {
		printf("Elemento ja existente\n"); //TODO: mover para a main
		return 0;
	} else if(x < (*raiz)->info) {
		inserir(&(*raiz)->esq, x, priori);
		if((*raiz)->priori < (*raiz)->esq->priori) {
			(*raiz) = rotacao_DD((*raiz)); // Rotacao heap
		}
	} else {
		inserir(&(*raiz)->dir, x, priori);
		if((*raiz)->priori < (*raiz)->dir->priori) { 
			(*raiz) = rotacao_EE((*raiz)); // Rotacao heap
		}
	}
}

int remover(no_t **raiz, elem x) {
	if(*raiz == NULL) {
		printf("Chave nao localizada\n");
		return 0;
	} else if(x < (*raiz)->info) {
		return remover(&(*raiz)->esq, x);
	} else if(x > (*raiz)->info) {
		return remover(&(*raiz)->dir, x);
	} else {
		if((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
			free(*raiz);
			*raiz = NULL;
			return 1;
		}			
		else if((*raiz)->esq == NULL) {
			no_t *aux = *raiz;
			*raiz = (*raiz)->dir;
			free(aux);
			return 1;
		}
		else if((*raiz)->dir == NULL) {
			no_t *aux = *raiz;
			*raiz = (*raiz)->esq;
			free(aux);
			return 1;
		}		
		else { //Caso em que a rotacao deve ser aplicada
	
			while((*raiz)->dir != NULL) {
				*raiz = rotacao_EE(*raiz);
			}

			return remover(&(*raiz)->esq, x);
		}
	}
	return 0;
}
