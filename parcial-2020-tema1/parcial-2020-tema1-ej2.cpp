
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Dato
{
    char palabra[20];
} STR_DATO;

typedef struct Nodo
{
    STR_DATO dato;
    Nodo *siguiente;
} STR_NODO;

//pila
void push(STR_DATO dato, STR_NODO **pila);
STR_DATO pop(STR_NODO **pila);
void create(STR_NODO **pila);
bool isEmpty(STR_NODO *pila);

//LISTA:
void create(STR_NODO **lista);
bool isEmpty(STR_NODO *lista);
STR_NODO *insertInFront(STR_DATO valor, STR_NODO **lista);
void print(STR_NODO *lista);
void clearList(STR_NODO **lista);

bool esVocal(char letra);
bool esCadenaValida(const char *cadena);
void llenarLista(STR_NODO **pila, STR_NODO **lista);

int main()
{

    STR_NODO *pila;
    create(&pila);
    STR_DATO dato;
    STR_NODO *lista = NULL;
    int posicion = 0;
    char palabra[30];

    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese una palabra:");
        scanf(" %s", dato.palabra);

        push(dato, &pila);
    }

    llenarLista(&pila, &lista);

    print(lista);

    clearList(&lista);

    system("pause");
    return 0;
}

void create(STR_NODO **pila)
{
    *pila = NULL;
}

void push(STR_DATO dato, STR_NODO **pila)
{
    STR_NODO *ptrNodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    if (ptrNodo)
    {
        ptrNodo->dato = dato;
        ptrNodo->siguiente = *pila;
        *pila = ptrNodo;
    }
}

bool isEmpt(STR_NODO *pila)
{
    return pila == NULL;
}

STR_DATO pop(STR_NODO **pila)
{
    STR_DATO valor = (*pila)->dato;
    STR_NODO *aux = *pila;
    *pila = (*pila)->siguiente;
    free(aux);
    return valor;
}

//lista:

bool isEmpty(STR_NODO *lista)
{
    return lista == NULL;
}

STR_NODO *insertInFront(STR_DATO valor, STR_NODO **lista)
{
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    if (nodo)
    {
        nodo->dato = valor;
        nodo->siguiente = *lista;

        *lista = nodo;
    }

    return nodo;
}

void print(STR_NODO *lista)
{
    STR_NODO *listaAux;
    listaAux = lista;
    printf("Palabras sin vocales\n");
    while (listaAux != NULL)
    {
        printf("%s\n", listaAux->dato.palabra);
        listaAux = listaAux->siguiente;
    }
}

void clearList(STR_NODO **lista)
{
    STR_NODO *aux = NULL;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}

bool esVocal(char letra)
{
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U');
}

bool esCadenaValida(const char *cadena)
{

    bool caracteresValidos = true;

    while (*cadena)
    {
        if (esVocal((*cadena)))
        {
            caracteresValidos = false;
        }
        cadena++;
    }
    return caracteresValidos;
}

void llenarLista(STR_NODO **pila, STR_NODO **lista)
{
    STR_DATO dato;
    while (!isEmpt(*pila))
    {
        dato = pop(pila);
        if (esCadenaValida(dato.palabra))
        {
            insertInFront(dato, lista);
        }
    }
}
