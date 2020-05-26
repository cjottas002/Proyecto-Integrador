#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct sFecha
{
    int _hora;
    int  _minuto;
    int _segundo;
    int _dia;
    int _mes;
    int _anyo;

};

void inicFecha (struct sFecha *fecha);
struct sFecha fechaSistema ();
#endif /* FECHA_H_INCLUDED*/
