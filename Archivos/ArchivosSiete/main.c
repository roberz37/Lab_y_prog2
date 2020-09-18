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

FILE *abrir(const char *, const char *);

int main(){
    Alumno alumno;
    int codigo;
    FILE *archivoUno = abrir("../ArchivosSeis/DIAFINALES.DAT", "rb");
    FILE *archivoDos = abrir("MATFINALES.DAT", "wb");
    printf("Ingrese el codigo de materia\n");
    scanf("%d", &codigo);
    fread(&alumno, sizeof(Alumno), 1, archivoUno);
    while(!feof(archivoUno)){
        if(alumno.materia == codigo){
            fwrite(&alumno, sizeof(Alumno), 1, archivoDos);
        }
        fread(&alumno, sizeof(Alumno), 1, archivoUno);
    }
    fclose(archivoUno);
    fclose(archivoDos);
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

