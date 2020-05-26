/*Funciones relacionadas con la lista de atributos de un producto.*/
#include <stdio.h>
#include <string.h>
#include "../productos/listaAtributos.h"
#include "../productos/atributo.h"
#include "../auxiliar/auxiliar.h"
#include <malloc.h>


void inicAtributos (struct sListaAtributos *pAtributos)/*Inicializa los atributos de una lista de atributos de productos.*/
{

    pAtributos->_num = 0;
    pAtributos->_lista = NULL;

    return;
}


int seleccionaAtributo (struct sListaAtributos categorias, char tipo)/*Selecciona un atributo (una categoría o una marca)*/
{
    /*Declaración de variables*/
    int  h=0;
    int valor;



    if (tipo == 1)
    {
        borraPantalla();
        gotoxy(22,8);
        printf("Selección de categoría");
        gotoxy(3,10);
        printf("núm. categoría");

        muestraAtributos(categorias);/*Llama a dicha función para mostrar por pantalla los atributos que contiene*/

    }/*Fin sentencia if(para categoría)*/
    else if(tipo == 2)
    {

        borraPantalla();
        gotoxy(22,8);
        printf("Selección de marca");
        gotoxy(3,10);
        printf("núm. Marca");
        muestraAtributos(categorias);/*Llama a dicha función para mostrar por pantalla los atributos que contiene*/

    }/*Fin sentencia else...if*/


     while(h==0)
        {


            gotoxy(32,40);
            printf("Seleccione una opcion: ");
            scanf("%d", &valor);


            if(valor <= categorias._num)
            {
                break;
            }
            else
            {
                gotoxy(32,42);
                printf("Introduzca una opción válida.[Pulse una tecla]");
                getch();
                gotoxy(32,42);
                printf("                                                    ");/*Limpia la pantalla*/
            }/*Fin sentencia if...else(controla que le usuario seleccione correctamente la opción)*/


        }/*Fin sentencia while*/
        gotoxy(2,10);
        printf("                                                               ");/*Limpia la pantalla*/
        gotoxy(32,40);
        printf("                                                                 ");/*Limpiar la ventana de mendaje*/
        gotoxy(2,8);
        printf("                                                              ");/*Limpia la pantalla*/

        borraPantalla();
    return valor;

}


/*Lee de un archivo los datos de una lista de atributos.*/
int cargaDatosAtributos (struct sListaAtributos *plAtributos, const char nombreArch[])
{

    /*Declaración de variables*/
    int i=0;
    FILE *categ;

    if (strcmp(nombreArch,"./BASEDATOS/categorias.txt") == 0)
    {

        categ = fopen(nombreArch, "rt");

        if (categ == NULL)/*Controla la apertura del archivo categorias.txt*/
        {
            gotoxy(30,42);
            printf("Error en lectura de archivo categorias.txt");
            exit(0);
        }
        else
        {

            plAtributos->_lista = malloc(sizeof(struct sAtributo));/*Creación de un vector de memoria dinamica*/

            while(fscanf(categ, "%u", &plAtributos->_lista[i]._ID) == 1)/*Lee el fichero hasta el final*/
            {
                fflush(stdin);
                fgets(plAtributos->_lista[i]._nombre, 255, categ);/*Almacena los datos concernientes al nombre del producto contenido en el archivo*/

                i++;/*Variable de control que actualiza el valor de i*/
                plAtributos->_lista = realloc(plAtributos->_lista,(i+1)*sizeof(struct sAtributo));
            }/*Fin sentencia while(controla que se lea el archivo categorías.txt hasta el final)*/
            plAtributos->_num = i;

            if (fclose(categ))/*Controla la apertura del archivo categorias.txt*/
            {
                gotoxy(30,42);
                printf("Problemas al cerrar el fichero categorias.txt");
                exit(0);
            }


        }/*Fin sentecia if...else(controla que se abra el fichero correctamente)*/



    }/*Fin sentencia if(para categoría)*/
    else if (strcmp(nombreArch, "./BASEDATOS/marcas.txt") == 0)
    {
        categ = fopen(nombreArch, "rt");

        if (categ == NULL)/*Controla la apertura del archivo marcas.txt*/
        {
            gotoxy(30,42);
            printf("Error en lectura de archivo marcas.txt");
            exit(0);
        }
        else
        {


            plAtributos->_lista = malloc(sizeof(struct sAtributo));/*Creación de un vector de memoria dinamica*/

            while(fscanf(categ, "%u", &plAtributos->_lista[i]._ID) == 1)/*Lee el fichero hasta el final*/
            {

                fflush(stdin);/*Limpiar el buffer de entrada*/
                fgets(plAtributos->_lista[i]._nombre, 255, categ);/*Almacena los datos concernientes al nombre del producto contenido en el archivo*/

                i++;/*Variable de control que actualiza el valor de i*/

                plAtributos->_lista = realloc(plAtributos->_lista,(i+1)*sizeof(struct sAtributo));/*actualización del vector*/
            }/*Fin sentencia while(controla que se lea el archivo categorías.txt hasta el final)*/
            plAtributos->_num = i;

            if (fclose(categ))/*Controla la apertura del archivo marcas.txt*/
            {
                gotoxy(30,42);
                printf("Problemas al cerrar el fichero marcas.txt");
                exit(0);
            }


        }/*Fin sentecia if...else(controla que se abra el fichero correctamente)*/



    }/*Fin sentencia else..if*/

    return 0;
}


void muestraAtributos (struct sListaAtributos atributos)/*Muestra una lista de atributos.*/
{
    /*Declaración de variables*/
    int i, y=13;

    for(i=0; i<atributos._num; i++)
    {
        gotoxy(4,y);
        printf("%-2d %s", atributos._lista[i]._ID, atributos._lista[i]._nombre);


        if(y>=33)
            {
                gotoxy(32,42);
                printf("Para ver más productos pulse una tecla.");
                getch();
                borraPantalla();
                y= 13;
            }/*Fin sentencia if(controla que no se pase de la pantalla)*/

            y++;
    }/*Fin sentencia for(controla que se lean todos los atributos)*/


    return;
}
