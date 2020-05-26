/*Funciones relacionadas con la Tienda Virtual */
#include "../auxiliar/auxiliar.h"
#include "../clientes/listaClientes.h"
#include "../productos/listaproductos.h"
#include "../ventas/listaVentas.h"
#include "../main/menus.h"
#include <stdio.h>


int menuGerente()/*muestra las funcionalidades de la Tienda Virtual que están disponibles para el gerente*/
{
    /*declaracion de variable*/
    int opcion, y;

    gotoxy(30,40);
    printf("                                               ");/*Limpia la pantalla*/
    gotoxy(4,10);
    printf("                                                               ");/*Limpia la pantalla*/
    for(y=17; y<=30; y++)
    {
        gotoxy(4,y);
        printf("                                                                   ");/*Limpia la pantalla*/
    }

    gotoxy(32,42);
    printf("                                                                   ");/*Limpia la pantalla*/


    gotoxy(25,8);
    printf("Gestión de Tienda Virtual    ");/*cabecera del menu gerente*/


    gotoxy(4,13);
    printf("1 - Gestión de Clientes.                                            ");
    gotoxy(4,14);
    printf("2 - Gestión de Ventas.                                              ");
    gotoxy(4,15);
    printf("3 - Catálogo de productos.                                          ");
    gotoxy(4,16);
    printf("0 - Menú anterior.                                                  ");


    gotoxy(32,40);
    printf("Seleccione una opción: ");
    opcion = getch();


    return opcion-48;
}

void accesoGerenteTV()/*Gestiona las herramientas disponibles para el gerente*/
{

    /*declaracion de variables*/
    int seleccion;


    do
    {
        seleccion = menuGerente();/*llamada a dicha funcion*/

        switch(seleccion)
        {
        case 0:
            break;

        case 1:
            gestionClientes();
            break;

        case 2:
            gestionVentas();
            break;

        case 3:
            catalogoProductos();
            break;
        }/*fin switch*/

    }
    while (seleccion != 0); /*fin sentencia do...while*/


    return ;
}



void marcoTiendaVirtual()/*Dibuja la interfaz gráfica de la Tienda Virtual*/
{
    int i;/*declaración de variables*/

    /*Marco perteneciente a la parte superior de la consola*/
    gotoxy(1,1);
    printf("%c", 201);

    gotoxy(1,2);
    printf("%c", 186);
    gotoxy(1,3);
    printf("%c", 186);
    gotoxy(1,4);
    printf("%c", 186);

    gotoxy(2,1);
    for (i = 1; i<=72; i++)
        printf("%c%c", 205,205);
    gotoxy(1,5);
    printf("%c", 200);
    gotoxy(67,3);
    printf("TIENDA VIRTUAL");

    gotoxy(2,5);
    for (i = 1; i<=72; i++)
        printf("%c%c", 205,205);

    gotoxy(145,1);
    printf("%c", 187);

    gotoxy(145,2);
    printf("%c", 186);
    gotoxy(145,3);
    printf("%c", 186);
    gotoxy(145,4);
    printf("%c", 186);

    gotoxy(145,5);
    printf("%c", 188);

    /*Marco perteneciente a la primera ventana parte izquierda de la consola*/
    gotoxy(1,7);
    printf("%c", 218);
    gotoxy(72,7);
    printf("%c", 191);


    gotoxy(2,7);
    for(i=1; i<=35; i+=1)
        printf("%c%c",196, 196);


    gotoxy(1,8);
    printf("%c", 179);
    gotoxy(1,9);
    printf("%c", 195);

    gotoxy(2,9);
    for(i=1; i<=35; i+=1)
        printf("%c%c",196, 196);

    gotoxy(1,10);
    printf("%c", 179);
    gotoxy(1,11);
    printf("%c", 195);

    gotoxy(2,11);
    for(i=1; i<=35; i+=1)
        printf("%c%c",196, 196);

    gotoxy(1,12);
    printf("%c", 179);
    gotoxy(1,13);
    printf("%c", 179);
    gotoxy(1,14);
    printf("%c", 179);
    gotoxy(1,15);
    printf("%c", 179);
    gotoxy(1,16);
    printf("%c", 179);
    gotoxy(1,17);
    printf("%c", 179);
    gotoxy(1,18);
    printf("%c", 179);
    gotoxy(1,19);
    printf("%c", 179);
    gotoxy(1,20);
    printf("%c", 179);
    gotoxy(1,21);
    printf("%c", 179);
    gotoxy(1,22);
    printf("%c", 179);
    gotoxy(1,23);
    printf("%c", 179);
    gotoxy(1,24);
    printf("%c", 179);
    gotoxy(1,25);
    printf("%c", 179);
    gotoxy(1,26);
    printf("%c", 179);
    gotoxy(1,27);
    printf("%c", 179);
    gotoxy(1,28);
    printf("%c", 179);
    gotoxy(1,29);
    printf("%c", 179);
    gotoxy(1,30);
    printf("%c", 179);
    gotoxy(1,31);
    printf("%c", 179);
    gotoxy(1,32);
    printf("%c", 179);
    gotoxy(1,33);
    printf("%c", 179);
    gotoxy(1,34);
    printf("%c", 179);
    gotoxy(1,35);
    printf("%c", 179);
    gotoxy(1,36);
    printf("%c", 192);


    gotoxy(2,36);
    for(i=1; i<=35; i++)
        printf("%c%c",196, 196);

    gotoxy(72,8);
    printf("%c",179);
    gotoxy(72,9);
    printf("%c", 180);
    gotoxy(72,10);
    printf("%c", 179);
    gotoxy(72,11);
    printf("%c", 180);
    gotoxy(72,12);
    printf("%c", 179);
    gotoxy(72,13);
    printf("%c", 179);
    gotoxy(72,14);
    printf("%c", 179);
    gotoxy(72,15);
    printf("%c", 179);
    gotoxy(72,16);
    printf("%c", 179);
    gotoxy(72,17);
    printf("%c", 179);
    gotoxy(72,18);
    printf("%c", 179);
    gotoxy(72,19);
    printf("%c", 179);
    gotoxy(72,20);
    printf("%c", 179);
    gotoxy(72,21);
    printf("%c", 179);
    gotoxy(72,22);
    printf("%c", 179);
    gotoxy(72,23);
    printf("%c", 179);
    gotoxy(72,24);
    printf("%c", 179);
    gotoxy(72,25);
    printf("%c", 179);
    gotoxy(72,26);
    printf("%c", 179);
    gotoxy(72,27);
    printf("%c", 179);
    gotoxy(72,28);
    printf("%c", 179);
    gotoxy(72,29);
    printf("%c", 179);
    gotoxy(72,30);
    printf("%c", 179);
    gotoxy(72,31);
    printf("%c", 179);
    gotoxy(72,32);
    printf("%c", 179);
    gotoxy(72,33);
    printf("%c", 179);
    gotoxy(72,34);
    printf("%c", 179);
    gotoxy(72,35);
    printf("%c", 179);
    gotoxy(72,36);
    printf("%c", 217);



    /*Marco perteneciente a la segunda ventana de la consola parte derecha*/
    gotoxy(74,7);
    printf("%c", 218);
    gotoxy(145,7);
    printf("%c", 191);

    gotoxy(75,7);
    for(i=1; i<=35; i+=1)
        printf("%c%c",196, 196);

    gotoxy(74,8);
    printf("%c", 179);
    gotoxy(74,9);
    printf("%c", 195);
    gotoxy(74,10);
    printf("%c", 179);

    gotoxy(75,9);
    for(i=0; i<=70; i++)
        printf("%c", 196);

    gotoxy(74,11);
    printf("%c", 195);

    gotoxy(75,11);
    for(i=0; i<=70; i++)
        printf("%c", 196);

    gotoxy(74,12);
    printf("%c", 179);
    gotoxy(74,13);
    printf("%c", 179);
    gotoxy(74,14);
    printf("%c", 179);
    gotoxy(74,15);
    printf("%c", 179);
    gotoxy(74,16);
    printf("%c", 179);
    gotoxy(74,17);
    printf("%c", 179);
    gotoxy(74,18);
    printf("%c", 179);
    gotoxy(74,19);
    printf("%c", 179);
    gotoxy(74,20);
    printf("%c", 179);
    gotoxy(74,21);
    printf("%c", 179);
    gotoxy(74,22);
    printf("%c", 179);
    gotoxy(74,23);
    printf("%c", 179);
    gotoxy(74,24);
    printf("%c", 179);
    gotoxy(74,25);
    printf("%c", 179);
    gotoxy(74,26);
    printf("%c", 179);
    gotoxy(74,27);
    printf("%c", 179);
    gotoxy(74,28);
    printf("%c", 179);
    gotoxy(74,29);
    printf("%c", 179);
    gotoxy(74,30);
    printf("%c", 179);
    gotoxy(74,31);
    printf("%c", 179);
    gotoxy(74,32);
    printf("%c", 179);
    gotoxy(74,33);
    printf("%c", 179);
    gotoxy(74,34);
    printf("%c", 179);
    gotoxy(74,35);
    printf("%c", 179);
    gotoxy(74,36);
    printf("%c", 192);

    gotoxy(75,36);
    for(i=1; i<=35; i+=1)
        printf("%c%c",196, 196);

    gotoxy(145,8);
    printf("%c", 179);
    gotoxy(145,9);
    printf("%c", 180);
    gotoxy(145,10);
    printf("%c", 179);
    gotoxy(145,11);
    printf("%c", 180);
    gotoxy(145,12);
    printf("%c", 179);
    gotoxy(145,13);
    printf("%c", 179);
    gotoxy(145,14);
    printf("%c", 179);
    gotoxy(145,15);
    printf("%c", 179);
    gotoxy(145,16);
    printf("%c", 179);
    gotoxy(145,17);
    printf("%c", 179);
    gotoxy(145,18);
    printf("%c", 179);
    gotoxy(145,19);
    printf("%c", 179);
    gotoxy(145,20);
    printf("%c", 179);
    gotoxy(145,21);
    printf("%c", 179);
    gotoxy(145,22);
    printf("%c", 179);
    gotoxy(145,23);
    printf("%c", 179);
    gotoxy(145,24);
    printf("%c", 179);
    gotoxy(145,25);
    printf("%c", 179);
    gotoxy(145,26);
    printf("%c", 179);
    gotoxy(145,27);
    printf("%c", 179);
    gotoxy(145,28);
    printf("%c", 179);
    gotoxy(145,29);
    printf("%c", 179);
    gotoxy(145,30);
    printf("%c", 179);
    gotoxy(145,31);
    printf("%c", 179);
    gotoxy(145,32);
    printf("%c", 179);
    gotoxy(145,33);
    printf("%c", 179);
    gotoxy(145,34);
    printf("%c", 179);
    gotoxy(145,35);
    printf("%c", 179);
    gotoxy(145,36);
    printf("%c", 217);

    /*Marco perteneciente a las ventanas inferiones de la consola*/
    gotoxy(29,39);
    printf("%c", 218);
    gotoxy(110,39);
    printf("%c", 191);


    gotoxy(30,39);
    for(i=1; i<=40; i+=1)
        printf("%c%c",196, 196);

    gotoxy(29,40);
    printf("%c", 179);
    gotoxy(29,41);
    printf("%c", 195);

    gotoxy(30,41);
    for(i=1; i<=40; i+=1)
        printf("%c%c",196, 196);

    gotoxy(110,40);
    printf("%c", 179);
    gotoxy(110,41);
    printf("%c", 180);

    gotoxy(29,42);
    printf("%c", 179);
    gotoxy(29,43);
    printf("%c", 192);

    gotoxy(30,43);
    for(i=1; i<=40; i+=1)
        printf("%c%c",196, 196);

    gotoxy(110,42);
    printf("%c", 179);
    gotoxy(110,43);
    printf("%c", 217);



    return;
}
