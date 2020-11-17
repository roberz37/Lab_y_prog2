#include <iostream>

using namespace std;

typedef struct NodoPila{
    char* palabra;
    NodoPila* siguiente;
}NodoPila;

typedef struct NodoLista{
    char* palabra;
    NodoLista* siguiente;
}NodoLista;

NodoPila* create();
bool isEmpty(NodoPila *);
void push(NodoPila **, char *);
char* pop(NodoPila **);
void vaciar(NodoPila **);
void crearLista(NodoLista** , NodoPila**);
bool tieneVocal(char *);
NodoLista* insertarPrimero(NodoLista**, char *);
void borrarLista(NodoLista**);

int main(){

    NodoPila* pila = create();
    NodoLista* lista = NULL;
    push(&pila, "hola");
    push(&pila, "mundo");
    push(&pila, "aprendiendo");
    push(&pila, "el");
    push(&pila, "lenguaje");
    push(&pila, "c");
    crearLista(&lista, &pila);
    borrarLista(&lista);
    return 0;
}

NodoPila* create(){
    return NULL;
}

bool isEmpty(NodoPila *pila){
    return pila == NULL;
}

void push(NodoPila **pila, char* palabra){
    NodoPila *nodo = (NodoPila*)malloc(sizeof(NodoPila));
    nodo->palabra = palabra;
    nodo->siguiente = *pila;
    *pila = nodo;
}

char* pop(NodoPila **pila){
    char* palabra = (*pila)->palabra;
    NodoPila *aux = *pila;
    *pila = (*pila)->siguiente;
    free(aux);
    return palabra;
}

void vaciar(NodoPila **pila){
    while(!isEmpty(*pila)){
        printf("%s\n", pop(pila));
    }
    *pila = NULL;
}

void crearLista(NodoLista** lista, NodoPila** pila){
    char *palabra;
    while(!isEmpty(*pila)){
        palabra = pop(pila);
        if(!tieneVocal(palabra)){
            insertarPrimero(lista, palabra);
        }
    }
}

bool tieneVocal(char * palabra){
    int i = 0;
    while(*(palabra + i) != '\0'){
        if(*(palabra + i) == 'a' || *(palabra + i) == 'e' || *(palabra + i) == 'i' || *(palabra + i) == 'o' || *(palabra + i) == 'u'){
            return true;
        }
        i++;
    }
    return false;
}

NodoLista* insertarPrimero(NodoLista** lista, char * palabra){
    NodoLista* nodo = (NodoLista*)malloc(sizeof(NodoLista));
    nodo->palabra = palabra;
    nodo->siguiente = *lista;
    *lista = nodo;
    return nodo;
}

void borrarLista(NodoLista** lista){
    NodoLista* listaAux;
    while(*lista != NULL){
        listaAux = *lista;
        printf("%s\n", listaAux->palabra);
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}
