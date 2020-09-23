#include <stdio.h>
#include <stdlib.h>
#define MAX_aLTAS 20
#include <string.h>
/*
    Estrategia
    Abrir archivos
    Crear vector de altas con 20 registros, cada registro tiene codigo y posicion en el archivo
    Mientras novedades no se termine
        Si es alta, se guarda en el vector(codigo y posicion en el archivo)
        Si es modificacion:
            Buscamos la posicion (busqueda binaria) con el codigo de producto
            Pisamos el registro en el archivo con los datos del producto
        Si es baja:
            Buscamos la posicion(Busqueda binaria) con el codigo de producto
            Lo marcamos como inactivo(campo estado)
    Fin mientras

    Ordenar el vecto de altas por codigo
    Buscamos el final del archivo Productos
    Recorremos el vector de altas
        Por cada posicion buscamos el registro en Novedades con el campo posicion del alta
        Escribimos el registro del producto de Novedades
    Cerrar archivos

*/

typedef struct{
    char codigo[9];
    char descripcion[31];
    short cantidad;
    float precio;
    char estado;
}Producto;

typedef struct{
    Producto producto;
    char operacion;
}Novedad;

typedef struct{
    char codigo[9];
    char posicion;
}Alta;

int main()
{
    FILE *productos = abrir("productos.dat", "ab+");
    FILE *novedades = abrir("novedades.dat", "rb");
    Alta altas[MAX_ALTAS];
    cantAltas = 0;
    Novedad novedad;
    leer(&novedad, novedades);
    while(!feof(novedades)){
        if(novedad.operacion == 'A'){
            strcpy(altas[cantAltas].codigo, novedad.producto.codigo);
            altas[cantAltas].posicion = cantAltas;
        }
        leer(&novedad, novedades);
    }

    return 0;
}
