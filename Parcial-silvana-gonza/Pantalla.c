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

        if(pan[posLibre].isEmpty==1)
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

int pan_buscarEnArray (Pantalla* pan, int cantidad, int* pantallaEncontrada)
{
    int ret=1;
    Pantalla auxPantalla;

    if (getString(auxPantalla.nombre,"ingrese el nombre del pantalla que quiera eliminar: ","Vuelva a ingresar",2,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        ret=-1;
        for(int i=0;i<cantidad;i++)
        {
            //pan[i].nombre=tolower(pan[i].nombre);
            if (strcmp(pan[i].nombre, auxPantalla.nombre)==0)
            {
                ret=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return ret;
}

int pan_baja(Pantalla* pan, int cantidad)
{

    int posPantalla;
    switch (pan_buscarEnArray(pan, cantidad,&posPantalla))
    {
    case 0:
        if (pan[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            pan[posPantalla].isEmpty=1;
            printf("El empleado borrado es: %s\n\n",pan[posPantalla].nombre);

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

int pan_listarPantalla(Pantalla* pantalla,int len)
{
    int i=0,retorno=-1;
    if(pantalla !=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(pantalla[i].isEmpty==0)
            {
                printf("%s\t",pantalla[i].nombre);
                printf("%s\t",pantalla[i].direccion);
                printf("%2.f\t",pantalla[i].precioPantalla);
                printf("%d\t",pantalla[i].tipo);
                printf("%d\n",pantalla[i].idPantalla);
                retorno=0;
            }
            else
            {
                printf("no hay elementos cargados\n");
                break;
            }

        }
    }
    return retorno;
}

void pan_Harcodeo(Pantalla* pan)
{
    strncpy(pan[0].nombre,"mati",sizeof(pan->nombre));
    strncpy(pan[0].direccion,"mati",sizeof(pan->direccion));
    pan[0].precioPantalla=23;
    pan[0].tipo=1;
    pan[0].isEmpty=0;
    pan[0].idPantalla=1;

    strncpy(pan[1].nombre,"marcelo",sizeof(pan->nombre));
    strncpy(pan[1].direccion,"marcelo",sizeof(pan->direccion));
    pan[1].precioPantalla=20;
    pan[1].tipo=2;
    pan[1].isEmpty=0;
    pan[1].idPantalla=2;
}

int pan_modificarPantalla(Pantalla* pan,int len,int id)
{
    int retorno=-1,i,opcion;
    int posicion;
    Pantalla Auxpantalla;
    for( i=0; i<len; i++)
    {
        //pan[i].nombre=tolower(pan[i].nombre);
        if (pan[i].idPantalla== id)
        {
            posicion=i;
            printf("1-Nombre\t2-direccion\t3-Precio\t4-Tipo\n");
            scanf("%d",&opcion);
            switch(opcion)
            {

                case 1:
                {
                    getString(Auxpantalla.nombre,
                            "ingrese nuevo nombre\n",
                            "el nombre no es valido\n",
                            1,sizeof(Auxpantalla.nombre),3);
                            strncpy(pan[posicion].nombre,Auxpantalla.nombre,sizeof(Auxpantalla.nombre));
                            break;
                }
                case 2:
                {
                    getString(Auxpantalla.direccion,
                            "ingrese nueva direccion\n",
                            "el nombre no es valido",
                            1,sizeof(Auxpantalla.direccion),3);
                            strncpy(pan[posicion].direccion,Auxpantalla.direccion,sizeof(Auxpantalla.direccion));
                            break;
                }
                case 3:
                {
                    printf("ingrese nuevo precio: \n");
                    scanf("%f",&Auxpantalla.precioPantalla);
                    pan[posicion].precioPantalla=Auxpantalla.precioPantalla;
                    break;
                }
                case 4:
                {
                    printf("ingrese nuevo tipo: \n");
                    scanf("%d",&Auxpantalla.tipo);
                    pan[posicion].tipo=Auxpantalla.tipo;
                    break;
                }
                default:
                    break;
            }
            if(retorno==0)
            {
            pan[posicion]=Auxpantalla;
            }
            break;
        }
        }
    return retorno;
}


