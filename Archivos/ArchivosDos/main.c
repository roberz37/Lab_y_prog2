#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int legajo;
    float promedio;
}Alumno;

int main()
{
    Alumno alumno;
    FILE *archivoUno = fopen("../ArchivosUno/CURSO.TXT", "r");
    if(archivoUno == NULL){
        printf("No se pudo abrir el archivo!\n");
        exit(EXIT_FAILURE);
    }
    FILE *archivoDos = fopen("APROB.TXT", "w");
    if(archivoDos == NULL){
        printf("No se pudo abrir el archivo!\n");
        exit(EXIT_FAILURE);
    }
    while(fscanf(archivoUno, "%d%f\n", &alumno.legajo, &alumno.promedio) != EOF){
        if(alumno.promedio >= 6){
            fprintf(archivoDos, "%08d %.2f\n", alumno.legajo, alumno.promedio);
        }
    }
    fclose(archivoUno);
    fclose(archivoDos);
    return 0;
}
