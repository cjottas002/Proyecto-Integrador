/*Funciones relacionadas con la lista de clientes de la tienda virtual.*/
#include <stdio.h>
#include <string.h>
#include "../main/menus.h"
#include "../clientes/clientes.h"
#include "../auxiliar/auxiliar.h"
#include "../tiendaVirtual/Tvirtual.h"
#include "../clientes/listaClientes.h"
#include "../clientes/solicitud.h"

void inicListaClientes (struct sListaClientes *pClientes)/*Inicializa los datos de una lista de clientes.*/
{
    int i;

    pClientes->_num = (int)NULL;

    for(i=0; i<pClientes->_num; i++)
    {

        pClientes->_lista[i]._login[i] = '\0';
        pClientes->_lista[i]._DNI[i] = '\0';
        pClientes->_lista[i]._apellidos[i] = '\0';
        pClientes->_lista[i]._nombre[i] = '\0';
    }

    return;
}


void eliminaCliente ()/*Elimina un cliente de la lista de clientes*/
{
    struct sListaClientes cliente1;
    int i;
    char login[30], archBorrador[30] = "./BASEDATOS/temp.dat";
    FILE *borraCliente;

    inicListaClientes(&cliente1);/*Llamada a dicha funci�n para inicializar los datos a "0"*/
    cargaListaClientes(&cliente1);/*Llamada a dicha funci�n para cargar los datos*/
    muestraListaClientes(cliente1);/*Funci�n que muestra por pantalla a los clientes contenidos en el fichero clientes.dat*/

    borraCliente = fopen(archBorrador, "wb");

    if (borraCliente == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo usuarios.dat");
        exit(0);
    }


    gotoxy(30,8);
    printf("Elimina Usuario             ");

    gotoxy(32,42);
    printf("                                                                        ");
    gotoxy(32,42);
    printf("Introduzca el login del cliente que desea eliminar: ");
    fflush(stdin);
    gets(login);

    for(i=0; i<cliente1._num; i++)
    {

        if(strcmp(login, cliente1._lista[i]._login) == 0)/*Controla que coincidan el login del usuario que desea borrar*/
        {


            gotoxy(32,42);
            printf("                                                                        ");
            gotoxy(32,42);
            printf("Usuario -%s- eliminado correctamente.[Pulse una tecla]", cliente1._lista[i]._login);
            getch();

        }
        else
        {
            fwrite (&cliente1._lista[i], sizeof(struct sCliente),1, borraCliente);/*Escribe los datos de todos los clientes excepto el que se ha tecleado por pantalla*/

            if (borraCliente == NULL)/*Controla la apertura del fichero*/
            {
                gotoxy(30,42);
                printf("Error en lectura de archivo temp.dat");
                exit(0);
            }/*fin if*/

        }/*Fin sentencia if(controla que coincidan los logins)*/

    }/*Fin sentencia for(controla que se compare la cadena metida por el usuario con la que contiene el login)*/



    if( fclose(borraCliente) != 0)/*Controla el cierre del fichero*/
    {
        gotoxy(30,42);
        printf( "Problemas al cerrar el fichero temp.dat" );
        exit(0);
    }/*Fin sentencia if(Controla el cierre del fichero*/



    guardaListaClientes(cliente1);/*Llama a dicha funci�n para guardar la lista modificada en el archivo de clientes.dat*/

    return;
}



void muestraListaClientes (struct sListaClientes lClientes)/*Muestra en pantalla los datos de TODOS los clientes registrados.*/
{
    /*Declaraci�n de variables y ficheros*/
    int i, y=13;

        gotoxy(32,42);
    printf("                                                                       ");/*Limpia la pantalla*/

    gotoxy(4,10);
    printf("login\tDNI\t    Apellidos\t\tNombre");


    for(i=0; i<lClientes._num; i++)
    {

        gotoxy(4,y);
        muestraCliente(lClientes._lista[i]);/*Funci�n que muestra por pantalla a los clientes contenidos en el fichero clientes.dat*/
        y++;

        if(y>30)
        {
            gotoxy(32,42);
            printf("[Pulse una tecla para ver mas clientes]");
            getch();
            borraPantalla();/*Funcion que borra la pantalla*/
            y=13;
        }/*Fin funci�n if(sirve para cuando se llene la pantalla no colapse y muestre los clientes en la siguiente pantalla)*/

    }/*Fin sentencia for(Controla que se muestren todos los clientes del dichero cliente.dat)*/

    gotoxy(32,40);
    printf("                                                              ");
    gotoxy(32,42);
    printf("[Pulse una tecla para continuar]");
    getch();
    gotoxy(32,40);
    printf("                                        ");/*limpia la pantalla*/

    return;
}


void gestionClientes ()/*Gestiona la lista de clientes de la tienda virtual.*/
{
    /*declaracion de variables*/
    int seleccion;
    struct sListaClientes clientes;
    const char archInfoClientes[20];

    do
    {
        seleccion = menuClientes();/*llamada a dicha funcion*/


        switch(seleccion)
        {
        case 0:
            break;

        case 1:
            cargaListaClientes(&clientes);
            muestraListaClientes(clientes);
            break;

        case 2:
            cargaListaClientes(&clientes);
            generaInformeClientes(archInfoClientes);
            break;

        case 3:
            tramitacionSolicitudes();
            break;

        case 4:
            eliminaCliente();
            break;
        }/*fin switch*/

    }
    while(seleccion != 0);

    return;
}


int menuClientes ()/*Muestra las opciones relacionadas con los clientes.*/
{
    /*declaraci�n de variables*/
    char opcion;
    int y;

    gotoxy(4,10);
    printf("                                                       ");
    gotoxy(25,8);
    printf("     ");/*Limpia la pantalla*/
    gotoxy(20,16);
    printf("                                                    ");/*Limpia la pantalla*/
    gotoxy(20,17);
    printf("                                                 ");/*Limpia la pantalla men� anterior*/

    for(y=18; y<=35; y++)
    {
        gotoxy(4,y);
        printf("                                                                ");/*Limpia la pantalla*/
    }

    gotoxy(32,42);
    printf("                                                                       ");/*Limpia la pantalla*/



    gotoxy(30,8);
    printf("Gesti�n de Clientes             ");
    gotoxy(4,13);
    printf("1 - Listado de clientes.                                         ");
    gotoxy(4,14);
    printf("2 - Informe de clientes.                                          ");
    gotoxy(4,15);
    printf("3 - Tramitaci�n de solicitudes.                                    ");
    gotoxy(4,16);
    printf("4 - Eliminar cliente.");
    gotoxy(4,17);
    printf("0 - Men� anterior.\n");

    gotoxy(32,40);
    printf("Seleccione una opci�n: ");
    opcion = getch();



    return opcion-48;
}

/*Genera una archivo de texto con los datos de los clientes*/
void generaInformeClientes (const char archInfo[])
{
    /*Declaraci�n de variables y ficheros*/
    struct sListaClientes info;
    int i;
    FILE *ptr;
    archInfo = "./BASEDATOS/infoClientes.txt";

    cargaListaClientes(&info);/*Llamada a dicha funci�n para leer los datos que contiene(archivo cliente.dat)*/

    ptr = fopen(archInfo, "wt");/*Abre el archivo de texto que va a crear (infoClientes.txt) en modo escritura*/

    if (ptr == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo infoClientes.txt");
        exit(0);
    }
    else
    {
        for(i=0; i<info._num; i++)
        {
            fflush(stdin);/*Limpia el buffer de entrada*/
            fprintf(ptr, "%-5s\t", info._lista[i]._login);/*Escribe los datos le�dos (del fichero binario cliente.dat) en un fichero llamado infoClientes.txt*/
            fflush(stdin);/*Limpia el buffer de entrada*/
            fprintf(ptr, "%-10s\t",info._lista[i]._DNI );/*Escribe los datos le�dos (del fichero binario cliente.dat) en un fichero llamado infoClientes.txt*/
            fflush(stdin);/*Limpia el buffer de entrada*/
            fprintf(ptr, "%-20.15s\t", info._lista[i]._apellidos);/*Escribe los datos le�dos (del fichero binario cliente.dat) en un fichero llamado infoClientes.txt*/
            fflush(stdin);/*Limpia el buffer de entrada*/
            fprintf(ptr, "%-20s\n", info._lista[i]._nombre);/*Escribe los datos le�dos (del fichero binario cliente.dat) en un fichero llamado infoClientes.txt*/
        }/*Fin sentencia for*/

        gotoxy(32,42);
        printf("Informe generado correctamente [Pulse una tecla]");
        getch();

        if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero infoClientes.txt" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/

    }/*Fin sentencia if...else (controla la apertura del archivo infoClientes.txt)*/

    return;
}

void cargaListaClientes (struct sListaClientes *pClientes)/*Carga los datos del archivo de clientes en una lista de clientes.*/
{
    /*Declaraci�n de variables*/
    int i=0;
    int n;
    FILE *ptr;/*Se declara un puntero a un fichero llamado ptr*/


    ptr = fopen("./BASEDATOS/clientes.dat", "rb");/*abre el fichero que rec�be como par�metro en modo binario*/


    if (ptr == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo clientes.dat");
        exit(0);
    }
    else
    {
        /*Creaci�n del vector din�mico de esta estructura*/
        pClientes->_num = 0; /*Inicializa la variable _num a 0*/
        fseek(ptr, 0, SEEK_END);/*Posiciona el cursor al final del fichero*/
        n = ftell(ptr)/sizeof(struct sCliente);/*Nos dice el n�mero de datos a leer*/
        rewind(ptr);/*Posiciona el cursor al principio del fichero*/

        pClientes->_lista = malloc(n*sizeof(struct sCliente));/*Asignaci�n din�mica  de memoria necesaria*/

        /*Lee todos los datos del fichero usuario.dat*/
        while(fread (&pClientes->_lista[i], sizeof(struct sCliente),1, ptr) != 0)
        {
            i++;/*Proporciona al vector el n�mero de datos le�dos*/
        }/*Fin sentencia while*/
        pClientes->_num  = i;/*Ajusta el puntero al n�mero de clientes le�dos*/

        if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero clientes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/


    }/*Fin if..else(controla la apertura del fichero)*/



    return;
}

void guardaListaClientes (struct sListaClientes clientes)
{
    /*Declaraci�n de variables*/
    int i=0, n, num;
    FILE *temp;
    FILE *cliente;

    temp = fopen("./BASEDATOS/temp.dat", "rb");/*Apertura del archivo temp.dat(contiene los registros temporalment)*/
    cliente = fopen("./BASEDATOS/clientes.dat", "wb");/*Apertura del archivo clientes.dat(contiene los registros antiguos)*/


    if (temp == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo temp.dat");
        exit(0);
    }
    else if (cliente == NULL)
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo clientes.dat");
        exit(0);
    }
    else
    {
        /*Creaci�n del vector din�mico de esta estructura*/
        clientes._num = 0;
        fseek(temp, 0, SEEK_END);/*Posiciona el cursor al final del fichero*/
        n = ftell(temp)/sizeof(struct sCliente);/*Nos dice el n�mero de datos a leer*/
        rewind(temp);/*Posiciona el cursor al principio del fichero*/

        clientes._lista = malloc(n*sizeof(struct sCliente));/*Asignaci�n din�mica  de memoria necesaria*/

        /*Lee todos los datos del fichero temp.dat*/
        while(fread (&clientes._lista[i], sizeof(struct sCliente),1, temp) != 0)
        {
            i++;/*Proporciona al vector el n�mero de datos le�dos*/
        }/*Fin sentencia while*/
        num  = i;/*Ajusta el puntero al n�mero de clientes le�dos*/

        /*Lee todos los datos del fichero temp.dat*/
        for(i=0; i<num; i++)
        {
            fwrite (&clientes._lista[i], sizeof(struct sCliente),1, cliente);/*Escribe en el ficheo clientes.dat los datos le�dos de temp.dat*/

        }/*Fin sentencia for(controla que se escriban todos los datos le�dos)*/


        if( fclose(temp) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero temp.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/

        if( fclose(cliente) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero clientes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/

    }/*Fin sentencia if..else(controla que se abren los archivos temp.dat y clientes.dat)*/


    remove("./BASEDATOS/temp.dat");/*Elimina dicho archivo ya que no se necesita*/

    return;
}


