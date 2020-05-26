/*Funciones relacionadas con un producto de la tienda virtual*/
#include <stdio.h>
#include "../auxiliar/auxiliar.h"
#include "../productos/producto.h"

void muestraProducto (struct sProducto producto)/*Muestra en pantalla los datos de un producto, en una sola línea.*/
{


    printf("%-10s", producto._ref);/*Muestra por pantalla los datos que recibe como parámetros*/
    printf("%-47.35s", producto._nombre);/*Muestra por pantalla los datos que recibe como parámetros*/
    printf("%-10.2f", producto._precio);/*Muestra por pantalla los datos que recibe como parámetros*/

    return;
}


void muestraUnProducto (struct sProducto producto)/*Muestra en pantalla los datos de un producto, en varias líneas.*/
{

    gotoxy(4,13);
    printf("ref:\t%s", producto._ref);
    gotoxy(4,15);
    printf("nombre:%.40s", producto._nombre);
    gotoxy(4,17);
    printf("precio:\t%.2f", producto._precio);


    return;
}
