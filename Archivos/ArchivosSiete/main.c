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

int main(){
    FILE *archivoUno = fopen("DIAFINALES.DAT", "rb");
    FILE *archivoDos = fopen("MATFINALES.DAT", "wb");
    int codigo;
    Alumno alumno;
    if(archivoUno == NULL || archivoUno == NULL){
        printf("No se pudo abrir el archivo!");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese el codigo de materia\n");
    scanf("%d", &codigo);
    fread(&alumno, sizeof(alumno), 1, archivoUno);
    while(!feof(archivoUno)){
        if(alumno.materia == codigo){
            fwrite(&alumno, sizeof(alumno), 1, archivoDos);
        }
        fread(&alumno, sizeof(alumno), 1, archivoUno);
    }
    fclose(archivoUno);
    fclose(archivoDos);
    return 0;
}
