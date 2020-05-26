/*[FUNCIONES RELACIONADAS A LA MEJORA DE LA AMIGABILIDAD Y AYUDA AL PROGRAMADOR]*/
#include<windows.h>
#include<stdio.h>
#include<conio.h>




/* Funcion que nos permite colocar el cursor en cualquier parte de la pantalla.*/
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return ;
}

/* Cambia el color de la consola */
void setColorTexto(WORD colors)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colors);

    return ;
}

/*Borra la zona de la ventana 1*/
void borraPantalla()
{
    int y;

    for(y=12; y<=34; y++)
    {
        gotoxy(3,y);
        printf("                                                                    ");
    }
    return;
}

/*Borra la zona de la ventana 2*/
void borraPantalla2()
{
    int y;

    for(y=12; y<=34; y++)
    {
        gotoxy(76,y);
        printf("                                                                     ");
    }
 return;
}

