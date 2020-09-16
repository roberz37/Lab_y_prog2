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

FILE *abrir(const char*, const char*);

int main(){

    Alumno alumno;
    FILE *archivoTxt = abrir("LISTADO.TXT","w");
    FILE *archivoBin = abrir("../ArchivosSeis/DIAFINALES.DAT", "rb");
    fprintf(archivoTxt, "Legajo\tNombre\tFecha\tCodigo de materia\n");
    fread(&alumno, sizeof(Alumno), 1, archivoBin);
    while(!feof(archivoBin)){
        fprintf(archivoTxt, "%d\t%s\t%02d/%02d/%02d\t%d\n", alumno.legajo, alumno.nombre, alumno.dia, alumno.mes, ((alumno.anio) % 100), alumno.materia);
        fread(&alumno, sizeof(Alumno), 1, archivoBin);
    }
    fclose(archivoTxt);
    fclose(archivoBin);
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
