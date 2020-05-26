#ifndef CATALOGO_H_INCLUDED
#define CATALOGO_H_INCLUDED
#include"../productos/listaAtributos.h"
#include"../productos/listaProductos.h"
/*Estructuras y prototipos de funciones*/

struct sCatalogo/*Contiene los atributos de un catálogo de productos.*/
{
    struct sListaProductos productos;/*Lista de productos*/
    struct sListaAtributos categorias;/*Lista de categorías*/
    struct sListaAtributos marcas;/*Lista de marcas*/
};


void cargaCatalogo (struct sCatalogo *pCatalogo);
void inicCatalogo (struct sCatalogo *pCatalogo);

#endif /* CATALOGO_H_INCLUDED*/
