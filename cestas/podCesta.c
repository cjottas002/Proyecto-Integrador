/*Funciones relacionadas con un producto de la cesta.*/
#include <stdio.h>
#include "../auxiliar/auxiliar.h"
#include "../cestas/podCesta.h"

void eliminaCesta (char ID_cliente[])/*Elimina los productos de una cesta.*/
{
    /*Declaración de variables*/
    struct sProdCesta *prodcest;
    unsigned int num;
    register int i;
    FILE *ptr;

    num = cargaProductosPendientes(&prodcest);/*llamada a dicha función para cargar los productos que están pendientes de confirma*/

    ptr = fopen("./BASEDATOS/pendientes.dat", "wb");
    if (ptr == NULL)
    {
        gotoxy(32,42);
        printf("error en la apertura del archivo pendientes.dat");
        exit(0);
    }


    for(i = 0; i < num; i++)
    {
        if (strcmp(prodcest[i]._ID_cliente, ID_cliente) != 0)
        {
            fwrite(&prodcest[i], sizeof(struct sProdCesta), 1, ptr);
        }/*Fin sentencia if(controla que se escriban los clientes que no coinciden con el de la cesta actual)*/

    }/*Fin sentencia for*/

    if(fclose(ptr)!= 0)
    {
        gotoxy(32,42);
        printf("problemas al cerrar el fichero pendientes.dat");
        exit(0);
    }

    return;
}




unsigned int cargaProductosPendientes (struct sProdCesta *vPendientes[])/*Carga los productos pendientes de confirmar desde archivo binario.*/
{
    /*Declaración de variables*/
    unsigned int num = 0;
    FILE *ptr;
    char arch[30] = "BASEDATOS/pendientes.dat";

    ptr = fopen(arch, "rb");

    if (ptr == NULL)
    {
        gotoxy(32,42);
        printf("Error en la apertura del archivo pendientes.dat");
        exit(0);
    }

    *vPendientes = malloc(sizeof(struct sProdCesta));

    while(fread(&(*vPendientes)[num], sizeof(struct sProdCesta), 1, ptr) == 1)
    {

        *vPendientes = realloc(*vPendientes,sizeof(struct sProdCesta)*(num+2));
        num++;
    }/*Fin sentencia while(controla que se lean todos los productos del fichero pendientes.dat)*/



    if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
    {
        gotoxy(30,42);
        printf( "Problemas al cerrar el fichero pendientes.dat" );
        exit(0);
    }/*Fin sentencia if(Controla el cierre del fichero)*/



    return num;
}

void muestraProdCesta (struct sProdCesta producto)/*Muestra un producto de la cesta.*/
{

    printf("%-10s", producto._ID_producto);
    printf("%-33.30s", producto._nombre);
    printf("%-10.2f", producto._precio);
    printf("%-8d", producto._numUnidades);
    printf("%.2f", (producto._precio*producto._numUnidades));


    return;
}
