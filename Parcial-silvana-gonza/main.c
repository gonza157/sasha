#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "funciones_string.h"
#define CANTP 2

int main()
{
    int opcion=0;
    Pantalla pan[CANTP];
    int posicion=0;
    int id=0;
    pan_Inicializar(pan,CANTP);
    pan_Harcodeo(pan);
do
{
    printf("\n1-Altapantalla:\n2-Modificacionpantalla:\n3-Bajapantalla:\n4-Listarpantallas:\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
        {
            pan_buscarLibre(pan,CANTP,&posicion);
            //printf("%d",posicion);
            pan_Altaempleado(pan,CANTP,posicion);
            printf("%d",posicion);
            break;
        }
        case 2:
        {
            if(pan_listarPantalla(pan,CANTP)==0)
            {
            printf("ingrese el id a modificar:\n");
            scanf("%d",&id);
            pan_modificarPantalla(pan,CANTP,id);
            }else
            {
                printf("no existen elementos");
            }
            break;
        }
        case 3:
        {
            if(pan_listarPantalla(pan,CANTP)==0)
            {
            pan_baja(pan,CANTP);
            }
            break;
        }
        case 4:
        {
            pan_listarPantalla(pan,CANTP);
        }
        default:
        printf("el ingresado no es valido");
    }
    }while(opcion!=5);
    return 0;
}
