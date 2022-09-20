#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(){
    
    int x;
    pilha_t *p = NULL;

    p = create();

    for(int i = 0; i < 10; i++){
        push(p, (elem)i);
    }

    while(!isEmpty(p)){
        pop(p, &x);
        printf("%d ", x); 
    }
    printf("\n");

    return 0;
}