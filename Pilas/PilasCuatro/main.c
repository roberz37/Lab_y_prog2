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
void ingresarValor(Nodo**, int, int);
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
    ingresarValor(&pila, valorX, valorI);
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

void ingresarValor(Nodo **pila, int valorX, int valorI){
    Nodo *pilaAux = create();
    int i = 1;
    while(!isEmpty(*pila)&& i <= valorI){
        if(i == valorI){
            push(pila, valorX);
        }else{
            push(&pilaAux, pop(pila));
        }
        i++;
    }
    if((i - 1) != valorI){
        printf("No se puede ingresar el valor\n");
    }
    while(!isEmpty(pilaAux)){
        push(pila, pop(&pilaAux));
    }
}
