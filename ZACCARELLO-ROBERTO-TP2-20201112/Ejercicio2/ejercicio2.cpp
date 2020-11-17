#include <iostream>
#include "ejercicio2.h"

using namespace std;


int pop(int vec[], int tamano){
    int valor = vec[0];
    for (int i=0;i<tamano-1;i++){
        vec[i] = vec[i+1];
    }
    vec[tamano-1] = 0;

    return valor;
}

bool push(int vec[], int tamano, int dato){
    for (int i=tamano-1;i > 0;i--){
        vec[i] = vec[i-1];
    }
    vec[0]= dato;
    return true;
}

bool isEmptyPila(int vec[]){
    return vec[0]== 0;
}

void limpiar(int vec[], int tamano){
    while(!isEmptyPila(vec)){
        printf("%d\n", pop(vec, tamano));
    }
}
