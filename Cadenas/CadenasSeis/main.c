#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *palabraMasLarga(char *);
void miStrcpy(char *, char *);
int contarPalabras(char *);
int contarLetras(char *);
/*int contarPalabras(const char *);
void palabraMasLarga(const char *, char *);
int contarCaracteres(const char*);
void copiarCaracteres(const char *, char *);
/*Utilizando l a función gets, leer de la entrada estándar una línea de longitud máxima 80
caracteres. Utilizando sólo sintaxis de punteros determinar:
b) ¿Cuál es la palabra de longitud máxima y cuántos caracteres posee?
c) Repita el punto a) y b) utilizando la funciones strtok y strlen*/
int main(){
    /*printf("Ingerse una cadena. ");
    char cadena[81];
    char palabra[81];
    gets(cadena);
    printf("Se ingresaron %d palabras\n", contarPalabras(cadena));
    palabraMasLarga(cadena, palabra);
    printf("La palabra mas larga es %s tiene %d caracteres.\n", palabra, contarCaracteres(palabra));*/

    char *cadena = (char*) malloc(sizeof(char)*81);
    char *palabra = (char*) malloc(sizeof(char)*81);
    printf("Ingrese una cadena de longitud maxima 80 caracteres con espacios o no\n");
    gets(cadena);
    printf("Se ingresaron %d palabras\n", contarPalabras(cadena));
    palabra = palabraMasLarga(cadena);
    printf("La palabra mas larga es: %s y tiene %d caracteres\n", palabra, contarLetras(palabra));
    return 0;
}

int contarPalabras(char *cadena){
    char *aux = cadena;
    int contador = 0;
    while(*aux != '\0'){
        if(*aux == ' ' && *(aux + 1) != ' ' && *(aux + 1)!= '\0'){
            contador++;
        }
        aux++;
    }
    contador ++;
    return contador;
}

int contarLetras(char *cadena){
    int i=0;
    while(*(cadena +i) != '\0'){
        i++;
    }
    return i;
}

char *palabraMasLarga(char *cadena){
    char *aux = (char*)malloc(sizeof(char)*81);
    int i = 0;
    int caracteres = 0;
    char *palabraMasLarga = (char*)malloc(sizeof(char)*81);
    int max = 0;
    while(*(cadena + i) != '\0'){
        caracteres = 0;
        while(*(cadena + i) != '\0' && *(cadena + i) != ' '){
            *(aux + caracteres)= *(cadena + i);
            caracteres++;
            i++;
        }
        *(aux + caracteres) = '\0';
        if(caracteres > max){
            miStrcpy(palabraMasLarga, aux);
            max = caracteres;
        }
        if(*(cadena + i) == ' '){
            i++;
        }
    }
    return palabraMasLarga;
}

void miStrcpy(char *cadena, char *cadenaDos){
    int i = 0;
    while(*(cadenaDos + i) != '\0'){
        *(cadena + i) = *(cadenaDos + i);
        i++;
    }
    *(cadena + i) = '\0';
}


/*int contarPalabras(const char *cadena){
    int i = 0;
    int palabras = 0;
    while(*(cadena +i) != '\0'){
        while(*(cadena +i) != '\0' && *(cadena +i) != ' '){
            i++;
        }
        palabras++;
        if(*(cadena + i) == ' '){
            i++;
        }
    }
    return palabras;
}

void palabraMasLarga(const char *cadena, char *palabra){
    int i = 0;
    int caracteres = 0;
    char aux[81];
    int max = 0;
    while(*(cadena +i) != '\0'){
        caracteres = 0;
        while(*(cadena+i) != '\0' && *(cadena +i) != ' '){
            *(aux + caracteres) = *(cadena +i);
            caracteres++;
            i++;
        }
        *(aux + caracteres) = '\0';
        if(caracteres > max){
            max = caracteres;
            copiarCaracteres(aux, palabra);
        }
        if(*(cadena +i) == ' '){
            i++;
        }
    }
    return;
}

int contarCaracteres(const char *cadena){
    int i = 0;
    while(*(cadena +i) != '\0'){
        i++;
    }
    return i;
}

void copiarCaracteres(const char *source, char *dest){
    int i = 0;
    while(*(source +i) != '\0'){
        *(dest +i) = *(source +i);
        i++;
    }
    *(dest +i) = '\0';
}*/
