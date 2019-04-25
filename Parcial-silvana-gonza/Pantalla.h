#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[20];
    char direccion[20];
    int tipo;
    float precioPantalla;
    int isEmpty; // lleno=0 ; vacio=1
    int idPantalla; //autoincremental
} Pantalla;

int pan_Inicializar(Pantalla* pan, int cantidad);
void pan_mostrarArray(Pantalla* pan, int cantidad);
int pan_buscarLibre(Pantalla* pan, int cantidad, int* devuelve);
int pan_Altaempleado(Pantalla* pan, int cantidad, int posLibre);
int pan_buscarEnArray (Pantalla* pan, int cantidad, int* empleadoEncontrado);
int pan_baja(Pantalla* pan, int cantidad);
int pan_listarPantalla(Pantalla* pantalla,int len);
void pan_Harcodeo(Pantalla* pan);
int pan_modificarPantalla(Pantalla* pan,int len,int id);


#endif // PANTALLA_H_INCLUDED
