#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Idem ejercicio x pero retornando un parámetro con valor 'S' o 'N' según haya sido
exitoso o no el requerimiento. (Definir parámetros y codificar).*/
typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
}Nodo;

Nodo* create();
bool isEmpty(Nodo *);
void push(Nodo **, int);
int pop(Nodo **);
void isPossible(Nodo **, int );

int main(){
    int valor = 0;
    Nodo* pila = create();
    //push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    printf("Ingrese un valor\n");
    scanf("%d", &valor);
    isPossible(&pila, valor);
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

void isPossible(Nodo **pila, int valor){
    if((*pila)->siguiente->siguiente == NULL){
        printf("N\n");
    }else{
        int valorUno = pop(pila);
        int valorDos = pop(pila);
        push(pila, valor);
        push(pila, valorDos);
        push(pila, valorUno);
        printf("S\n");
    }
}
