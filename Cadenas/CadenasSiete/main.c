#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *concatenarCadena(char *);
bool esConsonante(char);
bool esVocal(char);

int main()
{
    char *cadena = (char *)malloc(sizeof(char)*81);
    char *cadenaConcatenada = (char*) malloc(sizeof(char)*81);
    printf("Ingrese una cadena\n");
    gets(cadena);
    cadenaConcatenada = concatenarCadena(cadena);
    printf("La cadena concatenada es: %s\n", cadenaConcatenada);
    return 0;
}

bool esConsonante(char caracter){
    if(caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u'){
        return true;
    }
    return false;
}

bool esVocal(char caracter){
    if(!esConsonante(caracter)){
        return true;
    }
    return false;
}

char *concatenarCadena(char *cadena){
    int i=0;
    int j=0;
    char *cadenaFormateada = (char *)malloc(sizeof(char)*81);
    while(*(cadena + i) != '\0'){
        if(*(cadena + i) == ' ' && esConsonante(*(cadena + i - 1)) && esVocal(*(cadena + i + 1))){
            i++;
        }
        *(cadenaFormateada + j) = *(cadena + i);
        i++;
        j++;
    }
    *(cadenaFormateada + j) = '\0';
    return cadenaFormateada;
}

