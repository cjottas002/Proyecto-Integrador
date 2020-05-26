/*Funciones relacionadas con la solicitud de un nuevo cliente.*/
#include <stdio.h>
#include <string.h>
#include "../clientes/solicitud.h"
#include "../clientes/clientes.h"
#include "../auxiliar/auxiliar.h"
#include "../clientes/listaClientes.h"

void solicitaRegistro ()/*Pide los datos al nuevo cliente.*/
{
    /*Declaración de variables*/
    struct sSolicitud clientes;
    FILE *ptr;/*Declara un puntero a fichero llamado ptr*/

    inicCliente(&clientes._cliente);/*Llamada a dicha función para inicializar los datos (login, DNI, apellidos, nombre) a cadena vacía*/
    getDatosSolicitud(&clientes);/*Llamada a dicha función para recoger los datos que contiene*/

    ptr = fopen("./BASEDATOS/solicitudes.dat", "wb");

    if (ptr == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(30,42);
        printf("Error en lectura de archivo solicitudes.dat");
        exit(0);
    }
    else
    {

        fwrite(&clientes._cliente, sizeof(struct sCliente),1, ptr);/*Escribe los 4 datos de la estructura de sCliente en el archivo solicitudes.dat*/
        fwrite(&clientes._user, sizeof(struct sUsuario),1, ptr);/*Escribe los 3 datos de la estructura de sUsuario en el archivo solicitudes.dat*/

        if( fclose(ptr) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero solicitudes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/
    }/*Fin sentencia if...else (controla la apertura del fichero solicitudes.dat)*/




    return;
}

void getDatosSolicitud (struct sSolicitud *pSolicitud)/*Solicita al usuario los datos para rellenar la solicitud.*/
{
    /*Declaración de variables*/
    bool t;


    gotoxy(28,8);
    printf("Solicitud de registro");/*Cabecera de la ventana solicitud de registro*/

    gotoxy(32,40);
    printf("                                                                ");/*Limpia la zona de la pantalla*/
    gotoxy(32,42);
    printf("                                                          ");/*limpia la pantalla*/

    borraPantalla();/*Borra la pantalla*/
    /*solicita al nuevo cliente sus credenciales completas*/
    gotoxy(4,13);
    printf("Introduzca su login: ");
    fflush(stdin);
    gets(pSolicitud->_cliente._login);

    do
    {

        gotoxy(4,14);
        printf("Introduzca su DNI: ");
        fflush(stdin);
        gets(pSolicitud->_cliente._DNI);

        t = compruebaDNI(pSolicitud->_cliente._DNI);

        if (t != true)
        {
            gotoxy(32,42);
            printf("El DNI introducido no es correcto.[Pulse una tecla]");
            getch();
            gotoxy(32,42);
            printf("                                                   ");
            gotoxy(4,14);
            printf("                                                    ");
        }/*Fin sentencia if*/


    }while(t != true);/*Fin sentencia do...while(Controla que se introduzca un dni correctamente)*/


    gotoxy(4,15);
    printf("Introduzca sus apellidos: ");
    fflush(stdin);
    gets(pSolicitud->_cliente._apellidos);

    gotoxy(4,16);
    printf("Introduzca su Nombre: ");
    fflush(stdin);
    gets(pSolicitud->_cliente._nombre);

    strcpy(pSolicitud->_user._login, pSolicitud->_cliente._login);/*_cliente pasa el valor almacenado en su variable a _user(ambos contenidos en struct sSolicitud)*/

    borraPantalla();/*Borra la pantalla*/
    gotoxy(4,13);
    printf("Login: %s",pSolicitud->_user._login);

    gotoxy(4,14);
    printf("Introduzca su contraseña: ");
    fflush(stdin);
    gets(pSolicitud->_user._clave);


    pSolicitud->_user._tipo = 2;/*Da al nuevo usuario una cuenta de tipo cliente*/


    borraPantalla();/*Borra la pantalla*/


    return;
}


void tramitacionSolicitudes ()/*Gestiona las solicitudes de registro pendientes.*/
{


    /*Declaración de variables*/
    char opcion;
    struct sSolicitud nueSolicitud;

    FILE *_solicitudes;/*Se declara un puntero a un fichero llamado _solicitudes*/
    FILE *_cliente;/*Se declara un puntero a un fichero llamado _cliente*/
    FILE *_usuario;/*Se declara un puntero a un fichero llamado _usuario*/


    _solicitudes = fopen("./BASEDATOS/solicitudes.dat", "rb");/*abre el fichero que recíbe como parámetro en modo binario*/



    if (_solicitudes == NULL)/*Controla la apertura del fichero*/
    {
        gotoxy(32,42);
        printf("No hay solicitudes pendientes.[Pulse una tecla]");
        getch();
    }
    else
    {

        /*Lee todos los datos del fichero usuario.dat*/
        while(fread (&nueSolicitud._cliente, sizeof(struct sCliente),1, _solicitudes) != 0)/*Se lee los datos de cliente*/
        {
            fread (&nueSolicitud._user, sizeof(struct sUsuario),1, _solicitudes);/*Se leen los datos de usuario*/
        }/*Fin sentencia for(controla que se lean todos los caracteres del fichero binario solicitudes.dat)*/

        borraPantalla();/*limpia la pantalla*/
        /*Muestra por pantalla (al gerente), la ultima solicitud que ha realizado un usuario*/
        gotoxy(4,13);
        printf("Login: %s", nueSolicitud._cliente._login);
        gotoxy(4,14);
        printf("DNI: %s", nueSolicitud._cliente._DNI);
        gotoxy(4,15);
        printf("Apellidos: %s", nueSolicitud._cliente._apellidos);
        gotoxy(4,16);
        printf("Nombre: %s", nueSolicitud._cliente._nombre);
        gotoxy(4,18);
        printf("Login: %s", nueSolicitud._user._login);
        gotoxy(4,19);
        printf("Contraseña: %s", nueSolicitud._user._clave);
        gotoxy(4,20);
        printf("tipo: %d", nueSolicitud._user._tipo+48);


        if( fclose(_solicitudes) != 0)/*Controla el cierre del fichero*/
        {
            gotoxy(30,42);
            printf( "Problemas al cerrar el fichero solicitudes.dat" );
            exit(0);
        }/*Fin sentencia if(Controla el cierre del fichero*/

        /*Pregunta al gerente si quiere guardar la nueva solicitud*/

        gotoxy(32,42);
        printf("Nueva solicitud, ¿Acepta?: [s/n]");

        do
        {

            opcion = getche();/*Función que recoge la opción que ha seleccionado el gerente*/
            /*n = 110*/
            /*s = 115*/

            if (opcion != 115 && opcion != 110 )
            {
                gotoxy(32,42);
                printf("Perdón, no le he entendido, ¿Acepta la solicitud?: [s/n]");
            }/*fin if*/

        }
        while(opcion != 115 && opcion != 110); /*fin sentencia do...while(controla que el usuario teclee bien la opción)*/

        switch(opcion)
        {
        case 115:
            /*opcion 1*/
            _cliente = fopen("./BASEDATOS/clientes.dat", "ab");/*abre el fichero que recíbe como parámetro en modo binario*/
            if (_cliente == NULL)/*Controla la apertura del fichero*/
            {
                gotoxy(30,42);
                printf("Error en lectura de archivo cliente.dat");
                exit(0);
            }
            else
            {
                fseek(_cliente,0,SEEK_END);/*Posiciona el cursor al final del fichero*/
                fwrite(&nueSolicitud._cliente, sizeof(struct sCliente),1, _cliente);/*Escribe en el fichero la nueva solicitud de los caracteres
                                                                                    concernientes a struct sCliente, siempre y cuando el gerente acepte*/

                if( fclose(_cliente) != 0)/*Controla el cierre del fichero*/
                {
                    gotoxy(30,42);
                    printf( "Problemas al cerrar el fichero cliente.dat" );
                    exit(0);
                }/*Fin sentencia if(Controla el cierre del fichero*/
            }/*Fin sentencia if...else(controla la apertura del fichero cliente.dat)*/



            _usuario = fopen("./BASEDATOS/usuarios.dat", "ab");/*abre el fichero que recíbe como parámetro en modo binario*/

            if (_usuario == NULL)/*Controla la apertura del fichero*/
            {
                gotoxy(30,40);
                printf("Error en lectura de archivo usuarios.dat");
                exit(0);
            }
            else
            {
                fseek(_usuario,0,SEEK_END);/*Posiciona el cursor al final del fichero*/
                fwrite(&nueSolicitud._user, sizeof(struct sUsuario),1, _usuario);/*Escribe en el fichero la nueva solicitud de los caracteres concernientes
                                                                                a struct sUsuario, siempre y cuando el gerente acepte*/

                if( fclose(_usuario) != 0)/*Controla el cierre del fichero*/
                {
                    gotoxy(30,42);
                    printf( "Problemas al cerrar el fichero usuario.dat" );
                    exit(0);
                }/*Fin sentencia if(Controla el cierre del fichero*/
            }/*Fin sentencia if..else(controla la apertura del fichero usuario.dat)*/
            gotoxy(51,42);
            printf("                                                      ");/*Limpia la pantalla*/
            gotoxy(32,42);
            printf("Solicitud Aceptada.[Pulse una tecla] ");
            getch();
            gotoxy(51,42);
            printf("                                                      ");/*Limpia la pantalla*/
            gotoxy(3,14);
            printf("                            ");/*Limpia la pantalla*/
            remove("./BASEDATOS/solicitudes.dat");
            break;

        case 110:
            /*opcion 2*/
            gotoxy(51,42);
            printf("                                                      ");/*Limpia la pantalla*/
            gotoxy(32,42);
            printf("Solicitud rechazada. [Pulse una tecla]");
            getch();
            gotoxy(51,42);
            printf("                                                      ");/*Limpia la pantalla*/
            gotoxy(3,14);
            printf("                            ");/*Limpia la pantalla*/
            remove("./BASEDATOS/solicitudes.dat");/*elimina el fichero que recibe como parámetro*/
            break;

        }/*Fin sentencia switch(controla la dirección de la opción elegida)*/

    }/*Fin if..else(controla la apertura del fichero)*/

    return ;
}
