#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "herramientas.h"
#include "ejercicioUno.h"

void generarArchivosUsuarios(FILE* usuarios, FILE* rejected, FILE* entrada){
    ST_USUARIO usuario;
    char auxiliar[76];
    char nombreAux[26];
    char emailAux[26];
    char passwordAux[26];

    while (fgets(auxiliar, 76, entrada) != NULL){
        strcpy(nombreAux, strtok (auxiliar,";"));
        strcpy(emailAux, strtok (NULL, ";"));
        strcpy(passwordAux, strtok (NULL, "\n"));
        if (nombreValido(nombreAux) && mailValido(emailAux) && passValido(passwordAux)){
            strcpy(usuario.nombre, nombreAux);
            strcpy(usuario.email, emailAux);
            strcpy(usuario.password, passwordAux);
            fwrite(&usuario, sizeof(ST_USUARIO), 1, usuarios);
        } else {
            fprintf(rejected, "%s\t%s\t%s\n", nombreAux, emailAux, passwordAux);
        }
    }
}


