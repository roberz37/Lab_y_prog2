#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
    struct ST_NODO* siguiente;
}ST_NODO;

ST_NODO* create();
bool isEmpty(ST_NODO*);
void push(ST_NODO**, int);
int pop(ST_NODO**);
void clear(ST_NODO**);
void isPosible (ST_NODO**, int);

int main()
{
    ST_NODO* pila = create();
    push(&pila, 5);
    push(&pila, 4);
    push(&pila, 3);
    push(&pila, 2);
    push(&pila, 1);
    isPosible(&pila, 7);
    clear(&pila);

    return 0;
}
ST_NODO* create(){
    return NULL;
}
bool isEmpty(ST_NODO* pila){
    return pila == NULL;
}

void push(ST_NODO** pila, int valor){
    ST_NODO* auxiliar = (ST_NODO*) malloc (sizeof(ST_NODO));
    auxiliar->valor = valor;
    auxiliar->siguiente = *pila;
    *pila = auxiliar;
}
int pop(ST_NODO** pila){
    int valor = (*pila)->valor;
    ST_NODO *auxiliar = *pila;
    *pila = (*pila)->siguiente;
    free(auxiliar);
    return valor;
}
void clear(ST_NODO** pila){
    while(!isEmpty(*pila)){
        printf("%d\n", pop(pila));
    }
    *pila = NULL;
}

void isPosible (ST_NODO** pila, int valor){
    int cont = 0;
    ST_NODO* pilaAux = NULL;

    while (!isEmpty(*pila) && cont < 2){
        push(&pilaAux, pop(pila));
        cont++;
    }
    if (cont == 2){
        push(pila, valor);
        printf("S\n");
    } else {
        printf("N\n");
    }
    while (!isEmpty(pilaAux)){
        push(pila, pop(&pilaAux));
    }
}
