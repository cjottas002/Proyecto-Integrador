/*Contiene la función main*/
#include <stdio.h>
#include <locale.h>
#include "../auxiliar/auxiliar.h"
#include "../tiendavirtual/TVirtual.h"
#include "../main/menus.h"
#include "../cestas/cesta.h"


int main()
{

    setColorTexto(31);
    system("mode con cols=150 lines=50");
    marcoTiendaVirtual();

    setlocale(LC_CTYPE, "Spanish");

    gotoxy(3,14);
    gestionMenuPrincipal();





    return 0;
}
