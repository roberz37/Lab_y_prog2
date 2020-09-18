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

FILE *abrir(const char*, const char *);

int main(){

    Alumno alumno;
    FILE *novedades = abrir("../ArchivosSeis/DIAFINALES.DAT", "rb");
    FILE *anteriores = abrir("FINALES.DAT", "ab+");
    fseek(anteriores, sizeof(Alumno)*0, SEEK_END);
    long posInicial = ftell(anteriores);
    fread(&alumno, sizeof(Alumno), 1, novedades);

    while(!feof(novedades)){
        fwrite(&alumno, sizeof(Alumno), 1, anteriores);
        fread(&alumno, sizeof(Alumno), 1, novedades);
    }

    fseek(anteriores, posInicial, SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, anteriores);
    while(!feof(anteriores)){
        printf("Legajo: %d, Materia: %d, %d/%d/%d, Nombre: %s\n", alumno.legajo, alumno.materia, alumno.dia, alumno.mes, alumno.anio, alumno.nombre);
        fread(&alumno, sizeof(Alumno), 1, anteriores);
    }
    fclose(novedades);
    fclose(anteriores);
    return 0;
}

FILE *abrir(const char* fileName, const char * modo){
    FILE* archivo = fopen(fileName, modo);
    if(archivo == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return archivo;
}
