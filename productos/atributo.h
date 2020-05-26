#ifndef ATRIBUTO_H_INCLUDED
#define ATRIBUTO_H_INCLUDED
/*Estructuras y prototipos de funciones*/

struct sAtributo/*Contiene los campos de una atributo de producto.*/
{
    unsigned int _ID;/*Identificador*/
    char _nombre [255];/*Nombre de la categoría*/

};

int menuAtributos ();

#endif /* ATRIBUTO_H_INCLUDED*/
