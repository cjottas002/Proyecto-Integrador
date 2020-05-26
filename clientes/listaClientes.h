#ifndef LISTACLIENTES_H_INCLUDED
#define LISTACLIENTES_H_INCLUDED
/*Archivo que contiene los prototipos de las funciones siguientes*/


typedef struct sListaClientes/*Contiene los atributos de una lista de clientes.*/
{
    int _num;/*Número de clientes*/
    struct sCliente *_lista;/*Lista de clientes*/

} tListaClientes;

void inicListaClientes (struct sListaClientes *pClientes);
void eliminaCliente ();
void muestraListaClientes (struct sListaClientes lClientes);
void gestionClientes ();
int menuClientes ();
void generaInformeClientes (const char archInfo[]);
void cargaListaClientes (struct sListaClientes *pClientes);
void guardaListaClientes (struct sListaClientes clientes);



#endif /* LISTACLIENTES_H_INCLUDED*/
