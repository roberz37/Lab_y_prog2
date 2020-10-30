#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char titulo[31];
    char cantidad;
    char ubicacion[4];
    short codEditorial;
    char autor[26];
}Libro;

typedef struct{
    short
}Editorial;

typedef struct{

}Consulta;

int main(){
    FILE *libros = abrir("libros.dat", "rb");
    FILE *editoriales = abrir("editoriales.dat", "rb");
    FILE *consultas = abrir("consultas.dat", "rb");
    FILE *porcentajes = abrir("procentajesConsultas.dat", "wb");

    int codigos[MAX_LIBRO_CONSULTA];
    short consultasXLibro[MAX_LIBRO_CONSULTA][CANT_MESES];
    int cantCodigos = 0;

    cargarCodigosConsultas(consultas, codigos, &cantCodigos);

    cargarConsultasMensuales(consultas, consultasXLibro);

    imprimir(codigos, consultasXLibro, libros, cantCodigos);

    return 0;
}
