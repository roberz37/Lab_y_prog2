#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    char nombreUsuario[16];
    char email[16];
    char contrasenia[9];
}Usuario;

FILE *abrir(const char*, const char*);
bool nombreValido(char*);
bool emailValido(char*);
bool contraseniaValida(char*);
bool esAlfanumerico(char);
Usuario login(char*, char*);


int main(){

    Usuario usuario;
    char nombre[26];
    char email[26];
    char contrasenia[26];
    FILE *fileUsersTxt = abrir("users.txt", "r");
    FILE *fileUserBin = abrir("users.dat", "wb");
    FILE *fileRejectedTxt = abrir("rejected.txt", "w");

    while(fscanf(fileUsersTxt,"%s;%s;%s", nombre,email, contrasenia ) != EOF){
        if(nombreValido(nombre) && emailValido(email) && contraseniaValida(contrasenia)){
            strcpy(usuario.nombreUsuario,nombre);
            strcpy(usuario.email, email);
            strcpy(usuario.contrasenia, contrasenia);
            fwrite(&usuario, sizeof(Usuario), 1, fileUserBin);
        }else{
            fprintf(fileRejectedTxt, "%s;%s;%s", nombre, email, contrasenia);
        }
    }
    fclose(fileUsersTxt);
    fclose(fileUserBin);
    fclose(fileRejectedTxt);
    return 0;
}

FILE *abrir(const char *fileName, const char *modo){
    FILE *file = fopen(fileName, modo);
    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }
    return file;
}

bool nombreValido(char *nombre){
    int i = 0;
    while(*(nombre + i) != '\0'){
        i++;
    }
    return i <= 16;
}

bool emailValido(char *email){
    int i = 0;
    int arrobas = 0;
    while(*(email + i) != '\0'){
        if(*(email + i) == '@'){
            arrobas++;
        }
        i++;
    }
    return i <= 16 && arrobas == 1;
}

bool contraseniaValida(char *contrasenia){
    int i=0;
    int contador = 0;
    while(*(contrasenia + i) != '\0'){
        if(esAlfanumerico(*(contrasenia +i))){
            contador++;
        }
        i++;
    }
    return i>=9 && i == contador;
}

bool esAlfanumerico(char letra){
    return letra >= '0' && letra <= '9' && letra >= 'a' && letra <= 'z';
}

Usuario login(char *email, char *contrasenia){

}




