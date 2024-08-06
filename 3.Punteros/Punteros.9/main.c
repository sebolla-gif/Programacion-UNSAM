/*
 Implemente la siguiente función para calcular el producto escalar de dos vectores:
double prod_esc (double *a, double *b, int n);
Donde a y b apuntan a vectores de longitud n.
La función debe retornar a[0]*b[0]+a[1]*b[1]+ … + a[n-1]*b[n-1]
Usar notación aritmética de punteros (no subíndices []) para recorrer los vectores.
*/
#include <stdio.h>
#include <stdlib.h>

double Prod_esc (double *a, double *b, int n)
{

    double prod_esc=0;
    for(int i=0; i<n; i++)
    {
        prod_esc+=(*(a+i) * *(b+i));
    }
    return prod_esc;
}

int main(void)
{
    int n=10;
    double v1[n], v2[n];

    for(int i=0; i<n; i++)
    {
        *(v1+i) = i, *(v2+i) = i;
    }

    printf("%.2lf", Prod_esc(v1,v2,n));
    return 0;
}
