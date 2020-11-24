#include <iostream>
#include "string.h"
using namespace std;

#define MAX_BUFFER 250

typedef struct Producto {
    int codigo;
    char descripcion[51];
    float precio;
    int stock;
} STR_PRODUCTO;

typedef struct Pedido {
    int fecha;
    int codigo;
    char cantidad;
} STR_PEDIDO;

typedef struct Perdida {
    int codigo;
    int cantPedidos;
    float perdidas;
} STR_DATO;

typedef struct Nodo {
    STR_DATO dato;
    Nodo *siguiente;
} STR_NODO;

// Funciones de lista
void create(STR_NODO **lista);
bool isEmpty(STR_NODO *lista);
STR_NODO* insertInFront(STR_DATO valor, STR_NODO **lista);
STR_NODO* insertAtEnd(STR_DATO valor, STR_NODO **lista);
STR_NODO* insertOrdered(STR_DATO valor, STR_NODO **lista);
STR_NODO* insertWithoutDuplicate(STR_DATO valor, STR_NODO **lista);
void print(STR_NODO *lista);
void clearList(STR_NODO **lista);
STR_NODO *search(STR_NODO *lista, STR_DATO valor);
STR_DATO deleteFirst(STR_NODO **lista);
void sort(STR_NODO **lista);
int count(STR_NODO *listaAux);

FILE *abrir(const char *fileName, const char *modo);
void cerrar(FILE *file);
int leer(FILE *file, STR_PRODUCTO *registro);
int contarRegistros(FILE * file);
int posicionar(FILE * file, int posicion);
int leer(STR_PRODUCTO *registro, FILE *file, int posicion);
int escribir(STR_PRODUCTO registro, FILE *file);
int escribir(STR_PRODUCTO registro, FILE *file, int posicion);

int buscar(int codigo, FILE * file);
STR_PEDIDO parse(char cadena[]);
STR_PRODUCTO parsear(char *cadena);
void generarArchivo(const char *entrada, const char *salida);

void procesarPedido(STR_PEDIDO pedido, int posProd, FILE *productos, STR_NODO **perdidas, float diaria[]);
void grabarPerdidas(STR_NODO **lista, const char *fileName);
int maximo(float vector[], int cant);

int main () {
    //Comentar luego de tener el archivo binario generado
    generarArchivo("productos.txt", "productos.dat");

    FILE *productos = abrir("productos.dat", "rb+");
    FILE *pedidos = abrir("pedidos.txt", "r");

    STR_NODO *lista = NULL;
    float perdidaDiaria[31]={0};

    char buffer[MAX_BUFFER];

    int posProducto = 0;
    while(fgets(buffer, 250, pedidos) != NULL) {
        STR_PEDIDO pedido = parse(buffer);
        posProducto = buscar(pedido.codigo, productos);
        if(posProducto > 0) {
            procesarPedido(pedido, posProducto, productos, &lista, perdidaDiaria);
        }
    }

    grabarPerdidas(&lista, "productos_perdidas.txt");

    int pos = maximo(perdidaDiaria, 31);
    printf("El día de mayor perdidas fue el %d ($%.2f)\n", pos + 1, perdidaDiaria[pos]);

    cerrar(productos);
    cerrar(pedidos);

    system("pause");
    return 0;
}

void procesarPedido(STR_PEDIDO pedido, int posProd, FILE *productos, STR_NODO **perdidas, float diaria[]) {
    STR_PRODUCTO producto;
    leer(&producto, productos, posProd);

    if (producto.stock >= pedido.cantidad) {
        producto.stock -= pedido.cantidad;
    } else {
        int perdida = pedido.cantidad - producto.stock;
        producto.stock = 0;

        STR_DATO regPerdida;
        regPerdida.codigo = pedido.codigo;
        regPerdida.perdidas = 0;
        regPerdida.cantPedidos = 0;
        STR_NODO *ptrPerdida = insertWithoutDuplicate(regPerdida, perdidas);

        ptrPerdida->dato.cantPedidos++;
        ptrPerdida->dato.perdidas+=(perdida*producto.precio);

        diaria[(pedido.fecha % 100) - 1] += (perdida*producto.precio);
    }

    escribir(producto, productos, posProd);
    fflush(productos);
}

void grabarPerdidas(STR_NODO **lista, const char *fileName) {
    FILE *perdidas = abrir(fileName, "w");

    STR_DATO perdida;
    while(!isEmpty(*lista)) {
        perdida = deleteFirst(lista);
        fprintf(perdidas, "%d;%.2f;%d\n", perdida.codigo, perdida.perdidas, perdida.cantPedidos);
    }
    cerrar(perdidas);
    return;
}

FILE *abrir(const char *fileName, const char *modo) {
    FILE *file = fopen(fileName, modo);
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}

void cerrar(FILE *file)
{
    fclose(file);
    file = NULL;
}

int leer(FILE *file, STR_PRODUCTO *registro) {
    return fread(registro, sizeof(STR_PRODUCTO), 1, file);
}

int contarRegistros(FILE * file) {
    long posActual = ftell(file);
    fseek(file, 0, SEEK_END);
    int cant = ftell(file) / sizeof(STR_PRODUCTO);
    fseek(file, posActual, SEEK_SET);
    return cant;
}

int posicionar(FILE * file, int posicion) {
    return fseek(file, posicion * sizeof(STR_PRODUCTO), SEEK_SET);
}

int leer(STR_PRODUCTO *registro, FILE *file, int posicion) {
    posicionar(file, posicion);
    return leer(file, registro);
}

int escribir(STR_PRODUCTO registro, FILE *file) {
    return fwrite(&registro, sizeof(STR_PRODUCTO), 1, file);
}

int escribir(STR_PRODUCTO registro, FILE *file, int posicion) {
    posicionar(file, posicion);
    return escribir(registro, file);
}

int buscar(int codigo, FILE * file) {
    int inicio = 0;
    int final = contarRegistros(file) - 1;
    int mitad = 0;
    STR_PRODUCTO registro;

    while (final >= inicio) {
        mitad = inicio + (final - inicio) / 2;
        leer(&registro, file, mitad);

        if(registro.codigo == codigo) {
            return mitad;
        }

        if(codigo < registro.codigo) {
            final = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }

    return -1;
}

STR_PEDIDO parse(char cadena[]) {
    STR_PEDIDO pedido;
    pedido.fecha = atoi(strtok(cadena,";"));
    pedido.codigo = atoi(strtok(NULL, ";"));
    pedido.cantidad = atoi(strtok(NULL, "\n"));
    return pedido;
}

int maximo(float vector[], int cant) {
    int max = vector[0];
    int pos = 0;
    for (int i = 1; i < cant; i++) {
        if(vector[i] > max) {
            max = vector[i];
            pos = i;
        }
    }
    return pos;
}

STR_PRODUCTO parsear(char *cadena) {
    STR_PRODUCTO registro;

    registro.codigo = atoi(strtok(cadena, ";"));

    strcpy(registro.descripcion,strtok(NULL, ";"));
    strcat(registro.descripcion,"\0");

    registro.precio = atof(strtok(NULL, ";"));
    registro.stock = atoi(strtok(NULL, "\n;"));
    return registro;
}

void generarArchivo(const char *entrada, const char *salida) {
    FILE *fileTxt = abrir(entrada, "r");
    FILE *fileBin = abrir(salida, "wb");
    STR_PRODUCTO registro;
    char buffer[250];
    fgets(buffer, 250, fileTxt);
    while(!feof(fileTxt)) {
        registro.codigo = atoi(strtok(buffer, ";"));
        strcpy(registro.descripcion,strtok(NULL, ";"));
        strcat(registro.descripcion,"\0");
        registro.precio = atof(strtok(NULL, ";"));
        registro.stock = atoi(strtok(NULL, "\n;"));

        fwrite(&registro, sizeof(STR_PRODUCTO), 1, fileBin);
        fgets(buffer, 250, fileTxt);
    }

    cerrar(fileTxt);
    cerrar(fileBin);

    return;
}

// Funciones de Listas
void create(STR_NODO **lista) {
    *lista = NULL;
    return;
}

bool isEmpty(STR_NODO *lista) {
    return lista == NULL;
}

STR_NODO* insertInFront(STR_DATO valor, STR_NODO **lista) {
    STR_NODO* nodo = (STR_NODO *) malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = *lista;

    *lista = nodo;
    return nodo;
}

STR_NODO* insertAtEnd(STR_DATO valor, STR_NODO **lista) {
    STR_NODO* nodo = (STR_NODO *) malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    if(isEmpty(*lista)) {
        *lista = nodo;
    } else {
        STR_NODO *listaAux = *lista;
        while(listaAux->siguiente != NULL) {
            listaAux = listaAux->siguiente;
        }
        listaAux->siguiente = nodo;
    }

    return nodo;
}

STR_NODO* insertOrdered(STR_DATO valor, STR_NODO **lista) {
    STR_NODO* nodo = (STR_NODO *) malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    STR_NODO *listaAux = *lista;
    STR_NODO *nodoAnt = NULL;
    while(listaAux != NULL && listaAux->dato.codigo < valor.codigo) {
        nodoAnt = listaAux;
        listaAux = listaAux->siguiente;
    }

    if(nodoAnt == NULL) {
        *lista = nodo;
    } else {
        nodoAnt->siguiente = nodo;
    }

    nodo->siguiente = listaAux;
    return nodo;
}

STR_NODO* insertWithoutDuplicate(STR_DATO valor, STR_NODO **lista) {
    STR_NODO *nodo = search(*lista, valor);
    if(nodo == NULL) {
        nodo = insertOrdered(valor, lista);
    }

    return nodo;
}

void clearList(STR_NODO **lista) {
    STR_NODO *aux = NULL;
    while(*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}

STR_NODO *search(STR_NODO *lista, STR_DATO valor) {
    STR_NODO *listaAux = lista;
    while(listaAux != NULL && listaAux->dato.codigo != valor.codigo) {
        listaAux = listaAux->siguiente;
    }
    return listaAux;
}

STR_DATO deleteFirst(STR_NODO **lista) {
    STR_DATO dato = (*lista)->dato;
    STR_NODO *aux = *lista;
    *lista = (*lista)->siguiente;
    free(aux);
    return dato;
}

void sort(STR_NODO **lista) {
    STR_NODO *listaAux;
    create(&listaAux);
    STR_DATO dato;
    while(*lista != NULL) {
        dato = deleteFirst(lista);
        insertOrdered(dato, &listaAux);
    }

    *lista = listaAux;
}

int count(STR_NODO *listaAux) {
    int cant = 0;
    while(listaAux != NULL) {
        listaAux = listaAux->siguiente;
        cant++;
    }

    return cant;
}
