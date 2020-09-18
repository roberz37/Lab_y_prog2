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
Usuario login(char*, char*, FILE*);
int busquedaBinaria(char *, FILE *);

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
    printf("Ingrese su email\n");
    scanf("%s", email);
    usuario = login(email, contrasenia, fileUserBin);
    if(strcmp(usuario.nombreUsuario, "")==0){
        printf("No encontro el usuario brou\n");
    }else{
        printf("Email y contraseña validos");
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

Usuario login(char *email, char *contrasenia, FILE *archivoBin){
    Usuario usuario;
    int pos = busquedaBinaria(email, archivoBin);
    if(pos < 0){
        strcpy(usuario.nombreUsuario, "");
        strcpy(usuario.email, "");
        strcpy(usuario.contrasenia, "");
        return usuario;
    }else{
        fseek(archivoBin, pos*sizeof(Usuario), SEEK_SET);
        fread(&usuario, sizeof(Usuario), 1, archivoBin);
        return usuario;
    }
}

 int busquedaBinaria(char *email, FILE *archivoBin){

    Usuario usuario;
    long primero=0;
    fseek(archivoBin,0,SEEK_END);
    long ultimo=ftell(archivoBin);
    long medio=(primero+ultimo)/(sizeof(Usuario)*2);
    ultimo = ultimo/sizeof(Usuario);

    while (primero<=ultimo){
        fseek(archivoBin, sizeof(Usuario)*medio, SEEK_SET);
        fread(&usuario,sizeof(Usuario),1, archivoBin);

        if (strcmp(usuario.email, email) < 0) {
            primero=medio+1;

        } else if (strcmp(usuario.email, email) == 0){
            return medio;
        }
        else {
            ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;
    }
    return -1;
 }
