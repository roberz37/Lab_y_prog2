#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"
#include "ejercicioTres.h"


ST_USUARIO cargarDatosUsuario(){
    ST_USUARIO usuario;
    printf("Ingrese el nombre del usuario\n");
    gets(usuario.nombre);
    while(!nombreValido(usuario.nombre)){
        printf("El nombre de usuario no es valido. Por favor ingrese otro.\n");
        gets(usuario.nombre);
    }
    printf("Ingrese el mail.\n");
    scanf("%s",usuario.email);
    while(!mailValido(usuario.email)){
        printf("El nombre de usuario no es valido. Por favor ingrese otro.\n");
        scanf("%s",usuario.email);
    }
    printf("Ingrese la contraseña.\n");
    scanf("%s",usuario.password);
    while(!passValido(usuario.password)){
        printf("La contraseña no es valida. Por favor ingrese otra.\n");
        scanf("%s",usuario.password);
    }
    return usuario;
}
void agregarUsuario(FILE *archivo){
    ST_USUARIO usuarioFile;
    ST_USUARIO usuario = cargarDatosUsuario();
    ST_USUARIO usuarioAux;
    int flag = 0;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuarioFile, sizeof(ST_USUARIO), 1, archivo);
    while (!feof(archivo)){
        if (strcmp(usuarioFile.nombre, usuario.nombre) == 0 ||
            strcmp(usuarioFile.email, usuario.email)== 0){
                printf("El email y/o el nombre de usuario ya existen.\n\n");
                return;
        }

        fread(&usuarioFile, sizeof(ST_USUARIO), 1, archivo);
    }

    //insertando el nuevo usuario en su lugar correspondiente.
    //En linux el codigo me funciona bien, le agrege 2 fflush (comentados) porque en
    //windows son necesarios.

    fseek(archivo, 0, SEEK_SET);
    fread(&usuarioFile, sizeof(ST_USUARIO), 1, archivo);
        while (!feof(archivo)){
            if (flag == 1){
                fseek(archivo, sizeof(ST_USUARIO)*-1, SEEK_CUR);
                fwrite(&usuarioAux, sizeof(ST_USUARIO), 1, archivo);
                //fflush(archivo);
                usuarioAux = usuarioFile;
            }
            if (strcmp(usuarioFile.email, usuario.email) > 0 && flag == 0){
                usuarioAux = usuarioFile;
                fseek(archivo, sizeof(ST_USUARIO)*-1, SEEK_CUR);
                fwrite(&usuario, sizeof(ST_USUARIO), 1, archivo);
                //fflush(archivo);
                flag = 1;
            }
            fread(&usuarioFile, sizeof(ST_USUARIO), 1, archivo);
        }
        if (flag == 0){
            fwrite(&usuario, sizeof(ST_USUARIO), 1, archivo);
        } else {
            fwrite(&usuarioAux, sizeof(ST_USUARIO), 1, archivo);
        }
}

