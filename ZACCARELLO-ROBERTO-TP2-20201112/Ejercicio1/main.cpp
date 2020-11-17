#include <iostream>
#include "ejercicio1.h"

using namespace std;

int main()
{
    printf("Ejercicio 1\n\n");

    FILE* materia = abrirArchivo("materia.txt", "r");
    FILE* promedioMateria = abrirArchivo("promedioMateria.dat", "wb+");
    ST_NODO *listaMateria;
    crearLista(&listaMateria);
    ordenarPorLegajo(&listaMateria, materia);
    imprimirNotasPorMateria(listaMateria);
    escribirArchivo(promedioMateria, &listaMateria);
    imprimirPromedios(promedioMateria);
    borrarLista(&listaMateria);
    fclose(promedioMateria);
    fclose(materia);

    return 0;
}
