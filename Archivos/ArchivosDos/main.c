#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivoUno = fopen("ArchivosUno.txt", "r");
    if(archivoUno == NULL){
        printf("No se pudo abrir el archivo!\n");
        exit(EXIT_FAILURE);
    }
    FILE *archivoDos = fopen("ArchivoDos.txt", "w");
    if(archivoDos == NULL){
        printf("No se pudo abrir el archivo!\n");
        exit(EXIT_FAILURE);
    }
    int legajo=0;
    float promedio=0;

    while(fscanf(archivoUno, "%d%f\n", &legajo, &promedio) != EOF){
        if(promedio >= 6){
            fprintf(archivoDos, "%08d %.2f\n", legajo, promedio);
        }
    }
    fclose(archivoUno);
    fclose(archivoDos);
    return 0;
}
