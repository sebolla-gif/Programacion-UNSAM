/*
Escriba un programa que permita al usuario ingresar valores enteros en una
matriz de 3x3 y luego imprima los elementos de la diagonal principal.
Usar notación aritmética de punteros (no subíndices []) para recorrer la matriz.
*/
#include <stdio.h>

int main(void)
{
    int v[3][3];

    // Ingresar valores en la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Ingrese el valor de la matriz %dx%d: ", i, j);
            scanf("%d", (*(v + i) + j));
        }
    }

    // Imprimir los elementos de la diagonal principal
    printf("Elementos de la diagonal principal:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(*(v + i) + i));
    }

    return 0;
}
