#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"


fila_t *create(){
    fila_t *f = (fila_t*)malloc(sizeof(fila_t));
    assert(f != NULL);

    f->ini = 0;
    f->fim = 0;
    f->total = 0;

    return f;
}

void destroy(fila_t *f){
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

int insert(fila_t *f, elem x){
    if(isFull(f) == 1)
        return 0;

    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % TamFila;
    f->total++;
    return 1;
}

int removeElem(fila_t *f, elem *x){
    if(isEmpty(f) == 1)
        return 0;

    *x = f->itens[f->ini];
    f->ini = (f->ini + 1) % TamFila;
    f->total--;
    return 1;
}
