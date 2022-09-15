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
    no_t *prox;
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

void inserir(lista_t *l, elem x){
    assert(l != NULL);

    //não inserir elementos repetidos
    if(esta_na_lista(l, x) == 1)
            return;

    no_t *p = (no_t*)malloc(sizeof(no_t));
    p->info = x;
    p->prox = NULL;

    //1o caso: lista vazia
    if(l->ini == NULL){
        l->ini = p;
    } else{ //2o caso: lista com pelo menos 1 elem
        l->fim->prox = p;
    }
    l->fim = p;

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

    no_t *ant = NULL;
    no_t *p = l->ini;

    while(p != NULL){
        if(p->info == x){
            //1o. caso: remover no inicio
            if(p == l->ini){ //ou ant == NULL
                l->ini = l->ini->prox;
                free(p);
            } else if(p == l->fim){ //2o. caso: remover do fim
                l->fim = ant;
                l->fim->prox = NULL;
                free(p);
            } else{ //3o. caso: remover do meio
                ant->prox = p->prox;
                free(p);
            }
            l->tam--;
            return 1;
        } else{
            ant = p;
            p = p->prox;
        }
    }
    return 0;
}




