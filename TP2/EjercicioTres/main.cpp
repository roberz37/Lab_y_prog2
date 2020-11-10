#include <iostream>

using namespace std;

void agregar(int[], int, int);
int remover(int[], int);
bool isEmpty(int[], int);
void limpiar(int[], int);

int main(){

    int tam = 10;
    int vec [tam];
    for(int i = 0; i < tam; i++){
        vec[i] = 0;
    }
    agregar(vec, tam, 1);
    agregar(vec, tam, 2);
    agregar(vec, tam, 3);
    agregar(vec, tam, 4);
    agregar(vec, tam, 5);
    agregar(vec, tam, 6);
    agregar(vec, tam, 7);
    agregar(vec, tam, 8);
    agregar(vec, tam, 9);
    agregar(vec, tam, 10);
    agregar(vec, tam, 11);
    printf("%d\n", remover(vec, tam));
    limpiar(vec, tam);
    printf("%d\n", remover(vec, tam));
    return 0;
}

void agregar(int vec[], int tamano, int dato){
    int cont = 0;
    for(int i = 0 ; i < tamano; i++){
        if(vec[i] != 0){
            cont++;
        }
    }
    if(cont < 10){
        vec[cont] = dato;
    }else{
        printf("Tenes la cola llena\n");
    }
}

int remover(int vec[], int tamano){
    int valor = vec[0];
    for (int i = 0;i < tamano - 1;i++){
        vec[i] = vec[i + 1];

    }
    vec[tamano - 1] = 0;
    if(valor == 0){
        printf("Tenes la cola vacia\n");
    }
    return valor;
}

bool isEmpty(int vec[], int tamano){
    return vec[0] == 0;
}
void limpiar(int vec[], int tamano){
    while(!isEmpty(vec, tamano)){
        printf("%d\n", remover(vec, tamano));
    }
}
