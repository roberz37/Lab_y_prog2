#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Utilizando la función gets , leer de la entrada estándar dos líneas de longitud máxima 80
caracteres cada una. Se pide generar y devolver l a cadena que surge como producto de
la intersección de las palabras de ambas líneas. Ejemplo:
línea 1: El fútbol es un deporte que se juega con una pelota redonda.
línea 2: El rugby es un deporte que se juega con una pelota ovalada.
salida: El es un deporte que se juega con una pelota.*/

char *interseccionCadenas(char *, char *);

int main()
{
    char *cadenaUno =(char*)malloc(sizeof(char)*81);
    char *cadenaDos = (char*)malloc(sizeof(char)*81);
    char *cadenaResultante = (char*)malloc(sizeof(char)*81);
    printf("Ingrese please la cadena uno\n");
    gets(cadenaUno);
    printf("Ingrese please la cadena dos\n");
    gets(cadenaDos);
    cadenaResultante = interseccionCadenas(cadenaUno, cadenaDos);
    printf("La cadena resultante de la concatenacion es:\n%s", cadenaResultante);
    return 0;
}

char *interseccionCadenas(char *cadenaUno, char *cadenaDos){
    char *cadenaSalida = (char*)malloc(sizeof(char)*81);
    char *vector[80];
    int i = 0;
    while(*(cadenaUno + i) != '\0' && *(cadenaDos + i) != '\0'){
        palabraUno = NULL;
        palabraDos = NULL;
        while(*(cadenaUno + i) != '\0' && *(cadenaDos + i) != '\0' && *(cadenaUno + i) != ' ' && *(cadenaDos + i) != ' '){
            *(palabraUno + j) = *(cadenaUno + i);
            *(palabraDos + j) = *(cadenaDos + i);
            j++;
            i++;
        }
        *(palabraUno + j) = '\0';
        *(palabraDos + j) = '\0';
        if(strcmp(palabraUno,palabraDos) == 0){
            strcat(cadenaSalida, palabraUno);
            strcat(cadenaSalida, " ");
        }
        i++;
        j=0;
    }
    return cadenaSalida;
}
