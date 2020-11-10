#include <iostream>
#include <string.h>
using namespace std;

/*Realizar la implementación de una pila utilizando un vector como espacio de
almacenamiento. Realizar las funciones conocidas para la estructura (push, pop,
etc.) y luego hacer un programa que cargue N valores aleatorios y los imprima.*/
int pop(int[], int);
bool isEmpty(int[]);
void push(int[], int, int);
void limpiar(int[], int);

int main(){

    int tam = 10;
    int vec [tam];
    for(int i = 0; i < tam; i++){
        vec[i] = 0;
    }
    push(vec, tam, 1);
    push(vec, tam, 2);
    push(vec, tam, 3);
    push(vec, tam, 5);
    push(vec, tam, 7);
    push(vec, tam, 10);
    push(vec, tam, 14);
    push(vec, tam, 17);
    push(vec, tam, 20);
    push(vec, tam, 25);
    push(vec, tam, 40);
    printf("afuera del while:%d\n", pop(vec, tam));
    printf("afuera del while:%d\n", pop(vec, tam));
    limpiar(vec, tam);
    printf("afuera del while:%d\n", pop(vec, 10));
    return 0;
}

bool isEmpty(int vec[]){
    return vec[0] == 0;
}

int pop(int vec[], int tamano){
    int valor = vec[0];
    for (int i=0;i<tamano-1;i++){
        vec[i] = vec[i+1];

    }
    vec[tamano-1] = 0;
    return valor;
}

void push(int vec[], int tamano, int dato){
    int cont = 0;
    if(vec[0] == 0){
        vec[0] = dato;
    }else{
        for(int i = 0 ; i < tamano; i++){
            if(vec[i] != 0){
                cont++;
            }
        }
        if(cont < 10){
            for(int i = tamano - 1 ; i > 0; i--){
                vec[i] = vec[i - 1];
            }
            vec[0] = dato;
        } else {
            printf("La pila esta llena\n");
        }
    }
}

void limpiar(int vec[], int tamano){
    while(!isEmpty(vec)){
        printf("%d\n", pop(vec, tamano));
    }
}
