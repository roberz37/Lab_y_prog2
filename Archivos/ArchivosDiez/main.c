#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Dado el archivo binario generado en el ejercicio 7, desarrolle un programa que genere un archivo
ordenado por número de legajo (cada registro debe tener los campos legajo y apellido y nombre) para
todos los alumnos que se inscribieron una o más veces. Cada legajo debe ocupar una posición única y
predecible en el archivo. El intervalo de los legajos es 80001 a 110000. Pueden no presentarse todos los
legajos*/

typedef struct{
    int legajo;
    char nombre[26];
}Nuevo;

typedef struct{
    int legajo;
    int materia;
    char dia;
    char mes;
    char anio;
    char nombre[26];
}Viejo;

FILE *abrir(const char*, const char*);

int main(){

    Nuevo nuevo;
    Viejo viejo;
    FILE *archivoFinales = abrir("../ArchivosSeis/DIAFINALES.DAT", "rb");
    FILE *archivoAlumnos = abrir("ALUMNOS.DAT", "wb+");
    fread(&viejo, sizeof(Viejo), 1, archivoFinales);
    while(!feof(archivoFinales)){

        fseek(archivoAlumnos, sizeof(Nuevo)*viejo.legajo, SEEK_SET);
        nuevo.legajo = viejo.legajo;
        strcpy(nuevo.nombre, viejo.nombre);
        fwrite(&nuevo, sizeof(Nuevo), 1, archivoAlumnos);
        fread(&viejo, sizeof(Viejo), 1, archivoFinales);
    }
    fseek(archivoAlumnos, 0, SEEK_SET);
    fread(&nuevo, sizeof(Nuevo), 1, archivoAlumnos);
    while(!feof(archivoAlumnos)){
        printf("Legajo: %d, Nombre: %s\n", nuevo.legajo, nuevo.nombre);
        fread(&nuevo, sizeof(Nuevo), 1, archivoAlumnos);
    }
    fclose(archivoFinales);
    fclose(archivoAlumnos);
    return 0;
}

FILE *abrir(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}
