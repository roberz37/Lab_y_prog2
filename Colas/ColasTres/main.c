#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo{
    int dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
}Cola;

void add(Cola*, int);
int remover(Cola*);
bool isEmpty(Cola*);
void create(Cola*);
bool isEmptyPila(Nodo *);
int pop(Nodo **);
void push(Nodo **, int);
void imprimirCola(Cola *);

int main(){

    Cola cola;
    create(&cola);
    for(int i = 1; i < 100; i++){
        add(&cola, i);
    }
    imprimirCola(&cola);
    return 0;
}

void add(Cola *cola, int dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    if(cola->primero == NULL){
        cola->primero = nodo;
    } else {
        cola->ultimo->siguiente = nodo;
    }
    cola->ultimo = nodo;
}

int remover(Cola *cola){
    Nodo *nodo = cola->primero;
    int valor = nodo->dato;
    cola->primero = nodo->siguiente;
    if(cola->primero == NULL){
        cola->ultimo = NULL;
    }
    free(nodo);
    return valor;
}

bool isEmpty(Cola *cola){
    return cola->primero == NULL && cola->ultimo == NULL;
}

void create(Cola *cola){
    cola->primero = NULL;
    cola->ultimo = NULL;
}

void imprimirCola(Cola *cola){
    Cola colaAux;
    int cont = 0;
    create(&colaAux);
    Nodo *pila = NULL;
    while(!isEmpty(cola)){
        add(&colaAux, remover(cola));
        cont++;
    }
    if(cont >= 100){
        while(!isEmpty(&colaAux)){
            printf("%d\n", remover(&colaAux));
        }
    }else{
        while(!isEmpty(&colaAux)){
            push(&pila, remover(&colaAux));
        }
        while(!isEmptyPila(pila)){
            printf("%d\n", pop(&pila));
        }
    }
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

bool isEmptyPila(Nodo *pila){
    return pila == NULL;
}
