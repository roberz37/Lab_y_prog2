#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>

typedef struct{
    char nombreUsuario[16];
    char email[16];
    char contrasenia[20];
}Usuario;

FILE *abrir(const char*, const char*);
bool nombreValido(char*);
bool emailValido(char*);
bool contraseniaValida(char*);
bool esAlfanumerico(char);
Usuario login(char*, char*, FILE*);
int busquedaBinaria(char *, FILE *);
void discardChars();

int main(){

    Usuario usuario;
    char nombre[26];
    char email[26];
    char contrasenia[26];
    FILE *fileUsersTxt = abrir("users.txt", "r");
    FILE *fileUserBin = abrir("users.dat", "wb+");
    FILE *fileRejectedTxt = abrir("rejected.txt", "w");
    while(fscanf(fileUsersTxt,"%s\t%s\t%s\n", nombre,email, contrasenia ) != EOF){
        if(nombreValido(nombre) && emailValido(email) && contraseniaValida(contrasenia)){
            strcpy(usuario.nombreUsuario,nombre);
            strcpy(usuario.email, email);
            strcpy(usuario.contrasenia, contrasenia);
            fwrite(&usuario, sizeof(Usuario), 1, fileUserBin);
        }else{
            fprintf(fileRejectedTxt, "%-26s\t%-26s\t%-26s\r\n", nombre, email, contrasenia);
        }
    }
    fseek(fileUserBin, 0, SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, fileUserBin);
    while(!feof(fileUserBin)){
        printf("%s;%s;%s\n", usuario.nombreUsuario, usuario.email, usuario.contrasenia);
        fread(&usuario, sizeof(Usuario), 1, fileUserBin);
    }
    printf("Ingrese su email\n");
    gets(email);
    printf("Ingrese una contrasenia\n");
    gets(contrasenia);
    usuario = login(email, contrasenia, fileUserBin);
    if(strcmp(usuario.nombreUsuario, "")==0){
        printf("Usuario y/o contrasenia invalidos\n");
    }else{
        printf("Email y contrasenia validos\nNombre: %s\nContrasenia: %s\nEmail: %s", usuario.nombreUsuario, usuario.contrasenia, usuario.email);
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
    return i <= 15;
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
    return i <= 15 && arrobas == 1;
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
    return i>=8 && i == contador;
}

bool esAlfanumerico(char letra){
    char alfanumericos[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'
    ,'s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S',
    'T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < 62; i++){
        if(letra == alfanumericos[i]){
            return true;
        }
    }
    return false;
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
        if(strcmp(usuario.contrasenia,contrasenia) == 0){
            return usuario;
        }else{
            strcpy(usuario.nombreUsuario, "");
            strcpy(usuario.email, "");
            strcpy(usuario.contrasenia, "");
            return usuario;
        }
    }
}

 int busquedaBinaria(char *email, FILE *archivoBin){

    Usuario usuario;
    int primero=0;
    fseek(archivoBin,0,SEEK_END);
    int ultimo = ftell(archivoBin)/sizeof(Usuario);
    int medio = (primero+ultimo)/2;

    while (primero<=ultimo){
        fseek(archivoBin, sizeof(Usuario)*medio, SEEK_SET);
        fread(&usuario,sizeof(Usuario),1, archivoBin);
        if(strcmp(usuario.email, email) < 0){
            primero = medio+1;
        }else if (strcmp(usuario.email, email) == 0){
            return medio;
        }
        else{
            ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;
    }
    return -1;
 }

 void discardChars(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    return;
 }
