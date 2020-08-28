#include "circulo.h"

float perimetroCirculo(Circulo circulo){
    float perimetro = (2*circulo.radio) * 3.14;
    return perimetro;
}

float areaCirculo(Circulo circulo){
    float area = (circulo.radio*circulo.radio)*3.14;
    return area;
}
