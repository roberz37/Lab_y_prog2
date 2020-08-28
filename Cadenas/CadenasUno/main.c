#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int miStrlen(char * cadena)
{
    char*aux = cadena;
    int tamanio = 0;
    while(*aux != '\0')
    {
        tamanio++;
        aux++;
    }
    return tamanio;
}
bool esPalindromo(char * cadena)
{
    int tamanio = miStrlen(cadena);
    for(int i = 0; i < tamanio/2; i++)
    {
        if(*(cadena+i) != *(cadena+tamanio-1-i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char* ptrCadena = (char*) malloc(sizeof(char)*80);
    printf("Ingrese una palabra\n");
    scanf("%s", ptrCadena);

    printf("%d\n", miStrlen(ptrCadena));

    if(esPalindromo(ptrCadena))
    {
        printf("%s Es palindromo", ptrCadena);
    }
    else
    {
        printf("%s No es palindromo", ptrCadena);
    }
    return 0;
}
