/*
Leer 5 strings por teclado y mostrar el “mayor” (alfabéticamente) 
*/
#include <stdio.h>
#include <string.h>

void MayorAlfabeticamente(int cantidad)
{
    char mayor[100];

    char str[100];

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese una cadena: ");
        gets(str);
        if(i==0)
        {
            strcpy(mayor, str);
        }
        if (strcmp(str, mayor) > 0)
        {
            strcpy(mayor, str);
        }
    }

    printf("El mayor (alfabeticamente) es: %s\n", mayor);
}

int main(void)
{
    MayorAlfabeticamente(5);

    return 0;
}
