#ifndef LISTAATRIBUTOS_H_INCLUDED
#define LISTAATRIBUTOS_H_INCLUDED
/*Estructuras y prototipos de funciones*/

struct sListaAtributos/*Contiene los atributos de una lista de atributos.*/
{

    unsigned short _num;/*Número de registro*/
    struct sAtributo *_lista;/*Lista de registro*/

};

void inicAtributos (struct sListaAtributos *pAtributos);
int seleccionaAtributo (struct sListaAtributos categorias, char tipo);
int cargaDatosAtributos (struct sListaAtributos *plAtributos, const char nombreArch[ ]);
void muestraAtributos (struct sListaAtributos atributos);


#endif /* LISTAATRIBUTOS_H_INCLUDED*/
