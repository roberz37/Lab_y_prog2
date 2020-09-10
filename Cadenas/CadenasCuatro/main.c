#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formatearNumero(char*, char*);

int main(){

    char *numero = (char*)malloc(sizeof(char)*81);
    char *cambio = (char*)malloc(sizeof(char)*3);
    printf("Ingrese un numero\n");
    scanf("%s", numero);
    printf("Ingrese el tipo de cambio\n");
    scanf("%s", cambio);
    formatearNumero(numero, cambio);
    printf("Su cadena formatea es: %s\n", numero);

    return 0;
}

void formatearNumero(char *numero, char *cambio){
    int i = 0;
    int ultimo = 0;
    while(*(numero + i) != '\0'){
        if(*(numero + i)== ',' || *(numero + i)== '.'){
            ultimo = i;
            i++;
        }
        i++;
    }
    i = 0;
    if(strcmp(cambio, "AR") == 0 && *(numero + ultimo) != ','){
        while(*(numero + i) != '\0'){
            if(*(numero + i)== ','){
                *(numero + i)= '.';
                i++;
            }
            if(*(numero + i)== '.'){
                *(numero + i)= ',';
                i++;
            }
            i++;
        }
        *(numero + i)='\0';
    }
    if(strcmp(cambio, "EN") == 0 && *(numero + ultimo) != '.'){
           while(*(numero + i) != '\0'){
            if(*(numero + i)== ','){
                *(numero + i)= '.';
                i++;
            }
            if(*(numero + i)== '.'){
                *(numero + i)= ',';
                i++;
            }
            i++;
        }
        *(numero + i)='\0';
    }
}
