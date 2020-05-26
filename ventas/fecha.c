/*Funciones relacionadas con datos horarios.*/
#include <stdio.h>
#include <time.h>
#include "../ventas/fecha.h"

void inicFecha (struct sFecha *fecha)/*Inicializa un registro de tipo sFecha*/
{
    fecha->_hora = 00;
    fecha->_minuto = 00;
    fecha->_segundo = 00;

    fecha->_dia = 1;
    fecha->_mes = 01;
    fecha->_anyo = 1900;


    return;
}


struct sFecha fechaSistema ()/*Lee la fecha del sistema.*/
{
    /*la funcion del archivo de cabecera time.h, localtime , convierten un valor time_t a una estructura struct tm*/
    /*Declaración de variables*/
    struct sFecha sistem;/*Se declara un atributo de tipo struct sFecha*/
    struct tm *horario;/*Se declara un puntero a la struct tm*//* Contiene los componentes del tiempo de Calendario */
    time_t start;/*Se declara una variable de tipo time_t*/
    /*time_t Representa tiempo de calendario */
    time(&start);
    horario = localtime(&start);

    /*Se agrega un 1 a horario->tm_mon porque el array se cuenta a partir de 0 y
    1900 a horario->tm_year porque el reloj cuenta a partir de ese año sin incluirlo*/
    sistem._dia = horario->tm_mday;
    sistem._mes = horario->tm_mon+1;
    sistem._anyo = horario->tm_year+1900;

    sistem._hora = horario->tm_hour;
    sistem._minuto = horario->tm_min;
    sistem._segundo = horario->tm_sec;



    return sistem;
}
