/*Funciones relacionadas con el catálogo de la tienda virtual.*/
#include <stdio.h>
#include "../productos/catalogo.h"
#include "../productos/listaAtributos.h"
#include "../productos/listaProductos.h"


void inicCatalogo (struct sCatalogo *pCatalogo)/*Inicializa un catálogo de productos.*/
{


    inicListaProductos(&pCatalogo->productos);
    inicAtributos(&pCatalogo->categorias);
    inicAtributos(&pCatalogo->marcas);


    return;
}


void cargaCatalogo (struct sCatalogo *pCatalogo)/*Carga en memoria los datos de los productos, categorías y marcas.*/
{
    /*Declaración de variables*/
    char arch1[30] = "./BASEDATOS/categorias.txt";
    char arch2[30] = "./BASEDATOS/marcas.txt";

    cargaListaProductos(&pCatalogo->productos);/*Llamada a dicha función(lee archivo productos.txt) para cargar los datos en la función actual*/
    cargaDatosAtributos(&pCatalogo->categorias,arch1);/*Llamada a dicha función(lee archivo categorias.txt) para cargar los datos en la función actual*/
    cargaDatosAtributos(&pCatalogo->marcas,arch2);/*Llamada a dicha función(lee el archivo marcas.txt) para cargar los datos en la función actual*/



    return;
}
