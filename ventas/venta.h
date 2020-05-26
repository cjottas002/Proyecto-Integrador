#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "../cestas/cesta.h"
#include "../ventas/fecha.h"


typedef struct sVenta/*Contiene los atributos de una venta.*/
{
    char _ref [13];/*Referencia de la venta*/
    struct sFecha _fecha;/*Fecha y hora de la venta*/
    struct sCesta _cesta;/*Cesta con los productos vendidos*/


} tVenta;


void confirmaCompra (tCesta *pCesta);
void inicVenta (struct sVenta *pVenta);
void muestraExtractoVenta (int indice, struct sVenta venta);
void muestraVenta (struct sVenta venta);


#endif /* VENTA_H_INCLUDED*/
