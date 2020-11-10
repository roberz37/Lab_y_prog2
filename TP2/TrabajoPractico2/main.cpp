#include <iostream>

using namespace std;

typedef struct{
    int legajo;
    float promedio;
}Alumno;

typedef struct{
    int parcial;
    char fecha[11];
    int legajo;
    int nota;
}Materia;

typedef struct Nodo{
    Materia materia;
    Nodo* siguiente;
}Nodo;

void create(Nodo**);
void ordenarPorLegajo(Nodo**, FILE*);
void imprimirNotasPorMateria(Nodo *);
Nodo* insertarOrdenado(Nodo**, Materia);
void borrarLista(Nodo**);
void escribirArchivo(FILE*, Nodo**);
void imprimirArchivo(FILE*);
FILE *abrir(const char *, const char *);

int main(){
    FILE* fisica = abrir("fisica.txt", "r");
    FILE* promedioFisica = abrir("promedioFisica.dat", "wb+");
    Nodo *listaFisica;
    create(&listaFisica);
    ordenarPorLegajo(&listaFisica, fisica);
    printf("Imprimo notas por materia\n");
    imprimirNotasPorMateria(listaFisica);
    escribirArchivo(promedioFisica, &listaFisica);
    printf("\nImprimo archivo de promedios\n");
    imprimirArchivo(promedioFisica);
    borrarLista(&listaFisica);
    fclose(promedioFisica);
    fclose(fisica);
    return 0;
}
void create(Nodo** lista){
    *lista = NULL;
}
void ordenarPorLegajo(Nodo** lista, FILE* asignatura){
    Materia materia;
    while(fscanf(asignatura, "%d\t%s\t%d\t%d\n" , &materia.parcial, materia.fecha, &materia.legajo, &materia.nota) != EOF){
        insertarOrdenado(lista, materia);
    }
}

void imprimirNotasPorMateria(Nodo *lista){
    while(lista != NULL){
        printf("legajo: %d, nota del primer parcial: %d, nota del segundo parcial: %d\n", lista->materia.legajo, lista->materia.nota, lista->siguiente->materia.nota);
        lista = lista->siguiente->siguiente;
    }
}

Nodo* insertarOrdenado(Nodo** lista, Materia materia){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->materia = materia;
    nodo->siguiente = NULL;
    Nodo* listaAux = *lista;
    Nodo* listaAnt = NULL;
    while(listaAux != NULL && materia.legajo > listaAux->materia.legajo){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;

    }
    if(listaAux != NULL && materia.legajo == listaAux->materia.legajo && materia.parcial > listaAux->materia.parcial){
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

void borrarLista(Nodo** lista){
    Nodo* listaAux = NULL;
    while(listaAux != NULL){
        listaAux = *lista;
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}

void escribirArchivo(FILE* archivo, Nodo** lista){
    Nodo *listaAux = *lista;
    Alumno alumno;
    while(listaAux != NULL){
        alumno.legajo = listaAux->materia.legajo;
        alumno.promedio = (((float)listaAux->materia.nota) + ((float)listaAux->siguiente->materia.nota))/2;
        fwrite(&alumno, sizeof(Alumno), 1, archivo);
        listaAux = listaAux->siguiente->siguiente;
    }
}

void imprimirArchivo(FILE* archivo){
    Alumno alumno;
    fseek(archivo, 0, SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, archivo);
    while(!feof(archivo)){
        printf("Legajo:%d, Promedio:%f\n", alumno.legajo, alumno.promedio);
        fread(&alumno, sizeof(Alumno), 1, archivo);
    }
}

FILE *abrir(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}
