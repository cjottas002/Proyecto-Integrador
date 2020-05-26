/*Funciones relacionadas con los productos de la tienda virtual */
#include <stdio.h>
#include "../productos/listaProductos.h"
#include "../productos/producto.h"
#include "../auxiliar/auxiliar.h"

void inicListaProductos (struct sListaProductos *pProductos)/*Inicializa los datos de una lista de productos.*/
{


    pProductos->_num = 0;
    pProductos->_lista = NULL;

    return;
}


/*Carga los datos del archivo (de texto) de productos en una lista de productos.*/
void cargaListaProductos (struct sListaProductos *pProductos)
{

    /*Declaración de variables*/
    int i=0;
    FILE *productos;
    char arcProd[30] = "./BASEDATOS/productos.txt";
    productos = fopen(arcProd, "rt");

    if (productos == NULL)/*Controla la apertura del archivo productos.txt*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo productos.txt");
        exit(0);
    }
    else
    {

        pProductos->_lista = malloc(sizeof(struct sProducto));/*Creación de un vector de memoria dinamica*/

        while(fscanf(productos, "%hu", &pProductos->_lista[i]._categoria) == 1)/*Lee el fichero hasta el final*/
        {

            fflush(stdin);/*Limpiar el buffer de entrada*/
            fscanf(productos, "%hu", &pProductos->_lista[i]._marca);/*Almacena los datos concernientes a la marca del producto contenido en el archivo*/
            fflush(stdin);/*Limpiar el buffer de entrada*/
            fscanf(productos, "%s", pProductos->_lista[i]._ref);/*Almacena los datos concernientes a la referencia del producto contenido en el archivo*/
            fflush(stdin);/*Limpiar el buffer de entrada*/
            fscanf(productos, "%f", &pProductos->_lista[i]._precio);/*Almacena los datos concernientes al precio de un producto contenido en el archivo*/
            fflush(stdin);/*Limpiar el buffer de entrada*/
            fgets(pProductos->_lista[i]._nombre, 255, productos);/*Almacena los datos concernientes al nombre del producto contenido en el archivo*/
            pProductos->_lista[i]._nombre[strlen(pProductos->_lista[i]._nombre)-1]= '\0';

            i++;/*Variable de control que actualiza el valor de i*/

            pProductos->_lista = realloc(pProductos->_lista,(i+1)*sizeof(struct sProducto));/*actualización del vector*/

        }/*Fin sentencia while(controla que se lea el archivo productos.txt hasta el final)*/
        pProductos->_num = i;/*Almacena el número de veces que se han leído los datos*/

        if (fclose(productos))/*Controla la apertura del archivo productos.txt*/
        {
            gotoxy(30,42);
            printf("Problemas al cerrar el fichero productos.txt");
            exit(0);
        }/*Fin sentencia if(controla que se lea el archivo productos.txt)*/


    }/*Fin sentecia if...else(controla que se abra el fichero correctamente)*/

    return;
}


void catalogoProductos()/*Muestra los datos de TODOS los productos registrados.*/
{
    /*Declaracion de variables*/
    int y=13, i=0;
    struct sListaProductos pProductos;

    gotoxy(4,10);
    printf("ref\t\tnombre\t\t\t\t\t     precio");

    cargaListaProductos(&pProductos);

    for(i=0; i<pProductos._num; i++)
    {
        gotoxy(4,y);
        muestraProducto(pProductos._lista[i]);
        y++;

        if(y>33)
        {
            gotoxy(32,42);
            printf("Pulse una tecla para continuar...");
            getch();
            borraPantalla();
            y=13;
        }/*Fin sentencia if*/

    }/*Fin sentenciafor(controla que se lean todos los productos)*/
    gotoxy(32,42);
    printf("Pulse una tecla para continuar...");
    getch();
    borraPantalla();

    return;
}


/*Muestra solamente los productos de una categoría o de una marca.*/
void muestraProductosxAtributo (tListaProductos productos, int tipo, int cod_atributo)
{
    /*Declaración de variables*/
    int i, y=13;


    gotoxy(4,10);
    printf("ref\t\tnombre\t\t\t\t\t     precio");


    if (tipo == 1)
    {

        for(i=0; i<productos._num; i++)
        {
            if(productos._lista[i]._categoria == cod_atributo)
            {
                gotoxy(4,y);
                muestraProducto(productos._lista[i]);/*Llama a dicha función para que se muestren sólo los productos que se requieren por categoría*/
                y++;/*Variable de control para que no se llene la pantalla*/
                if(y>=30)
                {
                    gotoxy(32,42);
                    printf("Para ver más productos pulse una tecla.");
                    getch();
                    borraPantalla();
                    y= 13;/*Vuelve a retonar la variable a dicho valor*/
                }/*Fin sentencia if(controla que no se llene la pantalla)*/
            }/*Fin sententia if(controla que coincidan el codigo del atributo seleccionado por el usuario y los que existen en categoria.txt)*/
        }/*Fin sentencia for*/
    }/*Fin sentencia if(opción 1)*/

    else if(tipo == 2)
    {
        for(i=0; i<productos._num; i++)
        {
            if(productos._lista[i]._marca == cod_atributo)
            {
                gotoxy(4,y);
                muestraProducto(productos._lista[i]);/*Llama a dicha función para que se muestren sólo los productos que se requieren por marcas*/
                y++;/*Variable de control para que no se llene la pantalla*/
                if(y>=30)
                {
                    gotoxy(32,42);
                    printf("Para ver más productos pulse una tecla.");
                    getch();
                    borraPantalla();
                    y= 13;/*Vuelve a retonar la variable a dicho valor*/
                }/*Fin sentencia if(controla que no se llene la pantalla)*/
            }/*Fin sententia if(controla que coincidan el codigo del atributo seleccionado por el usuario y los que existen en categoria.txt)*/
        }/*Fin sentencia for(controla que se lean todos los productos requeridos)*/
    }/*Fin sentencia else..if(opción 2)*/

    return;
}
