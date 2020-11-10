#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dato;
    struct Nodo* siguiente;
}Nodo;

typedef struct{
   char nombreApellido[36];
   int legajo;
   int division;
}Alumno;

void create(Nodo**);
Nodo* insertarPrimero(Nodo** , int);
Nodo* insertarAlFinal(Nodo**, int);
Nodo* insertarOrdenado(Nodo**, int);
Nodo* search(Nodo*, int);
int borrarPrimero(Nodo**);
int borrar(Nodo**, int);
void borrarLista(Nodo**);
void ordenarLista(Nodo**);
Nodo* insertarSinDuplicados(Nodo**, int);
void imprimirLista(Nodo*);
Nodo* insertarEn(Nodo**, int, int);
Nodo* leerEn(Nodo**, int);

int main(){

    return 0;
}

void create(Nodo** lista){
    *lista = NULL;
}

Nodo* insertarPrimero(Nodo** lista, int dato){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = *lista;
    *lista = nodo;
    return nodo;
}

Nodo* insertarAlFinal(Nodo** lista, int dato){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    Nodo* listaAux = *lista;
    while(listaAux != NULL && listaAux->siguiente != NULL){
        listaAux= listaAux->siguiente;
    }
    if(listaAux == NULL){
        *lista = nodo;
    } else {
        listaAux->siguiente = nodo;
    }
    return nodo;
}

Nodo* insertarOrdenado(Nodo** lista, int dato){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    Nodo* listaAux = *lista;
    Nodo* listaAnt = NULL;
    while(listaAux != NULL && dato < listaAux->dato){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
    if(listaAnt == NULL){
        *lista = nodo;
    }else{
        listaAnt->siguiente = nodo;
    }
    nodo->siguiente = listaAux;
    return nodo;
}

Nodo* search(Nodo* lista, int buscado){
    Nodo* listaAux = lista;
    while(listaAux != NULL && listaAux->dato != buscado){
        listaAux = listaAux->siguiente;
    }
    return listaAux;
}

int borrarPrimero(Nodo** lista){
    Nodo* listaAux = *lista;
    *lista = (*lista)->siguiente;
    int dato = listaAux->dato;
    free(listaAux);
    return dato;
}

int borrar(Nodo** lista, int dato){
    Nodo* listaAux = *lista;
    Nodo* listaAnt = NULL;
    while(listaAux != NULL && listaAux->dato != dato){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
    if(listaAnt == NULL){
        *lista = (*lista)->siguiente;
    }else {
        listaAnt->siguiente = listaAux->siguiente;
    }
    int valor = listaAux->dato;
    free(listaAux);
    return valor;
}

void borrarLista(Nodo** lista){
    Nodo* listaAux = NULL;
    while(listaAux != NULL){
        listaAux = *lista;
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}

void ordenarLista(Nodo** lista){
    Nodo* listaAux = NULL;
    int dato = 0;
    while(*lista != NULL){
        dato = borrarPrimero(lista);
        insertarOrdenado(&listaAux, dato);
    }
    *lista = listaAux;
}

Nodo* insertarSinDuplicados(Nodo** lista, int dato){
    Nodo* nodo = search(*lista, dato);
    if(nodo == NULL){
        nodo = insertarOrdenado(lista, dato);
    }
    return nodo;
}

void imprimirLista(Nodo* lista){
    while(lista != NULL){
        printf("Dato: %d\n", lista->dato);
        lista = lista->siguiente;
    }
}

Nodo* insertarEn(Nodo** lista, int dato, int posicion){
    Nodo* listaAux = *lista;
    Nodo* listaAnt = NULL;
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    for(int i = 0; i < posicion && *lista != NULL; i++){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
    if(listaAnt == NULL){
        *lista = nodo;
    } else {
        listaAnt->siguiente = nodo;
    }
    nodo->siguiente = listaAux;
    return nodo;
}

Nodo* leerEn(Nodo** lista, int posicion){
    Nodo* listaAux = *lista;
    Nodo* nodo = NULL;
    int i = 0;
    for(int i = 0; i < posicion && listaAux != NULL; i++){
        nodo = listaAux;
        listaAux = listaAux->siguiente;
    }
    if(i < posicion && listaAux == NULL){
        return NULL;
    }
    return nodo;
}
