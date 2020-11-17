#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"
#include "ejercicioUno.h"
#include "ejercicioDos.h"
#include "ejercicioTres.h"
#include "ejercicioCuatro.h"

int main()
{
    FILE *fileEntrada = abrir("users.txt", "r");
    FILE *fileUsuarios = abrir("users.dat", "wb+");
    FILE *fileRejected = abrir("rejected.txt", "w");
    FILE *filePedidosTXT = abrir("pedidos.txt", "w+");
    FILE *filePedidosDAT = abrir("pedidos.dat", "rb");

    printf("Generando archivo de usuarios.\n\n");
    generarArchivosUsuarios(fileUsuarios, fileRejected, fileEntrada);//Ejercicio 1
    imprimirBin(fileUsuarios);
    printf("\nLogin usuario.\n\n");
    login(fileUsuarios);//Ejercicio 2
    printf("\nAgregando 2 usuarios.\n\n");
    agregarUsuario(fileUsuarios);//ejercicio 3
    discardChars();
    agregarUsuario(fileUsuarios);
    imprimirBin(fileUsuarios);
    printf("\nGenerando archivos de pedidos.\n");
    generarArchivoPedidos(filePedidosTXT, filePedidosDAT, fileUsuarios);//Ejercicio4

    fclose(fileEntrada);
    fclose(fileUsuarios);
    fclose(fileRejected);
    fclose(filePedidosDAT);
    fclose(filePedidosTXT);
    return 0;
}













