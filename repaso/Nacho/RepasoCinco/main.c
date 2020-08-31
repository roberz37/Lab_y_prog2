#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct{
    char nombre[20];
    int idHabitacion;
    int diasHospedaje;
    int reserva;
} Habitacion;

void imprimirHabitaciones(Habitacion vec[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        printf("%s\t" , vec[i].nombre);
        printf("%d\t" , vec[i].idHabitacion);
        printf("%d\t" , vec[i].diasHospedaje);
        printf("%d\n" , vec[i].reserva);
    }
}

void cambiarHabitaciones(Habitacion vec[], int tamanio){
    char nombre[20];
    int i = 0;
    int idHabitacionActual;
    bool disponible = true;
    printf("Ingrese su nombre please\n");
    scanf("%s", nombre);
    for(int i = 0; i<tamanio; i++){
        if(strcmp(nombre, vec[i].nombre) == 0){
            idHabitacionActual = i;
        }
    }
    while(i < tamanio && disponible){
        if(vec[i].reserva == 0){
            strcpy(vec[i].nombre, vec[idHabitacionActual].nombre);
            printf("vec[i]: %s, vec[idHabitacionActual]: %s\n", vec[i].nombre, vec[idHabitacionActual].nombre);

            vec[i].diasHospedaje = vec[idHabitacionActual].diasHospedaje;
            vec[i].reserva = vec[idHabitacionActual].reserva;
            disponible = false;
            printf("Su nueva habitacion es la numero: %d\n", vec[i].idHabitacion);
        }
        i++;
    }
    strcpy(vec[idHabitacionActual].nombre, " ");
    vec[idHabitacionActual].diasHospedaje = 0;
    vec[idHabitacionActual].reserva = 0;
}
void setearHabitaciones(Habitacion vec[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        strcpy(vec[i].nombre, " ");
        vec[i].idHabitacion = i+1;
        vec[i].diasHospedaje = 0;
        vec[i].reserva = 0;
    }
}
void ingresarPersona(Habitacion vec[], int tamanio){
    int i = 0;
    bool disponible = true;
    while(i < tamanio && disponible){
        if(vec[i].diasHospedaje == 0){
            printf("Ingrese el nombre: ");
            scanf("%s", vec[i].nombre);
            fflush(stdin);
            printf("Ingrese los dias que se va a quedar: ");
            scanf("%d", &vec[i].diasHospedaje);
            printf("Ingrese el numero de reserva: ");
            scanf("%d", &vec[i].reserva);
            printf("La habitacion correspondiente es: %d\n", vec[i].idHabitacion);
            disponible = false;
        }
        i++;
    }
}
int main(){

    Habitacion habitaciones[6];
    setearHabitaciones(habitaciones, 6);
    int opciones = 0;

    do{
        printf("Elija la opcion\n1)Ingresar una persona\n2)Cambiar habitacion\n3)Mostrar habitaciones\n4)Salir\n");
        scanf("%d", &opciones);
        //fflush(stdin);
        switch(opciones){

            case 1:
                ingresarPersona(habitaciones, 6);

                break;
            case 2:
                cambiarHabitaciones(habitaciones, 6);
                break;
            case 3:
                imprimirHabitaciones(habitaciones, 6);
                break;
            default:
                printf("Elija otra opcion please\n");
                scanf("%d", &opciones);
                break;
        }


    }while(opciones != 4);
    printf("Hasta luego\n");
    system("pause");
    return 0;
}
