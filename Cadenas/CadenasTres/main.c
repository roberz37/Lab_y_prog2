#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool esIp(char *ip);

int main()
{
    char ip[16] = "192.168.1.223";

    if(esIp(ip)){
        printf("El numero de ip: %s es valido.\n", ip);
    }else{
        printf("El numero de ip: %s no es valido.\n", ip);
    }
    return 0;
}

bool esIp(char *ip){
    int i = 0;
    int cantDigitos = 0;
    int cantSublotes = 0;
    while(*(ip + 1) != '\0'){
        cantDigitos = 0;
        while(*(ip+i) != '\0' && *(ip+i) != '.'){
            if(*(ip + i) >= 0 && *(ip +i) <= 9){
            cantDigitos++;
        }else{
            return false;
        }
        i++;
        }
        if(cantDigitos >= 4 || cantDigitos == 0){
            return false;
        }
        cantSublotes++;
    }
    return cantSublotes == 4;
}
