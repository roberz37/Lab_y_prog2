#ifndef EJERCICIO1_H_INCLUDED
#define EJERCICIO1_H_INCLUDED

typedef struct{
    int legajo;
    float promedio;
}ST_ALUMNE_ABRV;

typedef struct{
    int legajo;
    char carrera;
    char nombre[31];
    char apellido[31];
    char email[31];
    char telefono[11];
}ST_ALUMNE;

typedef struct{
    char nomenclatura;
    char carrera[21];
    char descripcion[31];
}ST_CARRERA;

typedef struct{
    int parcial;
    char fecha[8];
    int legajo;
    int nota;
}ST_MATERIA;

typedef struct ST_NODO{
    ST_MATERIA materia;
    ST_NODO* siguiente;
}ST_NODO;

FILE *abrirArchivo(const char*, const char*);
void crearLista(ST_NODO**);
void ordenarPorLegajo(ST_NODO**, FILE*);
ST_NODO* insertarOrdenado(ST_NODO**, ST_MATERIA);
void imprimirNotasPorMateria(ST_NODO *);
void borrarLista(ST_NODO**);
void escribirArchivo(FILE*, ST_NODO**);
void imprimirPromedios(FILE*);

#endif // EJERCICIO1_H_INCLUDED
