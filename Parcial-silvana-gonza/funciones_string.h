#ifndef FUNCIONES_STRING_H_INCLUDED
#define FUNCIONES_STRING_H_INCLUDED


int inicializarArray(char *nombres[]);

int buscarLibre (char lista[][56], int* pIndex, int cantidadPos);

int getString(char *pResult,char *pMsg,char *pMsgError,int min,int max,int intentos);

int validarLetra (char letras[]);

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int isValidIntNumber (char* cadena);


#endif // FUNCIONES_STRING_H_INCLUDED
