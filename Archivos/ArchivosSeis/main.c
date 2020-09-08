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
    Alumno alumno;
    FILE *archivo = fopen("DIAFINALES.DAT", "wb");
    if(archivo == NULL){
        printf("No se pudo abrir el archivo!");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese el nombre\n");
    gets(alumno.nombre);
    fflush(stdin);
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
