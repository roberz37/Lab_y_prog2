#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool esIp(char *ip);

int main()
{
    char *ip = (char*) malloc(sizeof(char)*16);
    strcpy(ip, "211.231.3.514");

    if(esIp(ip) == true){
        printf("El numero de ip: %s es valido.\n", ip);
    }else{
        printf("El numero de ip: %s no es valido.\n", ip);
    }
    return 0;
}

bool esIp(char *ip){
    int i = 0;
    int digitos =0;
    int lotes = 0;
    while(*(ip + i) != '\0'){
        digitos = 0;
        while(*(ip + i) != '\0' && *(ip + i) != '.'){
            if(*(ip + i) >= '0' && *(ip + i) <= '9'){
                digitos++;
            }else{
                return false;
            }
            i++;
        }
        if(digitos>= 4 || digitos == 0){
            return false;
        }
        lotes++;
        i++;
    }
    return lotes == 4;
}
