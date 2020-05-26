#ifndef LISTAUSUARIOS_H_INCLUDED
#define LISTAUSUARIOS_H_INCLUDED
#include "../clientes/usuario.h"


struct sListaUsuarios/*Contiene los atributos de una lista de usuarios.*/
{


    unsigned short _num;/*Número de registro*/
    struct sUsuario  *_lista;/*Lista de registro*/

};



int cargaListaUsuarios (struct sListaUsuarios *plUsuarios);


#endif /* LISTAUSUARIOS_H_INCLUDED*/
