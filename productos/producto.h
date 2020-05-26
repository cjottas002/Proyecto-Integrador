#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct sProducto/*Contiene los atributos de un producto.*/
{
    char _ref [10];/*Referencia del producto*/
    unsigned short _categoria;/*Categoría del producto*/
    unsigned short _marca;/*Marca del producto*/
    char _nombre [255];/*Nombre del producto*/
    float _precio;/*Precio del producto*/

} tProducto;


/*Archivo que contiene los prototipos de las funciones siguientes*/

void muestraProducto (struct sProducto producto);
void muestraUnProducto (struct sProducto producto);



#endif /* PRODUCTO_H_INCLUDED*/
