#include "triangulo.h"

float areaTriangulo(Triangulo triangulo){
    return (triangulo.base*triangulo.altura)/2;
}

int perimetroTriangulo(Triangulo triangulo){
    return triangulo.base*3;
}
