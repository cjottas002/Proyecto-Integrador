#ifndef PODCESTA_H_INCLUDED
#define PODCESTA_H_INCLUDED

typedef struct sProdCesta/*Contiene los atributos de un producto de la cesta.*/
{
    char _ID_cliente [10];/*ID del comprador*/
    char _ID_producto [10];/*ID del producto*/
    char _nombre [255];/*Nombre del producto*/
    float _precio;/*Precio en el momento de la compra*/
    int _numUnidades;/*Número de unidades compradas*/

} tProdCesta;

void eliminaCesta (char ID_cliente[]);
unsigned int cargaProductosPendientes (struct sProdCesta *vPendientes[]);
void muestraProdCesta (struct sProdCesta producto);


#endif /* PODCESTA_H_INCLUDED*/
