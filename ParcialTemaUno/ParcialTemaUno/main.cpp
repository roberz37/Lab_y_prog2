#include <iostream>

using namespace std;

typedef struct{
    int id;
    char descripcion[51];
    float precio;
    int stock;
}Producto;

typedef struct{
    int fecha;
    int id;
    int cantidad;
}Pedido;

typedef struct Nodo{
    int id;
    float totalPerdida;
    int cantidad;
    Nodo* siguiente;
}Nodo;

FILE *abrir(const char *, const char *);
void imprimirArchivo(FILE *);
int busquedaBinaria(FILE*, int);
void actualizarStock(FILE*, FILE*);
Nodo* buscar(Nodo*, int);
Nodo* insertarOrdenado(Nodo**, int);

int main(){

    FILE* productos = abrir("productos.dat", "rb+");
    FILE* pedidos = abrir("pedidos.txt", "r");
    FILE* perdidas = abrir("productos_perdidas.txt", "w");

    actualizarStock(productos, pedidos);

    fclose(pedidos);
    fclose(perdidas);
    fclose(productos);
    return 0;
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
    Producto usuario;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuario, sizeof(Producto), 1, archivo);
    while(!feof(archivo)){
        printf("%d;%s;%f;%d\n", usuario.id, usuario.descripcion, usuario.precio, usuario.stock);
        fread(&usuario, sizeof(Producto), 1, archivo);
    }
    printf("\n");
}

void actualizarStock(FILE* productos,FILE* pedidos, Nodo** listaPerdida){
    Pedido pedido;
    Producto producto;
    int buscado = 0;
    int resto = 0;
    Nodo* aux;
    bool flag = false;
    fscanf(pedidos, "%d;%d;%d\n", &pedido.fecha, &pedido.id, &pedido.cantidad);
    while(!feof(pedidos)){
        buscado = busquedaBinaria(productos, pedido.id);
        fseek(productos, sizeof(Producto)*(pedido.id-1), SEEK_SET);
        fread(&producto, sizeof(Producto), 1, productos);
        if(pedido.cantidad < producto.stock){
            fseek(productos, sizeof(Producto)*-1, SEEK_CUR);
            producto.stock -= pedido.cantidad;
            fwrite(&producto, sizeof(Producto), 1, productos);
        }else{
            resto = pedido.cantidad - producto.stock;
            producto.stock = 0;
            fseek(productos, sizeof(Producto)*-1, SEEK_CUR);
            fwrite(&producto, sizeof(Producto), 1, productos);
            aux = insertarSinDuplicados(listaPerdida, producto.id, producto.precio*resto, producto.stock);
            if(!flag){
                aux->cantidad+= producto.stock;
                aux->totalPerdida += producto.precio*resto;
            }
            flag = true;
        }
        fflush(productos);
        fscanf(pedidos, "%d;%d;%d\n", &pedido.fecha, &pedido.id, &pedido.cantidad);
    }
}

Nodo* insertarSinDuplicados(Nodo** lista, int dato){
    Nodo* nodo = buscar(*lista, dato);
    if(nodo == NULL){
        nodo = insertarOrdenado(lista, dato);
    }
    return nodo;
}

Nodo* buscar(Nodo* lista, int buscado){
    Nodo* listaAux = lista;
    while(listaAux != NULL && listaAux->dato != buscado){
        listaAux = listaAux->siguiente;
    }
    return listaAux;
}

Nodo* insertarOrdenado(Nodo** lista, int dato){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    Nodo* listaAux = *lista;
    Nodo* listaAnt = NULL;
    while(listaAux != NULL && dato < listaAux->dato){
        listaAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
    if(listaAnt == NULL){
        *lista = nodo;
    }else{
        listaAnt->siguiente = nodo;
    }
    nodo->siguiente = listaAux;
    return nodo;
}

void escribirArchivo()
