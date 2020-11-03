#include <stdio.h>
#include <stdlib.h>

/*Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila
modificada. En caso de no haber ningún valor igual a X retornar la pila sin cambio.
(Definir parámetros y codificar).*/



int main()
{

    return 0;
}

void cambiarValor (ST_NODO** pila, int valor, int nuevoValor){
    ST_NODO* auxiliar = create ();
    while (!isEmpty(*pila)){
        push(&auxiliar, pop(pila));
    }
    while (!isEmpty(auxiliar)){
        if (auxiliar->valor == valor){
            auxiliar->valor = nuevoValor;
        }
        push(pila, pop(&auxiliar));
    }
}
