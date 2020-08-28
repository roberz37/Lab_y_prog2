#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *miPuntero = (char*)malloc(10*sizeof(char));
    strcpy(miPuntero, "hola");
    //A)
    printf("puntero formateado a string: %s\n", miPuntero);
    //B)
    printf("direccion de memoria del puntero: %p\n", &miPuntero);
    //C)
    printf("valor del puntero: %p\n", miPuntero);
    //D)
    printf("valor de miPuntero[0]: %c\n", *miPuntero);
    //E)
    miPuntero++;
    printf("Direccion de memoria de miPuntero++: %p\n", miPuntero);
    printf("valor de miPuntero[0]: %c\n", *miPuntero);
    free(miPuntero);
    return 0;
}
