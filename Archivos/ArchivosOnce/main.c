#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int legajo;
    char nombre[26];
}Alumno;

FILE *abrir(const char*, const char*);

int main(){
    Alumno alumno;
    FILE *archivoAlumnos = abrir("ALUMNOS.DAT", "rb");
    FILE *archivoAlumnosDos = abrir("AlumnosDOS.dat", "wb+");

    fread(&alumno, sizeof(Alumno), 1, archivoAlumnos);

    while(!feof(archivoAlumnos)){
        if(strcmp(alumno.nombre, "")!=0){
            fwrite(&alumno, sizeof(Alumno), 1, archivoAlumnosDos);
        }
        fread(&alumno, sizeof(Alumno), 1, archivoAlumnos);
    }

    fseek(archivoAlumnosDos, 0, SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, archivoAlumnosDos);
    while(!feof(archivoAlumnosDos)){
        printf("Legajo: %d, Nombre: %s\n", alumno.legajo, alumno.nombre);
        fread(&alumno, sizeof(Alumno), 1, archivoAlumnosDos);
    }



    fclose(archivoAlumnos);
    fclose(archivoAlumnosDos);
    remove("ALUMNOS.DAT");
    rename("AlumnosDOS.dat", "ALUMNOS.DAT");
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
