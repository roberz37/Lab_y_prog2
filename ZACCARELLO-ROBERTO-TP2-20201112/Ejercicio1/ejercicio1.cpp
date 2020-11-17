#include <iostream>
#include <string.h>
#include "ejercicio1.h"

using namespace std;

FILE *abrirArchivo(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}

void crearLista(ST_NODO** lista){
    *lista = NULL;
}

void ordenarPorLegajo(ST_NODO** lista, FILE* asignatura){
    ST_MATERIA materia;

    while(fscanf(asignatura, "%d\t%s\t%d\t%d\n" , &materia.parcial, materia.fecha, &materia.legajo, &materia.nota) != EOF){
        insertarOrdenado(lista, materia);
    }
}
ST_NODO* insertarOrdenado(ST_NODO** lista, ST_MATERIA asignatura){
    ST_NODO* nodo = (ST_NODO*)malloc(sizeof(ST_NODO));
    nodo->materia = asignatura;
    nodo->siguiente = NULL;

    ST_NODO* listaAux = *lista;
    ST_NODO* listaAnt = NULL;

    while(listaAux != NULL && asignatura.legajo > listaAux->materia.legajo){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
    if (listaAux != NULL && asignatura.legajo == listaAux->materia.legajo && asignatura.parcial > listaAux->materia.parcial){
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

void imprimirNotasPorMateria(ST_NODO *lista){
    while(lista != NULL){
        printf("legajo: %d, Nota Primer parcial: %d, Nota Segundo Parcial: %d\n", lista->materia.legajo, lista->materia.nota, lista->siguiente->materia.nota);
        lista = lista->siguiente->siguiente;
    }
}
void borrarLista(ST_NODO** lista){
    ST_NODO* listaAux = NULL;
    while(listaAux != NULL){
        listaAux = *lista;
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}
void escribirArchivo(FILE* archivo, ST_NODO** lista){
    ST_NODO *listaAux = *lista;
    ST_ALUMNE_ABRV alumno;
    while(listaAux != NULL){
        alumno.legajo = listaAux->materia.legajo;
        alumno.promedio = (((float)listaAux->materia.nota) + ((float)listaAux->siguiente->materia.nota))/2;
        fwrite(&alumno, sizeof(ST_ALUMNE_ABRV), 1, archivo);
        listaAux = listaAux->siguiente->siguiente;
    }
}
void imprimirPromedios(FILE* archivo){
    ST_ALUMNE_ABRV alumno;
    printf("\n\nPromedios Materia X:\n");
    fseek(archivo, 0, SEEK_SET);
    fread(&alumno, sizeof(ST_ALUMNE_ABRV), 1, archivo);
    while(!feof(archivo)){
        printf("Legajo: %d, Promedio: %0.2f\n", alumno.legajo, alumno.promedio);
        fread(&alumno, sizeof(ST_ALUMNE_ABRV), 1, archivo);
    }
}
