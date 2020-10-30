#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    char nombre[26];
    char apellido[26];
}Alumno;

typedef struct Nodo{
    Alumno alumno;
    struct Nodo* siguiente;
}Nodo;

Nodo* create();
bool isEmpty(Nodo *);
void push(Nodo **, Alumno);
Alumno pop(Nodo **);
void clear(Nodo **);

/*Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y
Nombre de alumnos y los imprima en orden inverso al de ingreso. (Definir
parámetros y codificar).*/

int main(){
    Alumno alumno;
    int cantidad;
    Nodo *pila = create();
    printf("Ingrese cantidad de alumnos\n");
    scanf("%d", &cantidad);
    for(int i = 0; i < cantidad; i++){
        printf("Ingrese nombre\n");
        scanf("%s", alumno.nombre);
        printf("Ingrese apellido\n");
        scanf("%s", alumno.apellido);
        push(&pila, alumno);
    }
    while(!isEmpty(pila)){
        alumno = pop(&pila);
        printf("nombre: %s, apellido: %s\n", alumno.nombre, alumno.apellido);
    }
    return 0;
}

Nodo* create(){
    return NULL;
}

bool isEmpty(Nodo *pila){
    return pila == NULL;
}

void push(Nodo **pila, Alumno alumno){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->alumno = alumno;
    nodo->siguiente = *pila;
    *pila = nodo;
}

Alumno pop(Nodo **pila){
    Alumno alumno = (*pila)->alumno;
    Nodo *aux = *pila;
    *pila = (*pila)->siguiente;
    free(aux);
    return alumno;
}

void clear(Nodo **pila){
    while(!isEmpty(*pila)){
        pop(pila);
    }
    *pila = NULL;
}
