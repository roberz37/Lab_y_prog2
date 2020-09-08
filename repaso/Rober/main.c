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

4) El empleado administrativo de una empresa atiende durante su jornada laboral a una
indeterminada cantidad de personas; todas ellas deben indicar su nombre y número de
legajo para ser atendidos.
Todos los días al terminar el turno, se informa quién fue la primera persona en ser
atendida, quien poseía el legajo más bajo, la cantidad total de personas y cuántas
personas fueron atendidas por tipo de trámite; los empleados suelen acercarse a la
administración por temas relacionados al salario, vacaciones y cobertura médica.

5)Con seis habitaciones repartidas en tres plantas, un hotel familiar abre sus puertas para
recibir turistas acaudalados.
El propietario necesita un sistema que le permita formular el checkin de las personas,
para lo cual le interesa identificar quién se aloja en qué habitación, el número de reserva
asociado y cantidad que días se hospedará.
También, porque a veces ocurre que las habitaciones no resultan del interés del turista,
necesita poder mover de una habitación a la otra a las personas y que eso se refleje en el
sistema.
Como todo sistema hotelero, este debe poder gestionar el checkout e imprimir por
pantalla los huéspedes.
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
    /*

    1) int vec[10] = {1,2,3,4,5,6,7,8,9,10};

    multiplicar(vec, 10);
    imprimir(vec, 10);
    invertir(vec, 10);
    printf("\n........................\n\n");
    imprimir(vec, 10);
    ----------------------------------------------------------------


    2) int entrada= solicitarNumero();
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

    3) ST_PERSONAS personas[10];

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
    ------------------------------------------------------------------------
    */
    ST_EMPLEADO empleado;

    int i=0, menorLegajo, tramiteS=0, tramiteV=0, tramiteM=0;
    char primerPersona[20], tipoTramite=NULL;

    do {
        printf("Para terminar ingrese la palabra 'NO'\n");
        printf("Ingrese el nombre de la persona: ");
        scanf("%s", empleado.nombre);
        fpurge(stdin);
        if (strcmp("no", empleado.nombre )!= 0){
            printf("Ingrese el legajo de la persona: ");
            scanf("%d", &empleado.legajo);
            printf("Ingrese el tipo de tramite: ");
            scanf("%c", &tipoTramite);

            if (i==0){
                strcpy(primerPersona, empleado.nombre);
            }
            if (i==0 || menorLegajo > empleado.legajo){
                menorLegajo= empleado.legajo;
            }
            switch (tipoTramite){
            case 's':
                tramiteS++;
                break;
            case 'v':
                tramiteV++;
                break;
            case 'm':
                tramiteM++;
                break;
            }

        }
        i++;
    } while (strcmp("no", empleado.nombre)!= 0);

    printf("La primera persona en ser atendida: %s", primerPersona);
    printf("Cantidad total de personas atendidas: %d\n", i);
    printf("tipo de personas atentidas por tipo de tramite salario: %d\n", tramiteS);
    printf("tipo de personas atentidas por tipo de tramite vacaciones: %d\n", tramiteV);
    printf("tipo de personas atentidas por tipo de tramite cobertura: %d\n", tramiteM);
    printf("El legajo mas bajo fue el: %d\n", menorLegajo);


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

