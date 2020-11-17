#include <iostream>
#include "ejercicio2.h"

using namespace std;

int main()
{
    int tam = 10;
    int vec [tam];
    for(int i = 0; i < tam; i++){
        vec[i] = 0;
    }
    push(vec, tam, 1);
    push(vec, tam, 2);
    push(vec, tam, 3);
    push(vec, tam, 5);
    pop(vec, tam);
    push(vec, tam, 7);
    push(vec, tam, 10);
    printf("La pila esta vacia?"); printf(isEmptyPila(vec)? " Si\n" : " No\n");
    push(vec, tam, 14);
    push(vec, tam, 17);
    push(vec, tam, 20);
    push(vec, tam, 25);
    push(vec, tam, 40);
    pop(vec, tam);
    limpiar(vec, tam);

    return 0;
}
