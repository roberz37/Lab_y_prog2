#include <stdio.h>
#include <stdlib.h>

/*typedef struct{
    char nombre[10];
    int edad;
}Persona;*/


int main()
{
    //printf("Hello world!\n");
    /*Persona personas[10];
    printf("Ingrese un nombre\n");
    scanf("%s", personas[0].nombre);
    printf("%s", personas[0].nombre);
    for(int i = 1; i<cant; i++){
        vec[i] = vec[i] * vec[i -1];
    }*/

    int * ptrVal = (int*) malloc(sizeof(int));
    *ptrVal = 10;
    free(ptrVal);
    return 0;
}
