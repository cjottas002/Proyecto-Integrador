/*Funciones relacionadas con una lista de usuarios.*/
#include <stdio.h>
#include <string.h>
#include "../auxiliar/auxiliar.h"
#include "../productos/listaProductos.h"
#include "../clientes/listaUsuarios.h"
#define long 20



char identificacionUsuario (char loginUsuario[])/*Identifica el tipo de usuario.*/
{
    /*Declaraci�n de variables*/
    int i, n=0;
    char *nomb, pass[long+1], identify;
    char *fpass;/*Creaci�n de un vector de memoria din�mica*/
    struct sListaUsuarios usuarios;

    cargaListaUsuarios (&usuarios);/*Llamada a dicha funci�n para utilizar los datos que tiene almacenado del archivo usuarios.dat*/
    fpass = (char *)malloc(sizeof(usuarios._lista[0]._clave));/*Vector din�mico que asigna a la variable fpass la misma cantidad de memoria que tiene su homologa en la estructura*/
    nomb = (char *)malloc(sizeof(usuarios._lista[0]._login));/*Vector din�mico que asigna a la variable nomb la misma cantidad de memoria que tiene su homologa en la estructura*/

    for(i=2; i>-1; i--)/*Controla que el usuario no meta m�s de tres veces sus credenciales*/
    {


        gotoxy(28,8);
        printf("Acceso al sistema       ");
        gotoxy(3,13);
        printf("                          ");/*limpia la pantalla*/
        gotoxy(3,14);
        printf("                             ");/*limpia la pantalla*/
        gotoxy(3,15);
        printf("                           ");/*limpia la pantalla*/
        gotoxy(33,40);
        printf("                                            ");/*limpia la pantalla*/
        gotoxy(32,42);
        printf("                                                                             ");/*limpia la pantalla*/



        /*Pide al usuario que introduzca sus credenciales(login y pass)*/
        gotoxy(32,40);
        printf("Introduzca su Login: ");
        scanf("%s", loginUsuario);

        gotoxy(32,40);
        printf("Introduzca su clave de acceso: ");
        scanf("%s", pass);

        /*Funciones relacionada con el acceso a la tienda del usuario(si est� registrado o no)*/
        for(n=0; n<usuarios._num; n++)
        {

            nomb = usuarios._lista[n]._login;/*Recoge los datos le�dos(ID del usuario) y los almacena en la variable nomb*/
            fpass = usuarios._lista[n]._clave;/*Recoge los datos le�dos(contrase�a del usuario) y los almacena en la variable fpass*/
            identify = usuarios._lista[n]._tipo;/*Recoge los datos le�dos(tip de usuario) y los almacena en la variable identify*/


            if (strcmp(loginUsuario, nomb) == 0 && strcmp(pass, fpass) == 0)/*Autentifica si el usuario est� registrado o no*/
            {

                return identify;/*Devuelve el valor del tipo de usuario*/
                break;
            }/*Fin sentencia if*/

        }/*Fin sentencia for(controla que se lean todos los usuarios del fichero usuarios.dat)*/


        if (strcmp(nomb, loginUsuario) != 0 || strcmp(pass, loginUsuario) != 0){/*Autentifica si el usuario est� registrado o no*/

            gotoxy(32,42);
            printf("Login o clave no son correctos. Le quedan %d intentos. [Pulse una tecla]", i);
            getch();

        }/*Fin sentencia if*/

    }/*Fin sentencia for(Controla que el usuario no introduzca m�s de 3 veces mal su contrase�a)*/


    gotoxy(32,42);
    printf("Sus datos no est�n registrados, registrese por favor. [Pulse una tecla]");
    getch();

    return 0;
}


/*Carga los datos del archivo binario de usuarios en una lista de usuarios.*/
int cargaListaUsuarios (struct sListaUsuarios *plUsuarios)
{
    /*Declaraci�n de variables*/
    int i=0;
    int n;
    FILE *ptr;/*Se declara un puntero a un fichero llamado ptr*/
    plUsuarios->_num = 0; /*Inicializa la variable _num a 0*/

    ptr = fopen("./BASEDATOS/usuarios.dat", "rb");/*abre el fichero que rec�be como par�metro en modo binario*/


    if (ptr == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo usuarios.dat");
        exit(0);
    }
    else
    {
        /*Creaci�n del vector din�mico de esta estructura*/
        fseek(ptr, 0, SEEK_END);/*Posiciona el cursor al final del fichero*/
        n = ftell(ptr)/sizeof(struct sUsuario);/*Nos dice el n�mero de datos a leer*/
        rewind(ptr);/*Posiciona el cursor al principio del fichero*/

        plUsuarios->_lista = malloc(n*sizeof(struct sUsuario));/*Asignaci�n din�mica  de memoria necesaria*/

        /*Lee todos los datos del fichero usuario.dat*/
        while(fread (&plUsuarios->_lista[i], sizeof(struct sUsuario),1, ptr) != 0)
        {
            i++;/*Proporciona al vector el n�mero de datos le�dos*/
        }/*Fin sentencia while*/
        plUsuarios->_num  = i;/*Ajusta el puntero al n�mero de clientes le�dos*/

        if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero usuarios.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/


    }/*Fin if..else(controla la apertura del fichero)*/


    return 0;
}
