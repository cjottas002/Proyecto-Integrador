/*Funciones relacionadas con el cat�logo de la tienda virtual.*/
#include <stdio.h>
#include "../productos/catalogo.h"
#include "../productos/listaAtributos.h"
#include "../productos/listaProductos.h"


void inicCatalogo (struct sCatalogo *pCatalogo)/*Inicializa un cat�logo de productos.*/
{


    inicListaProductos(&pCatalogo->productos);
    inicAtributos(&pCatalogo->categorias);
    inicAtributos(&pCatalogo->marcas);


    return;
}


void cargaCatalogo (struct sCatalogo *pCatalogo)/*Carga en memoria los datos de los productos, categor�as y marcas.*/
{
    /*Declaraci�n de variables*/
    char arch1[30] = "./BASEDATOS/categorias.txt";
    char arch2[30] = "./BASEDATOS/marcas.txt";

    cargaListaProductos(&pCatalogo->productos);/*Llamada a dicha funci�n(lee archivo productos.txt) para cargar los datos en la funci�n actual*/
    cargaDatosAtributos(&pCatalogo->categorias,arch1);/*Llamada a dicha funci�n(lee archivo categorias.txt) para cargar los datos en la funci�n actual*/
    cargaDatosAtributos(&pCatalogo->marcas,arch2);/*Llamada a dicha funci�n(lee el archivo marcas.txt) para cargar los datos en la funci�n actual*/



    return;
}
