#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    int notaUno;
    int notaDos;
}Alumno;

/*Se conoce de cada alumno de un curso los siguientes datos: legajo (8dígitos) y las notas de 2
parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe un
archivo de texto CURSO.TXT con una línea por cada alumno, con el número de legajo y su promedio
(real).

De Entrada De Salida
D CURSO.TXT :Archivo de texto con una línea por cada
A Legajo alumno con los siguientes datos
T Nota1 por cada alumno Legajo
O Nota2 del curso Promedio un alumno por línea
S*/
int main(){

    Alumno alumno;
    float promedio= 0;
    FILE *archivo = fopen("CURSO.TXT","w");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo!");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese el legajo: \n");
    scanf("%d", &alumno.legajo);

    while(alumno.legajo > 0){
        printf("Ingrese una nota: \n");
        scanf("%d", &alumno.notaUno);
        promedio = alumno.notaUno;
        printf("Ingrese una nota: \n");
        scanf("%d", &alumno.notaDos);
        promedio += alumno.notaDos;
        promedio = promedio/2;
        fprintf(archivo,"%08d %.2f\n", alumno.legajo, promedio);
        printf("Ingrese el legajo: \n");
        scanf("%d", &alumno.legajo);
    }
    fclose(archivo);
    return 0;
}
