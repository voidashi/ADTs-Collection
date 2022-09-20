#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main(){
    
    elem x;
    fila_t *p = NULL;

    p = create();

    for(int i = 0; i < 10; i++){
        insert(p, (elem)i);
    }

    while(!isEmpty(p)){
        removeElem(p, &x);
        printf("%d ", x); 
    }
    printf("\n");

    destroy(p);

    return 0;
}

