#include <stdio.h>
#include <stdlib.h>
#include "paraclase1.h"
#include <string.h>

/*1) Desarrollar un algoritmo que defina un vector de 10 posiciones y...
a) Asigne a cada una de las posiciones el valor que resulta de: valor posición_actual x
posición_anterior.
b) Imprimir en pantalla la posición y su valor.
c) Invertir el orden del vector e imprimir por pantalla la posición y su valor.

2) Implementar un sistema que solicite indefinidamente números por pantalla hasta que se
ingrese un valor de corte e...
a) Imprimir el número más alto.
b) Imprimir el número más bajo.
c) Imprimir el promedio.

  3) Crear un algoritmo que solicite por pantalla, hasta que ingrese un valor de corte, nombre
y edad, considerando que...
a) Modelar lo que ingresa el usuario en structs y almacenarlos en un vector
(considerar 10 posiciones).
b) Imprimir por pantalla los datos del vector.
c) Ordenar el vector en base a la edad, de mayor a menor.
d) Imprimir por pantalla los datos del vector ordenado.

*/

void multiplicar (int[], int);
void imprimir(int[], int);
void invertir(int[], int);
int solicitarNumero();
int compararMax(int, int);
int compararMin(int, int);
float calcularPromedio(int, int);
void ingresarPersonas(ST_PERSONAS[], int, char[]);
void ordenarPersonas(ST_PERSONAS[], int);
void imprimirPersonas(ST_PERSONAS[], int);


int main()
{
    /*int vec[10] = {1,2,3,4,5,6,7,8,9,10};

    multiplicar(vec, 10);
    imprimir(vec, 10);
    invertir(vec, 10);
    printf("\n........................\n\n");
    imprimir(vec, 10);
    ----------------------------------------------------------------


    int entrada= solicitarNumero();
    int max=entrada;
    int min=entrada;
    int sumatoria=0;
    int contador=0;
    float promedio;
    while (entrada !=0 ){
        max= compararMax(entrada, max);
        min= compararMin(entrada, min);
        sumatoria+=entrada;
        contador++;
        entrada=solicitarNumero();
    }
    promedio = calcularPromedio(sumatoria, contador);
    printf("El max es: %d, el min es: %d, y el promedio es: %f", max, min, promedio);

    ----------------------------------------------------------------------



    */

    ST_PERSONAS personas[10];

    int contador = 0;
    ingresarPersonas(personas, contador, "carlos");
    while (strcmp(personas[contador].nombre, "carlos") != 0 && contador < 10){
        contador++;
        ingresarPersonas(personas, contador, "carlos");
    }
    imprimirPersonas(personas, contador);
    ordenarPersonas(personas, contador);
    printf("Ordenado\n");
    imprimirPersonas(personas, contador);



    return 0;
}

void imprimirPersonas(ST_PERSONAS personas[], int maximo){
    for (int i=0; i < maximo;i++){
        printf("Nombre: %s, Edad: %d\n", personas[i].nombre, personas[i].edad);
    }
}
void ordenarPersonas(ST_PERSONAS personas[], int contador){
    for (int i=0; i< contador-1; i++){
        ST_PERSONAS aux;
        for (int j= 0; j < contador-1-i;j++){
            strcpy(aux.nombre, personas[j].nombre);
            aux.edad = personas[j].edad;
            strcpy(personas[j].nombre, personas[j+1].nombre);
            personas[j].edad = personas[j+1].edad;
            strcpy(personas[j+1].nombre, aux.nombre);
            personas[j+1].edad = aux.edad;
        }
    }


}


void ingresarPersonas(ST_PERSONAS vec[], int indice, char corte[]){
    printf("Ingrese el nombre de la persona\n");
    scanf("%s", vec[indice].nombre);
    if (strcmp(corte, vec[indice].nombre )!= 0){
        printf("Ingrese la edad de la persona\n");
        scanf("%d", &vec[indice].edad);
    }
}

void multiplicar (int vec[], int max){
    for (int i= max-1;i > 0; i--){
        vec[i]= vec[i]*vec[i-1];
    }
}

void imprimir(int vec[], int max){
    for (int i=0;i < max; i++){
        printf("la posicion es: %d y el valor es: %d\n", i, vec[i]);
    }
}
void invertir(int vec[], int max){
    int aux;
    for (int i=0; i< max/2; i++){
        aux = vec[i];
        vec[i] = vec[max-1-i];
        vec[max-1-i]=aux;
    }
}

int solicitarNumero(){
    int numero;
    printf("Ingrese un numero");
    scanf("%d", &numero);
    return numero;

}
int compararMax(int entrada, int max){
    if (entrada > max){
        max=entrada;
    }
    return max;
}

int compararMin(int entrada, int min){
    if (entrada < min){
        min=entrada;
    }
    return min;
}
float calcularPromedio (int sumatoria, int contador){
    float resultado= sumatoria/contador;
    return resultado;
}

