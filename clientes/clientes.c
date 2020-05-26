/*Funciones relacionadas con un cliente de la tienda virtual*/
#include <stdio.h>
#include "../auxiliar/auxiliar.h"
#include "../clientes/clientes.h"
#include <stdbool.h>
#include <string.h>


void inicCliente (struct sCliente *pCliente)/*Inicializa los datos de un cliente.*/
{
    /*Declaración de variables*/
    int i;

    /*Inicializa a 0 todos los caracteres de las cadenas*/
    for(i=0; i <10; i++)
    {
        pCliente->_login[i] = '\0';
    }

    for(i=0; i <11; i++)
    {

        pCliente->_DNI[i] = '\0';
    }

    for(i=0; i <80; i++)
    {
        pCliente->_apellidos[i]= '\0';
    }

    for(i=0; i <40; i++)
    {
        pCliente->_nombre[i] = '\0';
    }
    return;
}


bool compruebaDNI (const char DNI[])/*Comprueba si un DNI es válido.*/
{
    /*Declaración de variables*/
    bool t,f;
    int resto;
    int dni;
    char letras[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
    char letras2[23] = "trwagmyfpdxbnjzsqvhlcke";
    char lt;

    t = true;/*Se asigna valor de true a la variable de tipo booleana t*/
    f = false;/*Se asigna valor de false a la variable de tipo booleana f*/
    lt = DNI[8];/*Se le asigna la letra del dni a la variable de tipo char lt*/
    dni =  atoi(DNI);/*Se transforma, mediante la función atoi, la cadena de carácteres a tipo entero*/
    resto = dni%23;/*Se saca el resto de la variable dni y se almacena en la variable entera resto*/

        if(letras[resto] == lt)/*Busca que coincida la letra del DNI metido por teclado con la letra a la que corresponda*/
        {
            return t;
        }/*Fin sentencia if*/

        if(letras2[resto] == lt)/*Busca que coincida la letra del DNI metido por teclado con la letra a la que corresponda*/
        {
            return t;
        }/*Fin sentencia if*/

    return f;
}


void muestraCliente (struct sCliente clientes)/*Muestra en pantalla los datos de un cliente.*/
{

    printf("%-10s", clientes._login);/*Muestra por pantalla los datos que recibe como parámetros*/
    printf("%-10s   ", clientes._DNI);/*Muestra por pantalla los datos que recibe como parámetros*/
    printf("%-20.15s", clientes._apellidos);/*Muestra por pantalla los datos que recibe como parámetros*/
    printf("%-20s", clientes._nombre);/*Muestra por pantalla los datos que recibe como parámetros*/


    return;
}
