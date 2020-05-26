#ifndef LISTAPRODUCTOS_H_INCLUDED
#define LISTAPRODUCTOS_H_INCLUDED

typedef struct sListaProductos/*Contiene los atributos de una lista de productos.*/
{
    int _num;/*Número de productos*/
    struct sProducto *_lista;/*Lista de productos*/

} tListaProductos;


/*Archivo que contiene los prototipos de las funciones siguientes*/

void inicListaProductos (struct sListaProductos *pProductos);
void cargaListaProductos (struct sListaProductos *pProductos);
void catalogoProductos ();
void muestraProductosxAtributo (tListaProductos productos, int tipo, int cod_atributo);


#endif /* LISTAPRODUCTOS_H_INCLUDED*/
