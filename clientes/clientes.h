#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdbool.h>

typedef struct sCliente/*Contiene los atributos de un cliente.*/
{
    char _login [10];/*Login del cliente*/
    char _DNI [11];/*DNI del cliente*/
    char _apellidos [80];/*Apellidos del cliente*/
    char _nombre [40];/*Nombre del cliente*/

} tCliente;


void inicCliente (struct sCliente *pCliente);
bool compruebaDNI (const char DNI[]);
void muestraCliente (struct sCliente cliente);


#endif /* CLIENTES_H_INCLUDED*/
