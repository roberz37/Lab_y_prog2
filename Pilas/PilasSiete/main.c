#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por
un punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si
no lo son. Los conjuntos deben ingresarse por teclado. (Definir parámetros y
codificar).*/
typedef struct Nodo{
    char dato;
    struct Nodo* siguiente;
}Nodo;

Nodo* create();
bool isEmpty(Nodo *);
void push(Nodo **, char);
char pop(Nodo **);
bool inversa(char *);
void clear(Nodo **);

int main(){

    char conjuntoUno[26];
    char conjuntoDos[26];
    char conjuntoResultante[52];
    memset(conjuntoResultante, '\0', 52);
    printf("Ingrese el conjunto uno\n");
    scanf("%s", conjuntoUno);
    printf("Ingrese el conjunto dos\n");
    scanf("%s", conjuntoDos);
    strcat(conjuntoResultante, conjuntoUno);
    strcat(conjuntoResultante, ".");
    strcat(conjuntoResultante, conjuntoDos);
    printf("%s\n", conjuntoResultante);
    bool esLaInversa = inversa(conjuntoResultante);
    if(esLaInversa){
        printf("es inversa la cadena\n");
    }else{
        printf("No es inversa\n");
    }
    return 0;
}

Nodo* create(){
    return NULL;
}

bool isEmpty(Nodo *pila){
    return pila == NULL;
}

void push(Nodo **pila, char dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = *pila;
    *pila = nodo;
}

char pop(Nodo **pila){
    char valor = (*pila)->dato;
    Nodo *aux = *pila;
    *pila = (*pila)->siguiente;
    free(aux);
    return valor;
}

bool inversa(char *cadena){
    int i = 0;
    bool punto = false;
    Nodo *pila = create();
    while(*(cadena + i) != '\0'){
        if(!punto){
            if(*(cadena + i) == '.'){
                punto = true;
            }else{
                push(&pila, *(cadena + i));
            }
        }else if(*(cadena + i) != pop(&pila)){
            clear(&pila);
            return false;
        }
        i++;
    }
    clear(&pila);
    return true;
}

void clear(Nodo **pila){
    while(!isEmpty(*pila)){
        pop(pila);
    }
    *pila = NULL;
}
