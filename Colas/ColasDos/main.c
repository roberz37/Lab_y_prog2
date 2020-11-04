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
void concatenarColas(Cola*, Cola*);

/*Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere una única cola COLAB a partir de ellas. (Primero los
nodos de COLA y luego los de COLB).*/

int main(){
    Cola colA;
    Cola colB;
    create(&colA);
    create(&colB);
    add(&colA, 1);
    add(&colA, 2);
    add(&colA, 3);
    add(&colA, 4);
    add(&colB, 5);
    add(&colB, 6);
    add(&colB, 7);
    add(&colB, 8);
    concatenarColas(&colA, &colB);
    while(!isEmpty(&colB)){
        printf("%d\n", remover(&colB));
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

void concatenarColas(Cola* colA, Cola* colB){
    while(!isEmpty(colB)){
        add(colA, remover(colB));
    }
    while(!isEmpty(colA)){
        add(colB, remover(colA));
    }
}
