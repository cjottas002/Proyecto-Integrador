/*Funciones relacionadas con las ventas */
#include <stdio.h>
#include <conio.h>
#include "../auxiliar/auxiliar.h"
#include "../tiendavirtual/TVirtual.h"
#include "../ventas/listaVentas.h"
#include"../ventas/fecha.h"

void inicListaVentas (struct sListaVentas *pVentas)/*Inicializa los datos de una lista de ventas.*/
{

    pVentas->_num = 0;
    pVentas->_lista = NULL;

    return;
}

void gestionVentas (void)/*Gestiona las ventas de la tienda virtual.*/
{
    int seleccion;
    char archInfoVentas[30] = "./BASEDATOS/infoVentas.txt";


    do
    {

        seleccion = menuVentas();/*llamada a dicha funcion*/

        switch(seleccion)
        {
        case 0:
            break;

        case 1:
            muestraListaVentas();
            break;

        case 2:
            generaInformeVentas(archInfoVentas);
            break;
        }/*fin switch*/

    }
    while(seleccion != 0);  /*fin sentencia do...while*/


    return;
}

int menuVentas (void)/*Muestra las opciones relacionadas con las ventas.*/
{
    /*declaración de variables*/
    char opcion;

    /*limpia la pantalla*/
    gotoxy(4,14);
    printf("                                              ");
    gotoxy(25,8);
    printf("           ");
    gotoxy(33,40);
    printf("                                            ");
    gotoxy(32,42);
    printf("                                                                             ");
    borraPantalla();

    gotoxy(28,8);
    printf("Menu de Ventas                              ");

    gotoxy(4,13);
    printf("1 - Listado de todas las ventas.                             ");
    gotoxy(4,14);
    printf("2 - Informe de ventas.                           ");

    gotoxy(4,15);
    printf("0 - Menú anterior.                                       ");
    gotoxy(4,16);
    printf("                                         ");/*Limpiar la pantalla*/

    gotoxy(32,40);
    printf("Seleccione una opción: ");
    opcion = getche();


    return opcion-48;


    return 0;
}

void generaInformeVentas (char archInfoVentas[])/*Genera un archivo de texto con los datos de ventas.*/
{
    /*Declaración de variables*/
    struct sListaVentas amd;
    FILE *ptr;
    register int i;


    inicListaVentas(&amd);
    cargaListaVentas(&amd);


    ptr = fopen(archInfoVentas, "at");


    for(i=0; i<amd._num; i++)
    {

        fprintf(ptr, "\nVENTA NÚMERO: %d\n", i+1);
        fprintf(ptr, "ID de venta: %s\n", amd._lista[i]._ref);
        fprintf(ptr, "fecha: %.2d/%.2d/%.2d\n", amd._lista[i]._fecha._dia, amd._lista[i]._fecha._mes,amd._lista[i]._fecha._anyo);
        fprintf(ptr, "Hora: %.2d:%.2d:%.2d\n", amd._lista[i]._fecha._hora, amd._lista[i]._fecha._minuto,amd._lista[i]._fecha._segundo);

        fprintf(ptr, "Numero de productos: %d\n", amd._lista[i]._cesta._num);
        fprintf(ptr, "Cod.\t\tProducto\t\t   p.u.\tCant\tTotal\n");

        fprintf(ptr, "\n%-10s", amd._lista[i]._cesta._lista[i]._ID_producto);
        fprintf(ptr, "%-30.25s", amd._lista[i]._cesta._lista[i]._nombre);
        fprintf(ptr, "%-10.2f", amd._lista[i]._cesta._lista[i]._precio);
        fprintf(ptr, "%-10d", amd._lista[i]._cesta._lista[i]._numUnidades);
        fprintf(ptr, "%.2f\n", amd._lista[i]._cesta._lista[i]._numUnidades*amd._lista[i]._cesta._lista[i]._precio);

        fprintf(ptr, "\n\nImporte total de la cesta: %.2f\n\n", amd._lista[i]._cesta.importe);
    }


    if (fclose(ptr) != 0)/*Controla el cierre del dichero*/
    {
        gotoxy(32,42);
        printf("Error al cerrar el fichero infoVentas.txt");
        exit(0);
    }/*Fin sentencia if(controla que se cierre el fichero infoventas.txt)*/

    gotoxy(32,42);
    printf("Informe generado correctamente.[Pulse una tecla]");
    getch();
    gotoxy(32,42);
    printf("                                                                   ");

    return;
}


void muestraListaVentas (void)/*Muestra en pantalla los datos de las ventas registradas.*/
{
    /*Declaración de variables*/
    struct sListaVentas venta;
    int i=0;
    int opcion;
    int y;

    inicListaVentas(&venta);
    cargaListaVentas(&venta);
    y =13;


    borraPantalla();
    gotoxy(4,10);
    printf("N.  ID venta   ID cliente    fecha      Hora        Nº  importe");


    for(i=0; i<venta._num; i++)
    {
        gotoxy(4,y);
        muestraExtractoVenta(i, venta._lista[i]);

        y++;
        if (y>33)
        {
            gotoxy(32,42);
            printf("para ver más ventas pulse una tecla.");
            getch();
            gotoxy(32,42);
            printf("                                        ");/*Borra la pantalla*/
            borraPantalla();
            y=13;
        }/*Fin sentencia if(controla que no sobrepase el marco)*/

    }/*Fin sentencia for(controla que se lean todas las ventas que hay)*/

    gotoxy(32,40);
    printf("seleccione el número de orden(0 menú anterior): ");
    scanf("%d", &opcion);


    if (opcion == 0)
    {
        borraPantalla();
        gotoxy(4,10);
        printf("                                                                   ");
        gotoxy(32,40);
        printf("                                                                   ");
        return;
    }
    else
    {

        gotoxy(76,10);
        printf("Cod.\tProducto\t\t\tp.u.\tCant\tTotal");
        muestraVenta(venta._lista[opcion-1]);

        gotoxy(32,42);
        printf("Para continuar pulse una tecla");
        getch();
        borraPantalla2();

    }/*Fin sentencia if...else(controla que se lea el producto seleccionado)*/
    gotoxy(4,10);
    printf("                                                                    ");
    gotoxy(76,8);
    printf("                                                                   ");
    gotoxy(76,10);
    printf("                                                                   ");
    gotoxy(32,40);
    printf("                                                                   ");


    return;
}

void cargaListaVentas (struct sListaVentas *pVentas)/*Carga los datos del archivo de ventas en una lista de clientes.*/
{

    /*Declaración de variables*/
    int i;
    FILE *ptr;
    pVentas->_num = 0;
    for(i=0; i<pVentas->_num; i++)
    {
        inicVenta(&pVentas->_lista[i]);
    }/*Fin sentencia for(inicializa todos los registros de sVenta)*/



    ptr = fopen("./BASEDATOS/ventas.dat", "rb");

    if(ptr == NULL)
    {
        gotoxy(32,42);
        printf("Error en la apertura del archivo ventas.dat");
        exit(0);
    }
    else
    {

        pVentas->_lista = malloc(sizeof(struct sVenta));/*Creación de un vector de memoria dinamica*/

        for(i=0; fread(&pVentas->_lista[i],sizeof(struct sVenta), 1, ptr)== 1 ; i++)/*Lee el fichero hasta el final*/
        {
            pVentas->_lista = realloc(pVentas->_lista, (i+2)*sizeof(struct sVenta));
            pVentas->_num++;
        }/*Fin sentencia for(controla que se lea el archivo ventas.dat hasta el final)*/

        if (fclose(ptr))/*Controla la apertura del archivo categorias.txt*/
        {
            gotoxy(30,42);
            printf("Problemas al cerrar el fichero ventas.dat");
            exit(0);
        }/*Fin sentencia if(controla que se cierre el fichero ventas.dat)*/

    }/*Fin sentencia if...else(controla la apertura del fichero ventas.dat)*/


    return;
}
