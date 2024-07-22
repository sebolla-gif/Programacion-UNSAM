/*
Leer un string por teclado y luego mostrarlo en orden inverso sin usar las 
funciones de string.h 
*/
#include <stdio.h>
#include <stdlib.h>

void OrdenInverso(char str[])
{
    char *ptr;

    // Mover el puntero al final de la cadena
    ptr = str;
    while (*ptr != '\0')
    {
        ptr++;
    }

    // Retroceder el puntero y imprimir la cadena en orden inverso
    while (ptr > str)
    {
        ptr--;
        printf("%c", *ptr);
    }

}

int main(void)
{
    char str[200];

    gets(str);

    OrdenInverso(str);

    return 0;
}
