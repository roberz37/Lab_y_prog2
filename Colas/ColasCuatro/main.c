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
Cola apareo(Cola*, Cola*);

int main(){
    Cola colA;
    Cola colB;
    Cola colaB;
    create(&colA);
    create(&colB);
    create(&colaB);
    add(&colA, 1);
    add(&colA, 5);
    add(&colA, 7);
    add(&colA, 9);
    add(&colB, 2);
    add(&colB, 4);
    add(&colB, 6);
    add(&colB, 8);
    colaB = apareo(&colA, &colB);
    while(!isEmpty(&colaB)){
        printf("%d\n", remover(&colaB));
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
/*Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere otra cola COLAB por apareo del campo ARRIBO del registro
(define orden creciente en ambas). Nota: COLA y COLB dejan de ser útiles
después del apareo*/

Cola apareo(Cola* colA, Cola* colB){
    Cola colaB;
    create(&colaB);
    while(!isEmpty(colA) && !isEmpty(colB)){
        if(colA->primero->dato <= colB->primero->dato){
            add(&colaB, remover(colA));
        }else {
            add(&colaB, remover(colB));
        }
    }
    while(!isEmpty(colA)){
        add(&colaB, remover(colA));
    }
    while(!isEmpty(colB)){
        add(&colaB, remover(colB));
    }
    return colaB;
}
