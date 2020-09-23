#include <stdio.h>
#include <stdlib.h>
/*
    Estrategia:
    Abrir los archivos de entrada
    Abrir los archivo de salida
    meter el archivo novedades en un vector
    Ordenar el vector de novedades por legajo
    Hacer el apareo entre archivo de alumnos y vector de novedades
        Por cada registro hacer la actualizacion correspondiente
    Cerrar archivos


*/
typedef struct{
    int legajo;
    char nombre[31];
    char domicilio[21];
    short CP;
    char telefono[11];
    short anioIngreso;
}Alumno;

typedef struct{
    Alumno alumno;
    char operacion;
}AlumnoNovedad;

FILE *abrir(const char*, const char*);
int cargarNovedades(AlumnoNovedad [], FILE*);
int escribir(Alumno, FILE *);
int leer(Alumno*, FILE *);
void ordenarXLegajo(AlumnoNovedad [], int cant);

int main(){

    Alumno alumno;
    FILE *alumnos = abrir("alumnos.dat", "rb");
    FILE *novedades = abrir("novedades.dat", "rb");
    FILE *actualizados = abrir("actualizados.dat", "wb");
    AlumnoNovedad novedadesVec[100];
    int cantNovedades = cargarNovedades(novedadesVec, novedades);
    fclose(novedades);
    ordenarXLegajo(novedadesVec, cantNovedades);
    leer(&alumno, alumnos);
    int i = 0;
    while(!feof(alumnos) && i < cantNovedades){
        if(alumno.legajo < novedadesVec[i].alumno.legajo){
            escribir(alumno, actualizados);
            leer(&alumno, alumnos);
        }else{
            if(alumno.legajo > novedadesVec[i].alumno.legajo){
                escribir(novedadesVec[i].alumno, actualizados);
                i++;
            }else{
                if(novedadesVec[i].operacion == 'M'){
                    escribir(novedadesVec[i].alumno, actualizados);
                }
                leer(&alumno, alumnos);
                i++;
            }
        }
    }
    while(!feof(alumnos)){
        escribir(alumno, actualizados);
        leer(&alumno, alumnos);
    }
    while(i < cantNovedades){
        escribir(novedadesVec[i].alumno, actualizados);
        i++;
    }

    fclose(alumnos);
    fclose(actualizados);
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

int cargarNovedades(AlumnoNovedad novedadesVec[], FILE *file){
    return fread(novedadesVec, sizeof(AlumnoNovedad), 100, file);
}

int leer(Alumno *registro, FILE *file){
    return fread(registro, sizeof(Alumno),1, file);
}

int escribir(Alumno registro, FILE *file){
    return fwrite(&registro, sizeof(Alumno), 1, file);
}
