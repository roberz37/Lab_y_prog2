#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros
nodos de la pila y deje el valor I como primero. (Definir parámetros y codificar).*/

typedef struct Nodo{
    int dato;
    struct ST_NODO *siguiente;
}ST_NODO;

ST_NODO *create ();
bool isEmpty(ST_NODO*);
void push(ST_NODO**, int);
int pop(ST_NODO**);
void clear(ST_NODO**);
void ingresarValor(ST_NODO**, int);

int main()
{
    ST_NODO** pila = create();
    push(&pila, 5);
    push(&pila, 4);
    push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    ingresarValor(&pila, 7);
    clear(&pila);

    return 0;
}

ST_NODO *create (){
    return NULL;
}

bool isEmpty(ST_NODO* nodex){
    return nodex == NULL;
}
void push(ST_NODO** nodex, int valor){
    ST_NODO *nodexAux = (ST_NODO*) malloc (sizeof(ST_NODO));
    nodexAux->dato = valor;
    nodexAux->siguiente = *nodex;
    *nodex = nodexAux;
}
int pop(ST_NODO** nodex){
    int valor = (*nodex)->dato;
    ST_NODO *aux = *nodex;
    *nodex = (*nodex)->siguiente;
    free(aux);
    return valor;
}
void clear(ST_NODO** nodez){
    while(!isEmpty(*nodez)){
        printf("%d\n", pop(nodez));
    }
    *nodez = NULL;
}
void ingresarValor(ST_NODO** pila, int valor){
    pop(pila);
    pop(pila);
    push(pila, valor);
}


