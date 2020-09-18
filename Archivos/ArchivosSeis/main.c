#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    int materia;
    char dia;
    char mes;
    char anio;
    char nombre[26];
}Alumno;

void discardChars();
FILE *abrir(const char *, const char *);

int main(){
    Alumno alumno;
    int dia = 0;
    int mes = 0;
    int anio = 0;
    FILE *archivo = abrir("DIAFINALES.DAT", "wb");//PARA CREAR EL ARCHIVO LA W, PARA LEERLO LA R Y COMENTAR EL PRIMER WHILE
    printf("Ingrese el nombre\n");
    gets(alumno.nombre);
    while(*(alumno.nombre) != '\0'){
        printf("Ingrese el numero de legajo\n");
        scanf("%d", &alumno.legajo);
        printf("Ingrese el codigo de materia\n");
        scanf("%d", &alumno.materia);
        printf("Ingrese el dia\n");
        scanf("%d", &dia);
        alumno.dia = dia;
        printf("Ingrese el mes\n");
        scanf("%d", &mes);
        alumno.mes = mes;
        printf("Ingrese el anio\n");
        scanf("%d", &anio);
        alumno.anio = anio;
        discardChars();
        fwrite(&alumno, sizeof(Alumno),1, archivo);
        printf("Ingrese el nombre\n");
        gets(alumno.nombre);
    }
    /*fread(&alumno, sizeof(Alumno), 1, archivo);
    while(!feof(archivo)){
        printf("Legajo: %d, Materia: %d, Fecha: %d/%d/%d, Nombre: %s\n", alumno.legajo, alumno.materia, alumno.dia, alumno.mes, alumno.anio, alumno.nombre);
        fread(&alumno, sizeof(Alumno), 1, archivo);
    }*/
    fclose(archivo);
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

void discardChars(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
}


