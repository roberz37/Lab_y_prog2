#include <stdio.h>
#include <stdlib.h>

/*Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la
última posición de la pila y la retorne. (Definir parámetros y codificar).*/


int main()
{

    return 0;
}

void colocarUltimoValor(ST_NODO** pila, int valor){
    ST_NODO* auxiliar = create();

    while (!isEmpty(*pila)){
        push(&auxiliar, pop(pila));
    }
    push(pila, valor);
    while (!isEmpty(auxiliar)){
        push(pila, pop(auxiliar));
    }
}
