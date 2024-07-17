#include <stdio.h>
#include <stdlib.h>

void Mayusculas(char str[])
{
//Usamos punteros para facilitar el manejo de los vectores.
    while(*str != '\0') //Recorremos el vector hasta el '\0'.
    {
        if(97 <= *str && *str <= 122) //Revisamos si el caracter de la posicion es una letra.
        {
            *str = *str - 32; //De ser asi lo cambiamos a mayusculas restando 32 (revisar tabla ASCII).
        }
        str++; //Movemos el puntero a la posicion siguiente del vector.
    }

}

int main(void)
{
    char str[200];

    gets(str);

    Mayusculas(str);

    printf("%s", str);

    return 0;
}
