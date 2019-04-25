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
    pan_Inicializar(pan,CANTP);
do
{
    printf("\n1-Altapantalla:\n2-Modificacionpantalla:\n3-Bajapantalla:\n");
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
            printf("ingreso2");
            break;
        }
        case 3:
        {
            printf("ingreso3");
            break;
        }
        default:
        printf("el ingresado no es valido");
    }
    }while(opcion!=4);
    return 0;
}
