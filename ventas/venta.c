/*Funciones relacionadas con una venta de la tienda virtual.*/
#include <stdio.h>
#include "../auxiliar/auxiliar.h"
#include "../ventas/venta.h"
#include "../cestas/cesta.h"

void confirmaCompra (struct sCesta *pCesta)/*Confirma la compra de los productos de la cesta actual.*/
{
    /*Declaración de variables*/
    struct sVenta primeraVenta;
    FILE *ptr;
    int i;

    inicVenta(&primeraVenta);/*Se inicializan lo0 valores a 0*/
    /*Se asignan valores a los diferentes atributos*/
    primeraVenta._fecha = fechaSistema();/*asignación de valor de lo que devuelve fechaSistema a primeraVenta._fecha*/
    /*Creación de la referencia del producto*/
    sprintf(primeraVenta._ref, "%.2d%.2d%.2d%.2d%.2d%.2d", primeraVenta._fecha._anyo%2000,primeraVenta._fecha._mes, primeraVenta._fecha._dia, primeraVenta._fecha._hora, primeraVenta._fecha._minuto, primeraVenta._fecha._segundo);

    primeraVenta._cesta = *pCesta;/*Asignación de valor de pcesta a primeraventa._cesta*/


    for(i=0; i<primeraVenta._cesta._num; i++)
    {
        primeraVenta._cesta.importe += primeraVenta._cesta._lista[i]._numUnidades * primeraVenta._cesta._lista[i]._precio;
    }/*Fin sentencia for(controla que se lean todos los productos para realizar el importe total de la cesta actual)*/


    ptr = fopen("./BASEDATOS/ventas.dat", "ab");/*Abre el archivo ventas.dat y si no existe lo crea*/

    fwrite(&primeraVenta,sizeof(struct sVenta),1,ptr);/*Escribe en el fichero de ventas.dat los datos corresponcientes a la cesta del cliente actual*/


    if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
    {
        gotoxy(30,42);
        printf( "Problemas al cerrar el fichero ventas.dat" );
        exit(0);
    }/*Fin sentencia if(Controla el cierre del fichero*/

    eliminaCesta(pCesta->_ID_cliente);
    vaciaCesta(pCesta);



    borraPantalla();
    gotoxy(32,42);
    printf("Pedido realizado con exito.[Pulse una tecla]");
    getch();
    borraPantalla2();




    return;
}

void inicVenta (struct sVenta *pVenta)/*Inicializa los datos de una venta.*/
{
    /*Declaración de variables*/
    register int i;

    inicCesta(&pVenta->_cesta, pVenta->_cesta._ID_cliente);

    inicFecha(&pVenta->_fecha);


    for(i=0; i<13; i++)
    {
        pVenta->_ref[i]='\0';
    }


    return;
}

void muestraExtractoVenta (int indice, struct sVenta venta)/*Muestra en pantalla un extracto de la venta actual.*/
{



    printf("%-4d", indice+1);
    printf("%-15s",venta._ref);
    printf("%-10.8s", venta._cesta._ID_cliente);
    printf("%.2d/%.2d/%-5.2d", venta._fecha._dia, venta._fecha._mes,venta._fecha._anyo);
    printf("%.2d:%.2d:%-8.2d", venta._fecha._hora, venta._fecha._minuto,venta._fecha._segundo);
    printf("%-5d", venta._cesta._num);
    printf("%.2f",venta._cesta.importe);


    return;
}

void muestraVenta (struct sVenta venta)/*Muestra los datos de la venta.*/
{
    /*Declaración de variables*/
    int i=0;
    int y=13;

    gotoxy(76,8);
    printf("fecha: %.2d/%.2d/%.2d", venta._fecha._dia, venta._fecha._mes,venta._fecha._anyo);
    gotoxy(100,8);
    printf("Hora: %.2d:%.2d:%.2d", venta._fecha._hora, venta._fecha._minuto,venta._fecha._segundo);

    for(i=0; i<venta._cesta._num; i++)
    {
        gotoxy(76,y);
        printf("%s", venta._cesta._lista[i]._ID_producto);
        gotoxy(80,y);
        printf("%.30s", venta._cesta._lista[i]._nombre);
        gotoxy(120,y);
        printf("%.2f", venta._cesta._lista[i]._precio);
        gotoxy(130,y);
        printf("%d", venta._cesta._lista[i]._numUnidades);
        gotoxy(135,y);
        printf("%.2f", venta._cesta._lista[i]._numUnidades*venta._cesta._lista[i]._precio);


        y++;
    }
        gotoxy(80,y+1);
        printf("precio total de venta:                                 %.2f", venta._cesta.importe);

    return;
}
