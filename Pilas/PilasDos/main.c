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

void ponerValor(Nodo **pila, int valor){
    int valorUno = pop(pila);
    int valorDos = pop(pila);
    push(pila, valor);
    push(pila, valorDos);
    push(pila, valorUno);
}
