/*
 *       Filename:  main.c
 *         Author:  Jefferson E. M. Bueno, 
 */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){

    lista_t *l = cria();

    inserir(l, 14);
    inserir(l, 10);
    inserir(l, 9);
    inserir(l, 18);
    inserir(l, 5);
    inserir(l, 8);

    imprimir(l);
    imprimir_inv(l);

    remover(l, 5);
    imprimir(l);

    remover(l, 14);
    imprimir(l);

    remover(l, 18);
    imprimir(l);

    liberar(l);


    return 0;
}

