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
void eliminarDosNodos(Cola*);

int main(){
    Cola cola;
    create(&cola);
    add(&cola, 1);
    add(&cola, 2);
    add(&cola, 3);
    add(&cola, 4);
    add(&cola, 5);
    add(&cola, 6);
    add(&cola, 7);
    add(&cola, 8);
    eliminarDosNodos(&cola);
    while(!isEmpty(&cola)){
        printf("%d\n", remover(&cola));
    }
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

void eliminarDosNodos(Cola *cola){
    bool sePudo = false;
    if(cola->primero != NULL){
        if(cola->primero->siguiente != NULL){
            remover(cola);
            remover(cola);
            sePudo = true;
        }
    }
    if(sePudo){
        printf("S\n");
    } else {
        printf("N\n");
    }
}

