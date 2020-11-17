#include <iostream>
#include "ejercicio3.h"

using namespace std;

void add(int vec[], int tamano, int dato){
    int cont = 0;
    for(int i = 0 ; i < tamano; i++){
        if(vec[i] != 0){
            cont++;
        }
    }
    if(cont < 10){
        vec[cont] = dato;
    }else{
        printf("La cola esta llena\n");
    }
}

int remover(int vec[], int tamano){
    int valor = vec[0];
    for (int i = 0;i < tamano - 1;i++){
        vec[i] = vec[i + 1];

    }
    vec[tamano - 1] = 0;
    if(valor == 0){
        printf("La cola esta vacia\n");
    }
    return valor;
}

bool isEmptyCola(int vec[]){
    return vec[0] == 0;
}

void limpiar(int vec[], int tamano){
    while(!isEmptyCola(vec)){
        printf("%d\n", remover(vec, tamano));
    }
}
