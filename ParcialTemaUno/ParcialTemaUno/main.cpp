#include <iostream>

using namespace std;

typedef struct{
    int id;
    char descripcion[50];
    float precio;
    int stock;
}Productos;

typedef struct{
    int fecha;
    int id;
    int cantidad;
}Pedidos;

typedef struct NodoProd{
    int id;
    float precio;
    int stock;
    NodoProd* siguiente;
}NodoProd;

typedef struct NodoPed{
    int id;
    int cantidad;
    NodoPed* siguiente;
}NodoPed;

FILE *abrir(const char *, const char *);
void imprimirArchivo(FILE *);
int busquedaBinaria(int , FILE*);
void llenarListaProd(NodoProd**, FILE*);
void llenarListaPed(NodoPed**, FILE*);
void actualizarStock(NodoProd**, NodoPed**);
NodoProd* insertarAlFinalProd(NodoProd**, int, int, int);
NodoPed* insertarAlFinalPed(NodoPed**, int, int);
void borrarListaProd(NodoProd**);
void borrarListaPed(NodoPed**);

int main(){

    FILE* productos = abrir("productos.dat", "rb");
    FILE* pedidos = abrir("pedidos.txt", "r");
    FILE* perdidas = abrir("productos_perdidas.txt", "w");
    NodoProd* listaProd = NULL;
    NodoPed* listaPed = NULL;
    llenarListaProd(&listaProd, productos);
    llenarListaPed(&listaPed, pedidos);
    //actualizarStock(&listaProd, &listaPed);
    borrarListaProd(&listaProd);
    borrarListaPed(&listaPed);
    //imprimirArchivo(productos);
    fclose(pedidos);
    fclose(perdidas);
    fclose(productos);
    return 0;
}

void llenarListaProd(NodoProd** listaProd, FILE* productos){
    Productos producto;
    fread(&producto, sizeof(Productos), 1, productos);
    while(!feof(productos)){
        insertarAlFinalProd(listaProd, producto.id, producto.precio, producto.stock);
        fread(&producto, sizeof(Productos), 1, productos);
    }
}

void llenarListaPed(NodoPed** listaPed, FILE* pedidos){
    Pedidos pedido;
    fscanf(pedidos, "%d;%d;%d\n", &pedido.fecha, &pedido.id, &pedido.cantidad);
    while(!feof(pedidos)){
        insertarAlFinalPed(listaPed, pedido.id, pedido.cantidad);
        fscanf(pedidos, "%d;%d;%d\n", &pedido.fecha, &pedido.id, &pedido.cantidad);
    }
    insertarAlFinalPed(listaPed, pedido.id, pedido.cantidad);
}

FILE *abrir(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}

void imprimirArchivo(FILE *archivo){
    Productos usuario;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuario, sizeof(Productos), 1, archivo);
    while(!feof(archivo)){
        printf("%d;%s;%f;%d\n", usuario.id, usuario.descripcion, usuario.precio, usuario.stock);
        fread(&usuario, sizeof(Productos), 1, archivo);
    }
    printf("\n");
}

void actualizarStock(NodoProd** listaProd, NodoPed** listaPed){

}

NodoProd* insertarAlFinalProd(NodoProd** lista, int id, int precio, int stock){
    NodoProd* nodo = (NodoProd*)malloc(sizeof(NodoProd));
    nodo->id = id;
    nodo->precio = precio;
    nodo->stock = stock;
    nodo->siguiente = NULL;
    NodoProd* listaAux = *lista;
    while(listaAux != NULL && listaAux->siguiente != NULL){
        listaAux= listaAux->siguiente;
    }
    if(listaAux == NULL){
        *lista = nodo;
    } else {
        listaAux->siguiente = nodo;
    }
    return nodo;
}

NodoPed* insertarAlFinalPed(NodoPed** lista, int id, int cantidad){
    NodoPed* nodo = (NodoPed*)malloc(sizeof(NodoPed));
    nodo->id = id;
    nodo->cantidad = cantidad;
    nodo->siguiente = NULL;
    NodoPed* listaAux = *lista;
    while(listaAux != NULL && listaAux->siguiente != NULL){
        listaAux= listaAux->siguiente;
    }
    if(listaAux == NULL){
        *lista = nodo;
    } else {
        listaAux->siguiente = nodo;
    }
    return nodo;
}

void borrarListaProd(NodoProd** lista){
    NodoProd* listaAux;
    while(*lista != NULL){
        listaAux = *lista;
        printf("%d;%f;%d\n", listaAux->id, listaAux->precio, listaAux->stock);
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}

void borrarListaPed(NodoPed** lista){
    NodoPed* listaAux;
    while(*lista != NULL){
        listaAux = *lista;
        printf("%d;%d\n", listaAux->id, listaAux->cantidad);
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}
