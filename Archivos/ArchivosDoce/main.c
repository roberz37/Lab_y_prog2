#include <stdio.h>
#include <stdlib.h>

/*Dado un archivo binario de productos que contiene 100 registros, y cada registro corresponde a
un producto que est� codificado del 1 a 100, ordenado por c�digo de producto
con el siguiente dise�o:

c�digo de producto (1..100, char) stock (int)

y otro archivo binario de pedidos, con el siguiente dise�o:

N�mero de pedido(int) n�mero de cliente (long)
C�digo de producto (1..100, char) cantidad pedida (int)

Se pide desarrollar un algoritmo que:
a) grabar un archivo de texto con los pedidos que fueron satisfechos en su totalidad seg�n el
siguiente listado:

Pedidos Satisfechos
N�mero de pedido N�mero de Cliente C�digo de Producto Cantidad pedida
9999             999999            999                9999
9999             999999            999                9999

actualizar el campo stock del archivo de producto, cada vez que acepte un pedido.
c) grabar un archivo binario con el mismo dise�o que el archivo de pedidos, con aquellos pedidos
que no pueden ser satisfechos en su totalidad.*/

typedef struct{
    char codProd;
    int stock;
}Productos;

typedef struct{
    int numPedido;
    long numCliente;
    char codProd;
    int cantPedida;
}Pedidos;

typedef struct{
    int numPedido;
    long numCliente;
    char codProd;
    int cantPedida;
}PedidosOk;

int main(){

    FILE *productos = abrir("productos.dat", "rb");
    FILE *pedidos = abrir("pedidos.dat", "rb");
    FILE *pedidosOk = abrir("pedidosOk.dat", "w");
    FILE *rejected = abrir("rejected.txt", "wb");
    Productos producto;
    Pedidos pedido;
    PedidosOk pedidoOk;
    fread(&pedido, sizeof(Pedidos), 1, pedidos);
    fprintf("PEDIDOS SATISFECHOS\n")
    while(!feof(pedidos)){
        fseek(productos, sizeof(Producto)* pedido.codProd, SEEK_SET);
        fread(&producto, sizeof(Producto), 1, productos);
        if((pedido.cantPedida - producto.stock) > 0){
            pedidoOk.cantPedida = pedido.cantPedida;
            pedidoOk.codProd = pedido.codProd;
            pedidoOk.numCliente = pedido.numCliente;
            pedidoOk.numPedido = pedido.numPedido;
            fprintf(asd, "%d%d")

        }

    }
    return 0;
}
