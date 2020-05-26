#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

struct sUsuario/*Contiene los atributos de un usuario.*/
{

    char _login [10];/*Login*/
    char _clave [10];/*Contraseña*/
    char _tipo;/*tipo de usuario: 0 - gerente 1 - cliente*/

};
char identificacionUsuario (char loginUsuario[]);

#endif /* USUARIO_H_INCLUDED*/
