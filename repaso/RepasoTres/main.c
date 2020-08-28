#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nombre[10];
    int edad;
}Persona;

//void inicializarVector(Persona, int);
int main()
{
    Persona personas[10];
    int contador = 0;

    printf("Ingrese un nombre\n");
    scanf("%s", personas[contador].nombre);


    while(strcmp(personas[contador].nombre, "Carlos") != 0){

        printf("Ingresa edad\n");
        scanf("%d", &personas[contador].edad);
        contador++;
        printf("Ingrese un nombre\n");
        scanf("%s", personas[contador].nombre);
        fflush(stdin);
    }
    for(int i = 0; i < contador; i++){
        printf("posicion: %d nombre: %s, edad: %d\n", i, personas[i].nombre, personas[i].edad);
    }

    for (int i=1; i<contador; i++){
       Persona aux;
       for (int j=0 ; j<contador - 1; j++){
               if (personas[j].edad > personas[j+1].edad){
                   aux = personas[j];
                   personas[j] = personas[j+1];
                   personas[j+1] = aux;
               }
       }
    }
    for(int i = 0; i < contador; i++){
        printf("\nposicion: %d nombre: %s, edad: %d\n", i, personas[i].nombre, personas[i].edad);
    }



    return 0;
}
