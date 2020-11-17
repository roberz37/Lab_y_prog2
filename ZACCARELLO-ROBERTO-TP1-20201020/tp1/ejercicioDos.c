#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"
#include "ejercicioDos.h"

ST_USUARIO getUser (FILE* archivo){
    ST_USUARIO usuario;
    char password[16];
    int indice;
    printf("Ingrese su email\n");
    gets(usuario.email);
    printf("Ingrese la contraseña\n");
    gets(password);
    indice = busquedaBinaria(archivo, usuario.email);
    fseek(archivo, sizeof(usuario)*indice, SEEK_SET);
    if (indice == -1){
        strcpy(usuario.nombre, "");
        strcpy(usuario.email, "");
        strcpy(usuario.password, "");
        return usuario;
    } else {
        fread(&usuario, sizeof(usuario), 1, archivo);
        if (strcmp(password, usuario.password)!=0){
            strcpy(usuario.nombre, "");
            strcpy(usuario.email, "");
            strcpy(usuario.password, "");
        }


    }
    return usuario;
}
void login(FILE* fileUsuarios){
    ST_USUARIO usuario = getUser(fileUsuarios);
    if (strcmp(usuario.nombre, "") != 0){
        printf("Nombre: %s, Email: %s, Contraseña: %s\n\n", usuario.nombre, usuario.email, usuario.password);
    } else {
        printf("Email y/o contraseña invalidos\n");
    }
}
