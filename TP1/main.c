#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char nombreUsuario[16];
    char email[16];
    char contrasenia[20];
}Usuario;

typedef struct{
    char email[16];
    int idProd;
    float valorUnitario;
    short cantSolicitada;
}PedidosDat;

typedef struct{
    char email[16];
    char nombre[16];
    short cantProductos;
    float total;
}PedidosTxt;

FILE *abrir(const char*, const char*);
void escribirArchivos(FILE*, FILE*, FILE*);
void imprimirArchivo(FILE*);
bool nombreValido(char*);
bool emailValido(char*);
bool contraseniaValida(char*);
bool esAlfanumerico(char);
Usuario login(FILE*);
void checkearLogin(Usuario);
int busquedaBinaria(char *, FILE *);
void agregarUsuario(FILE*);
void insertarUsuario(Usuario,FILE *);
int busquedaBinariaNombre(char *, FILE *);
void discardChars();
void generarArchivo(FILE* , FILE*, FILE*);
void imprimirPedidos(FILE*);

int main(){

    FILE *fileUsersTxt = abrir("users.txt", "r");
    FILE *fileRejectedTxt = abrir("rejected.txt", "w");
    FILE *fileUsersBin = abrir("users.dat", "wb+");
    FILE *fileOrdersBin = abrir("pedidos.dat", "rb");
    FILE *fileOrdersTxt = abrir("pedidos.txt", "w+");
    Usuario usuario;
    printf("PUNTO 1:\n");
    printf("Generando archivos users.dat y rejected.txt\n\n");
    escribirArchivos(fileUsersTxt, fileUsersBin, fileRejectedTxt);
    printf("Imprimo el archivo users.dat\n\n");
    imprimirArchivo(fileUsersBin);
    system("PAUSE");
    printf("\nPUNTO 2:\n");
    printf("Validacion de credenciales\n\n");
    usuario = login(fileUsersBin);
    checkearLogin(usuario);
    system("PAUSE");
    printf("\nPUNTO 3:\n");
    printf("Agregar un usuario manteniendo ordenado el archivo\n\n");
    agregarUsuario(fileUsersBin);
    printf("\nImprimo el archivo para mostrar que esta ordenado\n\n");
    imprimirArchivo(fileUsersBin);
    system("PAUSE");
    printf("\nPUNTO 4:\n");
    printf("Generar archivo pedidos.txt\n\n");
    generarArchivo(fileOrdersTxt, fileOrdersBin, fileUsersBin);
    printf("Imprimo el archivo pedidos.txt\n\n");
    imprimirPedidos(fileOrdersTxt);
    fclose(fileUsersTxt);
    fclose(fileUsersBin);
    fclose(fileRejectedTxt);
    fclose(fileOrdersBin);
    fclose(fileOrdersTxt);
    printf("\nFIN\n");
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

void escribirArchivos(FILE *archivo, FILE *archivoBin, FILE *archivoTxt){
    Usuario usuario;
    char nombre[26];
    char email[26];
    char contrasenia[26];
    printf("Empezando a escribir users.dat y rejected.txt\n");
    while(fscanf(archivo,"%s\t%s\t%s\n", nombre,email, contrasenia ) != EOF){
        if(nombreValido(nombre) && emailValido(email) && contraseniaValida(contrasenia)){
            strcpy(usuario.nombreUsuario,nombre);
            strcpy(usuario.email, email);
            strcpy(usuario.contrasenia, contrasenia);
            fwrite(&usuario, sizeof(Usuario), 1, archivoBin);
        }else{
            fprintf(archivoTxt, "%-26s\t%-26s\t%-26s\r\n", nombre, email, contrasenia);
        }
    }
    printf("\nFinal de escritura de users.dat y rejected.txt\n\n");
}

void imprimirArchivo(FILE *archivo){
    Usuario usuario;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, archivo);
    while(!feof(archivo)){
        printf("%s;%s;%s\n", usuario.nombreUsuario, usuario.email, usuario.contrasenia);
        fread(&usuario, sizeof(Usuario), 1, archivo);
    }
    printf("\n");
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
    return i >= 8 && i == contador;
}

bool esAlfanumerico(char letra){
    return (letra >= '0' && letra <= '9' )||( letra >= 'a' && letra <= 'z' )||( letra >= 'A' && letra <= 'Z');
}

Usuario login(FILE *archivoBin){
    Usuario usuario;
    char email[26];
    char contrasenia[26];
    printf("Ingrese su email\n");
    scanf("%s", email);
    printf("Ingrese una contrasenia\n");
    scanf("%s", contrasenia);

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

void checkearLogin(Usuario usuario){
    if(strcmp(usuario.nombreUsuario, "")==0){
        printf("\nEmail y/o contrasenia invalidos\n");
    }else{
        printf("\nEmail y contrasenia validos\n");
        printf("Sus datos de usuario son:\nNombre: %s\tEmail: %s\tContrasenia: %s\n", usuario.nombreUsuario, usuario.email, usuario.contrasenia);
    }
    printf("\n");
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

void agregarUsuario(FILE *archivo){
    Usuario usuario;
    printf("Ingrese el nombre de usuario\n");
    scanf("%s", usuario.nombreUsuario);
    printf("Ingrese el email\n");
    scanf("%s", usuario.email);
    printf("Ingrese la contrasenia\n");
    scanf("%s", usuario.contrasenia);
    int busquedaEmail = busquedaBinaria(usuario.email, archivo);
    if(nombreValido(usuario.nombreUsuario) && emailValido(usuario.email) && contraseniaValida(usuario.contrasenia)){
        if(busquedaEmail == -1){
            insertarUsuario(usuario, archivo);
        }else{
            printf("\nEmail existente\n");
        }
    }else{
        printf("\nNombre y/o email y/o contrasenia de formato inapropiado\n");
    }
    return;
}

void burbujeo(Usuario vec[], int tamanio){
    Usuario aux;
    bool flag = true;
    for(int i = 0;i < tamanio - 1 && flag == 1; i++){
        flag = false;
        for(int j = 0; j < tamanio - i - 1; j++){
            if(strcmp(vec[j + 1].email, vec[j].email) < 0){
              flag = true;
              aux = vec[j + 1];
              vec[j + 1] = vec[j];
              vec[j] = aux;
            }
        }
    }
}

void insertarUsuario(Usuario nuevoUsuario,FILE *archivo){
    fseek(archivo, 0, SEEK_END);
    int tamanio = (ftell(archivo)/sizeof(Usuario)) + 1;
    Usuario usuarios[tamanio];
    Usuario usuario;
    int i = 0;
    fseek(archivo, 0, SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, archivo);
    while(!feof(archivo)){
        usuarios[i] = usuario;
        if(strcmp(nuevoUsuario.nombreUsuario, usuario.nombreUsuario) == 0){
            printf("\nNombre de usuario existente\n");
            return;
        }
        fread(&usuario, sizeof(Usuario), 1, archivo);
        i++;
    }
    usuarios[i] = nuevoUsuario;
    burbujeo(usuarios, tamanio);
    fseek(archivo, 0, SEEK_SET);
    for(int j = 0; j < tamanio; j++){
        fwrite(&usuarios[j], sizeof(Usuario), 1, archivo);
    }
}

void discardChars(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

void generarArchivo(FILE *fileTxt, FILE *fileBin, FILE *fileUsersBin){
    PedidosDat pedidoDat;
    PedidosTxt pedidoTxt;
    int indice = 0;
    Usuario usuario;
    fseek(fileBin, 0, SEEK_SET);
    printf("Empezando a escribir pedidos.txt\n");
    fread(&pedidoDat, sizeof(PedidosDat), 1, fileBin);
    fprintf(fileTxt, "Email\t\t\tNombre\t\t\tCantidad\tTotal\n");
    while(!feof(fileBin)){
        pedidoTxt.cantProductos = 0;
        pedidoTxt.total = 0;
        strcpy(pedidoTxt.email, pedidoDat.email);
        indice = busquedaBinaria(pedidoDat.email, fileUsersBin);
        fseek(fileUsersBin,sizeof(Usuario)* indice, SEEK_SET);
        fread(&usuario, sizeof(Usuario), 1, fileUsersBin);
        strcpy(pedidoTxt.nombre, usuario.nombreUsuario);

        while(!feof(fileBin) && strcmp(pedidoDat.email,pedidoTxt.email) == 0){
            pedidoTxt.cantProductos += pedidoDat.cantSolicitada;
            pedidoTxt.total += (pedidoDat.valorUnitario * pedidoDat.cantSolicitada);
            fread(&pedidoDat, sizeof(PedidosDat), 1, fileBin);
        }
        fprintf(fileTxt, "%-16s\t%-16s\t%03d\t\t%0.2f\n", pedidoTxt.email, pedidoTxt.nombre, pedidoTxt.cantProductos, pedidoTxt.total);
    }
    printf("\nFinal de escritura de pedidos.txt\n\n");
    return;
}

void imprimirPedidos(FILE* fileTxt){
    char email[6];
    char nombre[7];
    char cantidad[9];
    char total[6];
    PedidosTxt pedido;
    fseek(fileTxt, 0, SEEK_SET);
    fscanf(fileTxt, "%s\t\t\t%s\t\t\t%s\t%s\n", email, nombre, cantidad, total);
    printf("%s\t\t\t%s\t\t\t%s\t%s\n", email, nombre, cantidad, total);
    fscanf(fileTxt, "%s\t%s\t%d\t\t%f\n", pedido.email, pedido.nombre, &pedido.cantProductos, &pedido.total);
    printf("%-16s\t%-16s\t%03d\t\t%0.2f\n", pedido.email, pedido.nombre, pedido.cantProductos, pedido.total);
    while(!feof(fileTxt)){
        fscanf(fileTxt, "%s\t%s\t%d\t\t%f\n", pedido.email, pedido.nombre, &pedido.cantProductos, &pedido.total);
        printf("%-16s\t%-16s\t%03d\t\t%0.2f\n", pedido.email, pedido.nombre, pedido.cantProductos, pedido.total);
    }
}
