#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool esPalindromo(char*);

int main(){

    char *cadena = (char*)malloc(sizeof(char)*81);

    printf("Ingrese una cadena palindroma o no\n");
    scanf("%s", cadena);

    if(esPalindromo(cadena)){
        printf("%s, es palindromo\n", cadena);
    }
    else{
        printf("%s, no es palindromo\n", cadena);
    }

    return 0;
}

bool esPalindromo(char *cadena){
    int tamanio= strlen(cadena);
    for(int i = 0; i<tamanio/2;i++){
        if(*(cadena+i) != *(cadena+tamanio-1-i)){
            return false;
        }
    }
    return true;
}
