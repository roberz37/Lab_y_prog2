#include <stdio.h>
#include <stdlib.h>
/*Declarar una variable entera, un vector de caracteres de diez posiciones y una variable con
soporte de decimales y ...
a) Asignarle valores.
b) Imprimir el valor de cada una.
c) Imprimir la dirección de memoria de cada una.*/
int main()
{
    int variable;
    char vector[10];
    float flotante;
    //a)
    variable = 10;
    vector[0] = 'h';
    vector[1] = 'o';
    vector[2] = 'l';
    vector[3] = 'a';
    vector[4] = ' ';
    vector[5] = 'm';
    vector[6] = 'u';
    vector[7] = 'n';
    vector[8] = 'd';
    vector[9] = 'o';
    flotante = 10.10;
    //b)
    printf("%d\n", variable);
    for(int i = 0; i<10; i++){
        printf("%c\n", vector[i]);
    }
    printf("%f\n", flotante);
    //c)
    printf("punteros\n");
    printf("%p\n", &variable);
    for(int i = 0; i<10; i++){
        printf("%p\n", vector[i]);
    }
    printf("vector: %p\n", vector);
    printf("%p\n", &flotante);
    return 0;
}
