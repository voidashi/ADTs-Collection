/*
 *       Filename:  lista.c
 *         Author:  Jefferson E. M. Bueno, 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

typedef struct no no_t;

struct no{
    elem info;
    no_t *ant, *prox;
};

struct lista {
    no_t *ini, *fim;
    int tam;
};


lista_t *cria(){
    lista_t *l;
    l = (lista_t*)malloc(sizeof(lista_t));
    assert(l != NULL);

    l->ini = NULL;
    l->fim = NULL;
    l->tam = 0;

    return l;
}

void liberar(lista_t *l){
    if(l != NULL){
        no_t *p = l->ini;
        while(p != NULL){
            l->ini = p->prox;
            free(p);
            p = l->ini;
        }
        free(l);
    }
}

int inserir(lista_t *l, elem x){
    assert(l != NULL);

    /*
    //não inserir elementos repetidos
    if(esta_na_lista(l, x) == 1)
            return;
    */
   
    no_t *p = (no_t*)malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;
    p->ant = NULL;

    no_t *aux, *ant;
    ant = NULL;
    aux = l->ini;

    while(aux != NULL && x > aux->info){
        ant = aux;
        aux = aux->prox;
    }

    // caso onde x ja existe na lista
    if(aux != NULL && x == aux->info){
        free(p);
        return 0;
    }

    // caso onde x nao existe na lista
    if(ant == NULL){ // lista vazia ou com elementos
        p->prox = l->ini;
        if(l->ini != NULL) l->ini->ant = p;
        l->ini = p;
    }else{ //inserindo no meio ou no fim da lista
         p->prox = ant->prox;
         ant->prox = p;
         if(p->prox != NULL) p->prox->ant = p;
         else l->fim = p;
         p->ant = ant;
    }

    l->tam++;
}

int tamanho(lista_t *l){
    assert(l != NULL);

    return l->tam;
}

void imprimir(lista_t *l){
    assert(l != NULL);

    no_t *p = l->ini;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void imprimir_inv(lista_t *l){
    assert(l != NULL);

    no_t *p = l->fim;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->ant;
    }
    printf("\n");
}

int esta_na_lista(lista_t *l, elem x){
    assert(l != NULL);

    no_t *p = l->ini;
    while(p != NULL){
        if(p->info == x)
            return 1;
        p = p->prox;
    }
    return 0;
}

int remover(lista_t *l, elem x){
    assert(l != NULL);

    no_t *p = l->ini;
    no_t *ant = NULL;

    while(p != NULL && x > p->info){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return 0;
    }
    
    if(ant == NULL){ //remover primeiro elemento
        l->ini = l->ini->prox;
        if(l->ini != NULL) l->ini->ant = NULL;
        else l->fim = NULL;
        free(p);
    }else{ //remover elemento no meio ou fim
        if(p->prox == NULL){ //remover no fim
            l->fim = p->ant;
            ant->prox = NULL;
            free(p);
        }else{ //remover no meio 
            ant->prox = p->prox;
            p->prox->ant = ant;
            free(p);
        }
    }

    return 1;
}


