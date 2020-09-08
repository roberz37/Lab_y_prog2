#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *formatearNumero(char*);

int main(){

    char *numero = (char*)malloc(sizeof(char)*81);
    //char *cambio = (char*)malloc(sizeof(char)*3);
    printf("Ingrese un numero\n");
    scanf("%s", numero);
    /*printf("Ingrese el tipo de cambio\n");
    scanf("%s", cambio);*/

    printf("Su cadena formatea es: %s\n", formatearNumero(numero));

    return 0;
}

char *formatearNumero(char *numero){
    char *aux = (char*)malloc(sizeof(char)*81);
    aux = numero;
    while(*numero != '\0'){
        if(*numero == ','){
            *numero = '.';
            numero++;
        }
        if(*numero == '.'){
            *numero = ',';
            numero++;
        }
        numero++;
    }
    *numero='\0';
    return aux;
}
    /*if(strcmp(cambio, "EN") == 0)´{
        while(numero){
            if(strcmp(numero, ",")==0){
                *aux = ".";
                aux++;
            }
            if(strcmp(numero, ".") == 0){
                *aux = ",";
                aux++;
            }
            *aux = *numero;
            aux++;
        }
    }*/
