#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
typedef struct{
    int base;
    float altura;
}Triangulo;

float areaTriangulo(Triangulo);
int perimetroTriangulo(Triangulo);

#endif // TRIANGULO_H_INCLUDED
