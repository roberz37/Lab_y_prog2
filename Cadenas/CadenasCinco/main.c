#include <stdio.h>
#include <stdlib.h>

void invertirCadena(char *);
int miStrlen(char *);

int main()
{
    char *cadena = (char*)malloc(sizeof(char)*81);
    printf("Ingrese una cadena\n");
    scanf("%s", cadena);
    invertirCadena(cadena);
    printf("La cadena invertida es: %s\n", cadena);
    return 0;
}

void invertirCadena(char *cadena){
    int tamanio = miStrlen(cadena);
    char aux;
    for(int i = 0; i < tamanio/2; i++){
        aux = *(cadena + i);
        *(cadena + i) = *(cadena + tamanio - i - 1);
        *(cadena + tamanio - i - 1) = aux;
    }
    *(cadena + tamanio) = '\0';
}

int miStrlen(char *cadena){
    char *aux = cadena;
    int i = 0;
    while(*aux != '\0'){
        i++;
        aux++;
    }
    return i;
}
