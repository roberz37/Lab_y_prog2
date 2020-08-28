#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nombre[20];
    int legajo;
}Cliente;
/*Todos los días al terminar el turno, se informa quién fue la primera persona en ser
atendida, quien poseía el legajo más bajo, la cantidad total de personas y cuántas
personas fueron atendidas por tipo de trámite; los empleados suelen acercarse a la
administración por temas relacionados al salario, vacaciones y cobertura médica.*/
int main(){
    int cantidad;
    Cliente min;
    char tramite;
    int contadorSalario = 0;
    int contadorVacaciones = 0;
    int contadorCobertura = 0;
    int otroTipoTramite = 0;
    printf("Ingrese la cantidad que quisiera atender\n");
    scanf("%d", &cantidad);
    Cliente clientes[cantidad];
    for(int i = 0; i < cantidad; i++){
        printf("Ingrese su nombre\n");
        scanf("%s", clientes[i].nombre);
        printf("Ingrese su legajo\n");
        scanf("%d", &clientes[i].legajo);
        printf("Que tipo de tramite es\n");
        if(min.legajo > clientes[i].legajo || i == 0){
            strcpy(min.nombre,clientes[i].nombre);
            min.legajo = clientes[i].legajo;
        }
        fflush(stdin);
        scanf("%c", &tramite);
        switch(tramite){
        case 's':
            contadorSalario++;
            break;
        case 'v':
            contadorVacaciones++;
            break;
        case 'c':
            contadorCobertura++;
            break;
        default:
            printf("Otro tipo de tramite\n");
            otroTipoTramite++;
        }

    }
    printf("La primera persona en ser atendida: %s, y su legajo: %d\n", clientes[0].nombre, clientes[0].legajo);
    printf("Cantidad total de personas atendidas: %d\n", cantidad);
    printf("tipo de personas atentidas por tipo de tramite salario: %d\n", contadorSalario);
    printf("tipo de personas atentidas por tipo de tramite vacaciones: %d\n", contadorVacaciones);
    printf("tipo de personas atentidas por tipo de tramite cobertura: %d\n", contadorCobertura);
    printf("La persona con el legajo mas bajo es: %s, con el legajo: %d\n", min.nombre, min.legajo);

    return 0;
}
