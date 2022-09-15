#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct ponto{
    int x, y;
}ponto_t;

int main(){
    
    int x;
    fila_t *p = NULL;

    p = create(sizeof(ponto_t));

    ponto_t ponto;
    for(int i = 0; i < 10; i++){
        ponto.x = i;
        ponto.y = -i;
        insert(p, &ponto);
    }

    while(!isEmpty(p)){
        remover(p, &ponto);
        printf("%d %d\n", ponto.x, ponto.y);
    }
    printf("\n");


    destroy(p);

    return 0;
}

