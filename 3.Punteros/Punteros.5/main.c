/*
Escribir una función que devuelva un puntero al máximo valor de un vector de
“doubles”.  Si el vector está vacío (cant = 0) la función debe retornar NULL.
double* max (double *v, int cant);
*/
#include <stdio.h>

double* findMax(double *v, int cant)
{
    if (cant == 0)
    {
        return NULL;
    }

    double *maxPtr = v;
    for (int i = 1; i < cant; i++)
    {
        if (*(v + i) > *maxPtr)
        {
            maxPtr = v + i;
        }
    }

    return maxPtr;
}

void readVector(double *v, int cant)
{
    printf("Ingrese los valores del vector:\n");
    for (int i = 0; i < cant; i++)
    {
        scanf("%lf", &v[i]);
    }
}

int main(void)
{
    int cant;
    double *max;

    printf("Ingrese la cantidad de valores del vector: \n");
    scanf("%d", &cant);

    if (cant < 0)
    {
        printf("La cantidad debe ser mayor que 0.\n");
        return 1;
    }

    double v[cant];

    readVector(v, cant);
    max = findMax(v, cant);

    if (max != NULL)
    {
        printf("El valor maximo es: %.2lf\n", *max);
    }
    else
    {
        printf("El vector esta vacio.\n");
    }

    return 0;
}
