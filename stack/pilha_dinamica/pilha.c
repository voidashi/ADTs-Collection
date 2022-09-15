#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"


pilha_t *create(){
    pilha_t *p = (pilha_t*)malloc(sizeof(pilha_t));
    assert(p != NULL);
    
    p->itens = malloc(sizeof(elem) * TamPilha);
    assert(p->itens != NULL);

    p->topo = -1;

    return p;
}

void destroy(pilha_t *p){

    if(p->itens != NULL)
        free(p->itens);

    if(p != NULL)
        free(p);

    p = NULL;
}

int isFull(pilha_t *p){
    assert(p != NULL);

    if(p->topo == TamPilha - 1)
        return 1;
    else
        return 0;
}

int isEmpty(pilha_t *p){
    assert(p != NULL);

    if(p->topo == -1)
        return 1;
    else
        return 0; 
}

int push(pilha_t *p, elem x){
    assert(p != NULL);

    if(isFull(p) == 1)
        return -1;

    p->topo = p->topo + 1;
    p->itens[p->topo] = x;
    return 1;
}

int pop(pilha_t *p, elem *x){
    assert(p != NULL);

    if(isEmpty(p) == 1)
        return -1;

    *x = p->itens[p->topo];
    p->topo -= 1;
    return 1;
}

int top(pilha_t *p, elem *x){
    assert(p != NULL);
    
    if(isEmpty(p) == 1)   
        return -1;
    
    *x = p->itens[p->topo];         
    return 1;
}
