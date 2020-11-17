#ifndef HERRAMIENTAS_H_INCLUDED
#define HERRAMIENTAS_H_INCLUDED

typedef struct {
    char email[16];
    int id;
    float valorUnitario;
    short cantidadSolicitada;
}ST_PEDIDOSDAT;
typedef struct {
    char email[16];
    char nombreUsuario[16];
    short cantidadDeProductos;
    float totalFacturable;
}ST_PEDIDOSTXT;
typedef struct {
    char nombre[16];
    char email[16];
    char password[16];
} ST_USUARIO;


FILE *abrir(const char*, const char*);
bool nombreValido(char*);
bool mailValido(char*);
bool passValido(char*);
bool esAlfanumerico(char);
int busquedaBinaria(FILE*, char*);
bool verificarDatosNuevoUsuario(ST_USUARIO, ST_USUARIO[], int);
void imprimirBin(FILE*);
void discardChars();


#endif // HERRAMIENTAS_H_INCLUDED
