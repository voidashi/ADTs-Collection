#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "fila.h"


fila_t *create(int tamElem){
    fila_t *f = (fila_t*)malloc(sizeof(fila_t));
    assert(f != NULL);

    f->itens = (void**)malloc(sizeof(void*) * TamFila);
    assert(f->itens != NULL);

    f->ini = 0;
    f->fim = 0;
    f->total = 0;
    f->tamElem = tamElem;


    return f;
}

void destroy(fila_t *f){

    while(f->total > 0){
        free(f->itens[f->fim]);
        f->total -= 1;
    }

    if(f->itens != NULL)
        free(f->itens);

    if(f != NULL)
        free(f);

    f = NULL;
}

int isFull(fila_t *f){
    assert(f != NULL);

    if(f->total == TamFila)
        return 1;
    else
        return 0;
}

int isEmpty(fila_t *f){
    assert(f != NULL);

    if(f->total == 0)
        return 1;
    else
        return 0; 
}

int insert(fila_t *f, void *x){
    if(isFull(f) == 1)
        return 0;

    f->itens[f->fim] = (void*)malloc(f->tamElem);

    memcpy(f->itens[f->fim], x, f->tamElem);
    assert(f->itens[f->fim] != NULL);

    f->fim = f->fim + 1;
    f->total++;
    return 1;
}

int remover(fila_t *f, void *x){
    if(isEmpty(f) == 1)
        return 0;

    memcpy(x, f->itens[f->ini], f->tamElem);
    free(f->itens[f->ini]);

    f->ini = (f->ini + 1) % TamFila;
    f->total--;
    return 1;
}
