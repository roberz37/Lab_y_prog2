#include <iostream>
#include "ejercicio3.h"

using namespace std;

int main()
{
     int tam = 10;
    int vec [tam];
    for(int i = 0; i < tam; i++){
        vec[i] = 0;
    }
    add(vec, tam, 1);
    add(vec, tam, 2);
    add(vec, tam, 3);
    add(vec, tam, 5);
    remover(vec, tam);
    add(vec, tam, 7);
    add(vec, tam, 10);
    printf("La Cola esta vacia?"); printf(isEmptyCola(vec)? " Si\n" : " No\n");
    add(vec, tam, 14);
    add(vec, tam, 17);
    add(vec, tam, 20);
    add(vec, tam, 25);
    add(vec, tam, 40);
    remover(vec, tam);
    limpiar(vec, tam);

    return 0;
}
