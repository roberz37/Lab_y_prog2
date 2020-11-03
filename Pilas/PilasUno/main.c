#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros
nodos de la pila y deje el valor I como primero. (Definir parámetros y codificar).*/
typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
}Nodo;

Nodo* create();
bool isEmpty(Nodo *);
void push(Nodo **, int);
int pop(Nodo **);
void clear(Nodo **);
void ponerValor(Nodo **, int);

int main(){
    int valor;
    Nodo *pila = create();
    push(&pila, 5);
    push(&pila, 4);
    push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    printf("Ingrese un valor\n");
    scanf("%d", &valor);
    ponerValor(&pila, valor);
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

void clear(Nodo **pila){
    while(!isEmpty(*pila)){
        pop(pila);
    }
    *pila = NULL;
}

void ponerValor(Nodo **pila, int valor){
    pop(pila);
    pop(pila);
    push(pila, valor);
    return;
}
