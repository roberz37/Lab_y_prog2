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
void isPosible(Nodo**, int, int);
/*Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X
en la posición I de la pila si es posible. (Definir parámetros y codificar).*/

int main(){

    Nodo *pila = create();
    int valorX;
    int valorI;
    push(&pila, 5);
    push(&pila, 4);
    push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    printf("Ingrese un valor\n");
    scanf("%d", &valorX);
    printf("Ingrese la posicion\n");
    scanf("%d", &valorI);
    isPosible(&pila, valorX, valorI);
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

void isPosible(Nodo** pila, int valor, int posicion){
    Nodo* auxiliar = create();

    while (!isEmpty(*pila) && posicion > 1){
        push(&auxiliar, pop(pila));
        posicion--;
    }
    if (posicion == 1){
        push(pila, valor);
        printf("S\n");
    } else {
        printf("N\n");
    }
    while (!isEmpty(auxiliar)){
        push(pila, pop(&auxiliar));
    }
}
