#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
    int legajo;
    float promedio;
}ST_ALUMNE;

typedef struct{
    int parcial;
    char fecha[11];
    int legajo;
    int nota;
}ST_MATERIA;

typedef struct ST_NODO{
    ST_MATERIA materia;
    ST_NODO* siguiente;
}ST_NODO;

void create(ST_NODO**);
void ordenarPorLegajo(ST_NODO**, FILE*);
void imprimirNotasPorMateria(ST_NODO *);//, FILE*);
ST_NODO* insertarOrdenado(ST_NODO**, ST_MATERIA);
void borrarLista(ST_NODO**);
void escribirArchivo(FILE*, ST_NODO**);
void imprimirArchivo(FILE*);

int main(){
    FILE* fisica = fopen("fisica.txt", "r");
    if(fisica == NULL){
        printf("fallo");
        return 0;
    }
    FILE* promedioFisica = fopen("promedioFisica.dat", "wb+");
    ST_NODO *listaFisica;
    create(&listaFisica);
    ordenarPorLegajo(&listaFisica, fisica);
    imprimirNotasPorMateria(listaFisica);
    escribirArchivo(promedioFisica, &listaFisica);
    imprimirArchivo(promedioFisica);
    borrarLista(&listaFisica);
    fclose(promedioFisica);
    fclose(fisica);
    return 0;
}
void create(ST_NODO** lista){
    *lista = NULL;
}
void ordenarPorLegajo(ST_NODO** lista, FILE* asignatura){
    ST_MATERIA materia;
    while(fscanf(asignatura, "%d\t%s\t%d\t%d\n" , &materia.parcial, materia.fecha, &materia.legajo, &materia.nota) != EOF){
        insertarOrdenado(lista, materia);
    }
}

void imprimirNotasPorMateria(ST_NODO *lista){
    while(lista != NULL){
        printf("legajo: %d, nota 1: %d, nota 2: %d\n", lista->materia.legajo, lista->materia.nota, lista->siguiente->materia.nota);
        lista = lista->siguiente->siguiente;
    }
}

ST_NODO* insertarOrdenado(ST_NODO** lista, ST_MATERIA asignatura){
    ST_NODO* nodo = (ST_NODO*)malloc(sizeof(ST_NODO));
    nodo->materia = asignatura;
    nodo->siguiente = NULL;
    ST_NODO* listaAux = *lista;
    ST_NODO* listaAnt = NULL;
    while(listaAux != NULL && asignatura.legajo >= listaAux->materia.legajo){
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
    ST_ALUMNE alumno;
    while(listaAux != NULL){
        alumno.legajo = listaAux->materia.legajo;
        alumno.promedio = (((float)listaAux->materia.nota) + ((float)listaAux->siguiente->materia.nota))/2;
        fwrite(&alumno, sizeof(ST_ALUMNE), 1, archivo);
        listaAux = listaAux->siguiente->siguiente;
    }
}

void imprimirArchivo(FILE* archivo){
    ST_ALUMNE alumno;
    printf("archivo\n");
    fseek(archivo, 0, SEEK_SET);
    fread(&alumno, sizeof(ST_ALUMNE), 1, archivo);
    while(!feof(archivo)){
        printf("%d, %f\n", alumno.legajo, alumno.promedio);
        fread(&alumno, sizeof(ST_ALUMNE), 1, archivo);
    }
}
