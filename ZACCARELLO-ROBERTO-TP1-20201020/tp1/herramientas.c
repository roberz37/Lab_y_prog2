#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"

FILE *abrir(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}
bool nombreValido(char* nombre){
    if (strlen(nombre) <= 15){
        return true;
    }
    return false;
}
bool mailValido(char* mail){
    int i=0, j=0;
    while (*(mail+i) != '\0'){
        if (*(mail+i) == '@'){
            j++;
        }
        i++;
    }
    if (i <= 15 && j == 1){
        return true;
    }
    return false;
}
bool passValido(char* password){
    int i=0, contador = 0;
    while (*(password+i) != '\0'){
        if (esAlfanumerico(*(password+i))){
           contador++;
        }
        i++;
    }
    return contador >= 8 && contador == i;
}
bool esAlfanumerico(char letra){
    if ((letra >= '0' && letra <= '9') || (letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')){
        return true;
    }
    return false;
}
int busquedaBinaria(FILE* archivo, char* email){
    ST_USUARIO usuario;
    int primero=0;
    fseek(archivo, 0, SEEK_END);
    int ultimo = (ftell(archivo)/sizeof(ST_USUARIO))-1;
    int medio = ultimo/2;
    while (primero <= ultimo){
        fseek(archivo, sizeof(ST_USUARIO)*medio, SEEK_SET);
        fread(&usuario, sizeof(usuario), 1, archivo);
        if (strcmp(email, usuario.email) == 0){
            return medio;
        } else if (strcmp(usuario.email, email) < 0){
            primero = medio + 1;
        } else {
            ultimo = medio - 1;
        }
        medio = (primero + ultimo)/2;
    }
    return -1;
}
bool verificarDatosNuevoUsuario(ST_USUARIO usuario, ST_USUARIO usuarios[], int tamano){
    if (!nombreValido(usuario.nombre) &&
        !mailValido(usuario.email) &&
        !passValido(usuario.password)){
            printf("Su email, nombre de usuario y/o contraseña no cumplen con los requisitos\n.");
            return false;
    }
    for (int i=0; i < tamano;i++){
        if (strcmp(usuario.email, usuarios[i].email) == 0 ||
            strcmp(usuario.nombre, usuarios[i].nombre) ==0){
                printf("El email y/o nombre de usuario ingresado ya existe.\n");
                return false;
        }
    }
    return true;
}
void imprimirBin (FILE* archivo){
    ST_USUARIO usuario;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuario, sizeof(ST_USUARIO), 1, archivo);
    while(!feof(archivo)){
        printf("%s;%s;%s\n", usuario.nombre, usuario.email, usuario.password);
        fread(&usuario, sizeof(ST_USUARIO), 1, archivo);
    }
}
void discardChars(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}
