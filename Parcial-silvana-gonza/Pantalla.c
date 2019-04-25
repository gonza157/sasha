#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones_string.h"
#include "Pantalla.h"

int pan_Inicializar(Pantalla* pan, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        pan[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

void pan_mostrarArray(Pantalla* pan, int cantidad)
{

    for (int i=0; i<cantidad;i++)
    {
        if(pan[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, pan[i].isEmpty);
            printf("posicion %d :nombre %s\n", i, pan[i].nombre);
            printf("posicion %d :direccion%s\n", i, pan[i].direccion);
            printf("posicion %d :precio%f\n", i, pan[i].precioPantalla);
            printf("posicion %d :tipo %d\n", i, pan[i].tipo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}

int pan_buscarLibre(Pantalla* pan, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        if (pan[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }

        ret=1;
    }

    return ret;
}

int pan_Altaempleado(Pantalla* pan, int cantidad, int posLibre)
{
    int ret=-1;
    Pantalla Auxpantalla;

        if(pan[posLibre].isEmpty=1)
            {
                getString(Auxpantalla.nombre,"ingrese nombre","el nombre no es valido",1,21,3);
                getString(Auxpantalla.direccion,"ingrese direccion","el direccion no es valido",1,21,3);
                //falta idautoincremental
                printf("ingrese precio");
                scanf("%f",&(Auxpantalla.precioPantalla));
                printf("ingrese tipo1:ld \n ingrese 2:lcd\n");
                scanf("%d",&(Auxpantalla.tipo));
                pan[posLibre]=Auxpantalla;
                ret=0;
            }

    return ret;
}

int pan_buscarEnArray (Pantalla* pan, int cantidad, int* empleadoEncontrado)
{
    int ret=1;
    Pantalla auxEmpleados;

    if (getString(auxEmpleados.nombre,"ingrese el nombre del empleado que quiera eliminar: ","Vuelva a ingresar",2,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        ret=-1;
        for(int i=0;i<cantidad;i++)
        {
            //pan[i].nombre=tolower(pan[i].nombre);
            if (strcmp(pan[i].nombre, auxEmpleados.nombre)==0)
            {
                ret=0;
                *empleadoEncontrado=i;
                break;
            }
        }
    }
    return ret;
}

int pan_baja(Pantalla* pan, int cantidad)
{

    int posEmpleado;
    switch (pan_buscarEnArray(pan, cantidad,&posEmpleado))
    {
    case 0:
        if (pan[posEmpleado].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            pan[posEmpleado].isEmpty=1;
            printf("El empleado borrado es: %s\n\n",pan[posEmpleado].nombre);

        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

