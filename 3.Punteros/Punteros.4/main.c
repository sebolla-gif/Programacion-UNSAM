/*
Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la
cantidad de números impares que contiene.
int impares (int *v, int tam);
*/
#include <stdio.h>
#include <stdlib.h>

int impares (int *v, int tam)
{
    int cant_imp=0;
    for(int i=0; i<tam; i++)
    {
        if(*(v+i)%2==0)
        {
            cant_imp++;
        }
    }
    return cant_imp;
}

int main(void)
{
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int tam=10, imp;
    int *p = v;
    imp=impares(p,tam);
    printf("la cantidad de impares es: %d", imp);
    return 0;
}
