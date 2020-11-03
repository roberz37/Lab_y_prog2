#include <stdio.h>
#include <stdlib.h>


/*Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X
en la posición I de la pila si es posible. (Definir parámetros y codificar).*/


int main()
{

    return 0;
}


void isPosible(ST_NODO** pila, int valor, int posicion){
    ST_NODO* auxiliar = create();

    while (!isEmpty(*pila) && posicion > 1){
        push(&auxiliar, pop(pila));
        posicion--;
    }
    if (posicion == 1){
        push(pila, valor);
        printf("S"\n);
    } else {
        printf("N\n");
    }
    while (!isEmpty(auxiliar)){
        push(pila, pop(&auxiliar));
    }
}
