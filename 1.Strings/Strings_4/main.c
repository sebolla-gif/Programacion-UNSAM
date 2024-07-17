#include <stdio.h>
#include <string.h>

void MayorLongitud(int cantidad){

    char str[100];

    char mayor[100];

    for(int i=0; i<cantidad; i++)
    {
        printf("Ingrese una cadena: ");

        gets(str);

        if(strlen(mayor) < strlen(str)){
            strcpy(mayor, str);
        }

    }
    printf("La cadena de mayor longitud es: %s", mayor);
}

int main(void)
{
    MayorLongitud(5);

    return 0;
}
