#ifndef LISTAVENTAS_H_INCLUDED
#define LISTAVENTAS_H_INCLUDED
#include "../ventas/venta.h"

typedef struct sListaVentas/*Contiene los atributos de una lista de ventas.*/
{
    int _num;/*Número de ventas*/
    struct sVenta *_lista;/*Lista de ventas*/

} tListaVentas;

/*Archivo que contiene los prototipos de las funciones siguientes*/

void inicListaVentas (struct sListaVentas *pVentas);
void gestionVentas ();
int menuVentas ();
void generaInformeVentas (char archInfoVentas[]);
void muestraListaVentas ();
void cargaListaVentas (struct sListaVentas *pVentas);



#endif /* LISTAVENTAS_H_INCLUDED*/
