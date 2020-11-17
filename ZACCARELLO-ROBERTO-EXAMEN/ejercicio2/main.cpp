#include <iostream>

using namespace std;

typedef struct ST_NODO{
    char* palabra;
    ST_NODO* siguiente;
}ST_NODO;

ST_NODO *create ();
bool isEmpty(ST_NODO*);
void push(ST_NODO**, char[]);
char* pop(ST_NODO**);
void limpiar(ST_NODO**);
bool noTieneVocales(char*);
bool esVocal(char);
ST_NODO* insertarPrimero(ST_NODO**, char*);
void borrarLista(ST_NODO**);
void listarSinVocales(ST_NODO** lista, ST_NODO** pila);
int main()
{
    ST_NODO* pila = create();
    ST_NODO* lista = create();
    push(&pila, "asd");
    push(&pila, "dsa");
    push(&pila, "uyt");
    push(&pila, "jghj");
    push(&pila, "ghj");
    push(&pila, "dfsdf");

    listarSinVocales(&pila, &lista);

    return 0;
}

ST_NODO* create(){
    return NULL;
}
bool isEmpty(ST_NODO* pila){
    return pila == NULL;
}
void push(ST_NODO** pila, char* valor){
    ST_NODO* auxiliar = (ST_NODO*) malloc (sizeof(ST_NODO));
    auxiliar->palabra = valor;
    auxiliar->siguiente = *pila;
    *pila = auxiliar;
}
char* pop(ST_NODO** pila){
    char* valor = (*pila)->palabra;
    ST_NODO *auxiliar = *pila;
    *pila = (*pila)->siguiente;
    free(auxiliar);
    return valor;
}

bool noTieneVocales(char* palabra){
    int i=0;
    while (*(palabra+i) != '\0'){
        if (esVocal(*(palabra+i))){
           return false;
        }
        i++;
    }
    return true;

}
bool esVocal(char letra){
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        return false;
    }
    return false;
}
ST_NODO* insertarPrimero(ST_NODO** lista, char * palabra){
    ST_NODO* nodo = (ST_NODO*)malloc(sizeof(ST_NODO));
    nodo->palabra = palabra;
    nodo->siguiente = *lista;
    *lista = nodo;
    return nodo;
}
void listarSinVocales(ST_NODO** lista, ST_NODO** pila){
    char *valor;
    while(!isEmpty(*pila)){
        valor = pop(pila);
        if(noTieneVocales(valor)){
            insertarPrimero(lista, valor);
        }
    }
}

