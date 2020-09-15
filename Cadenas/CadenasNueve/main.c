#include <stdio.h>
#include <stdlib.h>
/*Utilizando sintaxis de punteros, desarrollar la función comienzaEn que reciba dos
cadenas de caracteres, cuya longitud máxima será de 80 caracteres, y devuelva la
primer posición de la primer cadena donde comienza la segunda cadena. Ejemplo:
Entrada: “Hola mundo…mundo”, “mundo” → 5
Entrada: “Hola mundo…mundo”, “ola” → 1
Entrada: “Hola mundo…mundo”, “chau” → -1*/

int comienzaEn(char *, char *);

int main()
{
    char *cadenaUno = (char *)malloc(sizeof(char)*81);
    char *cadenaDos = (char *)malloc(sizeof(char)*81);
    printf("Ingrese la primer cadena\n");
    gets(cadenaUno);
    printf("Ingrese la palabra que desea buscar\n");
    scanf("%s", cadenaDos);

    printf("la palabra que buscas se encuentra: %d\n", comienzaEn(cadenaUno, cadenaDos));
    return 0;
}
hola mundo que tal
int comienzaEn(char *cadenaUno, char *cadenaDos){
    int i = 0;
    int j = 0;
    while(*(cadenaUno + i) != '\0'){
        if(*(cadenaDos + j) == *(cadenaUno + i)){
            cont++;
        }
    }
}
