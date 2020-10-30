#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
}Nodo;

Nodo* create();
bool isEmpty(Nodo *);
void push(Nodo **, int);
int pop(Nodo **);
void ingresarValor(Nodo **, int);

/*Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila
modificada. En caso de no haber ningún valor igual a X retornar la pila sin cambio.
(Definir parámetros y codificar).*/
int main(){

    Nodo *pila = create();
    int valor;
    push(&pila, 5);
    push(&pila, 4);
    push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    printf("Ingrese el valor\n");
    scanf("%d", &valor);
    ingresarValor(&pila, valor);
    while(!isEmpty(pila)){
        printf("%d\n", pop(&pila));
    }
    return 0;
}

Nodo* create(){
    return NULL;
}

bool isEmpty(Nodo *pila){
    return pila == NULL;
}

void push(Nodo **pila, int dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = *pila;
    *pila = nodo;
}

int pop(Nodo **pila){
    int valor = (*pila)->dato;
    Nodo *aux = *pila;
    *pila = (*pila)->siguiente;
    free(aux);
    return valor;
}

void ingresarValor(Nodo **pila, int valor){
    Nodo *pilaAux = create();
    while(!isEmpty(*pila)){
        push(&pilaAux, pop(pila));
    }
    push(pila, valor);
    while(!isEmpty(pilaAux)){
        push(pila, pop(&pilaAux));
    }
}
