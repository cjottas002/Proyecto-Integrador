/*[Contiene las funciones relacionadas con la gestión del menú principal]*/
#include <stdio.h>
#include <conio.h>
#include "../auxiliar/auxiliar.h"
#include "../main/accesoSistema.h"
#include "../clientes/listaClientes.h"
#include "../main/menus.h"
#include "../clientes/solicitud.h"

void gestionMenuPrincipal()/*Gestiona las opciones del menú principal.*/
{
    int seleccion;


    do
    {
        seleccion = menuPrincipal();/*llamada a dicha funcion*/

        switch(seleccion)
        {
        case 0:
            break;

        case 1:
            gestionAccesoTV();
            break;

        case 2:
            solicitaRegistro();
            break;
        }/*fin switch*/

    }
    while(seleccion != 0); /*fin sentencia do...while*/



    return;
}

int menuPrincipal()/*Muestra las opciones generales de la tienda virtual.*/
{
    /*declaración de variables*/
    char opcion;

    /*limpia la pantalla*/
    borraPantalla();
    gotoxy(25,8);
    printf("           ");
    gotoxy(33,40);
    printf("                                            ");
    gotoxy(32,42);
    printf("                                                                             ");


    gotoxy(28,8);
    printf("Menu principal                              ");

    gotoxy(4,13);
    printf("1 - Acceso a la Tienda.                             ");
    gotoxy(4,14);
    printf("2 - Solicitar registro.                           ");

    gotoxy(4,15);
    printf("0 - Fin del programa.                                       ");
    gotoxy(4,16);
    printf("                                         ");/*Limpiar la pantalla*/

    gotoxy(32,40);
    printf("Seleccione una opción: ");
    opcion = getche();


    return opcion-48;
}
