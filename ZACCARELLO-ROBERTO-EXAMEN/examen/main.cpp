#include <iostream>
#include "string.h"

using namespace std;

typedef struct ST_NODO_PROD{
    int codigoProductos;
    float precio;
    int stock;
    ST_NODO_PROD* siguiente;
}ST_NODO_PROD;

typedef struct ST_NODO_PED{
    int codigoProductos;
    int cantidad;
    ST_NODO_PED* siguiente;
}ST_NODO_PED;

typedef struct {
    int codigoProductos;
    char descripcion[50];
    float precio;
    int stock;
} ST_PRODUCTOS;

typedef struct{
    int fecha;
    int codigoProducto;
    int cantidad;
}ST_PEDIDOS;

FILE *abrirArchivo(const char*, const char*);
void imprimirProductos (FILE* archivo);
int busquedaProducto(int, FILE*);
void cargarListas(ST_NODO_PROD**, ST_NODO_PED**, FILE*, FILE*);
ST_NODO_PROD* insertarProdAlFinal(ST_NODO_PROD**, int, float, int);
ST_NODO_PED* insertarPedAlFinal(ST_NODO_PED**, int, int);
void borrarListaProd(ST_NODO_PROD** lista);
void borrarListaPed(ST_NODO_PED** lista);

int main(){
    FILE* productos = abrirArchivo("productos.dat", "rb+");
    FILE* pedidos = abrirArchivo("pedidos.txt", "r");
    FILE* perdidas = abrirArchivo("productos_perdidas.txt", "w");

    ST_NODO_PROD* listaProd = NULL;
    ST_NODO_PED* listaPedidos = NULL;
    cargarListas(&listaProd, &listaPedidos, productos, pedidos);
    //procesarPedidos()
    //imprimirProductos(productos);
    borrarListaProd(&listaProd);
    borrarListaPed(&listaPedidos);
    fclose(productos);
    fclose(pedidos);
    fclose(perdidas);

    return 0;
}

FILE* abrirArchivo(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}
void procesarPedidos(FILE* stock, FILE* pedidos){

}
void imprimirProductos (FILE* archivo){
    ST_PRODUCTOS productos;
    fseek(archivo, 0, SEEK_SET);
    fread(&productos, sizeof(ST_PRODUCTOS), 1, archivo);
    while(!feof(archivo)){
        printf("%d;%s;%0.2f;%d\n", productos.codigoProductos, productos.descripcion, productos.precio, productos.stock);
        fread(&productos, sizeof(ST_PRODUCTOS), 1, archivo);
    }
}
int busquedaProducto(int codigoProducto, FILE* archivo){
    ST_PRODUCTOS producto;
    int primero=0;
    fseek(archivo,0,SEEK_END);
    int ultimo = ftell(archivo)/sizeof(ST_PRODUCTOS) - 1;
    int medio = (primero+ultimo)/2;

    while (primero<=ultimo){
        fseek(archivo, sizeof(ST_PRODUCTOS)*medio, SEEK_SET);
        fread(&producto,sizeof(ST_PRODUCTOS),1, archivo);
        if(producto.codigoProductos < codigoProducto){
            primero = medio+1;
        }else if (producto.codigoProductos == codigoProducto){
            return medio;
        }
        else{
            ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;
    }
    return -1;
 }
 void cargarListas(ST_NODO_PROD** listaProd, ST_NODO_PED** listaPedidos, FILE* productos, FILE* pedidos){
    ST_PRODUCTOS producto;
    fseek(productos, 0, SEEK_SET);
    fread(&producto,sizeof(ST_PRODUCTOS),1, productos);
    while(!feof(productos)){
        insertarProdAlFinal(listaProd, producto.codigoProductos, producto.precio, producto.stock);
        fread(&producto,sizeof(ST_PRODUCTOS),1, productos);
    }

    ST_PEDIDOS pedido;

    fseek(pedidos, 0, SEEK_SET);
    while(fscanf(pedidos, "%d;%d;%d\n", &pedido.codigoProducto, &pedido.fecha , &pedido.cantidad)!= EOF){
        insertarPedAlFinal(listaPedidos, pedido.codigoProducto, pedido.cantidad);
    }
}
ST_NODO_PROD* insertarProdAlFinal(ST_NODO_PROD** lista, int codigoProducto, float precio, int stock){
    ST_NODO_PROD* nodo = (ST_NODO_PROD*)malloc(sizeof(ST_NODO_PROD));
    nodo->codigoProductos = codigoProducto;
    nodo->precio = precio;
    nodo->stock = stock;
    nodo->siguiente = NULL;

    ST_NODO_PROD* listaAux = *lista;
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
ST_NODO_PED* insertarPedAlFinal(ST_NODO_PED** lista, int codigoProducto, int cantidad){
    ST_NODO_PED* nodo = (ST_NODO_PED*)malloc(sizeof(ST_NODO_PED));
    nodo->codigoProductos = codigoProducto;
    nodo->cantidad = cantidad;
    nodo->siguiente = NULL;

    ST_NODO_PED* listaAux = *lista;
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
void borrarListaProd(ST_NODO_PROD** lista){
    ST_NODO_PROD* listaAux;
    while(*lista != NULL){
        listaAux = *lista;
        printf("%d;%f;%d\n", listaAux->codigoProductos, listaAux->precio, listaAux->stock);
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}
void borrarListaPed(ST_NODO_PED** lista){
    ST_NODO_PED* listaAux;
    while(*lista != NULL){
        listaAux = *lista;
        printf("%d;%d\n", listaAux->codigoProductos, listaAux->cantidad);
        *lista = (*lista)->siguiente;
        free(listaAux);
    }
}
