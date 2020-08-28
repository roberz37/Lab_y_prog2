#include <stdio.h>
#include <stdlib.h>
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"
/*Realizar un programa que presente un menu al usuario con las siguientes figuras geométricas:
* Cuadrado
* Circulo
* Triángulo (equilatero)
* Pentágono
* Esfera
* Cilindro

Según la opción ingresada solicitar al usuario los datos necesarios para calcular el área,
 perímetro y volumen según corresponda
Realizar el programa utilizando funciones y construir los TAD que considere necesarios
* Realizar la lectura y escritura por consola utilizando nuestros nuevos amigos printf y scanf en lugar de cin y cout
*/
int main(){

    int opciones;
    Cuadrado cuadrado;
    Circulo circulo;
    Triangulo triangulo;
    /*Pentagono pentagono;
    Esfera esfera;
    Cilindro cilindro;*/

    printf("Ingrese la opcion deseada\n1) Cuadrado\n2) Circulo\n3)triangulo equilatero\n4) pentagono\n5) esfera\n6) cilindro\n7)salir\n");
    scanf("%d", &opciones);
    switch(opciones){
        case 1:
            printf("Ingrese el lado del cuadrado\n");
            scanf("%d", &cuadrado.lado);
            printf("El perimetro del cuadrado es: %d, y su area: %d\n", perimetroCuadrado(cuadrado), areaCuadrado(cuadrado));
            break;
        case 2:
            printf("Ingrese el radio del circulo\n");
            scanf("%f", &circulo.radio);
            printf("El perimetro del circulo es: %f, y su area: %f\n", perimetroCirculo(circulo), areaCirculo(circulo));
            break;
        case 3:
            printf("Ingrese la base del triangulo equilatero\n");
            scanf("%d", &triangulo.base);
            printf("Ingrese la altura del triangulo equilatero\n");
            scanf("%f", &triangulo.altura);
            printf("El perimetro del cuadrado es: %d, y su area: %f", perimetroTriangulo(triangulo), areaTriangulo(triangulo));
            break;
        case 4:

            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
    }
    return 0;
}
