#include <stdio.h>
#include <stdlib.h>

/*Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor
de sus nodos y la retorne. Solo se deben usar pilas. (Definir parámetros y codificar).*/
void ordenarPila(Nodo**);
int main(){

    return 0;
}

Nodo* ordenarPila(Nodo** pila){
    int max = 0;
    Nodo *pilaAuxUno = create();
    Nodo *pilaAuxDos = create();
    while(!isEmpty(*pila)){
        int valor = pop(pila);
        if(max >= valor){
            max = valor;
        }
        push(&pilaAuxUno, valor));
    }
    while(!isEmpty(pilaAuxUno)){
        if(pilaAuxUno->dato == max){
            push(&pilaAuxDos, max));
        }else{
            push(pila, pop(pilaAuxUno));
        }
    }
}

