/*
Implemente una función que reciba un vector de números en punto flotante y un
entero que representa el tamaño del vector y devuelva el promedio.
Usar notación aritmética de punteros (no subíndices []) para recorrer el vector.
*/
#include <stdio.h>
#include <stdlib.h>

float Promedio(float *v,int cant)
{
    float promedio=0.0;
    for(int i=0; i<cant; i++)
    {
        promedio += *(v+i);
    }
    return (float)promedio/cant;
}

int main(void)
{
    int cant=10;
    float v[cant];

    for(int i=0; i<cant; i++)
    {
        *(v+i)=(float)i;
    }

    printf("%.2f", Promedio(v,cant));
    return 0;
}
