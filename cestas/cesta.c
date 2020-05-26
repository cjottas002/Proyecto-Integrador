/*Funciones relacionadas con la cesta de la compra.*/
#include <stdio.h>
#include <string.h>
#include "malloc.h"
#include "../ventas/venta.h"
#include "../productos/atributo.h"
#include "../productos/catalogo.h"
#include "../productos/producto.h"
#include "../cestas/cesta.h"
#include "../productos/listaProductos.h"
#include "../clientes/listaUsuarios.h"
#include "../auxiliar/auxiliar.h"


void seleccionaProducto (struct sCatalogo catalogo, struct sCesta *pCesta)/*Selecciona un producto del catálogo.*/
{

    /*Declaración de variables*/
    char opcion;
    int cod, mayor =0;
    register int i;
    char ref[10];




    do
    {
        gotoxy(4,10);
        printf("                                                                    ");/*Borra la pantalla*/
        opcion = menuAtributos();
        switch(opcion)
        {
        case 0:
            break;

        case 1:
            cod = seleccionaAtributo(catalogo.categorias, opcion);
            muestraProductosxAtributo(catalogo.productos, opcion, cod);

            for(i=0; i<catalogo.productos._num; i++)
            {
                if (catalogo.productos._lista[i]._categoria > mayor)
                {
                    mayor = catalogo.productos._lista[i]._categoria;
                }/*fin sentencia if(se utiliza para almacenar un valor, es el número mayor de la lista de categorías para comparar que el código metido exista en la lista de productos)*/

                if(cod > mayor)
                {
                    gotoxy(4,10);
                    printf("                                                                   ");
                    gotoxy(32,42);
                    printf("Por el momento no existe esta categoría.[Pulse una tecla]");
                    getch();
                    gotoxy(32,42);
                    printf("                                                          ");
                    return;
                }/*Fin sentencia if(controla que el código del producto exista, sino sale del bucle de esta función)*/
                break;/*Sale del switch*/

            case 2:
                cod = seleccionaAtributo(catalogo.marcas,opcion);
                muestraProductosxAtributo(catalogo.productos, opcion, cod);

                for(i=0; i<catalogo.productos._num; i++)
                {
                    if (catalogo.productos._lista[i]._marca > mayor)
                    {
                        mayor = catalogo.productos._lista[i]._marca;
                    }/*fin sentencia if(se utiliza para almacenar un valor, es el número mayor de la lista de marcas para comparar que el código metido exista en la lista de productos)*/
                }/*Fin sentencia for*/

                if(cod > mayor)
                {
                    gotoxy(4,10);
                    printf("                                                                   ");
                    gotoxy(32,42);
                    printf("Por el momento no existe esta marca.[Pulse una tecla]");
                    getch();
                    gotoxy(32,42);
                    printf("                                                          ");
                    return;
                }/*Fin sentencia if(controla que el código del producto exista, sino sale de esta función)*/
                break;/*Sale del switch*/
            }/*fin sentencia for*/
        }/*Fin switch*/

    }
    while(opcion != 0 && opcion != 1 && opcion != 2);    /*fin sentencia do...while*/

    if (opcion != 0)
    {
        do
        {
            gotoxy(32,42);
            printf("                                                                    ");/*Limpia la pantalla*/
            gotoxy(32,40);
            printf("Introduzca la referencia de un producto: ");/*Pide al usuario que introduzca el número de referencia del producto que desea*/
            scanf("%s", ref);
            gotoxy(32,40);
            printf("                                                                 ");/*Limpia la pantalla*/

            if(ref[10] == '\r')
            {
                return;
            }

            for(i=0; i<catalogo.productos._num; i++)
            {
                if (strcmp(catalogo.productos._lista[i]._ref, ref) == 0)
                {
                    borraPantalla();
                    gotoxy(4,13);
                    muestraUnProducto(catalogo.productos._lista[i]);/*Llamada a dicha función para mostra el producto selecionado por el usuario*/
                    agregaProductoCesta(catalogo.productos._lista[i], pCesta);
                    break;/*Sale del bucle for*/
                }/*Fin sentencia if*/
            }/*Fin sentencia for*/

            if(strcmp(catalogo.productos._lista[i]._ref, ref) != 0)
            {
                gotoxy(32,42);
                printf("Producto no encontrado.[Pulse una tecla]");
                getch();
                gotoxy(32,42);
                printf("                                                  ");/*Limpia la pantalla*/
            }/*Fin sentencia if*/

        }
        while(strcmp(catalogo.productos._lista[i]._ref, ref) != 0);   /*Fin sentencia do...while*/
    }/*Fin sentencia if*/

    return;
}

void agregaProductoCesta (struct sProducto producto, struct sCesta *pCesta)/*Agrega un nuevo producto a la cesta actual.*/
{

    /*Declaración de variables*/
    FILE *ptr;
    ptr = fopen("./BASEDATOS/pendientes.dat", "ab");
    if (ptr == NULL)
    {
        gotoxy(32,42);
        printf("Error en la apertura del archivo pendientes.dat");
        exit(0);
    }
    else
    {
        pCesta->_num++;
        pCesta->_lista = realloc(pCesta->_lista, (pCesta->_num)*sizeof(tProdCesta));/*Creación del vector dinámico*/

        /*Se asignan los valoes de los productos a la cesta del cliente actual*/
        strcpy(pCesta->_lista[pCesta->_num-1]._ID_cliente, pCesta->_ID_cliente);
        strcpy(pCesta->_lista[pCesta->_num-1]._ID_producto, producto._ref);
        strcpy(pCesta->_lista[pCesta->_num-1]._nombre, producto._nombre);
        pCesta->_lista[pCesta->_num-1]._precio = producto._precio;

        gotoxy(32,42);
        printf("Introduzca el número de unidades que desea: ");
        scanf("%d", &pCesta->_lista[pCesta->_num-1]._numUnidades);
        gotoxy(32,42);
        printf("                                                       ");/*Limpia la pantalla*/


        fwrite(&pCesta->_lista[pCesta->_num-1], sizeof(struct sProdCesta), 1, ptr);

        if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero pendientes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/

    }/*Fin sentencia if...else*/

    gotoxy(4,10);
    printf("                                                                  ");/*Limpia la pantalla*/
    borraPantalla();



    return;
}




void cargaCestaCliente (struct sCesta *pCesta)/*Carga la cesta del cliente actual.*/
{
    /*Declaración de variables*/
    int i=0;
    FILE *pendientes;

    char arch[30] = "./BASEDATOS/pendientes.dat";
    pendientes = fopen(arch, "rb");/*Carga en la cesta únicamente los productos correspondientes al cliente actual*/

    if (pendientes == NULL)/*Controla la apertura del archivo (pendientes.dat)*/
    {
        gotoxy(32,42);
        printf("Error en lectura de archivo pendientes.dat");
        getch();
        return;
    }
    else
    {

        pCesta->_lista = malloc(sizeof(struct sProdCesta));/*Asignación dinámica  de memoria necesaria*/

        i=0;

        while(fread(&pCesta->_lista[i],sizeof(struct sProdCesta),1,pendientes)==1)
        {
            if(strcmp(pCesta->_ID_cliente,pCesta->_lista[i]._ID_cliente)==0)
            {
                pCesta->_lista = realloc(pCesta->_lista,(i+2)*sizeof(struct sProdCesta));
                pCesta->_num++;
            }
            else
            {
                i--;
            }/*Fin sentencia if...else*/
            i++;
        }/*Fin sentencia while(controla que se sea el contenido del archivo pendientes.dat)*/

        if( fclose(pendientes) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero pendientes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/


    }/*Fin sentencia if...else(Controla que se abra el archivo pendientes.dat correctamente)*/

    return;
}




void inicCesta (struct sCesta *pCesta, char login[])/*Inicializa los atributos de una cesta.*/
{


    strcpy(pCesta->_ID_cliente ,login);
    vaciaCesta(pCesta);

    return;
}


void vaciaCesta (struct sCesta *pCesta)/*Inicializa los atributos de una cesta, excepto el login del cliente.*/
{

    pCesta->importe = 0.0;
    pCesta->_num = 0;

    if (pCesta->_lista != NULL)
    {
        pCesta->_lista = NULL;

        free(pCesta->_lista);

    }/*Fin sentencia if(Se libera la lista si tiene asignada alguna dirección distinta de NULL y se inicializa a NULL)*/


    return;
}


int menuCesta ()/*Muestra las opciones relacionadas con la cesta de la compra.*/
{
    /*declaración de variables*/
    char opcion;

    do
    {

        /*limpia la pantalla*/
        gotoxy(4,14);
        printf("                                              ");
        gotoxy(25,8);
        printf("           ");
        gotoxy(33,40);
        printf("                                            ");
        gotoxy(32,42);
        printf("                                                                             ");


        gotoxy(28,8);
        printf("Menu Cesta                              ");

        gotoxy(4,13);
        printf("1 - Agregar producto.                             ");
        gotoxy(4,14);
        printf("2 - Confirmar compra.                           ");
        gotoxy(4,15);
        printf("3 - Cancelar compra.                            ");

        gotoxy(4,16);
        printf("0 - Fin de sesión.                                       ");

        gotoxy(32,40);
        printf("Seleccione una opción: ");
        opcion = getche();

        opcion = opcion-48;

        if(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3)
        {
            gotoxy(32,42);
            printf("Opción inexistente.[Pulse una tecla]");
            getch();

        }

    }
    while(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3); /*Fin sentencia do..while(controla que se introduzca bien la opción seleccionada)*/

    return opcion;

}




void muestraCesta (struct sCesta cesta)/*Muestra el contenido de la cesta.*/
{
    /*Declaración de variables*/
    int i, y=13;

    for (i=0; i<cesta._num; i++)
    {
        gotoxy(76,y);
        muestraProdCesta(cesta._lista[i]);

        y++;
        if (y>33)
        {
            gotoxy(32,42);
            printf("Para ver más productos pulse una tecla");
            getch();
            borraPantalla2();
            y=13;
        }


    }/*Fin sentencia for*/


    return;
}


void cancelaCompra (tCesta *cesta)/*Cancel la compra de un cliente.*/
{
    /*Declaración de variables*/
    register int i;

    for(i= 0; i<cesta->_num; i++)
    {

        if (strcmp(cesta->_ID_cliente, cesta->_lista[i]._ID_cliente)==0)
        {
            eliminaCesta(cesta->_lista[i]._ID_cliente);
        }
    }/*Fin sentencia for*/

    vaciaCesta(cesta);

    gotoxy(32,42);
    printf("¡Pedido cancelado![Pulse una tecla]");
    getch();
    gotoxy(32,42);
    printf("                                            ");
    borraPantalla2();
    return;
}


int gestionMenuCesta (char loginCliente[])/*Gestiona las opciones disponibles para la cesta de la compra.*/
{
    /*Declaración de variables*/
    struct sCesta cest;
    struct sCatalogo catal;
    int seleccion;



    do
    {


        inicCesta(&cest, loginCliente);
        inicCatalogo(&catal);
        cargaCatalogo(&catal);
        cargaCestaCliente (&cest);
        muestraCesta(cest);


        gotoxy(90,8);
        printf("Cesta de la compra -cliente- %s", loginCliente);
        gotoxy(76,10);
        printf("ref\t\tnombre\t\t\t\tp.u.\tcant.\t  total");


        seleccion = menuCesta();

        switch(seleccion)
        {
        case 0:
            borraPantalla2();
            break;

        case 1:
            seleccionaProducto(catal, &cest);
            break;

        case 2:
            confirmaCompra(&cest);
            break;

        case 3:
            cancelaCompra(&cest);
            break;
        }/*fin switch*/

    }
    while(seleccion !=0);  /*Fin sentencia do...while*/


    gotoxy(90,8);
    printf("                                              ");/*Limpia la pantalla*/
    gotoxy(76,10);
    printf("                                                                    ");/*Limpia la pantalla*/


    return 0;
}
