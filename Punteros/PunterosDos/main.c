#include <stdio.h>
#include <stdlib.h>
/*Declarar una variable que sea puntero a un número entero y luego ...
a) Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c) Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.*/
int main()
{

    int* ptrInt = NULL;

    //A)
    printf("direccion de memoria del puntero: %p\n", &ptrInt);
    //B)
    printf("El valor del puntero: %p\n", ptrInt);
    //C)
    ptrInt = (int*)malloc(sizeof(int));
    *ptrInt = 50;
    //D)
    printf("el valor del puntero: %p\n", ptrInt);
    //E)
    printf("el valor al que apunta el puntero: %d", *ptrInt);
    free(ptrInt);
    return 0;
}
