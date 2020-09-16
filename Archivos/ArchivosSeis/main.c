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
    FILE *archivo = abrir("DIAFINALES.DAT", "wb");
    printf("Ingrese el nombre\n");
    gets(alumno.nombre);
    while(*(alumno.nombre) != '\0'){
        printf("Ingrese el numero de legajo\n");
        scanf("%d", &alumno.legajo);
        printf("Ingrese el codigo de materia\n");
        scanf("%d", &alumno.materia);
        printf("Ingrese el dia\n");
        scanf("%d", &alumno.dia);
        printf("Ingrese el mes\n");
        scanf("%d", &alumno.mes);
        printf("Ingrese el anio\n");
        scanf("%d", &alumno.anio);
        fflush(stdin);
        fwrite(&alumno, sizeof(Alumno),1, archivo);
        printf("Ingrese el nombre\n");
        gets(alumno.nombre);
    }
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
