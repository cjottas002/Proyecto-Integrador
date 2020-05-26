#ifndef SOLICITUD_H_INCLUDED
#define SOLICITUD_H_INCLUDED
#include "../clientes/clientes.h"
#include "../clientes/usuario.h"

typedef struct sSolicitud
{

    struct sUsuario _user;
    struct sCliente _cliente;



} tSolicitud;


void solicitaRegistro ();
void getDatosSolicitud (struct sSolicitud *pSolicitud);
void tramitacionSolicitudes ();

#endif /*SOLICITUD_H_INCLUDED*/
