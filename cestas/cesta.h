#ifndef CESTA_H_INCLUDED
#define CESTA_H_INCLUDED
#include "../productos/catalogo.h"
#include "../productos/producto.h"
#include "../cestas/podCesta.h"

typedef struct sCesta/*Contiene los atributos de una cesta de la compra.*/
{
    char _ID_cliente [10];/*Id del comprador*/
    int _num;/*Número de productos comprador*/
    struct sProdCesta *_lista;/*Lista de productos incluidos en la cesta*/
    float importe;/*Importe total de la cesta*/


} tCesta;

void seleccionaProducto (struct sCatalogo catalogo, struct sCesta *pCesta);
void cargaCestaCliente (struct sCesta *pCesta);
void inicCesta (struct sCesta *pCesta, char login[]);
void vaciaCesta (struct sCesta *pCesta);
int menuCesta ();
void agregaProductoCesta (struct sProducto producto, struct sCesta *pCesta);
void muestraCesta (struct sCesta cesta);
void cancelaCompra (tCesta *cesta);
int gestionMenuCesta (char loginCliente[]);

#endif /* CESTA_H_INCLUDED*/
