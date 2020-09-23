#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    short numero;
    float distancia;
}Destino;


typedef struct{
    float distancia;
    short cantViajes=0;
}DestinoAux;

typedef struct{
    char patente[7] ;
    short nroDestino;
    unsigned char nroChofer;
}Viaje;

int main()
{
    FILE *viajes = abrir("viajes.dat", "rb");
    FILE *destino = abrir("destinos.dat", "rb");

    DestinoAux destinosAux[DESTINOS_MAX];
    cargarDestinos(destinos, destinosAux);

    float kmsXChofer[CHOFERES_MAX] = {0};

    int cantPatentes = 0;
    char patentesDestino[PATENTES_MAX][PATENTE_CARACTERES] = {'\0'};

    Viaje viaje;
    leer(&viaje, viajes);
    while(!feof(viajes)){
        DestinoAux destinoAux = destinosAux[viaje.nroChofer];
        destinoAux.cantViajes++;
        kmsXChofer[viaje.nroChofer - 1] += destinoAux.distancia;

        if(viaje.nroDestino == DESTINO_116){
            agregarSinRepeticion(viaje.patente, patentesDestino);
        }
        leer(&viaje, viajes);
    }
    imprimirDestinos(destinosAux, DESTINOS_MAX);
    imprimirMenos(kmsXChofer, CHOFERES_MAX);
    imprimirPatentes(patentesDestino, cantPatentes);


    return 0;
}

void cargarDestinos(FILE *destinos, DestinoAux aux[]){
    Destino destino;
    leer(&destino, destinos);
    while(!feof(destinos)){
        aux[destino.numero].distancia = destino.distancia;
        aux[destino.numero].cantViajes = 0;
        leer(&destino, destinos);
    }
}

void agregarSinRepeticion(char patente[], char patentes[][PATENTE_CARACTERES], int &cantPatentes){
    int i = 0;
    for(i = 0; i < cantPatentes; i++){
        if(strcmp(patente, patentes[i]) == 0){
            return;
        }
    }
    strcpy(patentes[i], patente);
    cantPatentes = i;
}

void imprimirDestinos(DestinoAux destinos[], int cant){
    printf("DESTINO\tCANT. VIAJES\n");
    for(int i = 0; i < cant; i++){
        if(destinos[i].cantViajes > 0){
            printf("%d")
        }
    }
}

void imprimirMenor(){
    printf("El chofer que recorrio menos kms es: %d\n", buscarMenor(kmsXChofer, cant)+1);
}

void imprimirPatentes(char patentes[][PATENTE_CARACTERES], int cant){
    printf("Las patentes que fueron al destino %d, son:\n", DESTINO_116);

}
