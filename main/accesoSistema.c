/*Funciones relacionadas con el control de acceso a la tienda virtual.*/
#include <stdio.h>
#include <string.h>
#include "../main/menus.h"
#include "../auxiliar/auxiliar.h"
#include "../tiendavirtual/TVirtual.h"
#include "../clientes/listaUsuarios.h"
#include "../cestas/cesta.h"

void gestionAccesoTV ()/*Gestiona el acceso a la tienda virtual*/
{
    /*Declaración de variables*/
    char loginUsuario[20];
    char seleccion;


    seleccion = identificacionUsuario(loginUsuario);

    switch (seleccion)
    {
    case 0:
        break;

    case 1:
        accesoGerenteTV();
        break;

    case 2:
        gestionMenuCesta(loginUsuario);
        break;

    }/*fin switch*/

    return;
}
