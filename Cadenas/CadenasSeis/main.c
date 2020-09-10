#include <stdio.h>
#include <stdlib.h>

int contarPalabras(const char *);
void palabraMasLarga(const char *, char *);
int contarCaracteres(const char*);
void copiarCaracteres(const char *, char *);

int main(){
    printf("Ingerse una cadena. ");
    char cadena[81];
    char palabra[81];

    gets(cadena);

    printf("Se ingresaron %d palabras\n", contarPalabras(cadena));

    palabraMasLarga(cadena, palabra);
    printf("La palabra mas larga es %s tiene %d caracteres.\n", palabra, contarCaracteres(palabra));

    return 0;

}

int contarPalabras(const char *cadena){
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
}
