/*Funciones relacionadas con los atributos de un producto de la tienda virtual.*/
#include <stdio.h>
#include "../auxiliar/auxiliar.h"

int menuAtributos ()/*Muestra las opciones de atributos disponibles.*/
{
    /*Declaraci�n de variables*/
    int opcion;
    int y;



    for(y=13; y<=33; y++)
    {
        gotoxy(3,y);
        printf("                                                                    ");/*Limpia la pantalla*/
    }
    gotoxy(32,40);
    printf("                                                                    ");/*Limpia la pantalla*/

    gotoxy(22,8);
    printf("Selecci�n del tipo de atributo");


    gotoxy(4,13);
    printf("1 - Seleccionar productos por categor�a.");

    gotoxy(4,14);
    printf("2 - Seleccionar productos por marca.");

    gotoxy(4,15);
    printf("0 - Men� anterior.");

    gotoxy(32,40);
    printf("Seleccione una opci�n: ");

    opcion = getche();



    gotoxy(22,8);
    printf("                                           ");

    return opcion-48;
}
