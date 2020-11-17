#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"
#include "ejercicioTres.h"

void generarArchivoPedidos(FILE *fileTxt, FILE *fileBin, FILE *fileUsersBin){
    ST_PEDIDOSDAT pedidoDat;
    ST_PEDIDOSTXT pedidoTxt;
    int indice = 0;
    ST_USUARIO usuario;
    fseek(fileBin, 0, SEEK_SET);
    fread(&pedidoDat, sizeof(ST_PEDIDOSDAT), 1, fileBin);
    fprintf(fileTxt, "Email\t\tNombre\t\t\tCantidad\tTotal\n");
    printf("Email\t\tNombre\t\tCantidad\tTotal\n");
    while(!feof(fileBin)){
        pedidoTxt.cantidadDeProductos = 0;
        pedidoTxt.totalFacturable = 0;
        strcpy(pedidoTxt.email, pedidoDat.email);
        indice = busquedaBinaria(fileUsersBin, pedidoDat.email);
        fseek(fileUsersBin,sizeof(ST_USUARIO)* indice, SEEK_SET);
        fread(&usuario, sizeof(ST_USUARIO), 1, fileUsersBin);
        strcpy(pedidoTxt.nombreUsuario, usuario.nombre);

        while(!feof(fileBin) && strcmp(pedidoDat.email,pedidoTxt.email) == 0){
            pedidoTxt.cantidadDeProductos += pedidoDat.cantidadSolicitada;
            pedidoTxt.totalFacturable+= (pedidoDat.valorUnitario * pedidoDat.cantidadSolicitada);
            fread(&pedidoDat, sizeof(ST_PEDIDOSDAT), 1, fileBin);
        }
        printf(          "%s\t%s\t\t%d\t\t%0.2f\n", pedidoTxt.email, pedidoTxt.nombreUsuario, pedidoTxt.cantidadDeProductos, pedidoTxt.totalFacturable);
        fprintf(fileTxt, "%s\t%s\t\t\t%d\t%0.2f\n", pedidoTxt.email, pedidoTxt.nombreUsuario, pedidoTxt.cantidadDeProductos, pedidoTxt.totalFacturable);
    }
    return;
}
